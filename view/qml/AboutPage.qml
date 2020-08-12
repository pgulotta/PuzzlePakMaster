import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import Box2DStatic 2.0

import com.twentysixapps.puzzlepak.constants 1.0

Page {
    id: aboutPageId

    property string appNameVersion: GameController.applicationTitle(
                                        ) + " " + GameController.applicationVersion()

    objectName: "AboutPage"
    width: windowWidth

    Flickable {
        anchors.fill: parent
        contentHeight: paneId.implicitHeight
        flickableDirection: Flickable.AutoFlickIfNeeded

        Pane {
            id: paneId
            width: parent.width
            contentItem: Grid {
                id: aboutGridId
                width: parent.width * 0.80
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                    topMargin: largePadding
                    bottomMargin: largePadding
                    leftMargin: mediumPadding
                    rightMargin: largePadding * 3
                }
                columns: 1
                HtmlText {
                    text: qsTr("About ") + appNameVersion + "\n"
                    isTitle: false
                    isBold: true
                }
                HtmlText {
                    websiteLink: "https://sites.google.com/view/26appspuzzlepak"
                    text: appNameVersion + qsTr(
                              " from 26Apps is a fun collection of single player puzzle games. There are over 100 puzzles and more on the way." + " Puzzle Pak is available for mobile devices and desktop computers. For details, please visit <a href=\""
                              + websiteLink + "\"> Puzzle Pak.</a>")
                    isTitle: false
                }
                Rectangle {
                    color: "transparent"
                    height: largePadding
                    width: 1
                    visible: true
                }
                HtmlText {
                    text: qsTr("Feedback")
                    isTitle: true
                }
                HtmlText {
                    websiteLink: "https://play.google.com/store/apps/details?id=com.twentysixapps.puzzlepak"
                    text: qsTr("Leave feedback or rate " + GameController.applicationTitle(
                                   ) + ", " + "please visit <a href=\""
                               + websiteLink + "\"> Google Play</a>")
                    isTitle: false
                }
                Rectangle {
                    color: "transparent"
                    height: largePadding
                    width: 1
                    visible: true
                }
                HtmlText {
                    isTitle: true
                    text: qsTr("Privacy")
                }
                HtmlText {
                    websiteLink: "https://sites.google.com/view/26appspuzzlepak"
                    text: GameController.applicationTitle() + qsTr(
                              " does not request or share any personal information with third parties. "
                              + "It does not request or know the user's physical location. "
                              + "To review the privacy policy, please visit <a href=\""
                              + websiteLink + "\"> Puzzle Pak.</a>")

                    isTitle: false
                }
                Rectangle {
                    color: "transparent"
                    height: largePadding
                    width: 1
                    visible: true
                }
                HtmlText {
                    text: qsTr("Disclaimer")
                    isTitle: true
                }
                HtmlText {
                    websiteLink: "https://sites.google.com/view/26appspuzzlepak"
                    text: GameController.applicationTitle() + qsTr(
                              " provided by 26Apps is supplied 'AS IS' without any warranties and support. "
                              + "For details, please visit <a href=\""
                              + websiteLink + "\"> Puzzle Pak website.</a>")
                    isTitle: false
                }
                Rectangle {
                    color: "transparent"
                    height: largePadding
                    width: 1
                    visible: true
                }
                HtmlText {
                    isTitle: true
                    text: qsTr("Credits")
                }

                HtmlText {
                    websiteLink: "https://www1.qt.io/qt-licensing-terms/"
                    text: GameController.applicationTitle() + qsTr(
                              " is developed under the Qt Company GNU Lesser General Public License v. 3 (“LGPL”) open-source license. For details, please visit, " + "<a href=\""
                              + websiteLink + "\">Qt open source license terms.</a>")
                    isTitle: false
                }
                Text {
                    text: " "
                }
                HtmlText {
                    websiteLink: "https://github.com/erincatto/Box2D/"
                    text: "<a href=\"" + websiteLink + "\">Box2D</a>"
                          + ", a 2D physics engine for games, is used to develop "
                          + GameController.applicationTitle() + "."
                    isTitle: false
                }
                Text {
                    text: " "
                }
                HtmlText {
                    websiteLink: "https://openclipart.org/"
                    text: "<a href=\"" + websiteLink + "\">Openclipart</a>"
                          + " provides some graphics displayed in "
                          + GameController.applicationTitle() + "."
                    isTitle: false
                }
                Text {
                    text: " "
                }

                HtmlText {
                    websiteLink: "https://www.bensound.com/"
                    text: "<a href=\"" + websiteLink + "\">Bensound</a>"
                          + " is used to provide some music used in "
                          + GameController.applicationTitle() + "."
                    isTitle: false
                }
            }
        }

        ScrollIndicator.vertical: ScrollIndicator {}
    }
}
