#pragma once

#include <QString>


class ImagesFactory
{
public:
  ImagesFactory();
  void selectPuzzle( int previousPuzzleIndex );
  void nextPuzzle();
  int currentPuzzleIndex() const;
  int puzzlesCount() const;

private:
  QString getNextImageFileName( ) ;

  const QString IMAGE_NAME_ROOT {":/view/images/tile"};
  const QString IMAGE_NAME_SUFFIX {".jpg"};
  const int MAX_IMAGE_INDEX{4};
  const int MIN_ROW_COLUMN{ 2 };
  const int MAX_ROW_COLUMN {5};
  int mCurrentImageIndex{-1};
  int mCurrentRowColumnCount{MIN_ROW_COLUMN};

};


