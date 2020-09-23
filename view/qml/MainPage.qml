import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.12
import com.twentysixapps.puzzlepak.constants 1.0

ApplicationWindow {
    id: rootId

    readonly property bool isMobileDevice: Qt.platform.os === "android"
                                           || Qt.platform.os === "ios"

    property int windowHeight: isMobileDevice ? Screen.desktopAvailableHeight : Screen.desktopAvailableHeight * .8
    property int windowWidth: isMobileDevice ? Screen.width : Screen.width * .45
    property bool isPortraitMode: windowHeight > windowWidth
    property real drawUnit: isPortraitMode ? windowWidth * .03 : windowHeight * .08
    property real imageDimension: isPortraitMode ? windowHeight * 0.2 : windowWidth * 0.16
    property bool isWindowActive: Qt.application.state === Qt.ApplicationActive

    property real startXPath: windowWidth * 0.5
    property real startYPath: windowHeight * 0.8
    property real controlXFirst: windowWidth * 0.9
    property real controlYFirst: windowHeight * 0.4
    property real controlXLast: windowWidth * -0.1
    property real controlYLast: windowHeight * 0.4

    property int smallPadding: dp(2)
    property int mediumPadding: dp(8)
    property int mediumLargePadding: dp(16)
    property int largePadding: dp(20)
    property int exlargePadding: dp(40)
    readonly property int rectRadius: dp(2)
    readonly property int largeRectRadius: dp(4)
    readonly property int borderWidth: dp(3)
    readonly property int mediumLargeFontPointSize: dp(20)
    readonly property int largeFontPointSize: dp(26)
    readonly property int dialogSize: dp(220)

    property alias currentPage: stackViewId.currentItem

    objectName: "MainPage"

    visible: true
    width: windowWidth
    height: windowHeight
    x: 0
    y: 0

    Component.onCompleted: {
        GameController.setDrawUnit(drawUnit)
        title = GameController.applicationTitle()
    }

    onClosing: {
        var item = stackViewId.pop()
        while (item !== null) {
            item = stackViewId.pop()
        }
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

    onWidthChanged: calculateDependents()
    onHeightChanged: calculateDependents()

    header: ToolBar {
        id: headerToolBarId
        implicitHeight: backButtonId.height

        ToolButton {
            id: backButtonId
            text: Constants.backChar
            font.bold: true
            font.pointSize: mediumLargeFontPointSize
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
            ToolButton {
                text: Constants.previousPuzzleChar
                font.bold: true
                font.pointSize: mediumLargeFontPointSize
                anchors.verticalCenter: parent.verticalCenter
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
            ToolButton {
                text: Constants.nextPuzzleChar
                font.bold: true
                font.pointSize: mediumLargeFontPointSize
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    stackViewId.currentItem.state = Constants.stateNewPuzzle
                    stackViewId.currentItem.state = Constants.stateUnsolved
                }
            }
            ToolButton {
                text: Constants.toggleMusicChar
                font.bold: true
                font.pointSize: mediumLargeFontPointSize
                anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    GameController.toggleShouldPlayMusic()
                    stackViewId.currentItem.shouldPlayMusic = GameController.shouldPlayMusic()
                }
            }
            ToolButton {
                text: Constants.checkChar
                visible: stackViewId.currentItem.objectName !== "ColorFallPage"
                         && stackViewId.currentItem.objectName !== "TileSlidePage"
                font.bold: true
                font.pointSize: mediumLargeFontPointSize
                anchors.verticalCenter: parent.verticalCenter
                onClicked: stackViewId.currentItem.shouldSolvePuzzle = true
            }

            ToolButton {
                id: reloadPuzzleCharId
                text: Constants.refreshChar
                font.bold: true
                font.pointSize: mediumLargeFontPointSize
                anchors.verticalCenter: parent.verticalCenter
                visible: stackViewId.currentItem.objectName === "ColorFallPage"
                onClicked: {
                    GameController.setSelectedPuzzle(toolbarSliderId.value - 1)
                    stackViewId.currentItem.state = Constants.stateNewPuzzle
                    stackViewId.currentItem.state = Constants.stateUnsolved
                }
            }

            ToolButton {
                id: questionCharId
                text: Constants.questionChar
                font.bold: true
                font.pointSize: mediumLargeFontPointSize
                anchors.verticalCenter: parent.verticalCenter
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

    function calculateDependents() {
        console.log("calculateDependents: windowWidth=" + windowWidth
                    + "  windowHeight" + windowHeight)
        if (windowWidth === 0 || windowHeight === 0)
            return
        windowWidth = width
        windowHeight = height
        isPortraitMode = windowHeight > windowWidth
        drawUnit = isPortraitMode ? windowWidth * .09 : windowHeight * .09
        imageDimension = isPortraitMode ? windowHeight * 0.2 : windowWidth * 0.16
        startXPath = windowWidth * 0.5
        startYPath = windowHeight * 0.8
        controlXFirst = windowWidth * 0.9
        controlYFirst = windowHeight * 0.4
        controlXLast = windowWidth * -0.1
        controlYLast = windowHeight * 0.4
        GameController.setWindowSize(windowWidth, windowHeight)
    }
}
