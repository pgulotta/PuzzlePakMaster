#pragma once


#include <QObject>
#include "imageprovider.hpp"


class TileSlideGame final : public QObject
{
  Q_OBJECT
public:
  explicit TileSlideGame( QObject* parent = nullptr );
// ImageProvider* getImageProvider() {return &mImageProvider;}
  Q_INVOKABLE int puzzlePieceCount( int windowWidth, int windowHeight )  {return mImageProvider.puzzlePieceCount( windowWidth, windowHeight ); }
  Q_INVOKABLE int imageWidth() const {return mImageProvider.imageWidth() ;}
  Q_INVOKABLE int imageHeight() const {return mImageProvider.imageHeight() ;}

  Q_INVOKABLE int imagePieceWidth() const { return mImageProvider.imagePieceWidth() ;}
  Q_INVOKABLE int imagePieceHeight() const { return mImageProvider.imagePieceHeight();}

  Q_INVOKABLE bool isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const;

signals:
  void gamePuzzleChanged();



private:
//  ImageProvider mImageProvider{3, ":/images/wallpaper.png"};
// ImageProvider mImageProvider{3, ":/images/testImage.png"};
  ImageProvider mImageProvider{2, ":/images/tile7.jpg"};

};


