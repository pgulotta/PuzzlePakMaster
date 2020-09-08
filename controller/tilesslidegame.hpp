#pragma once

#include <QObject>
#include "imagesfactory.hpp"


class TilesSlideGame : public QObject
{
  Q_OBJECT
signals:

public:
  explicit TilesSlideGame( QObject* parent = nullptr );

  void selectPuzzle( int previousPuzzleIndex );
  void nextPuzzle();
  int currentPuzzleIndex() const;
  int puzzlesCount() const;

private:
  int mCurrentPuzzleIndex;
  ImagesFactory mSlidingTilesFactory ;


};


