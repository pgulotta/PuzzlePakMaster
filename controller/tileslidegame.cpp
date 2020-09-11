#include "tileslidegame.hpp"
#include "imageprovider.hpp"
#include "tileslidegame.hpp"
#include <QDebug>

//  eg.: ImageProvider mImageProvider{4, ":/images/tile9.jpg"};

TileSlideGame::TileSlideGame( QObject* parent ) : QObject( parent )
{
}

QString TileSlideGame::getNextImageFileName( )
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

void TileSlideGame::selectPuzzle( int previousPuzzleIndex )
{

}

void TileSlideGame::nextPuzzle()
{

}

int TileSlideGame::currentPuzzleIndex() const
{
  return mCurrentImageIndex;
}

int TileSlideGame::puzzlesCount() const
{
  return 0;
}

