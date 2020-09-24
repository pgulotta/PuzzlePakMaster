import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.2
import QtQuick.Particles 2.15
import QtQuick.Controls.Material 2.12
import com.twentysixapps.puzzlepak.constants 1.0
import Box2DStatic 2.0

Page {
    id: tileSlidePageId

    property string helpText
    property alias musicSource: playMusicId.musicSource
    property alias shouldPlayMusic: playMusicId.shouldPlayMusic
    property alias sourceImage: backgroundImageId.source
    property alias puzzlePieceModel: repeaterId.model
    property alias bestScore: bestScoreId.secondsCounter
    property alias currentScore: currentScoreId.secondsCounter

    property Body pressedBody: null
    property int imagePieceWidth: 0
    property int imagePieceHeight: 0
    property var xCoordinatesList
    property var yCoordinatesList

    objectName: "TileSlidePage"
    width: windowWidth

    onWidthChanged: {
        if (width > 0) {
            puzzlePieceModel = TileSlideGame.puzzlePieceCount()
            imagePieceWidth = TileSlideGame.imagePieceWidth()
            imagePieceHeight = TileSlideGame.imagePieceHeight()
        }
    }
    Component.onCompleted: {
        setToolbarTitle(title)
        shouldPlayMusic = GameController.shouldPlayMusic()
    }

    Component.onDestruction: {
        playMusicId.stop()
    }

    Connections {
        target: GameController
        function onGamePuzzleChanged() {
            sourceImage = ""
            puzzlePieceModel = TileSlideGame.puzzlePieceCount()
            imagePieceWidth = TileSlideGame.imagePieceWidth()
            imagePieceHeight = TileSlideGame.imagePieceHeight()
            sourceImage = "image://puzzleImage"
        }
    }

    background: Rectangle {
        anchors.fill: parent
        gradient: BackgroundGradient {}
    }

    RowLayout {
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        width: parent.width
        SecondsClock {
            id: bestScoreId
            z: 2
            Layout.alignment: Qt.AlignLeft
            Layout.fillWidth: false
            Layout.margins: mediumPadding
            secondsCounter: GameController.getCurrentPuzzleBestScore()
        }
        SecondsClock {
            id: currentScoreId
            z: 2
            Layout.alignment: Qt.AlignRight
            Layout.fillWidth: false
            Layout.margins: largePadding
        }
    }

    MouseJoint {
        id: mouseJoint
        bodyA: anchorId
        dampingRatio: 0.8
        maxForce: 100
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onPressed: {
            if (pressedBody != null) {
                mouseJoint.maxForce = pressedBody.getMass() * 500
                mouseJoint.target = Qt.point(mouseX, mouseY)
                mouseJoint.bodyB = pressedBody
                pressedBody.bodyType = Body.Dynamic
            }
            startTimerText()
        }

        onPositionChanged: {
            mouseJoint.target = Qt.point(mouseX, mouseY)
            if (pressedBody != null)
                pressedBody.bodyType = Body.Dynamic
        }

        onReleased: {
            if (pressedBody != null) {
                pressedBody.bodyType = Body.Static
                mouseJoint.bodyB = null
                pressedBody = null
                isPuzzleSolved()
            }
        }
    }

    Image {
        id: backgroundImageId
        anchors.centerIn: parent
        opacity: 0.40
        onSourceChanged: {
            console.log("backgroundImageId.onSourceChanged + source=" + source
                        + "  puzzlePieceModel=" + puzzlePieceModel)

            if (source === "") {

                //            for (var index = 0; index < puzzlePieceModel; ++index) {
                //                var itemPiece = repeaterId.itemAt(index)
                //                itemPiece.opacity = 1.0
                //                itemPiece.scale = 1.0
                //                itemPiece.itemImageSource = ""
                //            }
                //                for (var i = 0; i < puzzlePieceModel; ++i) {
                //                    var item = repeaterId.itemAt(i)
                //                    item.itemImageSource = sourceImage + "/" + i
                //                    console.log("item.itemImageSource = " + item.itemImageSource)
                //                }
            } else {

            }
        }
    }

    World {
        id: physicsWorld
    }

    RectangleBoxBody {
        height: 0
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
    }

    RectangleBoxBody {
        width: 0
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }
    }

    RectangleBoxBody {
        height: 0
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }
    RectangleBoxBody {
        width: 0
        anchors {
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
    }

    Body {
        id: anchorId
        world: physicsWorld
    }

    Repeater {
        id: repeaterId

        delegate: Rectangle {
            property alias itemImageSource: imageId.source
            id: rectangle
            x: windowWidth / 2 * Math.random()
            y: windowHeight / 2 * Math.random()
            width: imagePieceWidth
            height: imagePieceHeight
            smooth: true
            Image {
                id: imageId
                source: "image://puzzleImage/" + index
                fillMode: Image.Pad
                anchors.fill: parent
                sourceSize.width: rectangle.width
                sourceSize.height: rectangle.height
            }

            Body {
                id: rectangleBodyId

                target: rectangle
                world: physicsWorld

                bodyType: Body.Dynamic
                Box {
                    id: boxBodyId
                    width: rectangle.width
                    height: rectangle.height
                    restitution: 0.5
                    friction: 0.55
                }
            }

            MouseArea {
                anchors.fill: parent
                onPressed: {
                    mouse.accepted = false
                    pressedBody = rectangleBodyId
                    pressedBody.bodyType = Body.Dynamic
                }
            }
            Behavior on scale {
                NumberAnimation {
                    duration: Constants.longAnimationDuration
                    easing.type: Easing.InOutBack
                }
            }
            Behavior on opacity {
                NumberAnimation {
                    duration: Constants.longAnimationDuration
                }
            }
        }
    }

    MusicPlayer {
        id: playMusicId
    }

    function setHighBestScore(currentBestScore, currentScore) {
        if (currentScore === 0)
            return
        if (currentBestScore === 0 || currentBestScore > currentScore)
            GameController.setCurrentPuzzleBestScore(currentScore)
    }

    function isPuzzleSolved() {
        if (puzzlePieceModel === undefined)
            return
        xCoordinatesList = new Array
        yCoordinatesList = new Array
        for (var index = 0; index < puzzlePieceModel; ++index) {
            var itemAt = repeaterId.itemAt(index)
            xCoordinatesList[index] = itemAt.x
            yCoordinatesList[index] = itemAt.y
        }
        if (TileSlideGame.isPuzzleSolved(xCoordinatesList, yCoordinatesList)) {
            stopTimerText()
            playMusicId.tryPlaySoundEffect()
            setHighBestScore(bestScore, currentScore)
            currentScoreId.resetClock(0)
            GameController.nextPuzzle()
            // animateSuccess()
            bestScoreId.resetClock(GameController.getCurrentPuzzleBestScore())
        }
    }

    function animateSuccess() {
        for (var i = 0; i < puzzlePieceModel; ++i) {
            var item = repeaterId.itemAt(i)
            item.opacity = 0.0
            item.scale = 0.1
            item.data[0].bodyType = Body.Dynamic
            item.data[0].fixtures[0].density = 0
            item.data[0].fixtures[0].restitution = 1.0
            item.data[0].fixtures[0].friction = 0
            item.data[0].fixtures[0].rotation = Math.random() * 360
            item.data[0].fixtures[0].x += Math.random() * 10
            item.data[0].fixtures[0].y += Math.random() * 10
        }
    }

    function startTimerText() {
        if (!currentScoreId.timerRunning)
            currentScoreId.timerRunning = true
    }

    function stopTimerText() {
        if (currentScoreId.timerRunning)
            currentScoreId.timerRunning = false
    }
}
