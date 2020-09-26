#pragma once

#include <QObject>
#include "switchboardbuilder.hpp"
#include "gamefactory.hpp"
#include "shapesfactory.hpp"
#include "puzzlepiecessolutionanalyzer.hpp"
#include "colorfallsolutionanalyzer.hpp"
#include "datastore/dataaccessadapter.hpp"


class QVariant;
class ImageProvider;

class GameController final : public QObject
{
  Q_OBJECT
public:
  explicit GameController( QObject* parent );
  const QList<QObject*>& gamesMetaData() const ;
  QList<QObject*>& gamePuzzlePieces();
  TileSlideGame& tileSlideGame() {return mGameFactory.tileSlideGame();} ;
  ImageProvider* imageProvider() {return mGameFactory.imageProvider();}
  QString currentGameMoniker() const {return mGameFactory.currentGameMoniker();}

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
  Q_INVOKABLE void setSelectedPuzzle( int puzzleIndex );
  Q_INVOKABLE void setSelectedGame( const QString& moniker, const QString& player );
  Q_INVOKABLE bool isPuzzleSolved( QVariantList problemPositionPoints,  QVariantList solutionPositionPoints,
                                   QVariantList problemWorldPoints, QVariantList solutionWorldPoints ) const;
  Q_INVOKABLE QList<int> findColorGroupIndexes( int index, int columnCount, QVariantList grid );
  Q_INVOKABLE QStringList getUpdatedFillColors( int columnCount,  QList<int> indexColors,  QStringList colors );
  Q_INVOKABLE void setDimensions( int windowWidth, int windowHeight );

signals:
  void gamePuzzleChanged();


private:
  const QString mAppliationTitle{ "Puzzle Pak"};
  const QString mApplicationVersion{ "1.40"};

  GameFactory mGameFactory;
  DataAccessAdapter mDataAccessAdapter;
  SwitchboardBuilder mSwitchboardBuilder;
  ShapesFactory mShapesFactory;

  PuzzlePiecesSolutionAnalyzer mPuzzlePiecesSolutionAnalyzer;
  ColorFallSolutionAnalyzer mColorFallSolutionAnalyzer;

};

/*
 *        target: GameController
        function onGamePuzzleChanged() {
            sourceImage = ""
            sourceImage = "image://puzzleImage"
            for (var i = 0; i < puzzlePieceModel; ++i) {
                repeaterId.itemAt(i).itemImageSource = ""
                console.log("item.itemImageSource = " + repeaterId.itemAt(
                                i).itemImageSource)
            }
            puzzlePieceModel = TileSlideGame.puzzlePieceCount()
            imagePieceWidth = TileSlideGame.imagePieceWidth()
            imagePieceHeight = TileSlideGame.imagePieceHeight()
            //            sourceImage = "image://puzzleImage"
            for (var i = 0; i < puzzlePieceModel; ++i) {
                var item = repeaterId.itemAt(i)
                item.itemImageSource = sourceImage + "/" + i
                console.log("item.itemImageSource = " + item.itemImageSource)
            }
        }




2  void ImageProvider::setDimensions(int, int)   Window:   864  x  842
    void ImageProvider::setDimensions(int, int) Image size NOT adjusted
    void ImageProvider::setDimensions(int, int) Image path:   ":/view/images/tile0.jpg"   mImage.sizeInBytes= 977680
    void TileSlideGame::assignToImageProvider() mCurrentRowColumnCount= 2 mImageFileName= ":/view/images/tile0.jpg"
    void TileSlideGame::selectPuzzle(int)  puzzleIndex= 0  mCurrentImageIndex= 0  mCurrentRowColumnCount= 2
    int TileSlideGame::currentPuzzleIndex() const
    int TileSlideGame::currentPuzzleIndex() const
    void Initializer::onGamePuzzleChanged() "TileSlide"
    int TileSlideGame::currentPuzzleIndex() const
    3 PARTIAL image 244824   id= "0"
    3 PARTIAL image 244824   id= "1"
    3 PARTIAL image 244824   id= "2"
    3 PARTIAL image 244824   id= "3"
    void GameController::setSelectedGame(const QString&, const QString&) :  moniker =  "TileSlide"   player= "Player 1"
                                     void TileSlideGame::selectPuzzle(int)
                                         2  void ImageProvider::setDimensions(int, int)   Window:   864  x  842
                                     void ImageProvider::setDimensions(int, int) Image size NOT adjusted
                                     void ImageProvider::setDimensions(int, int) Image path:   ":/view/images/tile0.jpg"   mImage.sizeInBytes= 977680
    void TileSlideGame::assignToImageProvider() mCurrentRowColumnCount= 2 mImageFileName= ":/view/images/tile0.jpg"
    void TileSlideGame::selectPuzzle(int)  puzzleIndex= 0  mCurrentImageIndex= 0  mCurrentRowColumnCount= 2
                                                                                                          void TileSlideGame::selectPuzzle(int)
                                                                                                              2  void ImageProvider::setDimensions(int, int)   Window:   864  x  842
                                                                                                          void ImageProvider::setDimensions(int, int) Image size NOT adjusted
                                                                                                          void ImageProvider::setDimensions(int, int) Image path:   ":/view/images/tile0.jpg"   mImage.sizeInBytes= 977680
    void TileSlideGame::assignToImageProvider() mCurrentRowColumnCount= 2 mImageFileName= ":/view/images/tile0.jpg"
    void TileSlideGame::selectPuzzle(int)  puzzleIndex= 0  mCurrentImageIndex= 0  mCurrentRowColumnCount= 2
    int TileSlideGame::currentPuzzleIndex() const
    int TileSlideGame::currentPuzzleIndex() const
    3 FULL Image 977680   id= ""
                             void Initializer::onGamePuzzleChanged() "TileSlide"





*/

