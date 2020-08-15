import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import com.twentysixapps.puzzlepak.constants 1.0
import "Functions.js" as Functions

ApplicationWindow {
    id: rootId

    readonly property bool isMobileDevice: Qt.platform.os === "android"
                                           || Qt.platform.os === "ios"

    property int windowHeight: isMobileDevice ? Screen.desktopAvailableHeight : Screen.desktopAvailableHeight * .4
    property int windowWidth: isMobileDevice ? Screen.width : Screen.width * .4
    property bool isPortraitMode: windowHeight > windowWidth
    property real drawUnit: isPortraitMode ? windowWidth * .09 : windowHeight * .09
    property bool isWindowActive: Qt.application.state === Qt.ApplicationActive
    property int smallPadding: dp(2)
    property int mediumPadding: dp(8)
    property int mediumLargePadding: dp(16)
    property int largePadding: dp(20)
    property int exlargePadding: dp(40)
    readonly property int rectRadius: dp(2)
    readonly property int largeRectRadius: dp(8)
    readonly property int borderWidth: dp(3)
    readonly property int mediumLargeFontPointSize: dp(20)
    readonly property int largeFontPointSize: dp(26)

    objectName: "MainPage"

    visible: true
    width: windowWidth
    maximumWidth: width
    minimumWidth: width
    maximumHeight: height
    minimumHeight: height
    height: windowHeight
    x: 0
    y: 0

    Component.onCompleted: {

        console.log("drawUnit=" + drawUnit + "  pixelDensity="
                    + Screen.pixelDensity + "  rectRadius=" + rectRadius)
        GameController.setDrawUnit(drawUnit)
        title = GameController.applicationTitle()
    }

    onIsWindowActiveChanged: {
        if (stackViewId.currentItem.shouldPlayMusic === undefined)
            return
        if (Qt.application.state === 2) {
            stackViewId.currentItem.shouldPlayMusic = false
        } else if (Qt.application.state === 4) {
            stackViewId.currentItem.shouldPlayMusic = GameController.shouldPlayMusic()
        }
    }

    header: ToolBar {
        id: headerToolBarId
        implicitHeight: backButtonId.height

        ToolBarButton {
            id: backButtonId
            text: Constants.backChar
            font.bold: true
            anchors.left: parent.left
            anchors.leftMargin: smallPadding
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                if (stackViewId.depth > 1) {
                    stackViewId.pop()
                    setToolbarTitle(GameController.applicationTitle())
                } else
                    Qt.quit()
            }
        }

        Label {
            id: titleLabelId
            text: rootId.title
            anchors.centerIn: text === rootId.title ? parent : undefined
            anchors.left: text === rootId.title ? undefined : backButtonId.right
            anchors.leftMargin: text === rootId.title ? undefined : exlargePadding
            anchors.verticalCenter: text === rootId.title ? undefined : parent.verticalCenter
            wrapMode: Label.NoWrap
            clip: true
            elide: Qt.ElideRight
            SequentialAnimation on opacity {
                id: fadeInAnimationId
                running: false
                loops: 1
                NumberAnimation {
                    from: 0.0
                    to: 1.0
                    duration: Constants.animationDuration
                }
            }
        }

        Loader {
            anchors.right: parent.right
            visible: stackViewId.currentItem.objectName !== "SwitchboardPage"
                     && stackViewId.currentItem.objectName !== "AboutPage"
                     && !isPortraitMode
            sourceComponent: toolbarControlsId
        }
    }

    footer: ToolBar {
        id: footerToolBarId
        height: headerToolBarId.height
        Material.primary: Material.background
        visible: isPortraitMode
                 && stackViewId.currentItem.objectName !== "SwitchboardPage"
                 && stackViewId.currentItem.objectName !== "AboutPage"
        Loader {
            anchors.right: parent.right
            sourceComponent: toolbarControlsId
        }
    }

    StackView {
        id: stackViewId
        anchors.fill: parent
        initialItem: "qrc:/view/qml/SwitchboardPage.qml"
        Rectangle {
            Keys.onBackPressed: {
                event.accepted = true
                Qt.quit()
            }
        }
    }

    Component {
        id: toolbarControlsId

        Row {
            spacing: smallPadding
            rightPadding: mediumPadding
            bottomPadding: Constants.mediumPadding
            onVisibleChanged: {
                toolbarSliderId.to = GameController.puzzlesCount() - 1
            }
            ToolBarButton {
                text: Constants.previousPuzzleChar
                onClicked: {
                    GameController.setSelectedPuzzle(toolbarSliderId.value - 2)
                    stackViewId.currentItem.state = Constants.stateNewPuzzle
                    stackViewId.currentItem.state = Constants.stateUnsolved
                }
            }
            Slider {
                id: toolbarSliderId
                anchors.verticalCenter: parent.verticalCenter
                width: isPortraitMode ? windowWidth * 0.25 : windowWidth * 0.15
                from: 0
                value: 0
                onMoved: {
                    GameController.setSelectedPuzzle(Math.round(value) - 1)
                    stackViewId.currentItem.state = Constants.stateNewPuzzle
                    stackViewId.currentItem.state = Constants.stateUnsolved
                }

                Connections {
                    target: GameController
                    function onGamePuzzleChanged() {
                        var puzzleIndex = GameController.currentPuzzleIndex()
                        if (Math.round(toolbarSliderId.value) !== puzzleIndex) {
                            toolbarSliderId.value = puzzleIndex
                        }
                    }
                }
            }
            ToolBarButton {
                text: Constants.nextPuzzleChar
                onClicked: {
                    stackViewId.currentItem.state = Constants.stateNewPuzzle
                    stackViewId.currentItem.state = Constants.stateUnsolved
                }
            }
            ToolBarButton {
                text: Constants.toggleMusicChar
                onClicked: {
                    GameController.toggleShouldPlayMusic()
                    stackViewId.currentItem.shouldPlayMusic = GameController.shouldPlayMusic()
                }
            }
            ToolBarButton {
                text: Constants.checkChar
                visible: stackViewId.currentItem.objectName !== "ColorFallPage"
                onClicked: {
                    stackViewId.currentItem.shouldSolvePuzzle = true
                }
            }

            ToolBarButton {
                id: reloadPuzzleCharId
                text: Constants.refreshChar
                font.bold: true
                visible: stackViewId.currentItem.objectName === "ColorFallPage"
                onClicked: {
                    GameController.setSelectedPuzzle(toolbarSliderId.value - 1)
                    stackViewId.currentItem.state = Constants.stateNewPuzzle
                    stackViewId.currentItem.state = Constants.stateUnsolved
                }
            }

            ToolBarButton {
                id: questionCharId
                text: Constants.questionChar
                font.bold: true
                onClicked: timedMessageId.showMessage(
                               stackViewId.currentItem.helpText)
            }
        }
    }

    SequentialAnimation {
        id: toolbarFadeInAnimationId
        running: false
        NumberAnimation {
            target: titleLabelId
            property: "opacity"
            from: 0.0
            to: 1.0
            duration: Constants.animationDuration
        }
    }

    TimedMessage {
        id: timedMessageId
    }

    MusicPlayer {
        id: playMusicId
    }

    function setToolbarTitle(titleText) {
        titleLabelId.text = titleText
        toolbarFadeInAnimationId.running = true
    }

    function dp(x) {
        return (Screen.pixelDensity * 25.4 < 120) ? x : x * (Screen.pixelDensity * 25.4 / 160)
    }
}
