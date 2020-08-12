import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

import com.twentysixapps.puzzlepak.constants 1.0

ColumnLayout {
  visible: !isPortraitMode
  anchors {
    left: parent.left
    top: parent.top
    bottom: parent.bottom
  }
  Label {
    text: Constants.rightChar
    color: Material.accent
    font.pointSize: largeFontPointSize
    Layout.alignment: Qt.AlignTop
  }
  Label {
    text: Constants.rightChar
    color: Qt.darker(Material.accent, 1.5)
    font.pointSize: largeFontPointSize
    Layout.alignment: Qt.AlignBottom
  }
}
