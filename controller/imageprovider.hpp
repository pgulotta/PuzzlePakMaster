#pragma once

#include <QQuickImageProvider>

class QVariant;


class ImageProvider : public QQuickImageProvider
{
public:
  ImageProvider();
  void setImage( int columnRowCount, const QString imagePath );
  QImage requestImage( const QString& id, QSize* size, const QSize& requestedSize ) override;
  int puzzlePieceCount( int windowWidth, int windowHeight ) ;
  bool isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const;

  double mDevicePixelRatio;
  int mColumnRowCount;
  QString mImagePath;
  QImage mImage;

  double mImageWidth{0};
  double mImageHeight{0};

  double mImagePieceWidth{0};
  double mImagePieceHeight{0};

  double mPieceXPosition{0};
  double mPieceYPosition{0};

  int mWindowWidth{0};
  int mWindowHeight{0};

};


