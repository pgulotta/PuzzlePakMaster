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
  void selectPuzzle( int previousPuzzleIndex );
  void nextPuzzle();
  int currentPuzzleIndex() const;
  int puzzlesCount() const;
  Q_INVOKABLE int puzzlePieceCount( int windowWidth, int windowHeight )  {return mImageProvider.puzzlePieceCount( windowWidth, windowHeight ); }
  Q_INVOKABLE int imageWidth() const {return mImageProvider.imageWidth() ;}
  Q_INVOKABLE int imageHeight() const {return mImageProvider.imageHeight() ;}
  Q_INVOKABLE int imagePieceWidth() const { return mImageProvider.imagePieceWidth() ;}
  Q_INVOKABLE int imagePieceHeight() const { return mImageProvider.imagePieceHeight();}
  Q_INVOKABLE bool isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const { return mImageProvider.isPuzzleSolved( xCoordinatesList, yCoordinatesList );}


private:
  QString getNextImageFileName( ) ;

  const QString IMAGE_NAME_ROOT {":/view/images/tile"};
  const QString IMAGE_NAME_SUFFIX {".jpg"};
  const int MAX_IMAGE_INDEX{4};
  const int MIN_ROW_COLUMN{ 2 };
  const int MAX_ROW_COLUMN {5};
  int mCurrentImageIndex{-1};
  int mCurrentRowColumnCount{MIN_ROW_COLUMN};

  ImageProvider mImageProvider;
};


