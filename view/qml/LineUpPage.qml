import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Material 2.2
import QtQuick.Particles 2.0
import QtQuick.Controls 1.4 as ButtonControl
import QtQuick.Controls.Styles 1.4
import com.twentysixapps.puzzlepak.constants 1.0

Page {
    id: lineupPageId

    property bool shouldSolvePuzzle
    property string helpText
    property alias musicSource: playMusicId.musicSource
    property alias shouldPlayMusic: playMusicId.shouldPlayMusic
    readonly property string insufficientCircleMessage: qsTr("Please note: Each bottom row circle needs to be colored. Select the color from the puzzle's top row, then select the bottom row circle to color.")

    objectName: "LineUpPage"
    width: windowWidth
    state: Constants.stateUnsolved

    Component.onCompleted: {
        setToolbarTitle(title)
        shouldPlayMusic = GameController.shouldPlayMusic()
    }

    Component.onDestruction: {
        playMusicId.stop()
    }

    onStateChanged: {
        if (state === Constants.stateNewPuzzle) {
            selectPuzzle()
        }
    }

    onShouldSolvePuzzleChanged: {
        if (shouldSolvePuzzle) {
            state = Constants.stateSolved
            puzzleColorsGridId.state = Constants.stateSolved
            shouldSolvePuzzle = false
        }
    }

    background: Rectangle {
        anchors.fill: parent
        gradient: BackgroundGradient {}
    }

    RowLayout {
        id: scoresRowId
        z: 10
        spacing: 0

        anchors {
            top: parent.top
            left: parent.left
            topMargin: mediumPadding
            leftMargin: largePadding
            rightMargin: largePadding
        }

        PuzzleScore {
            id: bestScoreId
            Layout.alignment: Qt.AlignLeft
            Layout.fillWidth: false
            score: GameController.getCurrentPuzzleBestScore()
        }
        PuzzleScore {
            id: currentScoreId
            Layout.alignment: Qt.AlignRight
            Layout.fillWidth: false
        }
    }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: scoresRowId.top
        anchors.topMargin: isPortraitMode ? largePadding : smallPadding
        spacing: 0
        Rectangle {
            id: topRowRectId
            implicitHeight: topColorsRowId.height
            implicitWidth: topColorsRowId.width
            radius: largeRectRadius
            color: Material.primary
            Layout.alignment: Qt.AlignCenter
            RowLayout {
                id: topColorsRowId
                enabled: lineupPageId.state !== Constants.stateSolved
                Image {
                    source: "qrc:/view/images/palette.png"
                    Layout.preferredWidth: drawUnit
                    Layout.preferredHeight: drawUnit
                }
                RoundedButtonsRow {
                    id: topRoundedButtonsRowId
                    buttonBorderColor: Material.foreground
                    buttonColors: getAvailableColors()
                    onColorSelected: puzzleColorsGridId.roundedButtonColor = selection
                }
                Image {
                    source: "qrc:/view/images/circles.png"
                    Layout.preferredWidth: drawUnit
                    Layout.preferredHeight: drawUnit
                }
            }
        }

        RoundedButtonsGrid {
            id: puzzleColorsGridId
            columnCount: solutionColors.length
            rowCount: 25
            rowsVisible: 1

            solutionColors: GameController.puzzleColors()
            onColorSelected: currentScoreId.score = rowsVisible
            onInvalidSelection: timedMessageId.showMessage(
                                    insufficientCircleMessage)
            onCurrentScoreChanged: currentScoreId.score = currentScore
            onPuzzleSolved: {
                lineupPageId.state = Constants.stateNewPuzzle
                selectPuzzle()
                playMusicId.tryPlaySoundEffect()
                currentScoreId.setLowBestScore(bestScoreId.score)
                particleEmitterId.emitParticles(windowWidth * 0.90,
                                                windowHeight * .90)
            }
        }

        RowLayout {
            id: solutionColorsId
            Layout.alignment: Qt.AlignHCenter
            spacing: 0
            Rectangle {
                implicitHeight: solutionColorsRowId.height + largePadding
                implicitWidth: solutionColorsRowId.width + largePadding
                radius: largeRectRadius
                color: Material.background
                opacity: lineupPageId.state === Constants.stateSolved ? 1.0 : 0.0
                RoundedButtonsRow {
                    id: solutionColorsRowId
                    buttonColors: puzzleColorsGridId.solutionColors
                    buttonBorderColor: Material.accent
                    enabled: false
                    anchors.centerIn: parent
                }
                Behavior on opacity {
                    OpacityAnimator {
                        duration: Constants.animationDuration
                    }
                }
            }
        }
    }

    Timer {
        id: puzzleTimerId
        interval: Constants.animationDuration
        running: false
        repeat: false
        onTriggered: {
            GameController.nextPuzzle()
            puzzleColorsGridId.state = lineupPageId.state
            puzzleColorsGridId.solutionColors = GameController.puzzleColors()
            topRoundedButtonsRowId.buttonColors = getAvailableColors()
            puzzleColorsGridId.columnCount = 0
            puzzleColorsGridId.columnCount = puzzleColorsGridId.solutionColors.length
            puzzleColorsGridId.rowCount = 0
            puzzleColorsGridId.rowCount = 25
            puzzleColorsGridId.rowsVisible = 0
            puzzleColorsGridId.rowsVisible = 1
            puzzleColorsGridId.roundedButtonColor = "transparent"
            topRoundedButtonsRowId.opacity = 1.0
            topRoundedButtonsRowId.scale = 1.0
            puzzleColorsGridId.opacity = 1.0
            puzzleColorsGridId.scale = 1.0
            bestScoreId.resetCounter(GameController.getCurrentPuzzleBestScore())
            currentScoreId.resetCounter(0)
        }
    }
    MusicPlayer {
        id: playMusicId
    }

    ParticleEmitter {
        id: particleEmitterId
        parent: lineupPageId
        emitStar: false
    }

    function selectPuzzle() {
        topRoundedButtonsRowId.opacity = 0.0
        topRoundedButtonsRowId.scale = 0.0
        puzzleColorsGridId.opacity = 0.0
        puzzleColorsGridId.scale = 0.0
        puzzleTimerId.start()
    }

    function getAvailableColors() {
        var arr = new Array
        for (var i = 0; i < puzzleColorsGridId.solutionColors.length; i++) {
            arr[i] = puzzleColorsGridId.solutionColors[i]
        }
        return shuffle(arr)
    }

    function shuffle(array) {
        var currentIndex = array.length, temporaryValue, randomIndex

        while (0 !== currentIndex) {
            randomIndex = Math.floor(Math.random() * currentIndex)
            currentIndex -= 1
            temporaryValue = array[currentIndex]
            array[currentIndex] = array[randomIndex]
            array[randomIndex] = temporaryValue
        }
        return array
    }
}
