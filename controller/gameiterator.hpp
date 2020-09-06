#pragma once

#include <QObject>
#include <QUuid>
#include <vector>
#include <iterator>
#include <memory>
#include "shapesfactory.hpp"
#include "model/puzzle.hpp"
#include "model/gamemetadata.hpp"

using Puzzles = std::vector<std::shared_ptr<Puzzle>>;
using PuzzlesCit = std::vector<std::shared_ptr<Puzzle>>::const_iterator;


class GameIterator
{
public:
  GameIterator( const ShapesFactory& shapesFactory, const QString& moniker ):
    mShapesFactory{shapesFactory}, mMoniker{moniker}
  {
    // qDebug() << Q_FUNC_INFO;
  }

  virtual ~GameIterator()
  {
    //qDebug() << Q_FUNC_INFO;
  }

  static QString createUniqueId()
  {
    return QUuid::createUuid().toString().remove( '{' ).remove( '}' );
  }

  const Pieces* currentPuzzlePieces()
  {
    return  mPuzzlesCit != mPuzzles.cend() ? ( *mPuzzlesCit )->pieces() : nullptr;
  }

  const Colors* currentPuzzleColors()
  {
    return  mPuzzlesCit != mPuzzles.cend() ? ( *mPuzzlesCit )->colors() : nullptr;
  }

  void nextPuzzle()
  {
    if ( mPuzzlesCit != mPuzzles.cend() && mPuzzlesCit + 1 != mPuzzles.cend() ) {
      ++mPuzzlesCit;
    }
  }

  int puzzlesCount()
  {
    return mPuzzles.size();
  }

  void selectPuzzle( int previousPuzzleIndex )
  {
    if ( previousPuzzleIndex < -1 ) {
      previousPuzzleIndex = -1;
    }

    mPuzzlesCit = mPuzzles.cbegin()  + previousPuzzleIndex;
  }

  const std::shared_ptr<Puzzle> currentPuzzle()
  {
    return *mPuzzlesCit;
  }

  int currentPuzzleIndex() const
  {
    return mPuzzlesCit - mPuzzles.cbegin();
  }

  void generateGamePuzzles( QObject* parent )
  {
    mPuzzles.clear();
    generatePuzzles( parent );
    mPuzzlesCit = mPuzzles.cbegin();
    qInfo() << Q_FUNC_INFO << ":  puzzle count=" << mPuzzles.size();
  }

  virtual void generatePuzzles( QObject* parent ) = 0;

  const QString& gameMoniker()
  {
    return mMoniker;
  }

protected:
  const ShapesFactory& mShapesFactory;
  const QString mMoniker;
  Puzzles mPuzzles;


private:
  PuzzlesCit mPuzzlesCit;


};

