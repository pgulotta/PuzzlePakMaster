#pragma once

#include <QObject>

class QVariant;
class QPointF;

class PuzzlePiecesSolutionAnalyzer final {
 public:
  bool isPuzzleSolved(QVariantList solutionPoints, QVariantList problemPoints, qreal acceptableVariance) const;


 private:
  static bool variantXLessThan(const QVariant& v1, const QVariant& v2) ;
  static bool variantYLessThan(const QVariant& v1, const QVariant& v2) ;
  static bool pointXLessThan(const QPointF* p1, const QPointF* p2);
  static bool pointYLessThan(const QPointF* p1, const QPointF* p2);

};

