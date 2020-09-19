#pragma once


#include <QObject>
#include "imageprovider.hpp"
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
  ImageProvider* imageProvider() {return mImageProvider.get();}

  void selectPuzzle( int puzzleIndex );

  int currentPuzzleIndex() const;
  int puzzlesCount() const {return PUZZLES_COUNT;}
  void nextPuzzle();

  Q_INVOKABLE int puzzlePieceCount( int windowWidth, int windowHeight )
  {
    qDebug() << Q_FUNC_INFO;
    return mImageProvider->puzzlePieceCount( windowWidth, windowHeight );
  }
  Q_INVOKABLE int imageWidth() const
  {
    qDebug() << Q_FUNC_INFO;
    return mImageProvider->mImageWidth;
  }
  Q_INVOKABLE int imageHeight() const
  {
    qDebug() << Q_FUNC_INFO;
    return mImageProvider->mImageHeight ;
  }
  Q_INVOKABLE int imagePieceWidth() const
  {
    qDebug() << Q_FUNC_INFO;
    return mImageProvider->mImagePieceWidth ;
  }
  Q_INVOKABLE int imagePieceHeight() const
  {
    qDebug() << Q_FUNC_INFO;
    return mImageProvider->mImagePieceHeight;
  }
  Q_INVOKABLE bool isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const { return mImageProvider->isPuzzleSolved( xCoordinatesList, yCoordinatesList );}


private:
  void assignToImageProvider();

  const QString IMAGE_NAME_ROOT {":/view/images/tile"};
  const QString IMAGE_NAME_SUFFIX {".jpg"};
  const int MIN_IMAGE_INDEX{0};
  const int MAX_IMAGE_INDEX{4};
  const int TOTAL_IMAGE_COUNT{MAX_IMAGE_INDEX - MIN_IMAGE_INDEX + 1};  // 5
  const int MIN_ROW_COLUMN{ 2 };
  const int MAX_ROW_COLUMN {5};
  const int TOTAL_ROW_COLUMN_COUNT {MAX_ROW_COLUMN - MIN_ROW_COLUMN + 1};// 4
  const int PUZZLES_COUNT {TOTAL_IMAGE_COUNT * TOTAL_ROW_COLUMN_COUNT};
  int mCurrentImageIndex{MIN_IMAGE_INDEX};
  int mCurrentRowColumnCount{MIN_ROW_COLUMN};
  QString mImageFileName;
  std::shared_ptr<ImageProvider> mImageProvider;
  std::vector<int> mPuzzleIdList;
};

