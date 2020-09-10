#include "gamefactory.hpp"
#include "shapesfactory.hpp"
#include "puzzlesfactory.hpp"
#include "monochrometangramsiterator.hpp"
#include "tangramsiterator.hpp"
#include "lineupiterator.hpp"
#include "colorfalliterator.hpp"
#include "model/puzzle.hpp"
#include "model/gamemetadata.hpp"
#include "model/constants.hpp"
#include <QUuid>
#include <QTime>

Constants constants;

GameFactory::GameFactory( ShapesFactory& shapesFactory, QObject* parent ):
  QObject{parent},
  mShapesFactory{shapesFactory}
{
  QTime time = QTime::currentTime();
  qsrand( ( uint )time.msec() );
}

QString GameFactory::currentGameMoniker() const
{
  return  mCurrentGameMoniker;
}
QString GameFactory::currentPlayer() const
{
  return  mCurrentPlayer;
}

void GameFactory::nextPuzzle()
{
  mCurrentPuzzleGame->nextPuzzle();
  resetPuzzle();
}

QList<QObject*>& GameFactory::currentGamePieces()
{
  QList<QObject*>* currentPuzzlePieces = new QList<QObject*>();
  std::shared_ptr<Puzzle> puzzle = currentPuzzle();
  const Pieces*  pieces = puzzle->pieces();
  std::for_each( pieces->cbegin(), pieces->cend(),
  [currentPuzzlePieces]( Piece * p ) {
    currentPuzzlePieces->append( p );
  } );
  return *currentPuzzlePieces;
}

int GameFactory::puzzlesCount()
{
  return  ( mCurrentPuzzleGame == nullptr ) ? 0 : mCurrentPuzzleGame->puzzlesCount();
}

void GameFactory::selectGame( const QString& monikerSelected, const QString& player )
{
  mCurrentGameMoniker = monikerSelected;
  mCurrentPlayer = player;

  //qInfo() << Q_FUNC_INFO << "  mCurrentGameMoniker=" <<  mCurrentGameMoniker << "  mCurrentPlayer=" << mCurrentPlayer;
  if  ( monikerSelected == constants.GameTangrams ) {
    if ( !mTangramsGame ) {
      mTangramsGame =  std::shared_ptr<PuzzlesFactory>( new PuzzlesFactory( std::shared_ptr<GameIterator>
      { new TangramsIterator( mShapesFactory, player )}, this ) );
      mTangramsGame->generatePuzzles();
    }

    mCurrentPuzzleGame = mTangramsGame;
  } else if  ( monikerSelected == constants.GameTangramsMonochrome ) {
    if ( !mMonochromeTangramsGame ) {
      mMonochromeTangramsGame =  std::shared_ptr<PuzzlesFactory>( new PuzzlesFactory(
      std::shared_ptr<GameIterator> { new MonochromeTangramsIterator( mShapesFactory, player )}, this ) );
      mMonochromeTangramsGame->generatePuzzles();
    }

    mCurrentPuzzleGame = mMonochromeTangramsGame;
  } else if  ( monikerSelected == constants.GameLineUp ) {
    if ( !mLineUpGame ) {
      mLineUpGame =  std::shared_ptr<PuzzlesFactory>( new PuzzlesFactory( std::shared_ptr<GameIterator>
      { new LineUpIterator( mShapesFactory, player )}, this ) );
      mLineUpGame->generatePuzzles();
    }

    mCurrentPuzzleGame = mLineUpGame;
  } else if  ( monikerSelected == constants.ColorFall ) {
    if ( !mColorFallGame ) {
      mColorFallGame =  std::shared_ptr<PuzzlesFactory>( new PuzzlesFactory( std::shared_ptr<GameIterator>
      { new ColorFallIterator( mShapesFactory, player )}, this ) );
      mColorFallGame->generatePuzzles();
    }

    mCurrentPuzzleGame = mColorFallGame;
  } else {
    Q_ASSERT_X( false, "GameFactory::selectGame", "This option should be handled in the qml file" );
  }

  resetPuzzle();
}

const std::shared_ptr<Puzzle> GameFactory::currentPuzzle() const
{
  return mCurrentPuzzleGame->currentPuzzle();
}

void GameFactory::setSelectedPuzzle( int previousPuzzleIndex )
{
  mCurrentPuzzleGame->selectPuzzle( previousPuzzleIndex );
}

int GameFactory::currentPuzzleIndex() const
{
  return mCurrentPuzzleGame->currentPuzzleIndex();
}

void GameFactory::resetPuzzle()
{
// mCurrentPuzzle = nullptr;
}

QString GameFactory::createUniqueId()
{
  return QUuid::createUuid().toString().remove( '{' ).remove( '}' );
}

const Colors* GameFactory::currentPuzzleColors()
{
  return mCurrentPuzzleGame->currentPuzzleColors();
}


