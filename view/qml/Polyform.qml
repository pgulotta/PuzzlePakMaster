import QtQuick 2.15
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
    rotation: TangramPuzzlePieces[piecesIndex].rotation
    fillColor: TangramPuzzlePieces[piecesIndex].fillColor
    vertices: TangramPuzzlePieces[piecesIndex].vertices
    width: TangramPuzzlePieces[piecesIndex].width
    height: TangramPuzzlePieces[piecesIndex].height

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
        to: TangramPuzzlePieces[index].rotation
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
