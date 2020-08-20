import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12
import QtQuick.Particles 2.15
import Box2DStatic 2.0

import com.twentysixapps.puzzlepak.constants 1.0

Page {
    id: polyformsPageId

    property Body pressedBodyId: null
    property var problemPositionPoints: null
    property var solutionPositionPoints: null
    property var problemCenterPoints: null
    property var solutonCenterPoints: null
    property real xPositionDeltaProblem: isPortraitMode ? windowWidth * .2 : drawUnit
    property real yPositionDeltaProblem: drawUnit * .5
    property bool shouldSolvePuzzle
    property string helpText
    property alias musicSource: playMusicId.musicSource
    property alias shouldPlayMusic: playMusicId.shouldPlayMusic

    objectName: "PolyformsPage"
    width: windowWidth

    Component.onCompleted: {
        setToolbarTitle(title)
        shouldPlayMusic = GameController.shouldPlayMusic()
    }

    Component.onDestruction: {
        playMusicId.stop()
        clearPoints()
    }

    onStateChanged: {
        if (state === Constants.stateNewPuzzle)
            selectPuzzle()
    }

    onShouldSolvePuzzleChanged: {
        if (solutionModelId.model === null)
            return
        for (var i = 0; i < solutionModelId.count; i++) {
            solutionModelId.itemAt(
                        i).x = xPositionDeltaProblem + GamePuzzlePieces[i].xPosition
            solutionModelId.itemAt(
                        i).y = yPositionDeltaProblem + GamePuzzlePieces[i].yPosition
        }
        shouldSolvePuzzle = false
    }

    Rectangle {
        width: parent.width
        height: parent.height

        color: Material.accent

        SplitView {

            id: splitViewid
            anchors.fill: parent
            anchors.margins: mediumPadding
            orientation: isPortraitMode ? Qt.Vertical : Qt.Horizontal
            z: 1
            handleDelegate: Rectangle {
                id: splitViewDivideid
                width: mediumPadding
                height: mediumPadding
                color: Material.accent
            }
            // Problem Window Pane
            Rectangle {
                id: problemId

                property var problemPaneWidth: isPortraitMode ? polyformsPageId.width : polyformsPageId.width * 0.35
                property var problemPaneHeight: isPortraitMode ? polyformsPageId.height
                                                                 * 0.35 : polyformsPageId.height
                Layout.minimumWidth: isPortraitMode ? parent.width : drawUnit
                Layout.minimumHeight: isPortraitMode ? drawUnit : parent.height

                x: 0
                y: 0
                width: problemPaneWidth
                height: problemPaneHeight
                focus: false
                gradient: backColorProblemId

                SecondsClock {
                    id: problemSecondsClockId
                    z: 2
                    secondsCounter: GameController.getCurrentPuzzleBestScore()
                }

                World {
                    id: problemWorldId
                }

                Repeater {
                    id: problemModelId
                    model: GamePuzzlePieces
                    delegate: Polyform {
                        id: problemDelegateId
                        xPosition: xPositionDeltaProblem + GamePuzzlePieces[index].xPosition
                        yPosition: yPositionDeltaProblem + GamePuzzlePieces[index].yPosition
                        world: problemWorldId
                        piecesIndex: index
                        fixedRotation: true
                    }
                }
                ParticleSystem {
                    id: problemParticleSystemId
                    anchors.fill: parent
                    ImageParticle {
                        id: imageParticleId
                        system: problemParticleSystemId
                        source: "qrc:///particleresources/star.png"
                        color: Material.primary
                        colorVariation: 1.0
                        alpha: 0.1
                    }
                    Emitter {
                        id: emitterId
                        size: Screen.pixelDensity * 16
                        sizeVariation: size
                        velocity: PointDirection {
                            y: 0
                            yVariation: -1 * emitterId.size
                        }
                        x: 0
                        width: parent.width
                        height: parent.height
                    }
                }
            }

            // Solution Window Pane
            Rectangle {
                id: solutionId

                Layout.minimumWidth: drawUnit
                Layout.minimumHeight: drawUnit
                Layout.fillWidth: true
                Layout.fillHeight: true

                x: isPortraitMode ? problemId.x : problemId.x + problemId.width
                y: isPortraitMode ? problemId.y + problemId.height : problemId.y

                width: isPortraitMode ? parent.width : parent.width * 0.6
                height: isPortraitMode ? parent.height * 0.6 : parent.height
                focus: true

                gradient: backColorSolutionId

                SecondsClock {
                    id: solutionSecondsClockId
                    z: 2
                }

                World {
                    id: solutionWorldId
                }

                Body {
                    id: solutionBodyId
                    world: solutionWorldId
                }

                MouseJoint {
                    id: mouseJointId
                    bodyA: solutionBodyId
                    collideConnected: true
                    maxForce: 100
                }

                MouseArea {
                    anchors.fill: parent
                    pressAndHoldInterval: 10
                    onPressed: {
                        if (pressedBodyId != null) {
                            startTimerText()
                            pressedBodyId.bodyType = Body.Dynamic
                            mouseJointId.maxForce = 1000
                            mouseJointId.target = Qt.point(mouseX, mouseY)
                            mouseJointId.bodyB = pressedBodyId
                        }
                    }
                    onPositionChanged: {
                        mouseJointId.target = Qt.point(mouseX, mouseY)
                    }
                    onReleased: {
                        if (pressedBodyId != null) {
                            pressedBodyId.bodyType = Body.Static
                            mouseJointId.maxForce = 10
                            mouseJointId.bodyB = null
                            pressedBodyId = null
                            populatePoints()
                            var isSolved = GameController.isProblemSolved(
                                        problemPositionPoints,
                                        solutionPositionPoints,
                                        problemCenterPoints,
                                        solutonCenterPoints)
                            if (isSolved) {
                                stopTimerText()
                                playMusicId.tryPlaySoundEffect()
                                solutionParticleEmitterId.emitParticles(mouseX,
                                                                        mouseY)
                                setCurrentPuzzleBestScore()
                                selectPuzzle()
                            }
                        }
                    }
                }

                ImageScreenBoundary {
                    width: parent.width
                    height: parent.height
                    physicsWorld: solutionWorldId

                    Repeater {
                        id: solutionModelId
                        model: GamePuzzlePieces
                        delegate: Polyform {
                            id: solutionDelegateId
                            z: 10
                            xPosition: (drawUnit * Math.random(
                                            ) * 4.0) + drawUnit
                            yPosition: (drawUnit * Math.random(
                                            ) * 4.0) + drawUnit
                            world: solutionWorldId
                            piecesIndex: index
                            fixedRotation: true
                            onPolyformSelected: {
                                pressedBodyId = body
                            }
                            Behavior on x {
                                NumberAnimation {
                                    easing.type: Easing.OutElastic
                                    easing.amplitude: 3.0
                                    easing.period: 2.0
                                    duration: Constants.animationDuration
                                }
                            }
                            Behavior on y {
                                NumberAnimation {
                                    easing.type: Easing.OutElastic
                                    easing.amplitude: 3.0
                                    easing.period: 2.0
                                    duration: Constants.animationDuration
                                }
                            }
                        }
                    }
                }
                ParticleEmitter {
                    id: solutionParticleEmitterId
                    parent: solutionId
                    emitStar: true
                }
            }
        }
    }

    Gradient {
        id: backColorProblemId
        GradientStop {
            position: 0.0
            color: Material.primary
        }
        GradientStop {
            position: 0.50
            color: isPortraitMode ? Material.primary : Material.background
        }
        GradientStop {
            position: 1.0
            color: isPortraitMode ? Material.background : Material.accent
        }
    }

    Gradient {
        id: backColorSolutionId
        GradientStop {
            position: 0.0
            color: isPortraitMode ? Material.background : Material.primary
        }
        GradientStop {
            position: 0.50
            color: Material.background
        }
        GradientStop {
            position: 1.0
            color: Material.accent
        }
    }

    Timer {
        id: gamePuzzlePiecesTimerId
        interval: Constants.animationDuration
        running: false
        repeat: false
        onTriggered: {
            clearPoints()
            GameController.nextPuzzle()
            problemModelId.model = GamePuzzlePieces
            solutionModelId.model = GamePuzzlePieces
            problemSecondsClockId.resetClock(
                        GameController.getCurrentPuzzleBestScore())
            solutionSecondsClockId.resetClock(0)
        }
    }

    MusicPlayer {
        id: playMusicId
    }

    function setCurrentPuzzleBestScore() {
        if (solutionSecondsClockId.secondsCounter === 0)
            return
        if (problemSecondsClockId.secondsCounter === 0
                || problemSecondsClockId.secondsCounter > solutionSecondsClockId.secondsCounter)
            GameController.setCurrentPuzzleBestScore(
                        solutionSecondsClockId.secondsCounter)
    }

    function startTimerText() {
        if (!solutionSecondsClockId.timerRunning)
            solutionSecondsClockId.timerRunning = true
    }

    function stopTimerText() {
        if (solutionSecondsClockId.timerRunning)
            solutionSecondsClockId.timerRunning = false
    }

    function selectPuzzle() {
        stopTimerText()
        for (var i = 0; i < solutionModelId.count; i++) {
            problemModelId.itemAt(i).scale = 0.0
            problemModelId.itemAt(i).opacity = 0.0
            problemModelId.itemAt(i).rotation = 360
            solutionModelId.itemAt(i).scale = 0.0
            solutionModelId.itemAt(i).opacity = 0.0
            solutionModelId.itemAt(i).rotation = 360
        }
        gamePuzzlePiecesTimerId.start()
    }

    function populatePoints() {
        if (problemPositionPoints === null) {
            problemPositionPoints = new Array
            problemCenterPoints = new Array
            solutionPositionPoints = new Array
            solutonCenterPoints = new Array
            var i
            for (i = 0; i < solutionModelId.count; i++) {
                problemPositionPoints[i] = Qt.point(problemModelId.itemAt(i).x,
                                                    problemModelId.itemAt(i).y)
                problemCenterPoints[i] = problemModelId.itemAt(
                            i).body.getWorldCenter()
            }
        }
        for (i = 0; i < solutionModelId.count; i++) {
            solutionPositionPoints[i] = Qt.point(solutionModelId.itemAt(i).x,
                                                 solutionModelId.itemAt(i).y)
            solutonCenterPoints[i] = solutionModelId.itemAt(
                        i).body.getWorldCenter()
            //      console.log("x,y = " + (solutionModelId.itemAt(
            //                                i).x - xPositionDeltaProblem) / drawUnit + " , "
            //                  + (solutionModelId.itemAt(
            //                       i).y - yPositionDeltaProblem) / drawUnit)
        }
    }

    function clearPoints() {
        problemModelId.model = null
        solutionModelId.model = null
        problemPositionPoints = null
        solutionPositionPoints = null
        problemCenterPoints = null
        solutonCenterPoints = null
    }
}
