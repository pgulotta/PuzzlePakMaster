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

void TileSlideGame::assignToImageProvider( )
{
  if (  mCurrentRowColumnCount > MAX_ROW_COLUMN ) {
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
    ++mCurrentImageIndex;
  }

  if ( mCurrentImageIndex < MIN_IMAGE_INDEX ) {
    mCurrentImageIndex = MIN_IMAGE_INDEX;
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
  }

  if ( mCurrentImageIndex > MAX_IMAGE_INDEX ) {
    mCurrentImageIndex = MAX_IMAGE_INDEX;
    mCurrentRowColumnCount = MAX_ROW_COLUMN;
  }

  if ( mCurrentRowColumnCount < MIN_ROW_COLUMN ) {
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
  }

  mImageFileName = IMAGE_NAME_ROOT + QString::number( mCurrentImageIndex ) + IMAGE_NAME_SUFFIX ;
  mImageProvider->setImagePath( mCurrentRowColumnCount, mImageFileName );
  qDebug() << Q_FUNC_INFO << "mCurrentRowColumnCount=" << mCurrentRowColumnCount << "mImageFileName=" << mImageFileName;
}

void TileSlideGame::selectPuzzle( int puzzleIndex )
{
  mCurrentImageIndex = mPuzzleIdList[puzzleIndex] / 10;
  mCurrentRowColumnCount = mPuzzleIdList[puzzleIndex] - mCurrentImageIndex * 10;
  assignToImageProvider();

  //qDebug() << Q_FUNC_INFO << " puzzleIndex=" << puzzleIndex << " mCurrentImageIndex=" << mCurrentImageIndex << " mCurrentRowColumnCount=" << mCurrentRowColumnCount;
}

void TileSlideGame::nextPuzzle()
{
  qDebug() << Q_FUNC_INFO;
  ++mCurrentImageIndex;
  assignToImageProvider();
}

int TileSlideGame::currentPuzzleIndex() const
{
  qDebug() << Q_FUNC_INFO;
  int imageId =  getPuzzleId( mCurrentImageIndex, mCurrentRowColumnCount );
  int puzzleIndex{0};

  for (  std::vector<int>::size_type index = 0 ; index < mPuzzleIdList.size(); ++index ) {
    if ( mPuzzleIdList[index] == imageId ) {
      puzzleIndex = index;
      break;
    }
  }

  //qDebug() << Q_FUNC_INFO << " puzzleIndex=" << puzzleIndex << " mCurrentImageIndex=" << mCurrentImageIndex << " mCurrentRowColumnCount=" << mCurrentRowColumnCount;
  return puzzleIndex;
}


