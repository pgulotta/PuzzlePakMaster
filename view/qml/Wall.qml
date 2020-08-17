import QtQuick 2.15

import com.twentysixapps.puzzlepak.constants 1.0

ImageBoxBody {
    id: imageBoxBodyId

    source: "qrc:/view/images/border.jpg"
    fillMode: Image.Tile
    opacity: 0.0
    friction: Constants.friction
    density: Constants.density
}
