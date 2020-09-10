#pragma once

#include <QObject>
#include "switchboardbuilder.hpp"
#include "gamefactory.hpp"
#include "shapesfactory.hpp"
#include "puzzlepiecessolutionanalyzer.hpp"
#include "colorfallsolutionanalyzer.hpp"
#include "datastore/dataaccessadapter.hpp"
#include <memory>

class QVariant;


class GameController final : public QObject
{
  Q_OBJECT
public:
  Q_INVOKABLE QString applicationTitle() const ;
  Q_INVOKABLE QString applicationVersion() const ;
  Q_INVOKABLE QString aboutMoniker() const;
  Q_INVOKABLE QStringList players() const;
  Q_INVOKABLE void nextPuzzle() ;
  Q_INVOKABLE int puzzlesCount() ;
  Q_INVOKABLE int currentPuzzleIndex();
  Q_INVOKABLE void setDrawUnit( qreal drawUnit ) ;
  Q_INVOKABLE bool shouldPlayMusic() const;
  Q_INVOKABLE void toggleShouldPlayMusic()  const;
  Q_INVOKABLE const QStringList puzzleColors();
  Q_INVOKABLE QString getLastPlayer() const;
  Q_INVOKABLE void setLastPlayer( const QString& lastPlayer ) const;
  Q_INVOKABLE void setCurrentPuzzleBestScore( int bestScore ) const;
  Q_INVOKABLE int getCurrentPuzzleBestScore() const;
  Q_INVOKABLE void setSelectedPuzzle( int previousPuzzleIndex );
  Q_INVOKABLE void setSelectedGame( const QString& moniker, const QString& player );
  Q_INVOKABLE bool isPuzzleSolved( QVariantList problemPositionPoints,  QVariantList solutionPositionPoints,
                                   QVariantList problemWorldPoints, QVariantList solutionWorldPoints ) const;
  Q_INVOKABLE QList<int> findColorGroupIndexes( int index, int columnCount, QVariantList grid );
  Q_INVOKABLE QStringList getUpdatedFillColors( int columnCount,  QList<int> indexColors,  QStringList colors );


public:
  GameController( QObject* parent );
  const QList<QObject*>& gamesMetaData() const ;
  QList<QObject*>& gamePuzzlePieces();

signals:
  void gamePuzzleChanged();


private:
  const QString mAppliationTitle{ "Puzzle Pak"};
  const QString mApplicationVersion{ "1.40"};

  SwitchboardBuilder mSwitchboardBuilder;
  ShapesFactory mShapesFactory;
  GameFactory mGameFactory;
  PuzzlePiecesSolutionAnalyzer mPuzzlePiecesSolutionAnalyzer;
  ColorFallSolutionAnalyzer mColorFallSolutionAnalyzer;
  DataAccessAdapter mDataAccessAdapter;
};



