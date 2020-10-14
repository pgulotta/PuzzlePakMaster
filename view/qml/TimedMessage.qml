import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12
import com.twentysixapps.puzzlepak.constants 1.0

Item {
    property string message

    Drawer {
        id: drawerId
        width: windowWidth
        height: windowHeight * 0.65
        position: 0.25
        edge: Qt.BottomEdge

        Rectangle {
            anchors.fill: parent
            gradient: BackgroundGradient {
                topGradientColor: Qt.lighter(Material.primary)
                middleGradientColor: Qt.lighter(Material.background)
            }
        }

        Label {
            text: message
            anchors.centerIn: parent
            wrapMode: Label.WordWrap
            width: parent.width * .9
            horizontalAlignment: Text.AlignHCenter
            color: colorForeground
        }
    }

    Timer {
        id: closeMessageDialogTimerId
        repeat: false
        running: false
        onTriggered: drawerId.close()
    }

    function showMessage(textMessage) {
        message = textMessage

        if (message.length < 100)
            closeMessageDialogTimerId.interval = 5000
        else if (message.length < 150)
            closeMessageDialogTimerId.interval = 6000
        else if (message.length < 200)
            closeMessageDialogTimerId.interval = 7000
        else if (message.length < 250)
            closeMessageDialogTimerId.interval = 8000
        else if (message.length < 300)
            closeMessageDialogTimerId.interval = 9000
        else if (message.length < 400)
            closeMessageDialogTimerId.interval = 10000
        else if (message.length < 500)
            closeMessageDialogTimerId.interval = 11000
        else if (message.length < 600)
            closeMessageDialogTimerId.interval = 12000
        else if (message.length < 700)
            closeMessageDialogTimerId.interval = 13000
        else if (message.length < 800)
            closeMessageDialogTimerId.interval = 14000
        else
            closeMessageDialogTimerId.interval = 15000

        drawerId.open()
        closeMessageDialogTimerId.restart()
    }
}
