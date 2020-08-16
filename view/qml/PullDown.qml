import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

import com.twentysixapps.puzzlepak.constants 1.0

GridLayout {
    columns: 2
    rowSpacing: 0
    anchors {
        left: parent.left
        right: parent.right
        top: parent.top
        leftMargin: mediumPadding
        rightMargin: mediumPadding
    }

    Label {
        text: " :"
        color: Material.accent
        Layout.alignment: Qt.AlignLeft
    }
    Label {
        text: ": "
        color: Material.accent
        Layout.alignment: Qt.AlignRight
    }
    Label {
        text: Constants.vChar
        color: Material.accent
        Layout.alignment: Qt.AlignLeft
    }
    Label {
        text: Constants.vChar
        color: Material.accent
        Layout.alignment: Qt.AlignRight
    }
}
