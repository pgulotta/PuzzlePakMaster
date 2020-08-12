#include "gamecontroller.hpp"

#include <QList>


GameController::GameController( QObject* parent ):
  QObject( parent ),
  mGameFactory{ mShapesFactory, parent},
  mDataAccessAdapter{mApplicationVersion}
{
}

void GameController::setDrawUnit( qreal drawUnit )
{
  if ( drawUnit > 0.0f ) {
    mShapesFactory.setDrawUnit( drawUnit );
  }
}

void GameController::setSelectedPuzzle( int previousPuzzleIndex )
{
  mGameFactory.setSelectedPuzzle( previousPuzzleIndex );
}

void GameController::setSelectedGame( const QString& moniker, const QString& player )
{
  qInfo() << Q_FUNC_INFO << ":  moniker = " << moniker << "  player=" << player;
  mGameFactory.selectGame( moniker, player );
  mGameFactory.setSelectedPuzzle( mDataAccessAdapter.getGameLatestPuzzleIndex( moniker, player ) );
  emit gamePuzzleChanged();
}

QString GameController::getLastPlayer() const
{
  return mDataAccessAdapter.getLastPlayer();
}

void GameController::setLastPlayer( const QString& lastPlayer ) const
{
  mDataAccessAdapter.setLastPlayer( lastPlayer );
}

void GameController::setCurrentPuzzleBestScore( int bestScore ) const
{
  mDataAccessAdapter.setCurrentPuzzleBestScore( mGameFactory.currentGameMoniker(), mGameFactory.currentPlayer(),
                                                mGameFactory.currentPuzzleIndex(), bestScore );
}

int GameController::getCurrentPuzzleBestScore()  const
{
  return mDataAccessAdapter.getCurrentPuzzleBestScore( mGameFactory.currentGameMoniker(), mGameFactory.currentPlayer(),
                                                       mGameFactory.currentPuzzleIndex() );
}

void GameController::nextPuzzle()
{
  mGameFactory.nextPuzzle();
  emit gamePuzzleChanged();
}

bool GameController::isProblemSolved( QVariantList problemPositionPoints,  QVariantList solutionPositionPoints,
                                      QVariantList problemWorldPoints,
                                      QVariantList solutionWorldPoints ) const
{
  if ( mPuzzlePiecesSolutionAnalyzer.isPuzzleSolved( problemPositionPoints, solutionPositionPoints,
                                                     mShapesFactory.acceptableVariance() ) ) {
    return  mPuzzlePiecesSolutionAnalyzer.isPuzzleSolved( problemWorldPoints, solutionWorldPoints,
                                                          mShapesFactory.acceptableVariance() );
  } else {
    return false;
  }
}

QList<int> GameController::findColorGroupIndexes( int index, int columnCount, QVariantList grid )
{
  return  mColorFallSolutionAnalyzer.findColorGroupIndexes( index, columnCount, grid );
}

QStringList GameController::getUpdatedFillColors( int columnCount, QList<int> indexColors, QStringList colors )
{
  return  mColorFallSolutionAnalyzer.getUpdatedFillColors( columnCount, indexColors, colors );
}

QString GameController::applicationTitle() const
{
  return mAppliationTitle;
}

QString GameController::applicationVersion() const
{
  return mApplicationVersion;
}

int GameController::puzzlesCount()
{
  return mGameFactory.puzzlesCount();
}

int GameController::currentPuzzleIndex()
{
  return mGameFactory.currentPuzzleIndex();;
}

QStringList GameController::players() const
{
  QStringList list;
  mDataAccessAdapter.populatePlayers( list );
  return list;
}

const QStringList GameController::puzzleColors()
{
  auto result = *mGameFactory.currentPuzzleColors();
  qDebug() << Q_FUNC_INFO  << "  result.count()= " << result.count();
  return result;
}

bool GameController::shouldPlayMusic()  const
{
  return mDataAccessAdapter.shouldPlayMusic();
}

void GameController::toggleShouldPlayMusic()  const
{
  mDataAccessAdapter.toggleShouldPlayMusic();
}

QString GameController::aboutMoniker() const
{
  return Constants().About;
}

const QList<QObject*>& GameController::gamesMetaData() const
{
  return mSwitchboardBuilder.gamesMetaData();
}

QList<QObject*>& GameController::gamePuzzlePieces()
{
  QList<QObject*>& result = mGameFactory.currentGamePieces();
  mDataAccessAdapter.setGameLastPuzzleIndex( mGameFactory.currentGameMoniker(), mGameFactory.currentPlayer(),
                                             mGameFactory.currentPuzzleIndex() );
  return result;
}
