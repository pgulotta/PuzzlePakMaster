#pragma once

#include "gamecontroller.hpp"
#include "tileslidegame.hpp"
#include <QQmlApplicationEngine>
#include <QObject>


class Initializer final : public QObject
{
  Q_OBJECT

private slots:
  void onGamePuzzleChanged();
  void onTileSlideGameChanged();

signals:

public:
  explicit Initializer( QObject* parent );
  explicit Initializer( const Initializer& ) = delete;
  Initializer& operator= ( const Initializer& rhs ) = delete;



private:
  QQmlApplicationEngine mQmlApplicationEngine;
  GameController mGameController;
  TileSlideGame mTileSlideGame;

};

