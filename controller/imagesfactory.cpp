#include "imagesfactory.hpp"
#include <QDebug>

//  eg.: ImageProvider mImageProvider{4, ":/images/tile9.jpg"};


QString ImagesFactory::getNextImageFileName( )
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

ImagesFactory::ImagesFactory()
{
//  for ( int i = 0 ; i < 30; ++i ) {
//    qDebug() << Q_FUNC_INFO << getNextImageFileName() << "  mCurrentRowColumnCount=" << mCurrentRowColumnCount;
//  }
}

void ImagesFactory::selectPuzzle( int previousPuzzleIndex )
{

}

void ImagesFactory::nextPuzzle()
{

}

int ImagesFactory::currentPuzzleIndex() const
{
  return mCurrentImageIndex;
}

int ImagesFactory::puzzlesCount() const
{
  return 0;
}
