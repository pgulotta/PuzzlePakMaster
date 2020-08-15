import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 1.4 as ButtonControl
import QtQuick.Controls.Styles 1.4
import com.twentysixapps.puzzlepak.constants 1.0
import "Functions.js" as Functions

Pane {
    id: roundedButtonsGridId

    signal colorSelected
    signal invalidSelection
    signal currentScoreChanged(int currentScore)
    signal puzzleSolved

    readonly property real flickVelocity: -1 * windowHeight
    property int columnCount
    property int rowCount
    property int rowsVisible
    property string roundedButtonColor: "transparent"
    property var solutionColors
    property var solutionColorsList
    property var proposedColorsList

    clip: true
    Material.background: "transparent"
    contentHeight: isPortraitMode ? windowHeight * 0.5 : windowHeight * 0.4
    contentWidth: parent.width
    onSolutionColorsChanged: {
        solutionColorsList = new Array
        proposedColorsList = new Array
        if (!(solutionColors === null || solutionColors === undefined)) {
            for (var i = 0; i < solutionColors.length; i++) {
                solutionColorsList[i] = solutionColors[i]
                proposedColorsList[i] = "transparent"
            }
        }
    }

    onRowsVisibleChanged: {
        for (var i = 0; i < solutionColors.length; i++) {
            proposedColorsList[i] = "transparent"
        }
    }

    contentData: Rectangle {
        id: rectangleId
        width: roundedButtonsGridId.width
        height: roundedButtonsGridId.height
        color: "transparent"
        Flickable {
            id: flickableId
            anchors.fill: parent
            contentHeight: columnId.height
            flickableDirection: Flickable.AutoFlickIfNeeded
            clip: false
            ScrollBar.vertical: ScrollBar {
                active: true

                onActiveChanged: {
                    if (!active)
                        active = true
                }
            }

            Column {
                id: columnId
                Repeater {
                    id: columnRepeaterId
                    model: rowCount
                    delegate: Row {
                        id: userInputRowId
                        bottomPadding: smallPadding
                        visible: index < rowsVisible
                        enabled: !(index < rowsVisible - 1
                                   || state === Constants.stateSolved)
                        Rectangle {
                            width: drawUnit
                            height: drawUnit
                            color: "transparent"
                        }
                        RowLayout {
                            id: userSelectionRowId
                            Repeater {
                                id: rowRepeaterId
                                model: columnCount

                                delegate: RoundedButton {
                                    id: roundedButtonId
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            if (roundedButtonsGridId.state
                                                    === Constants.stateSolved)
                                                return
                                            colorSelected()
                                            rowRepeaterId.itemAt(
                                                        index).setButtonColor(
                                                        roundedButtonColor)
                                            for (var i = 0; i < solutionColors.length; i++) {
                                                proposedColorsList[i] = rowRepeaterId.itemAt(
                                                            i).buttonColor
                                            }
                                            colorsAndPositionsMatchedId.text
                                                    = calculateColorPositionsMatched(
                                                        proposedColorsList,
                                                        solutionColorsList)
                                        }
                                    }
                                }
                            }

                            ButtonControl.Button {
                                id: validateId
                                visible: index === rowsVisible - 1
                                Layout.preferredWidth: drawUnit + smallPadding
                                Layout.preferredHeight: drawUnit + smallPadding

                                style: ButtonStyle {
                                    label: Image {
                                        source: "qrc:/view/images/validate.png"
                                        fillMode: Image.PreserveAspectFit
                                    }
                                    background: Rectangle {
                                        radius: validateId.width / 2
                                        border.width: rectRadius
                                        border.color: Material.accent
                                        color: validateId.hovered ? (validateId.pressed ? Material.foreground : Material.background) : Material.primary
                                    }
                                }
                                onClicked: {
                                    if (state === Constants.stateSolved)
                                        return
                                    if (isSelectionValid()) {
                                        currentScoreChanged(
                                                    puzzleColorsGridId.rowsVisible)
                                        if (isPuzzleSolved()) {
                                            puzzleSolved()
                                        } else {
                                            rowsVisible++
                                            flickableId.flick(0, flickVelocity)
                                        }
                                    } else {
                                        invalidSelection()
                                    }
                                }
                            }
                        }
                        Rectangle {
                            id: colorsAndPositionsMatchedRectId
                            width: drawUnit
                            height: drawUnit
                            color: "transparent"
                            opacity: index < rowsVisible - 1
                                     || roundedButtonsGridId.state
                                     === Constants.stateSolved ? 1.0 : 0.0
                            Label {
                                id: colorsAndPositionsMatchedId
                                color: Material.accent
                                font.pointSize: mediumLargeFontPointSize
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }
        }
    }
    PropertyAnimation {
        target: roundedButtonsGridId
        property: "opacity"
        from: 0.0
        to: 1.0
        duration: Constants.shortAnimationDuration
        running: true
        loops: 1
    }
    PropertyAnimation {
        target: roundedButtonsGridId
        property: "scale"
        from: 0.0
        to: 1.0
        duration: Constants.shortAnimationDuration
        running: true
        loops: 1
    }
    Behavior on opacity {
        NumberAnimation {
            duration: Constants.shortAnimationDuration
        }
    }
    Behavior on scale {
        NumberAnimation {
            duration: Constants.shortAnimationDuration
        }
    }
    function calculateColorPositionsMatched() {
        if (proposedColorsList.length !== solutionColorsList.length)
            return 0
        var counter = 0
        for (var i = 0; i < solutionColorsList.length; i++) {
            if (proposedColorsList[i] !== undefined) {
                if (Qt.colorEqual(proposedColorsList[i], solutionColorsList[i]))
                    ++counter
            }
        }
        return counter
    }

    function calculateColorsMatched() {
        var colorsMatched = 0
        var uniqueSolutions = Functions.removeDuplicates(solutionColorsList)
        var proposedColorsMatchedCount = 0
        var solutionColorsMatchedCount = 0
        var length = solutionColorsList.length
        for (var i = 0; i < uniqueSolutions.length; i++) {
            var colorToMatch = uniqueSolutions[i]
            proposedColorsMatchedCount = 0
            for (var j = 0; j < length; ++j) {
                if (proposedColorsList[j] !== undefined) {
                    if (Qt.colorEqual(proposedColorsList[j], colorToMatch))
                        ++proposedColorsMatchedCount
                }
            }
            solutionColorsMatchedCount = 0
            for (var k = 0; k < length; ++k) {
                if (Qt.colorEqual(colorToMatch, solutionColorsList[k]))
                    ++solutionColorsMatchedCount
            }
            colorsMatched += Math.min(proposedColorsMatchedCount,
                                      solutionColorsMatchedCount)
        }
        return colorsMatched
    }

    function isSelectionValid() {
        var isNotValid = false
        for (var i = 0; i < puzzleColorsGridId.solutionColorsList.length; i++) {
            isNotValid = puzzleColorsGridId.proposedColorsList[i] === undefined
                    || puzzleColorsGridId.proposedColorsList[i] === "transparent"
                    || puzzleColorsGridId.proposedColorsList[i] === ""
            if (isNotValid)
                break
        }
        return !isNotValid
    }

    function isPuzzleSolved() {
        if (proposedColorsList.length !== solutionColorsList.length)
            return false
        var result = true
        for (var i = 0; result && i < solutionColorsList.length; i++) {
            result = Qt.colorEqual(proposedColorsList[i], solutionColorsList[i])
        }
        roundedButtonsGridId.state = result ? Constants.stateSolved : Constants.stateUnsolved
        return result
    }
}
