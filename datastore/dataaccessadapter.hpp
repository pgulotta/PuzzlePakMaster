#pragma once


#include "sqlite.hpp"
#include <QSharedPointer>
#include <QStringList>
#include "sqlite.hpp"

class QString;
class Score;


class DataAccessAdapter {
 public:
  DataAccessAdapter(const QString& applicationVersion);
  ~DataAccessAdapter();

  void setCurrentPuzzleBestScore( QString gameMoniker,  QString player,  int puzzleIndex, int bestScore) const;
  int getCurrentPuzzleBestScore( QString gameMoniker,  QString player,  int puzzleIndex) const ;
  void setGameLastPuzzleIndex( QString gameMoniker,  QString player,  int puzzleIndex) const;
  int getGameLatestPuzzleIndex( QString gameMoniker,  QString player) const;
  bool shouldPlayMusic() const;
  void toggleShouldPlayMusic() const;
  void populatePlayers(QStringList& players) const;
  QString getLastPlayer() const;
  void setLastPlayer(const QString& lastPlayer) const;

 private:
  typedef QSharedPointer<Connection> ConnectionPtr;
  ConnectionPtr mConnection {QSharedPointer<Connection>::create()};
  bool openDB();
  void releaseConnection();
  bool createDB();
  void saveDB(Connection const& sourceConnection);
  QString mAppDbName;
  const QString& mApplicationVersion;

};


