#pragma once
#include "shapesfactory.hpp"
#include "gameiterator.hpp"

class ColorFallIterator: public GameIterator
{
public:
  ColorFallIterator( const ShapesFactory& shapesFactory, const QString& moniker );

  virtual ~ColorFallIterator()
  {
  }

  void generatePuzzles( QObject* parent ) override;



};
