#pragma once

#include "shapesfactory.hpp"
#include "gameiterator.hpp"


class MonochromeTangramsIterator : public GameIterator
{
public:
  MonochromeTangramsIterator( const ShapesFactory& shapesFactory, const QString& moniker );

  virtual ~MonochromeTangramsIterator()
  {
  }

  void generatePuzzles( QObject* parent ) override;


};
