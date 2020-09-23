#pragma once

#include <QQuickImageProvider>

class QVariant;


class ImageProvider : public QQuickImageProvider
{
public:
  ImageProvider();
  void setWindowSize( int windowWidth, int windowHeight );
  void setImagePath( int columnRowCount, const QString imagePath );
  QImage requestImage( const QString& id, QSize* size, const QSize& requestedSize ) override;
  int puzzlePieceCount(  ) ;
  bool isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const;
  const QImage* getImage() const {return mImage.get();}

  double mDevicePixelRatio;
  int mColumnRowCount;
  QString mImagePath;

  double mImageWidth{0};
  double mImageHeight{0};

  double mImagePieceWidth{0};
  double mImagePieceHeight{0};

  double mPieceXPosition{0};
  double mPieceYPosition{0};

  int mWindowWidth{0};
  int mWindowHeight{0};

private:
  std::unique_ptr<QImage> mImage{new QImage};

};


