import QtQuick 2.15
import QtQuick.Window 2.15
import Box2DStatic 2.0

import com.twentysixapps.puzzlepak.constants 1.0

Item {
  id: polygonItemId
  objectName: "PolygonItem"

  signal itemSelected(Body body)

  property string fillColor: "#bfc45ed2"
  property alias vertices: polygonId.vertices
  property alias polygonWidth: polygonItemId.width
  property alias polygonHeight: polygonItemId.height
  property alias body: polygonBody
  property alias fixedRotation: polygonBody.fixedRotation
  property alias world: polygonBody.world

  Canvas {
    id: canvasId
    anchors.fill: parent

    onPaint: {
      var context = canvasId.getContext("2d")
      context.beginPath()
      context.moveTo(vertices[0].x, vertices[0].y)
      for (var i = 0; i < vertices.length; i++) {
        context.lineTo(vertices[i].x, vertices[i].y)
        //  console.log("vertices x & y =" + vertices[i].x + "  " + vertices[i].y)
      }
      context.fillStyle = fillColor
      context.fill()
    }
  }
  Body {
    id: polygonBody
    target: polygonItemId
    gravityScale: Constants.gravityScale
    Polygon {
      id: polygonId
      density: Constants.density
      friction: Constants.friction
      restitution: Constants.restitution
    }
  }
  MouseArea {
    anchors.fill: parent
    // propagateComposedEvents: true
    onPressed: {
      mouse.accepted = false
      if (canvasId.getContext("2d").isPointInPath(mouseX, mouseY)) {
        polygonItemId.itemSelected(polygonBody)
      }
    }
  }
}
