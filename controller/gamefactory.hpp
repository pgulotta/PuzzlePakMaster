#pragma once


#include <memory>
#include "tileslidegame.hpp"
#include "model/gamemetadata.hpp"
#include "model/puzzle.hpp"
#include <QObject>


class ShapesFactory;
class PuzzlesFactory;
class Puzzle;

class GameFactory  final : public QObject
{
  Q_OBJECT

public:
  GameFactory( ShapesFactory& shapesFactory, QObject* parent );
  int puzzlesCount() ;
  void nextPuzzle() ;
  QList<QObject*>& currentGamePieces() ;
  void selectGame( const QString& monikerSelected, const QString& player ) ;
  void setSelectedPuzzle( int previousPuzzleIndex );
  int currentPuzzleIndex() const;
  QString currentGameMoniker() const;
  QString currentPlayer() const;
  const Colors* currentPuzzleColors() ;


private:
  const std::shared_ptr<Puzzle>  currentPuzzle() const;
  void resetPuzzle() ;
  static QString createUniqueId();

  ShapesFactory& mShapesFactory;
  QString mCurrentGameMoniker;
  QString mCurrentPlayer;

  std::shared_ptr<PuzzlesFactory> mMonochromeTangramsGame;
  std::shared_ptr<PuzzlesFactory> mTangramsGame;
  std::shared_ptr<PuzzlesFactory> mLineUpGame;
  std::shared_ptr<PuzzlesFactory> mColorFallGame;
  std::shared_ptr<PuzzlesFactory> mCurrentPuzzleGame;

};


