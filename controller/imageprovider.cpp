#include "imageprovider.hpp"
#include <QBuffer>
#include <QScreen>
#include <QGuiApplication>
#include <math.h>


ImageProvider::ImageProvider():
  QQuickImageProvider( QQuickImageProvider::Image ),
  mDevicePixelRatio ( static_cast<double>( QGuiApplication::primaryScreen()->devicePixelRatio() ) )
{}


void ImageProvider::setImagePath( int columnRowCount, const QString imagePath  )
{
  mColumnRowCount = columnRowCount;
  mImagePath = imagePath;
  puzzlePieceCount( mWindowWidth, mWindowHeight );
  qDebug() << " 1 " << Q_FUNC_INFO << "mDevicePixelRatio=" << mDevicePixelRatio << " mColumnRowCount=" << mColumnRowCount
           << " mImagePath=" << mImagePath;
}

int ImageProvider::puzzlePieceCount( int windowWidth, int windowHeight )
{
  qDebug() << " 2 " <<  Q_FUNC_INFO;
  mWindowWidth = windowWidth;
  mWindowHeight = windowHeight;
  QImage image{mImagePath};

  if ( image.width()*mDevicePixelRatio > windowWidth  ||
       image.height()*mDevicePixelRatio > windowHeight  ) {
    auto widthDimension = std::min( static_cast<double>( windowWidth ), image.width() * mDevicePixelRatio ) ;
    auto heightDimension =   std::min( static_cast<double>( windowHeight ), image.height() * mDevicePixelRatio ) ;
    auto dimension = ( windowWidth > windowHeight ) ? widthDimension : heightDimension ;
    mImage = std::make_unique<QImage>(  image.scaled( dimension, dimension, Qt::KeepAspectRatio ) ) ;
  } else {
    qDebug() <<  Q_FUNC_INFO << "Image size NOT adjusted";
    mImage = std::make_unique<QImage>( image  ) ;
  }

  mImageWidth = mImage->width();
  mImageHeight =  mImage->height();
  mImagePieceWidth = mColumnRowCount == 0 ? 0 : static_cast<int>( ceil( mImageWidth / mColumnRowCount  /
                                                                        mDevicePixelRatio ) );
  mImagePieceHeight =  mColumnRowCount == 0 ? 0 :  static_cast<int>(  ceil( mImageHeight / mColumnRowCount /
                                                                            mDevicePixelRatio ) );
  qDebug() << Q_FUNC_INFO << "Image path:  " << mImagePath << "  mImage.sizeInBytes=" << mImage->sizeInBytes() ;
//  qDebug() << Q_FUNC_INFO << "Window:  " << windowWidth << " x " << windowHeight;
//  qDebug() << Q_FUNC_INFO << "Image:  " << mImageWidth << " x " << mImageHeight;
//  qDebug() << Q_FUNC_INFO << "Piece:  " << mImagePieceWidth << " x " << mImagePieceHeight;

  return ceil( mColumnRowCount * mColumnRowCount );
  //return 0;
}

bool ImageProvider::isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const
{
  qDebug() << Q_FUNC_INFO << "Image:  " << mImageWidth << " x " << mImageHeight;
  auto xCoordinatesListCount = xCoordinatesList.count();

  if ( xCoordinatesListCount == 0 ) {
    return false;
  }

  auto yCoordinatesListCount = yCoordinatesList.count();

  if ( yCoordinatesListCount == 0 ) {
    return false;
  }

  if ( xCoordinatesListCount != yCoordinatesListCount ) {
    return false;
  }

  static const int errThreshold = 8;
  int xPrior = -1;
  int yPrior = -1;
  int xCurrent = -1;
  int yCurrent = -1;
  int modulus = -1;

  for ( int index = 0; index < yCoordinatesListCount ; ++index ) {

    xCurrent = xCoordinatesList[index].toInt();
    yCurrent = yCoordinatesList[index].toInt();
    modulus =  index % mColumnRowCount ;

    if ( index > 0 ) {

      if ( modulus == 0 ) {
        if ( yCurrent - yPrior - errThreshold > mImagePieceHeight ) {
          return false;
        } else {
          if ( xCurrent - xPrior > errThreshold ) {
            return false;
          }
        }
      } else {
        if ( xCurrent - xPrior - errThreshold > mImagePieceWidth ) {
          return false;
        } else {
          if ( yCurrent - yPrior > errThreshold ) {
            return false;
          }
        }
      }
    }

//  qDebug() <<  " xCurrent=" << xCurrent << "  yCurrent=" << yCurrent  << " xPrior=" << xPrior  <<"  yPrior=" << yPrior  << "  index" << index << "  modulus" << modulus ;

    xPrior = xCurrent;
    yPrior = yCurrent;

  }

  return true;
}

QImage ImageProvider::requestImage( const QString& id, QSize* size, const QSize& requestedSize )
{
  Q_UNUSED( size );
  Q_UNUSED( requestedSize );

  qDebug() << Q_FUNC_INFO << " 3  id=" <<  id.toInt();

  if ( id.isEmpty() ) {
    mPieceXPosition = 0;
    mPieceYPosition = 0;
    QImage* image = new QImage( mImage->copy( mPieceXPosition, mPieceYPosition, mImageWidth,
                                              mImageHeight  ) );
    qDebug() << " 3 FULL Image  ************  " << image->sizeInBytes();
    return *image;
  } else {
    int x = mPieceXPosition ;
    int y = mPieceYPosition ;

    mPieceXPosition += ( mImagePieceWidth  );

    if ( mPieceXPosition * mDevicePixelRatio >= mImageWidth ) {
      mPieceXPosition = 0;
      mPieceYPosition += ( mImagePieceHeight  );
    }

    //qDebug() << " 3 " << Q_FUNC_INFO  << " x=" << x  << "  y=" << y << "  " << mImagePieceWidth << " x " << mImagePieceHeight;

    QImage* image = new QImage(
      mImage->copy( x * mDevicePixelRatio, y * mDevicePixelRatio, mImagePieceWidth * mDevicePixelRatio,
                    mImagePieceHeight * mDevicePixelRatio ) );
    qDebug() << " 3 partial image" << image->sizeInBytes();
    return *image;
  }
}

