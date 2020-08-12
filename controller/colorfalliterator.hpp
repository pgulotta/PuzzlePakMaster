#pragma once
#include "shapesfactory.hpp"
#include "gameiterator.hpp"

class ColorFallIterator: public GameIterator {
 public:
  ColorFallIterator(const ShapesFactory& shapesFactory, const QString& moniker);

  virtual ~ColorFallIterator() {
    // qDebug() << Q_FUNC_INFO;
  }

  void generatePuzzles(QObject* parent) override;



};
