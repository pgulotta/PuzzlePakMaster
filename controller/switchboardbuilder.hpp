#pragma once

#include <QObject>
#include "model/gamemetadata.hpp"
#include "model/constants.hpp"


const QString TangramHelpText{QObject::tr( "The Tangram puzzle is a tiling puzzle where a set of different colored pieces can be assembled in different ways to form distinct geometric shapes. "
                                             "The tangram consists of seven flat pieces, called tans, which are put together to form different shapes. "
                                             "The objective of this game is to form the specified shape using all seven tans. The tans cannot overlap. "
                                             "Display the solution by selecting the toolbar check button." )};

const QString OneColorTangramHelpText{QObject::tr( "The 1-Color Tangram puzzle is a tiling puzzle where a set of same colored pieces can be assembled in different ways to form distinct geometric shapes. "
                                                     "The tangram consists of seven flat shapes, called tans, which are put together to form the shapes. "
                                                     "The objective of this game is to form the specified shape using all seven tans. The tans cannot overlap. "
                                                     "Display the solution by selecting the toolbar check button." )};


const QString ColorFallHelpText{QObject::tr( "The Color Fall game objective is to remove all the colored blocks from the playing field. "
                                               "By selecting a group of adjoining blocks of the same color, the blocks are removed from the playing field. "
                                               "Blocks that are no longer supported by the removed blocks will fall down, and a column without any blocks will be trimmed "
                                               "away by sliding together with the other remaining columns. Clear the grid by selecting a groups of adjoining blocks of the same color." )};

const QString LineUpHelpText{QObject::tr( "The Line Up game objective is to find a predetermined sequence of colors. Chose a color by selecting the colored circle from the game board's top row. "
                                            "Then select one or more circle(s) in the last row.  Repeat until all circles in the last row are colored. "
                                            "Check your prediction by selecting the bottom row's check button. If correct, the next puzzle is presented, else the row's correct colored circles count is shown on the left and "
                                            "color and position count is displayed on the right. Display the solution by selecting the toolbar check button." )};
const QString TileSlideHelpText{QObject::tr( "The Tangram puzzle is a tiling puzzle where a set of different colored pieces can be assembled in different ways to form distinct geometric shapes. "
                                               "The tangram consists of seven flat pieces, called tans, which are put together to form different shapes. "
                                               "The objective of this game is to form the specified shape using all seven tans. The tans cannot overlap. "
                                               "Display the solution by selecting the toolbar check button." )};


class SwitchboardBuilder final : public QObject
{
  Q_OBJECT

signals:

public:
  SwitchboardBuilder()
  {
    build();
  }

  const QList<QObject*>& gamesMetaData() const
  {
    return mGameMetaData;
  }

private:
  QList<QObject*> mGameMetaData;

  void build()
  {
    Constants constants;
    mGameMetaData.append( new GameMetaData{
      constants.GameTangramsMonochrome, tr( "1-Color Tangrams" ),
      "qrc:/view/images/tangram-monochrome.png",
      "qrc:/view/qml/PolyformsPage.qml",
      "qrc:/view/music/bensound-theduel.mp3", OneColorTangramHelpText,
      parent()} );
    mGameMetaData.append( new GameMetaData{constants.ColorFall, tr( "Color Fall" ),
                                           "qrc:/view/images/color-fall.png",
                                           "qrc:/view/qml/ColorFallPage.qml",
                                           "qrc:/view/music/bensound-theduel.mp3", ColorFallHelpText,
                                           parent()} );
    mGameMetaData.append( new GameMetaData{constants.GameLineUp, tr( "Line Up" ),
                                           "qrc:/view/images/line-up.png",
                                           "qrc:/view/qml/LineUpPage.qml",
                                           "qrc:/view/music/bensound-theduel.mp3", LineUpHelpText,
                                           parent()} );
    mGameMetaData.append( new GameMetaData{constants.GameTangrams, tr( "Tangrams" ),
                                           "qrc:/view/images/tangram.png",
                                           "qrc:/view/qml/PolyformsPage.qml",
                                           "qrc:/view/music/bensound-theduel.mp3", TangramHelpText,
                                           parent()} );

    mGameMetaData.append( new GameMetaData{constants.TileSlide, tr( "Tile Slide" ),
                                           "qrc:/view/images/tile-slide.png",
                                           "qrc:/view/qml/TileSlidePage.qml",
                                           "qrc:/view/music/bensound-theduel.mp3", TileSlideHelpText,
                                           parent()} );
    mGameMetaData.append( new GameMetaData{constants.About, tr( "About" ),
                                           "qrc:/view/images/about.png",
                                           "qrc:/view/qml/AboutPage.qml",
                                           "", "", parent()} );
  }
};

