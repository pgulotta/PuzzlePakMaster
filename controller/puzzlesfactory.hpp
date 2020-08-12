#pragma once

#include <memory>
#include "shapesfactory.hpp"
#include "model/puzzle.hpp"
#include "gameiterator.hpp"
#include <QObject>


class PuzzlesFactory : public QObject {
 public:
  PuzzlesFactory(std::unique_ptr<GameIterator> gameIterator, QObject* parent):
    QObject{parent},
    mGameIterator{std::move(gameIterator)}
  {}

  void nextPuzzle() {
    mGameIterator->nextPuzzle();
  }

  const std::shared_ptr<Puzzle> currentPuzzle() const {
    return mGameIterator->currentPuzzle();
  }

  const Colors* currentPuzzleColors() {
    return mGameIterator->currentPuzzleColors();
  }

  const Pieces* currentPuzzlePieces() {
    return mGameIterator->currentPuzzlePieces();
  }

  void generatePuzzles() {
    mGameIterator->generateGamePuzzles(this);
  }

  int puzzlesCount() {
    return mGameIterator->puzzlesCount();
  }

  void selectPuzzle(int previousPuzzleIndex) {
    mGameIterator->selectPuzzle(previousPuzzleIndex);
  }

  int currentPuzzleIndex() const {
    return  mGameIterator->currentPuzzleIndex();
  }

  int lastPuzzleIndex() {
    return  mGameIterator->currentPuzzleIndex();
  }

 private:
  std::unique_ptr<GameIterator> mGameIterator;

};

