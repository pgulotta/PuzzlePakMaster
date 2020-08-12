import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

import com.twentysixapps.puzzlepak.constants 1.0

RowLayout {
  visible: isPortraitMode
  anchors {
    left: parent.left
    right: parent.right
    top: parent.top
    leftMargin: mediumPadding
    rightMargin: mediumPadding
  }
  Label {
    text: Constants.downChar
    color: Material.accent
    font.pointSize: largeFontPointSize
    Layout.alignment: Qt.AlignLeft
  }
  Label {
    text: Constants.downChar
    color: Material.accent
    font.pointSize: largeFontPointSize
    Layout.alignment: Qt.AlignRight
  }
}
