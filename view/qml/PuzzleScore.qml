import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

import com.twentysixapps.puzzlepak.constants 1.0

Label {
  id: puzzleScoreId

  property int score: 0
  property int resetScore: 0

  x: exlargePadding
  y: mediumPadding
  color: Material.accent
  text: ""

  SequentialAnimation on x {
    id: xAnimationId
    running: false
    loops: 1
    NumberAnimation {
      from: exlargePadding
      to: parent.width
      duration: Constants.animationDuration
    }
    ScriptAction {
      script: {
        puzzleScoreId.x = exlargePadding
        puzzleScoreId.y = mediumPadding
        puzzleScoreId.score = resetScore
      }
    }
  }

  onScoreChanged: puzzleScoreId.text = score < 1 ? "" : score

  function resetCounter(score) {
    xAnimationId.running = true
    puzzleScoreId.resetScore = score
  }

  function setHighBestScore(bestScore) {
    if (score === 0)
      return
    if (bestScore === 0 || bestScore < score)
      GameController.setCurrentPuzzleBestScore(score)
  }

  function setLowBestScore(bestScore) {
    if (score === 0)
      return
    if (bestScore === 0 || bestScore > score)
      GameController.setCurrentPuzzleBestScore(score)
  }
}
