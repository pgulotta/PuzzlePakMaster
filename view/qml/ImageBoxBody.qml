import QtQuick 2.9
import Box2DStatic 2.0

Image {
  id: image

  property alias body: boxBodyId
  property alias fixture: boxId

  // Body properties
  property alias world: boxBodyId.world
  property alias linearDamping: boxBodyId.linearDamping
  property alias angularDamping: boxBodyId.angularDamping
  property alias bodyType: boxBodyId.bodyType
  property alias bullet: boxBodyId.bullet
  property alias sleepingAllowed: boxBodyId.sleepingAllowed
  property alias fixedRotation: boxBodyId.fixedRotation
  property alias active: boxBodyId.active
  property alias awake: boxBodyId.awake
  property alias linearVelocity: boxBodyId.linearVelocity
  property alias angularVelocity: boxBodyId.angularVelocity
  property alias fixtures: boxBodyId.fixtures
  property alias gravityScale: boxBodyId.gravityScale

  // Box properties
  property alias density: boxId.density
  property alias friction: boxId.friction
  property alias restitution: boxId.restitution
  property alias sensor: boxId.sensor
  property alias categories: boxId.categories
  property alias collidesWith: boxId.collidesWith
  property alias groupIndex: boxId.groupIndex

  signal beginContact(Fixture other)
  signal endContact(Fixture other)

  Body {
    id: boxBodyId
    target: image
    Box {
      id: boxId
      width: image.width
      height: image.height
      onBeginContact: image.beginContact(other)
      onEndContact: image.endContact(other)
    }
  }
}
