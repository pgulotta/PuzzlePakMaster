#include "tilesslidegame.hpp"

TilesSlideGame::TilesSlideGame( QObject* parent ) : QObject( parent )
{

}


void TilesSlideGame::selectPuzzle( int previousPuzzleIndex )
{

}

void TilesSlideGame::nextPuzzle()
{

}

int TilesSlideGame::currentPuzzleIndex() const
{
  return mCurrentPuzzleIndex;
}

int TilesSlideGame::puzzlesCount() const
{
  return 0;
}
