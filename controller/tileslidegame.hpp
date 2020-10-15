#pragma once

#include "imageprovider.hpp"
#include <QObject>
#include <QDebug>
#include <QString>
#include <memory>
#include <vector>

class TileSlideGame: public QObject
{
  Q_OBJECT

private slots:

signals:


public:
  explicit TileSlideGame( QObject* parent = nullptr );

  void selectPuzzle( int puzzleIndex );
  void setWindowSize( int windowWidth, int windowHeight );
  int currentPuzzleIndex() const;
  int puzzlesCount() const {return PUZZLES_COUNT;}
  void nextPuzzle();
  Q_INVOKABLE void assignToImageProvider();

  Q_INVOKABLE QRect imageClipRect( int index ) {    return  mImageProvider->imageClipRect( index ); }

  Q_INVOKABLE QString puzzleImageUrl( ) {return mImageUrl;}

  Q_INVOKABLE int puzzlePieceCount( ) { return mImageProvider->puzzlePieceCount( );}

  Q_INVOKABLE int imageWidth() const {return mImageProvider->mImageWidth; }

  Q_INVOKABLE int imageHeight() const { return mImageProvider->mImageHeight ;}

  Q_INVOKABLE int imagePieceWidth() const { return mImageProvider->mImagePieceWidth ;}

  Q_INVOKABLE int imagePieceHeight() const { return mImageProvider->mImagePieceHeight; }

  Q_INVOKABLE bool isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const
  { return mImageProvider->isPuzzleSolved( xCoordinatesList, yCoordinatesList );}


private:


  const QString IMAGE_URL_ROOT {"qrc:/view/images/tile"};
  const QString IMAGE_NAME_ROOT {":/view/images/tile"};
  const QString IMAGE_NAME_SUFFIX {".jpg"};
  const int MIN_IMAGE_INDEX{0};
  const int MAX_IMAGE_INDEX{4};
  const int TOTAL_IMAGE_COUNT{MAX_IMAGE_INDEX - MIN_IMAGE_INDEX + 1};  // 5
  const int MIN_ROW_COLUMN{2};
  const int MAX_ROW_COLUMN {5};
  const int TOTAL_ROW_COLUMN_COUNT {MAX_ROW_COLUMN - MIN_ROW_COLUMN + 1};// 4
  const int PUZZLES_COUNT {TOTAL_IMAGE_COUNT * TOTAL_ROW_COLUMN_COUNT};
  int mCurrentImageIndex{MIN_IMAGE_INDEX};
  int mCurrentRowColumnCount{MIN_ROW_COLUMN};
  QString mImageUrl;
  QString mImageFileName;
  ImageProvider* mImageProvider { new ImageProvider() };  // qml releases this resource
  std::vector<int> mPuzzleIdList;
  void assignImageProviderParms();
};


