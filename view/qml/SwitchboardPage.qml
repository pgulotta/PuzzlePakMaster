import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.2
import GameMetaDataType 1.0
import com.twentysixapps.puzzlepak.constants 1.0

Page {
    id: switchboardPageId
    objectName: "SwitchboardPage"

    readonly property int imageAnimationDuration: 50
    property bool isInitialized: false

    width: parent.width
    height: parent.height

    Rectangle {
        anchors.fill: parent
        gradient: BackgroundGradient {}
    }

    PathView {
        id: gamesMetaDataId
        model: GamesMetaData
        anchors.fill: parent
        snapMode: PathView.SnapToItem
        path: Path {
            id: gamesMetaDataPathId
            startX: startXPath
            startY: startYPath
            PathAttribute {
                name: "iconScale"
                value: 1.1
            }
            PathQuad {
                x: gamesMetaDataPathId.startX
                y: windowHeight * 0.2
                controlX: controlXFirst
                controlY: controlYFirst
            }
            PathAttribute {
                name: "iconScale"
                value: 0.7
            }
            PathQuad {
                x: gamesMetaDataPathId.startX
                y: gamesMetaDataPathId.startY
                controlX: controlXLast
                controlY: controlYLast
            }
        }
        delegate: Component {
            Rectangle {
                id: switchboardDelegateId
                width: imageDimension
                height: imageDimension
                visible: true
                radius: rectRadius
                color: "transparent"
                scale: PathView.iconScale
                readonly property int animationDeltaX: 3

                SequentialAnimation on x {
                    id: hoverAnimationId
                    running: false
                    loops: 1
                    NumberAnimation {
                        from: x
                        to: x + animationDeltaX
                        duration: imageAnimationDuration
                        easing.type: Easing.Linear
                    }
                    NumberAnimation {
                        from: x + animationDeltaX
                        to: x - animationDeltaX
                        duration: imageAnimationDuration * 2
                        easing.type: Easing.Linear
                    }
                    NumberAnimation {
                        from: x - animationDeltaX
                        to: x
                        duration: imageAnimationDuration
                        easing.type: Easing.Linear
                    }
                }
                Rectangle {
                    id: columnRectId
                    width: imageDimension
                    height: imageDimension
                    color: "transparent"
                    radius: largeRectRadius
                    Column {
                        id: columnDelegateId
                        width: parent.width
                        anchors.fill: parent
                        anchors.topMargin: mediumPadding
                        anchors.bottomMargin: mediumPadding
                        Image {
                            id: selectableImageId
                            source: model.imageSource
                            width: imageDimension * .5
                            height: imageDimension * .5
                            anchors.horizontalCenter: columnDelegateId.horizontalCenter
                        }
                        Label {
                            text: model.title
                            wrapMode: Label.WordWrap
                            width: columnRectId.width
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }
                    MouseArea {
                        width: columnRectId.width
                        height: columnRectId.height
                        hoverEnabled: true
                        onHoveredChanged: {
                            if (containsMouse)
                                hoverAnimationId.running = true
                            columnRectId.color = containsMouse ? Qt.darker(
                                                                     Material.background,
                                                                     1.05) : "transparent"
                        }
                        onClicked: {
                            if (model.moniker === GameController.aboutMoniker(
                                        )) {
                                stackViewId.push("qrc:/view/qml/AboutPage.qml")
                            } else {
                                selectPlayerDialogId.gameMetaData = model
                                selectPlayerDialogId.open()
                            }
                        }
                    }
                }
            }
        }
    }

    SelectPlayerDialog {
        id: selectPlayerDialogId

        property var gameMetaData: null

        anchors.centerIn: parent
        onAccepted: {
            var selectedPlayer = selectPlayerDialogId.getValidPlayerName()
            if (selectedPlayer === null)
                return
            GameController.setLastPlayer(selectedPlayer)
            GameController.setSelectedGame(gameMetaData.moniker, selectedPlayer)
            stackViewId.push([gameMetaData.pageSource, {
                                  "title": gameMetaData.title,
                                  "helpText": gameMetaData.helpText,
                                  "musicSource": gameMetaData.musicSource
                              }])
            if (!isInitialized) {
                GameController.setSelectedGame(gameMetaData.moniker,
                                               selectedPlayer)
                isInitialized = true
            }
        }
    }
}
