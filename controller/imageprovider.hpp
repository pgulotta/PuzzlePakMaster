#pragma once

#include <QQuickImageProvider>
#include <memory>
class QVariant;


class ImageProvider : public QQuickImageProvider
{
public:
  ImageProvider( int columnRowCount, const QString imagePath );
  QImage requestImage( const QString& id, QSize* size, const QSize& requestedSize ) override;

  int puzzlePieceCount( int windowWidth, int windowHeight ) ;

  int imageWidth() const { return mImageWidth ;}
  int imageHeight() const { return mImageHeight;}

  int imagePieceWidth() const { return mImagePieceWidth ;}
  int imagePieceHeight() const { return mImagePieceHeight;}

  bool isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const;


private:
  double mDevicePixelRatio;
  const int mColumnRowCount;
  const QString mImagePath;


  QImage mImage;

  double mImageWidth{0};
  double mImageHeight{0};

  double mImagePieceWidth{0};
  double mImagePieceHeight{0};

  double mPieceXPosition{0};
  double mPieceYPosition{0};



};


