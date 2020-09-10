#include "tileslidegame.hpp"

#include <QList>

TileSlideGame::TileSlideGame( QObject* parent ) : QObject( parent )
{

}

bool TileSlideGame::isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const
{
  return mImageProvider.isPuzzleSolved ( xCoordinatesList, yCoordinatesList );
}
