import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
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
    font.pointSize: mediumLargeFontPointSize
    font.bold: isBold
    color: Material.accent
    onLinkActivated: {
      if (websiteLink !== "")
        Qt.openUrlExternally(websiteLink)
    }
  }
}
