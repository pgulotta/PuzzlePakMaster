#include "initializer.hpp"

#include <QGuiApplication>
#include <QQmlContext>
#include <box2dplugin.h>
#include "model/gamemetadata.hpp"

Initializer::Initializer(QObject* parent) :
  QObject(parent),
  mGameController{parent} {

  connect(&mGameController, &GameController::gamePuzzleChanged, this, &Initializer::onGamePuzzleChanged);

  Box2DPlugin plugin;
  plugin.registerTypes("Box2DStatic");
  qmlRegisterSingletonType(QUrl(QStringLiteral("qrc:/view/qml/Constants.qml")), "com.twentysixapps.puzzlepak.constants", 1, 0, "Constants" );
  auto rootContext = mQmlApplicationEngine.rootContext();
  qmlRegisterType<GameMetaData>("GameMetaDataType", 1, 0, "GameMetaData");
  rootContext->setContextProperty("GameController", &mGameController);
  rootContext->setContextProperty("GamesMetaData", QVariant::fromValue(mGameController.gamesMetaData()));
  mQmlApplicationEngine.load(QUrl(QStringLiteral("qrc:/view/qml/MainPage.qml")));
}

void Initializer::onGamePuzzleChanged() {
  mQmlApplicationEngine.rootContext()->setContextProperty("GamePuzzlePieces",
                                                          QVariant::fromValue(mGameController.gamePuzzlePieces()));
}
