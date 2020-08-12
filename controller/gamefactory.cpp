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

GameFactory::GameFactory(ShapesFactory& shapesFactory, QObject* parent ):
  QObject{parent},
  mShapesFactory{shapesFactory} {
  QTime time = QTime::currentTime();
  qsrand((uint)time.msec());
}

QString GameFactory::currentGameMoniker() const {
  return  mCurrentGameMoniker;
}
QString GameFactory::currentPlayer() const {
  return  mCurrentPlayer;
}

void GameFactory::nextPuzzle() {
  mCurrentGame->nextPuzzle();
  resetPuzzle();
}

QList<QObject*>& GameFactory::currentGamePieces() {
  QList<QObject*>* currentPuzzlePieces = new QList<QObject*>();
  std::shared_ptr<Puzzle> puzzle = currentPuzzle();
  const Pieces*  pieces = puzzle->pieces();
  std::for_each(pieces->cbegin(), pieces->cend(),
  [currentPuzzlePieces]( Piece * p) {
    currentPuzzlePieces->append(p);
  });
  return *currentPuzzlePieces;
}

int GameFactory::puzzlesCount() {
  return  ( mCurrentGame == nullptr) ? 0 : mCurrentGame->puzzlesCount();
}

void GameFactory::selectGame(const QString& monikerSelected, const QString& player) {
  Constants constants;
  mCurrentGameMoniker = monikerSelected;
  mCurrentPlayer = player;
  //qInfo() << Q_FUNC_INFO << "  mCurrentGameMoniker=" <<  mCurrentGameMoniker << "  mCurrentPlayer=" << mCurrentPlayer;
  if  (monikerSelected == constants.GameTangrams) {
    if (!mTangramsGame) {
      mTangramsGame =  std::shared_ptr<PuzzlesFactory>(new PuzzlesFactory(std::move(std::unique_ptr<GameIterator>
      { new TangramsIterator(mShapesFactory, player)}), this));
      mTangramsGame->generatePuzzles();
    }
    mCurrentGame = mTangramsGame;
  } else if  (monikerSelected == constants.GameTangramsMonochrome) {
    if (!mMonochromeTangramsGame) {
      mMonochromeTangramsGame =  std::shared_ptr<PuzzlesFactory>(new PuzzlesFactory(std::move(std::unique_ptr<GameIterator>
      { new MonochromeTangramsIterator(mShapesFactory, player)}), this));
      mMonochromeTangramsGame->generatePuzzles();
    }
    mCurrentGame = mMonochromeTangramsGame;
  } else if  (monikerSelected == constants.GameLineUp) {
    if (!mLineUpGame) {
      mLineUpGame =  std::shared_ptr<PuzzlesFactory>(new PuzzlesFactory(std::move(std::unique_ptr<GameIterator>
      { new LineUpIterator(mShapesFactory, player)}), this));
      mLineUpGame->generatePuzzles();
    }
    mCurrentGame = mLineUpGame;
  } else if  (monikerSelected == constants.ColorFall) {
    if (!mColorFallGame) {
      mColorFallGame =  std::shared_ptr<PuzzlesFactory>(new PuzzlesFactory(std::move(std::unique_ptr<GameIterator>
      { new ColorFallIterator(mShapesFactory, player)}), this));
      mColorFallGame->generatePuzzles();
    }
    mCurrentGame = mColorFallGame;
  } else {
    Q_ASSERT_X(false, "GameFactory::selectGame", "This option should be handled in the qml file");
  }
  resetPuzzle();
}

const std::shared_ptr<Puzzle> GameFactory::currentPuzzle() const {
  return mCurrentGame->currentPuzzle();
}

void GameFactory::setSelectedPuzzle(int previousPuzzleIndex) {
  mCurrentGame->selectPuzzle(previousPuzzleIndex);
}

int GameFactory::currentPuzzleIndex() const {
  return mCurrentGame->currentPuzzleIndex();
}

void GameFactory::resetPuzzle() {
  mCurrentPuzzle = nullptr;
}

QString GameFactory::createUniqueId() {
  return QUuid::createUuid().toString().remove('{').remove('}');
}

const Colors* GameFactory::currentPuzzleColors() {
  return mCurrentGame->currentPuzzleColors();
}

//QStringList GameFactory::currentPuzzleColors() {
//  if ( mCurrentGame == nullptr  ) {
//    return QStringList();
//  }
//  const Pieces* pieces =  mCurrentGame->currentPuzzlePieces();
//  if ( pieces == nullptr  ) {
//    return QStringList();
//  }

//  QSet<QString> colors;
//  for (auto cit = pieces->constBegin(); cit != pieces->constEnd() ; ++cit) {
//    const Piece* piece = *cit;
//    colors.insert(piece->fillColor().name());
//  }

//  while ( colors.size() < pieces->size()) {
//    int index = qrand() % (QColor::colorNames().size() ) ;
//    colors.insert(QColor(QColor::colorNames().at(index)).name(QColor::NameFormat::HexRgb));
//  }

//  return colors.toList();
//}
