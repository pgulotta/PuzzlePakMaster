#pragma once

#include <vector>
#include <iterator>
#include "model/piece.hpp"
#include "shapesfactory.hpp"
#include "gameiterator.hpp"


class MonochromeTangramsIterator : public GameIterator {
 public:
  MonochromeTangramsIterator(const ShapesFactory& shapesFactory, const QString& moniker);

  virtual ~MonochromeTangramsIterator() {
    //qDebug() << Q_FUNC_INFO;
  }

  void generatePuzzles(QObject* parent) override;


};
