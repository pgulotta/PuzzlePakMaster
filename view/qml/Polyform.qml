import QtQuick 2.0
import Box2DStatic 2.0

import com.twentysixapps.puzzlepak.constants 1.0

PolygonItem {
    id: polyformId

    signal polyformSelected(int index, Body body)

    property real xPosition
    property real yPosition

    property int zOrder
    property alias world: polyformId.world
    property alias fixedRotation: polyformId.fixedRotation
    property int piecesIndex: 0

    objectName: "Polyform"
    x: xPosition
    y: yPosition
    z: zOrder
    rotation: GamePuzzlePieces[piecesIndex].rotation
    fillColor: GamePuzzlePieces[piecesIndex].fillColor
    vertices: GamePuzzlePieces[piecesIndex].vertices
    width: GamePuzzlePieces[piecesIndex].polygonWidth
    height: GamePuzzlePieces[piecesIndex].polygonHeight

    onItemSelected: {
        polyformSelected(index, body)
    }

    PropertyAnimation {
        target: polyformId
        property: "opacity"
        from: 0.0
        to: 1.0
        duration: Constants.animationDuration
        running: true
        loops: 1
    }
    PropertyAnimation {
        target: polyformId
        property: "scale"
        from: 0.0
        to: 1.0
        duration: Constants.animationDuration
        running: true
        loops: 1
    }
    PropertyAnimation {
        target: polyformId
        property: "rotation"
        from: 360
        to: GamePuzzlePieces[index].rotation
        duration: Constants.animationDuration
        running: true
        loops: 1
    }
    Behavior on opacity {
        NumberAnimation {
            duration: Constants.animationDuration
        }
    }
    Behavior on scale {
        NumberAnimation {
            duration: Constants.animationDuration
        }
    }
    Behavior on rotation {
        RotationAnimation {
            direction: RotationAnimation.Clockwise
            duration: Constants.animationDuration
        }
    }
}
