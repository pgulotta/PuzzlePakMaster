#include "imageprovider.hpp"
#include <QDebug>
#include <QBuffer>
#include <QScreen>
#include <QGuiApplication>
#include <math.h>


ImageProvider::ImageProvider():
  mDevicePixelRatio ( static_cast<double>( QGuiApplication::primaryScreen()->devicePixelRatio() ) )
{}


void ImageProvider::setImagePath( int columnRowCount, const QString& imagePath  )
{
  mColumnRowCount = columnRowCount;
  mImagePath = imagePath;
  setDimensions( mWindowWidth, mWindowHeight );
}

void ImageProvider::setDimensions( int windowWidth, int windowHeight )
{
  qDebug() << " 2 " <<  Q_FUNC_INFO << "  Window:  " << windowWidth << " x " << windowHeight;
  mWindowWidth = windowWidth;
  mWindowHeight = windowHeight;
  QImage image{mImagePath};

  if ( image.width()*mDevicePixelRatio > windowWidth  ||
       image.height()*mDevicePixelRatio > windowHeight  ) {
    auto widthDimension = std::min( static_cast<double>( windowWidth ), image.width() * mDevicePixelRatio ) ;
    auto heightDimension =   std::min( static_cast<double>( windowHeight ), image.height() * mDevicePixelRatio ) ;
    auto dimension = ( windowWidth > windowHeight ) ? widthDimension : heightDimension ;
    mImage = new QImage(  image.scaled( dimension, dimension, Qt::KeepAspectRatio )  ) ;
  } else {
    qDebug() <<  Q_FUNC_INFO << "Image size NOT adjusted";
    mImage = new QImage( image  ) ;
  }

  mImageWidth = mImage->width();
  mImageHeight =  mImage->height();
  mImagePieceWidth = mColumnRowCount == 0 ? 0 : static_cast<int>( ceil( mImageWidth / mColumnRowCount  /
                                                                        mDevicePixelRatio ) );
  mImagePieceHeight =  mColumnRowCount == 0 ? 0 :  static_cast<int>(  ceil( mImageHeight / mColumnRowCount /
                                                                            mDevicePixelRatio ) );
  mPieceXPosition = 0;
  mPieceYPosition = 0;
}

int ImageProvider::puzzlePieceCount( )
{
  return ceil( mColumnRowCount * mColumnRowCount );
}

bool ImageProvider::isPuzzleSolved( QVariantList xCoordinatesList, QVariantList yCoordinatesList ) const
{
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

QRect ImageProvider::imageClipRect( int index )
{
  int x = mPieceXPosition ;
  int y = mPieceYPosition ;

  mPieceXPosition += ( mImagePieceWidth  );

  if ( mPieceXPosition * mDevicePixelRatio >= mImageWidth ) {
    mPieceXPosition = 0;
    mPieceYPosition += ( mImagePieceHeight  );
  }

  return QRect( x * mDevicePixelRatio, y * mDevicePixelRatio, mImagePieceWidth * mDevicePixelRatio,
                mImagePieceHeight * mDevicePixelRatio  );
}

