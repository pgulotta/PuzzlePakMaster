import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12
import com.twentysixapps.puzzlepak.constants 1.0

Row {
    id: roundedButtonsRowId

    signal colorSelected(string selection)

    property string buttonBorderColor
    property alias buttonColors: repeaterId.model
    property string dragTarget
    spacing: smallPadding
    Repeater {
        id: repeaterId
        delegate: RoundedButton {
            anchors.top: parent.top
            anchors.topMargin: smallPadding
            id: roundedButtonId
            color: modelData
            selectedButtonBorderColor: buttonBorderColor
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    for (var i = 0; i < repeaterId.model.length; i++) {
                        repeaterId.itemAt(i).state = Constants.stateDeselected
                    }
                    repeaterId.itemAt(index).state = Constants.stateSelected
                    colorSelected(repeaterId.itemAt(index).color)
                }
            }
        }
    }

    PropertyAnimation {
        target: roundedButtonsRowId
        property: "opacity"
        from: 0.0
        to: 1.0
        duration: Constants.shortAnimationDuration
        running: true
        loops: 1
    }
    PropertyAnimation {
        target: roundedButtonsRowId
        property: "scale"
        from: 0.0
        to: 1.0
        duration: Constants.shortAnimationDuration
        running: true
        loops: 1
    }
    Behavior on opacity {
        NumberAnimation {
            duration: Constants.animationDuration
        }
    }
    Behavior on scale {
        NumberAnimation {
            duration: Constants.animationDuration
        }
    }
}
