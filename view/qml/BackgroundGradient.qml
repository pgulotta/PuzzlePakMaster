import QtQuick 2.15
import QtQuick.Controls.Material 2.12

Gradient {
    id: backgroundGradientId

    property alias topGradientColor: topGradientColorId.color
    property alias middleGradientColor: middleGradientColorId.color
    property alias bottomGradientColor: bottomGradientColorId.color

    GradientStop {
        id: topGradientColorId
        position: 0.0
        color: Material.primary
    }
    GradientStop {
        id: middleGradientColorId
        position: 0.50
        color: Material.background
    }
    GradientStop {
        id: bottomGradientColorId
        position: 1.0
        color: Material.accent
    }
}
