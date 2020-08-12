import QtQuick 2.9

import com.twentysixapps.puzzlepak.constants 1.0

ImageBoxBody {
    id: imageBoxBodyId

    source: "qrc:/view/images/border.jpg"
    fillMode: Image.Tile
    opacity: 0.0
    friction: Constants.friction
    density: Constants.density
}
