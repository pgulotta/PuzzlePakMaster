import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import com.twentysixapps.puzzlepak.constants 1.0

Label {
  id: timerTextId

  property alias timerRunning: counterTimerId.running

  property int secondsCounter: 0
  property int resetClockSeconds: 0

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
        timerTextId.x = exlargePadding
        timerTextId.y = mediumPadding
        timerTextId.secondsCounter = resetClockSeconds
      }
    }
  }
  onSecondsCounterChanged: timerTextId.text = Functions.secondsToHms(
                             secondsCounter)

  Timer {
    id: counterTimerId
    running: false
    repeat: true
    interval: 1000
    onTriggered: secondsCounter += 1
  }

  function resetClock(seconds) {
    xAnimationId.running = true
    timerTextId.resetClockSeconds = seconds
  }

  function leftZeroPad(number) {
      var s = "00" + number
      return s.substr(s.length - 2)
  }

  function secondsToHms(seconds) {
      if (seconds === undefined || seconds === 0) {
          return ""
      } else {
          var h = Math.floor(seconds / 3600)
          var m = Math.floor(seconds % 3600 / 60)
          var s = Math.floor(seconds % 3600 % 60)

          return leftZeroPad(h) + ":" + leftZeroPad(m) + ":" + leftZeroPad(s)
      }
  }

}
