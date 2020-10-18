#include "tileslidegame.hpp"
#include "imageprovider.hpp"
#include "tileslidegame.hpp"
#include <QDebug>

int getPuzzleId( int imageIndex, int rowColumn )
{
  return  imageIndex * 10 + rowColumn;
}

TileSlideGame::TileSlideGame( QObject* parent ) : QObject( parent )
{
  for ( int rowColumn = MIN_ROW_COLUMN; rowColumn <= MAX_ROW_COLUMN; ++rowColumn ) {
    for ( int imageIndex = MIN_IMAGE_INDEX; imageIndex <= MAX_IMAGE_INDEX; ++imageIndex ) {
      mPuzzleIdList.push_back( getPuzzleId( imageIndex, rowColumn )  );
    }
  }
}

void TileSlideGame::setWindowSize( int windowWidth, int windowHeight )
{
  mImageProvider->setDimensions( windowWidth, windowHeight );
}

void TileSlideGame::assignImageProviderParms()
{
  if ( mCurrentRowColumnCount < MIN_ROW_COLUMN ) {
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
  }

  if ( mCurrentImageIndex < MIN_IMAGE_INDEX ) {
    mCurrentImageIndex = MIN_IMAGE_INDEX;
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
    return assignImageProviderParms();
  }

  if ( mCurrentImageIndex > MAX_IMAGE_INDEX ) {
    if (  mCurrentRowColumnCount > MAX_ROW_COLUMN ) {
      mCurrentImageIndex = MAX_IMAGE_INDEX;
      mCurrentRowColumnCount = MAX_ROW_COLUMN;
      return assignImageProviderParms();
    } else {
      mCurrentImageIndex = MIN_IMAGE_INDEX;
      ++mCurrentRowColumnCount;
      return assignImageProviderParms();
    }
  }

  if ( mCurrentRowColumnCount > MAX_ROW_COLUMN ) {
    ++mCurrentImageIndex;
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
    return assignImageProviderParms();
  }
}

void TileSlideGame::assignToImageProvider( )
{
  assignImageProviderParms();

  mImageUrl = IMAGE_URL_ROOT + QString::number( mCurrentImageIndex ) + IMAGE_NAME_SUFFIX ;
  mImageFileName = IMAGE_NAME_ROOT + QString::number( mCurrentImageIndex ) + IMAGE_NAME_SUFFIX ;
  mImageProvider->setImagePath( mCurrentRowColumnCount, mImageFileName );
  qDebug() << Q_FUNC_INFO << "mCurrentRowColumnCount=" << mCurrentRowColumnCount << "mImageFileName=" << mImageFileName;
}

void TileSlideGame::selectPuzzle( int puzzleIndex )
{
  // look here
  mCurrentImageIndex = mPuzzleIdList[puzzleIndex] / 10;
  mCurrentRowColumnCount = mPuzzleIdList[puzzleIndex] - mCurrentImageIndex * 10;
  assignToImageProvider();
}

void TileSlideGame::nextPuzzle()
{
  ++mCurrentImageIndex;
  assignToImageProvider();
}

int TileSlideGame::currentPuzzleIndex() const
{
  int imageId = getPuzzleId( mCurrentImageIndex, mCurrentRowColumnCount );
  int puzzleIndex{MIN_IMAGE_INDEX};

  for (  std::vector<int>::size_type index = 0 ; index < mPuzzleIdList.size(); ++index ) {
    if ( mPuzzleIdList[index] == imageId ) {
      puzzleIndex = index;
      break;
    }
  }

  return puzzleIndex;
}
