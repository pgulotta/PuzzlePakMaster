import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls.Material 2.2
import QtQuick.Particles 2.0
import com.twentysixapps.puzzlepak.constants 1.0

ParticleSystem {
  id: particleSystemId

  property bool emitStar: true
  property int particleEmitSize: Screen.pixelDensity * 10

  anchors.fill: parent

  ImageParticle {
    id: imageParticleId
    system: particleSystemId
    source: emitStar ? "qrc:///particleresources/star.png" : "qrc:///particleresources/glowdot.png"
    color: Material.primary
    colorVariation: 1.0
    alpha: 0.1
  }
  Component {
    id: emitterComponentId
    Emitter {
      id: emitterContainerId
      Emitter {
        id: emitMoreId
        system: particleSystemId
        size: particleEmitSize
        velocity: AngleDirection {
          angleVariation: 225
          magnitude: particleEmitSize * 2
          magnitudeVariation: particleEmitSize
        }
        emitRate: 4
        lifeSpan: Constants.animationDuration * 2
      }
      property real targetX: 0
      property real targetY: 0
      function go() {
        xAnimationId.start()
        yAnimationId.start()
        emitterContainerId.enabled = true
      }
      system: particleSystemId
      size: particleEmitSize
      NumberAnimation on x {
        id: xAnimationId
        to: targetX
        duration: Constants.animationDuration
        running: false
      }
      NumberAnimation on y {
        id: yAnimationId
        to: targetY
        duration: Constants.animationDuration
        running: false
      }
      Timer {
        interval: Constants.animationDuration
        running: true
        onTriggered: emitterContainerId.destroy()
      }
    }
  }

  function emitParticles(x, y) {
    for (var i = 0; i < 10; i++) {
      var obj = emitterComponentId.createObject(particleSystemId.parent)
      obj.x = x
      obj.y = y
      obj.targetX = (drawUnit * Math.random() * Screen.pixelDensity) + drawUnit
      obj.targetY = (drawUnit * Math.random() * Screen.pixelDensity) + drawUnit
      obj.go()
    }
  }
}
