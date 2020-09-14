#include "tileslidegame.hpp"
#include "imageprovider.hpp"
#include "tileslidegame.hpp"
#include <QDebug>

//  eg.: ImageProvider mImageProvider{4, ":/images/tile9.jpg"};

TileSlideGame::TileSlideGame( QObject* parent ) : QObject( parent )
{
}

void TileSlideGame::assignToImageProvider( )
{
  //:/view/images/tile0.jpg
  if ( mCurrentImageIndex < MIN_IMAGE_INDEX  || mCurrentImageIndex > MAX_IMAGE_INDEX ) {
    mCurrentImageIndex = MIN_IMAGE_INDEX;
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
  }

  if ( mCurrentRowColumnCount < MIN_ROW_COLUMN || mCurrentRowColumnCount > MAX_ROW_COLUMN ) {
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
  }

  mImageFileName = IMAGE_NAME_ROOT + QString::number( mCurrentImageIndex ) + IMAGE_NAME_SUFFIX ;
  mImageProvider.setImage( mCurrentRowColumnCount, mImageFileName );
}

void TileSlideGame::selectPuzzle( int puzzleIndex )
{
  mCurrentImageIndex = mCurrentImageIndex / 10;
  mCurrentRowColumnCount = puzzleIndex - mCurrentImageIndex;
  assignToImageProvider();
}

void TileSlideGame::nextPuzzle()
{
  ++mCurrentRowColumnCount;
  assignToImageProvider();
}

int TileSlideGame::currentPuzzleIndex() const
{
  return mCurrentImageIndex * 10 + mCurrentRowColumnCount;
}

int TileSlideGame::puzzlesCount() const
{
  return ( 1 + mCurrentImageIndex ) * MIN_ROW_COLUMN ;
}

void TileSlideGame::generatePuzzle()
{
  assignToImageProvider();
}

