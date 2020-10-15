#pragma once
#include "shapesfactory.hpp"
#include "gameiterator.hpp"

class LineUpIterator: public GameIterator
{
public:
  LineUpIterator( const ShapesFactory& shapesFactory, const QString& moniker );

  virtual ~LineUpIterator()
  {
  }

  void generatePuzzles( QObject* parent ) override;



};
