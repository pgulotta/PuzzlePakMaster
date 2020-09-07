#include "puzzlepiecessolutionanalyzer.hpp"

#include <QList>
#include <QPointF>
#include <QDebug>
#include <math.h>
bool PuzzlePiecesSolutionAnalyzer::isPuzzleSolved( QVariantList solutionPoints, QVariantList problemPoints,
                                                   qreal acceptableVariance ) const
{
  Q_ASSERT( solutionPoints.length() == problemPoints.length() );

  if ( solutionPoints.length() != problemPoints.length() ) {
    return false;
  }

  Q_ASSERT( solutionPoints.length() > 1 );

  if ( solutionPoints.length() < 2 ) {
    return false;
  }

  bool result{true};
  std::sort( problemPoints.begin(), problemPoints.end(), variantXLessThan );
  std::sort( solutionPoints.begin(), solutionPoints.end(), variantXLessThan );
  QPointF problemPoint1 =  problemPoints.at( 0 ).toPoint();
  QPointF problemPoint2;
  QPointF solutionPoint1 = solutionPoints.at( 0 ).toPoint();
  QPointF solutionPoint2 ;

  for ( auto index = 1; result && index < problemPoints.length(); ++index  ) {
    problemPoint2 =  problemPoints.at( index ).toPoint();
    solutionPoint2 = solutionPoints.at( index ).toPoint();

    if ( abs( abs( problemPoint1.x() - problemPoint2.x() ) -  abs( solutionPoint1.x() - solutionPoint2.x() ) ) >
         acceptableVariance ) {
      result = false;
    }

    if ( result ) {
      problemPoint1 = problemPoint2;
      solutionPoint1 = solutionPoint2;
    }

    //    qDebug() << "problem/soution x = " << problemPoint1.x() << "  " << problemPoint2.x() << "  " << solutionPoint1.x() << "  " <<
    //             solutionPoint2.x();
    //    qDebug() << " x result = " << std::abs(problemPoint1.x() - problemPoint2.x()) << "  " << std::abs(
    //               solutionPoint1.x() - solutionPoint2.x());
  }

  if ( result ) {
    std::sort( problemPoints.begin(), problemPoints.end(), variantYLessThan );
    std::sort( solutionPoints.begin(), solutionPoints.end(), variantYLessThan );
    problemPoint1 =  problemPoints.at( 0 ).toPoint();
    solutionPoint1 = solutionPoints.at( 0 ).toPoint();

    for ( auto index = 1; result && index < problemPoints.length(); ++index  ) {
      problemPoint2 =  problemPoints.at( index ).toPoint();
      solutionPoint2 = solutionPoints.at( index ).toPoint();

      if ( abs( abs( problemPoint1.y() - problemPoint2.y() ) -  abs( solutionPoint1.y() -
                                                                     solutionPoint2.y() ) ) > acceptableVariance ) {
        result =  false;
      }

      if ( result ) {
        problemPoint1 = problemPoint2;
        solutionPoint1 = solutionPoint2;
      }

      //      qDebug() << "problem/soution y = " << problemPoint1.y() << "  " << problemPoint2.y() << "  " << solutionPoint1.y() << "  " <<
      //               solutionPoint2.y();
      //      qDebug() << "y result = " << std::abs(problemPoint1.y() - problemPoint2.y()) << "  " << std::abs(
      //                 solutionPoint1.y() - solutionPoint2.y());
    }
  }

  //qDebug() << "isPuzzleSolved? " << result;
  return result;
}


bool PuzzlePiecesSolutionAnalyzer::variantXLessThan( const QVariant& v1, const QVariant& v2 )
{
  QPointF p1{v1.toPoint()};
  QPointF p2{v2.toPoint()};
  return  PuzzlePiecesSolutionAnalyzer::pointXLessThan( &p1, &p2 );
}

bool PuzzlePiecesSolutionAnalyzer::variantYLessThan( const QVariant& v1, const QVariant& v2 )
{
  QPointF p1{v1.toPoint()};
  QPointF p2{v2.toPoint()};
  return  PuzzlePiecesSolutionAnalyzer::pointYLessThan( &p1, &p2 );
}

bool PuzzlePiecesSolutionAnalyzer::pointXLessThan( const QPointF* p1, const QPointF* p2 )
{
  return p1->x() < p2->x();
}

bool PuzzlePiecesSolutionAnalyzer::pointYLessThan( const QPointF* p1, const QPointF* p2 )
{
  return p1->y() < p2->y();
}
