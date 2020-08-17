import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12
import com.twentysixapps.puzzlepak.constants 1.0

Item {
    property var buttonColor
    property bool isVisible: true
    property string selectedButtonBorderColor: Material.accent
    property alias color: roundedButtonId.color
    property alias buttonBorder: roundedButtonId.border

    state: Constants.stateDeselected
    width: drawUnit + mediumPadding
    height: drawUnit + mediumPadding

    states: [
        State {
            name: Constants.stateSelected
            PropertyChanges {
                target: roundedButtonTextId
                opacity: 1
            }
            PropertyChanges {
                target: roundedButtonId
                border.color: Material.accent
            }
        },
        State {
            name: Constants.stateDeselected
            PropertyChanges {
                target: roundedButtonTextId
                opacity: 0
            }
            PropertyChanges {
                target: roundedButtonId
                border.color: selectedButtonBorderColor
            }
        }
    ]

    Rectangle {
        id: roundedButtonId
        width: drawUnit
        height: drawUnit
        radius: drawUnit / 2
        border.width: borderWidth
        border.color: Material.accent
        color: "transparent"
        visible: isVisible
        Text {
            id: roundedButtonTextId
            text: Constants.starChar
            anchors.centerIn: parent
        }
    }
    PropertyAnimation {
        id: colorAnimationId
        target: roundedButtonId
        property: "color"
        to: buttonColor
        duration: Constants.animationDuration
    }

    function setButtonColor(color) {
        buttonColor = color
        colorAnimationId.running = true
    }
}
