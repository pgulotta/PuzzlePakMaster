#pragma once

#include <QString>
#include <QColor>

class Constants
{
public:
  const QColor Pink{"#FF80AB"};
  const QColor Orange{"#FF6D00"};
  const QColor Amber{"#FFBA19"};
  const QColor Brown{"#795548"};
  const QColor Indigo{"#3F51B5"};
  const QColor DeepRed{"#e50000"};
  const QColor Purple{"#7B1FA2"};
  const QString GameLineUp{"LineUp"};
  const QString GameTangrams{"Tangrams"};
  const QString GameTangramsMonochrome{"TangramsMonochrome"};
  const QString GameColorFall{"ColorFall"};
  const QString GameTileSlide{"TileSlide"};
  const QString About{"About"};
  const QString ShouldPlayMusic{"shouldPlayMusic"};
};


/*
RE:  https://www.w3.org/TR/SVG/types.html#ColorKeywords
There are 19 predefined QColor objects:
white, black, red, darkRed, green, darkGreen, blue,
darkBlue, cyan, darkCyan, magenta,
darkMagenta, yellow, darkYellow, gray, darkGray,
lightGray, color0 and color1,
accessible as members of the Qt namespace  */
