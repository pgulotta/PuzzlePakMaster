#include "tileslidegamefactory.hpp"
#include "imageprovider.hpp"
#include "tileslidegame.hpp"
#include <QDebug>

//  eg.: ImageProvider mImageProvider{4, ":/images/tile9.jpg"};

TileSlideGameFactory::TileSlideGameFactory( QObject* parent ) : QObject( parent )
{
}

QString TileSlideGameFactory::getNextImageFileName( )
{
  //:/view/images/tile0.jpg
  if ( !( mCurrentRowColumnCount == MAX_ROW_COLUMN && mCurrentImageIndex == MAX_IMAGE_INDEX ) ) {
    if ( ++mCurrentImageIndex > MAX_IMAGE_INDEX ) {
      mCurrentImageIndex = 0;
      ++mCurrentRowColumnCount;
    }
  }

  return IMAGE_NAME_ROOT + QString::number( mCurrentImageIndex ) + IMAGE_NAME_SUFFIX ;
}

void TileSlideGameFactory::selectPuzzle( int previousPuzzleIndex )
{

}

void TileSlideGameFactory::nextPuzzle()
{

}

int TileSlideGameFactory::currentPuzzleIndex() const
{
  return mCurrentImageIndex;
}

int TileSlideGameFactory::puzzlesCount() const
{
  return 0;
}
