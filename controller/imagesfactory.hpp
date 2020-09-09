#pragma once


class ImagesFactory
{
public:
  ImagesFactory();
  void selectPuzzle( int previousPuzzleIndex );
  void nextPuzzle();
  int currentPuzzleIndex() const;
  int puzzlesCount() const;

private:
  int mCurrentPuzzleIndex{0};
  int mCurrentRowColumnCount{0};
};


