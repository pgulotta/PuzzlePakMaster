#include "imagesfactory.hpp"
#include <QString>

//  eg.: ImageProvider mImageProvider{4, ":/images/tile9.jpg"};
const QString IMAGE_NAME_ROOT {":/view/images/tile"};
const QString IMAGE_NAME_SUFFIX {".jpg"};


QString getNextImageFileName( int index )
{

  //  mCurrentRowColumnCount
}

ImagesFactory::ImagesFactory()
{

}

void ImagesFactory::selectPuzzle( int previousPuzzleIndex )
{

}

void ImagesFactory::nextPuzzle()
{

}

int ImagesFactory::currentPuzzleIndex() const
{
  return mCurrentPuzzleIndex;
}

int ImagesFactory::puzzlesCount() const
{
  return 0;
}
