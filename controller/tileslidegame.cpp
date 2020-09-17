#include "tileslidegame.hpp"
#include "imageprovider.hpp"
#include "tileslidegame.hpp"
#include <QDebug>

//  eg.: ImageProvider mImageProvider{4, ":/images/tile9.jpg"};

TileSlideGame::TileSlideGame( QObject* parent ) : QObject( parent )
{
  mImageProvider = std::shared_ptr<ImageProvider>( new ImageProvider() );
}

void TileSlideGame::assignToImageProvider( )
{
  double devicePixelRatio = mImageProvider->mDevicePixelRatio;
  int columnRowCount = mImageProvider->mColumnRowCount;
  QString imagePath = mImageProvider->mImagePath;
  QImage image =  mImageProvider->mImage;
  double imageWidth = mImageProvider->mImageWidth;
  double imageHeight = mImageProvider->mImageHeight;
  double imagePieceWidth = mImageProvider->mImagePieceWidth;
  double imagePieceHeight =  mImageProvider->mImagePieceHeight ;
  double mPieceXPosition = mImageProvider->mPieceXPosition;
  double mPieceYPosition = mImageProvider->mPieceYPosition;
  int windowWidth = mImageProvider->mWindowWidth;
  int windowHeight = mImageProvider->mWindowHeight;

  mImageProvider = std::shared_ptr<ImageProvider>( new ImageProvider() );

  mImageProvider->mDevicePixelRatio = devicePixelRatio;
  mImageProvider->mColumnRowCount = columnRowCount ;
  mImageProvider->mImagePath = imagePath ;
  mImageProvider->mImage = image ;
  mImageProvider->mImageWidth = imageWidth;
  mImageProvider->mImageHeight = imageHeight;
  mImageProvider->mImagePieceWidth = imagePieceWidth;
  mImageProvider->mImagePieceHeight = imagePieceHeight;
  mImageProvider->mPieceXPosition = mPieceXPosition;
  mImageProvider->mPieceYPosition = mPieceYPosition ;
  mImageProvider->mWindowWidth = windowWidth;
  mImageProvider->mWindowHeight = windowHeight ;

  //:/view/images/tile0.jpg
  if ( mCurrentImageIndex < MIN_IMAGE_INDEX  || mCurrentImageIndex > MAX_IMAGE_INDEX ) {
    mCurrentImageIndex = MIN_IMAGE_INDEX;
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
  }

  if ( mCurrentRowColumnCount < MIN_ROW_COLUMN || mCurrentRowColumnCount > MAX_ROW_COLUMN ) {
    mCurrentRowColumnCount = MIN_ROW_COLUMN;
  }

  mImageFileName = IMAGE_NAME_ROOT + QString::number( mCurrentImageIndex ) + IMAGE_NAME_SUFFIX ;
  mImageProvider->setImage( mCurrentRowColumnCount, mImageFileName );
  qDebug() << Q_FUNC_INFO << "mCurrentRowColumnCount=" << mCurrentRowColumnCount << "mImageFileName=" << mImageFileName;
}

void TileSlideGame::selectPuzzle( int puzzleIndex )
{
  qDebug() << Q_FUNC_INFO;
  mCurrentImageIndex = mCurrentImageIndex / 10;
  mCurrentRowColumnCount = puzzleIndex - mCurrentImageIndex;
  assignToImageProvider();
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
  return mCurrentImageIndex * 10 + mCurrentRowColumnCount;
}

int TileSlideGame::puzzlesCount() const
{
  qDebug() << Q_FUNC_INFO;
  return ( 1 + mCurrentImageIndex ) * MIN_ROW_COLUMN ;
}

void TileSlideGame::generatePuzzle()
{
  qDebug() << Q_FUNC_INFO;
  assignToImageProvider();
}

