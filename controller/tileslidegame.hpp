#pragma once


#include <QObject>
#include "imageprovider.hpp"
#include <QString>
#include <memory>


class TileSlideGame: public QObject
{
  Q_OBJECT

private slots:

signals:


public:
  explicit TileSlideGame( QObject* parent = nullptr );
  ImageProvider* imageProvider() {return &mImageProvider;}

  void selectPuzzle( int puzzleIndex );
  void nextPuzzle();
  int currentPuzzleIndex() const;
  int puzzlesCount() const;
  void generatePuzzle();
  Q_INVOKABLE int puzzlePieceCount( int windowWidth, int windowHeight )  {return mImageProvider.puzzlePieceCount( windowWidth, windowHeight ); }
  Q_INVOKABLE int imageWidth() const {return mImageProvider.imageWidth() ;}
  Q_INVOKABLE int imageHeight() const {return mImageProvider.imageHeight() ;}
  Q_INVOKABLE int imagePieceWidth() const { return mImageProvider.imagePieceWidth() ;}
  Q_INVOKABLE int imagePieceHeight() const { return mImageProvider.imagePieceHeight();}
  Q_INVOKABLE bool isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const { return mImageProvider.isPuzzleSolved( xCoordinatesList, yCoordinatesList );}


private:
  void assignToImageProvider( ) ;

  const QString IMAGE_NAME_ROOT {":/view/images/tile"};
  const QString IMAGE_NAME_SUFFIX {".jpg"};
  const int MIN_IMAGE_INDEX{0};
  const int MAX_IMAGE_INDEX{4};
  const int MIN_ROW_COLUMN{ 2 };
  const int MAX_ROW_COLUMN {5};
  int mCurrentImageIndex{MIN_IMAGE_INDEX};
  int mCurrentRowColumnCount{MIN_ROW_COLUMN};
  QString mImageFileName;
  ImageProvider mImageProvider;
};


