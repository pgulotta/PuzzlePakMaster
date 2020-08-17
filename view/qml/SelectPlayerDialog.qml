import QtQuick 2.15
import QtQuick.Controls 2.15
import com.twentysixapps.puzzlepak.constants 1.0

Dialog {
    id: selectPlayerDialogId

    readonly property string defaultPlayerName: qsTr("Player 1")
    modal: true
    focus: true

    width: dialogSize
    height: dialogSize

    header: Label {
        x: mediumPadding
        y: mediumPadding
        text: qsTr("Select/Enter Player")
    }
    standardButtons: Dialog.Ok | Dialog.Cancel
    contentItem: ComboBox {
        id: playerSelectionId
        editable: true
    }

    onVisibleChanged: {
        if (visible) {
            playerSelectionId.model = GameController.players()
            playerSelectionId.editText = GameController.getLastPlayer()
        }
    }

    enter: Transition {
        // grow_fade_in
        NumberAnimation {
            property: "scale"
            from: 0.9
            to: 1.0
            easing.type: Easing.OutQuint
            duration: 2000
        }
        NumberAnimation {
            property: "opacity"
            from: 0.0
            to: 1.0
            easing.type: Easing.OutCubic
            duration: 2000
        }
    }

    exit: Transition {
        // shrink_fade_out
        NumberAnimation {
            property: "scale"
            from: 1.0
            to: 0.9
            easing.type: Easing.OutQuint
            duration: 2000
        }
        NumberAnimation {
            property: "opacity"
            from: 1.0
            to: 0.0
            easing.type: Easing.OutCubic
            duration: 2000
        }
    }

    function getValidPlayerName() {
        var selectedPlayer = (playerSelectionId.editText === null
                              || playerSelectionId.editText === undefined
                              || playerSelectionId.editText.length
                              === 0) ? defaultPlayerName : playerSelectionId.editText.trim()
        if (selectedPlayer.length === 0)
            selectedPlayer = defaultPlayerName
        playerSelectionId.editText = selectedPlayer
        return selectedPlayer
    }
}
