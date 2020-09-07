#pragma once
#include "shapesfactory.hpp"
#include "gameiterator.hpp"


class TileSlideIterator : public GameIterator
{
public:
  TileSlideIterator( const ShapesFactory& shapesFactory, const QString& moniker );

  virtual ~TileSlideIterator()
  {
    // qDebug() << Q_FUNC_INFO;
  }

  void generatePuzzles( QObject* parent ) override;
};

