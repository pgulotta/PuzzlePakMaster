import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Particles 2.0
import QtQuick.Controls.Material 2.2
import com.twentysixapps.puzzlepak.constants 1.0

Page {
  id: colorFallPageId

  property bool shouldSolvePuzzle
  property string helpText
  property alias musicSource: playMusicId.musicSource
  property alias shouldPlayMusic: playMusicId.shouldPlayMusic
  property int columnCount: isPortraitMode ? 8 : 0
  property int rowCount: isPortraitMode ? 0 : 8
  property var gridModel

  objectName: "ColorFallPage"
  width: windowWidth
  state: Constants.stateUnsolved

  onGridModelChanged: {
    if (isPortraitMode) {
      if (rowCount === 0) {
        rowCount = Math.floor(gridModel.length / columnCount)
      }
    } else {
      if (columnCount === 0) {
        columnCount = Math.floor(gridModel.length / rowCount)
      }
    }
    backgroundColorId.color = Qt.darker(GameController.puzzleColors()[0], 1.75)
  }

  Rectangle {
    id: backgroundColorId
    anchors.fill: parent
    Behavior on color {
      ColorAnimation {
        duration: Constants.animationDuration
      }
    }
  }

  Component.onCompleted: {
    setToolbarTitle(title)
    shouldPlayMusic = GameController.shouldPlayMusic()
    gridModel = GameController.puzzleColors()
    for (var j = 0; j < gridModel.length; j++) {
      repeaterId.itemAt(j).rotation = 180
      repeaterId.itemAt(j).scale = 1.0
    }
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
    state = Constants.stateSolved
    puzzleColorsGridId.state = Constants.stateSolved
    shouldSolvePuzzle = false
  }

  RowLayout {
    anchors {
      top: parent.top
      left: parent.left
      right: parent.right
    }
    width: parent.width
    PuzzleScore {
      id: bestScoreId
      z: 2
      Layout.alignment: Qt.AlignLeft
      Layout.fillWidth: false
      Layout.margins: mediumPadding
      score: GameController.getCurrentPuzzleBestScore()
    }
    PuzzleScore {
      id: currentScoreId
      z: 2
      Layout.alignment: Qt.AlignRight
      Layout.fillWidth: false
      Layout.margins: largePadding
    }
  }

  Grid {
    id: puzzleColorsGridId
    anchors.centerIn: parent
    rows: rowCount
    Repeater {
      id: repeaterId
      model: gridModel
      onModelChanged: {
        if (rowCount > 0
            && puzzleColorsGridId.state === Constants.stateSolved) {
          for (var j = 0; j < gridModel.length; j++) {
            if (repeaterId.itemAt(j) !== null) {
              repeaterId.itemAt(j).rotation = 0
              repeaterId.itemAt(j).scale = 0.0
            }
          }
        }
      }
      delegate: Rectangle {
        id: rectangleId
        scale: rowCount > 0 ? 1.0 : 0.0
        color: modelData
        border.width: 1
        border.color: Material.accent
        width: isPortraitMode ? drawUnit : drawUnit * 1.2
        height: isPortraitMode ? drawUnit * 1.2 : drawUnit * 0.9
        radius: rectRadius
        enabled: color !== "#00000000"
        gradient: Gradient {
          GradientStop {
            color: Qt.lighter(modelData, 1.5)
            position: 0.0
          }
          GradientStop {
            color: modelData
            position: 0.5
          }
          GradientStop {
            color: Qt.darker(modelData, 1.5)
            position: 1.0
          }
        }
        Behavior on rotation {
          RotationAnimation {
            direction: RotationAnimation.Clockwise
            duration: Constants.animationDuration
            easing.type: Easing.InOutBack
          }
        }
        Behavior on scale {
          NumberAnimation {
            duration: Constants.animationDuration
            easing.type: Easing.InOutBack
          }
        }
        Behavior on opacity {
          NumberAnimation {
            duration: Constants.animationDuration
          }
        }
        MouseArea {
          anchors.fill: parent
          hoverEnabled: true
          onHoveredChanged: rectangleId.opacity = containsMouse ? 0.4 : 1.0
          onClicked: {
            if (!isSelectionValid(modelData))
              return

            var length = gridModel.length
            var colCount = length / rowCount
            var colorsList = new Array
            for (var i = 0; i < length; i++) {
              colorsList[i] = repeaterId.itemAt(i).color
            }

            var indexColors = GameController.findColorGroupIndexes(index,
                                                                   colCount,
                                                                   colorsList)
            currentScoreId.score += Math.pow(indexColors.length - 1, 2)
            var grid = GameController.getUpdatedFillColors(colCount,
                                                           indexColors,
                                                           colorsList)
            if (grid.length === 0) {
              puzzleColorsGridId.state = Constants.stateNewPuzzle
              selectPuzzle()
              playMusicId.tryPlaySoundEffect()
              currentScoreId.setHighBestScore(bestScoreId.score)
            } else {
              gridModel = grid
            }
          }
        }
      }
    }
  }

  MusicPlayer {
    id: playMusicId
  }

  Timer {
    id: puzzleTimerId
    interval: Constants.animationDuration
    running: false
    repeat: false
    onTriggered: {
      GameController.nextPuzzle()
      puzzleColorsGridId.state = colorFallPageId.state
      columnCount = isPortraitMode ? 8 : 0
      rowCount = isPortraitMode ? 0 : 8
      gridModel = GameController.puzzleColors()
      for (var j = 0; j < gridModel.length; j++) {
        if (repeaterId.itemAt(j) !== null) {
          repeaterId.itemAt(j).rotation = 360
          repeaterId.itemAt(j).scale = 1.0
          repeaterId.itemAt(j).opacity = 1.0
        }
      }
      bestScoreId.resetCounter(GameController.getCurrentPuzzleBestScore())
      currentScoreId.resetCounter(0)
    }
  }

  function selectPuzzle() {
    for (var j = 0; j < gridModel.length; j++) {
      if (repeaterId.itemAt(j) !== null) {
        repeaterId.itemAt(j).opacity = 0.0
        repeaterId.itemAt(j).scale = 0.0
        repeaterId.itemAt(j).opacity = 0.0
      }
    }
    puzzleTimerId.start()
  }

  function isSelectionValid(modelData) {
    return (modelData === "#00000000") ? false : true
  }
}
