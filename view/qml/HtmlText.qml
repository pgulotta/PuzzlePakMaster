import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12
import com.twentysixapps.puzzlepak.constants 1.0

RowLayout {
    property string websiteLink: ""
    property bool isTitle: false
    property alias text: textId.text
    property bool isBold: false

    width: parent.width
    Text {
        id: textId
        width: parent.width
        Layout.leftMargin: isTitle ? largePadding : 2 * largePadding
        Layout.fillWidth: true
        Layout.fillHeight: true
        wrapMode: Label.Wrap
        font.underline: isTitle ? true : false
        font.bold: isBold
        color: Material.accent
        onLinkActivated: {
            if (websiteLink !== "")
                Qt.openUrlExternally(websiteLink)
        }
    }
}
