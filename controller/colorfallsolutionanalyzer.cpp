#include "colorfallsolutionanalyzer.hpp"
#include <cmath>
#include <QDebug>
#include <algorithm>


QString colorTransparent{"#00000000"};

ColorFallSolutionAnalyzer::ColorFallSolutionAnalyzer( QObject* parent ) : QObject( parent )
{

}

void ColorFallSolutionAnalyzer::findColorGroupIndexes( int index, int indexRow, int indexColumn,
                                                       const  QList<QColor>&  grid )
{
  int checkRow{indexRow};
  int checkCol{0};
  int checkIndex{0};

  bool lookForMatch{true};

  while ( lookForMatch ) {
    checkRow = checkRow - 1;

    if ( checkRow > -1 ) {
      checkIndex = checkRow * mColumnCount + indexColumn;

      if ( grid[checkIndex] == mGroupColor ) {
        if ( mIndexColors.contains( checkIndex ) ) {
          lookForMatch = false;
        } else {
          mIndexColors.append( checkIndex );
          findColorGroupIndexes( checkIndex, checkRow, indexColumn, grid );
        }
      } else {
        lookForMatch = false;
      }
    } else {
      lookForMatch = false;
    }
  }

  checkRow = indexRow;
  lookForMatch = true;

  while ( lookForMatch ) {
    checkRow = checkRow + 1;

    if ( checkRow < mRowCount ) {
      checkIndex = checkRow * mColumnCount + indexColumn;

      if ( grid[checkIndex] == mGroupColor ) {
        if ( mIndexColors.contains( checkIndex ) ) {
          lookForMatch = false;
        } else {
          mIndexColors.append( checkIndex );
          findColorGroupIndexes( checkIndex, checkRow, indexColumn, grid );
        }
      } else {
        lookForMatch = false;
      }
    } else {
      lookForMatch = false;
    }
  }

  checkCol = indexColumn;
  lookForMatch = true;
  checkIndex = index;

  while ( lookForMatch ) {
    checkCol = checkCol - 1;

    if ( checkCol > -1 ) {
      checkIndex = checkIndex - 1;

      if ( grid[checkIndex] == mGroupColor ) {
        if ( mIndexColors.contains( checkIndex ) ) {
          lookForMatch = false;
        } else {
          mIndexColors.append( checkIndex );
          findColorGroupIndexes( checkIndex, indexRow, checkCol, grid );
        }
      } else {
        lookForMatch = false;
      }
    } else {
      lookForMatch = false;
    }
  }

  checkCol = indexColumn;
  lookForMatch = true;
  checkIndex = index;

  while ( lookForMatch ) {
    checkCol = checkCol + 1;

    if ( checkCol < mColumnCount ) {
      checkIndex = checkIndex + 1;

      if ( grid[checkIndex] == mGroupColor ) {
        if ( mIndexColors.contains( checkIndex ) ) {
          lookForMatch = false;
        } else {
          mIndexColors.append( checkIndex );
          findColorGroupIndexes( checkIndex, indexRow, checkCol, grid );
        }
      } else {
        lookForMatch = false;
      }
    } else {
      lookForMatch = false;
    }
  }

  std::sort( mIndexColors.begin(), mIndexColors.end(), std::greater<int>() );
}


QList<int> ColorFallSolutionAnalyzer::findColorGroupIndexes( int index, int columnCount, QVariantList grid )
{
  mIndexColors.clear();
  mIndexColors.append( index );

  int gridCount = grid.length();

  if ( gridCount == 0 ||  columnCount == 0 ) {
    return mIndexColors;
  }

  QList<QColor> gridColors;
  convert( grid, gridColors );

  mColumnCount = columnCount;
  mRowCount = gridCount / mColumnCount;
  mGroupColor = grid[index].value<QColor>();

  int indexRow =  static_cast<int>( floor( index / mColumnCount ) );
  int indexColumn{index % mColumnCount};
  findColorGroupIndexes( index, indexRow, indexColumn, gridColors );
  return mIndexColors;
}

void ColorFallSolutionAnalyzer::convert( const QVariantList& source,  QList<QColor>& destination )
{
  destination.clear();

  for ( int i = 0 ; i < source.count() ; i++ ) {
    destination.append( source[i].value<QColor>() );
  }
}

void ColorFallSolutionAnalyzer::setFillColor( int index, QString color )
{
  if ( mFillColors[index] != colorTransparent ) {
    mFillColors[index] = color;
  }
}

int ColorFallSolutionAnalyzer::populateFillColor( int currentIndex, int columnCount,  QList<int>& indexColors )
{
  if ( currentIndex > 0 ) {
    int  previousIndex = currentIndex - columnCount;
    int savedCurrentIndex = currentIndex;

    while ( previousIndex > -1 ) {
      savedCurrentIndex = currentIndex;

      if ( indexColors.contains( previousIndex ) ) {
        indexColors.erase( std::find( indexColors.begin(), indexColors.end(), previousIndex ) );
        currentIndex = populateFillColor( previousIndex, columnCount, indexColors );
        setFillColor( savedCurrentIndex, mFillColors[previousIndex] );
        previousIndex = savedCurrentIndex - columnCount;
      } else {
        setFillColor( currentIndex, mFillColors[previousIndex] );
        currentIndex = previousIndex;
        previousIndex = currentIndex - columnCount;
      }
    }
  }

  setFillColor( currentIndex, colorTransparent );
  return currentIndex;
}

QStringList ColorFallSolutionAnalyzer::getUpdatedFillColors( int  columnCount,  QList<int> indexColors,
                                                             QStringList colors )
{
  mFillColors.clear();

  foreach ( auto color, colors ) {
    mFillColors.append( color );
  }

  for ( int columnIndex = 0; columnIndex < columnCount ; ++columnIndex ) {
    auto citCurrent =  std::find_if( indexColors.cbegin(), indexColors.cend(),
    [columnCount, columnIndex]( const int x ) {
      return x % columnCount  == columnIndex;
    } );

    if ( citCurrent != indexColors.cend() ) {
      int currentIndex = *citCurrent ;
      currentIndex =  populateFillColor( currentIndex, columnCount, indexColors );
    }
  }

  removeMissingColumns();
  return mFillColors;
}

void ColorFallSolutionAnalyzer::removeMissingColumns()
{

  QList<int> transparentColors;

  for ( int colorsIndex = 0; colorsIndex < mFillColors.count(); ++colorsIndex ) {
    if ( mFillColors[colorsIndex] == colorTransparent ) {
      transparentColors.append( colorsIndex );
    }
  }

  if ( transparentColors.count() > 0 ) {
    QList<int> fillColorsToRemove;
    QList<int> columnTransparentIndexes;

    for ( int columnIndex = 0; columnIndex < mColumnCount; ++columnIndex ) {
      columnTransparentIndexes.clear();

      foreach ( auto transparentColorsIndex, transparentColors ) {
        auto isTransparent = transparentColorsIndex % mColumnCount == columnIndex;

        if ( isTransparent ) {
          columnTransparentIndexes.append( transparentColorsIndex );
        }
      }

      if ( columnTransparentIndexes.count() == mRowCount ) {
        foreach ( int transparentColorIndex, columnTransparentIndexes ) {
          fillColorsToRemove.append( transparentColorIndex );
        }
      }
    }

    if ( fillColorsToRemove.count() > 0 ) {
      std::sort( fillColorsToRemove.begin(), fillColorsToRemove.end(), std::greater<int>() );

      for ( auto cit = fillColorsToRemove.cbegin() ;  cit < fillColorsToRemove.cend(); ++cit ) {
        mFillColors.erase( mFillColors.begin() + *cit );
      }
    }
  }
}

