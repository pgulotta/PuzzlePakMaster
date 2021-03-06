#pragma once

#include "shapesfactory.hpp"
#include "gameiterator.hpp"

class TangramsIterator : public GameIterator
{
public:
  TangramsIterator( const ShapesFactory& shapesFactory, const QString& moniker );

  virtual ~TangramsIterator()
  {
    // qDebug() << Q_FUNC_INFO;
  }

  void generatePuzzles( QObject* parent ) override;



};
