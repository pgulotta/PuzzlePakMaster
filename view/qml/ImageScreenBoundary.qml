import QtQuick 2.15
import Box2DStatic 2.0

Item {
    property World physicsWorld
    property int dimension: 1
    x: 0
    y: 0

    Wall {
        height: dimension
        world: physicsWorld
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
    }

    Wall {
        width: dimension
        world: physicsWorld
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }
    }

    Wall {
        width: dimension
        world: physicsWorld
        anchors {
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
    }

    Wall {
        height: dimension
        world: physicsWorld
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }
}
