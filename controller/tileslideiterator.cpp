#include "tileslideiterator.hpp"



TileSlideIterator::TileSlideIterator( const ShapesFactory& shapesFactory, const QString& moniker ):
  GameIterator{shapesFactory, moniker}
{
//qDebug() << Q_FUNC_INFO;
}

void TileSlideIterator::generatePuzzles( QObject* parent )
{

}
