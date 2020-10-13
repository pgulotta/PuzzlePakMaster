#pragma once
#include <QVariantList>
#include <QImage>

class QVariant;


class ImageProvider
{
public:
  ImageProvider();
  void setDimensions( int windowWidth, int windowHeight );
  void setImagePath( int columnRowCount, const QString& imagePath );
  QImage requestImage( const QString& id, QSize* size, const QSize& requestedSize ) ;
  int puzzlePieceCount(  ) ;
  bool isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const;
  const QImage* getImage() const {return mImage;}

  double mDevicePixelRatio;
  int mColumnRowCount{0};
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
  QImage* mImage{new QImage};

};


