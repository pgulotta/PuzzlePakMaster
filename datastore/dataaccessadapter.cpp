#include "dataaccessadapter.hpp"
#include "../model/score.hpp"
#include <QString>
#include <QStandardPaths>
#include <QDateTime>
#include <QTextStream>
#include <QDir>
#include <QFile>

//  android:  /data/user/0/com.twentysixapps.puzzlepak/files/com.twentysixapps.puzzlepak.db
//  windows:  C:/Users/WindowsUserName/AppData/Roaming/26Apps/Puzzle Pak/com.twentysixapps.puzzlepak.db

DataAccessAdapter::DataAccessAdapter(const QString& applicationVersion): mApplicationVersion{applicationVersion} {
  auto appDataFolder = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
  QDir dir = QDir::root();
  dir.mkpath(appDataFolder);
  mAppDbName = appDataFolder + "/" + "com.twentysixapps.puzzlepak.db" ;
  openDB();
}

DataAccessAdapter::~DataAccessAdapter() {
  try {
    releaseConnection();
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
}

bool DataAccessAdapter::createDB() {
  qInfo() << Q_FUNC_INFO << ": mAppDbName=" << qPrintable(mAppDbName);

  bool success = false;
  try {
    Connection connection = Connection::Memory();
    Execute(connection,
            "CREATE TABLE [Version]([Created] TEXT(32) NOT NULL, [ReleaseNumber] TEXT(32) NOT NULL)");
    Execute(connection,
            "CREATE TABLE [Settings]([PlayMusic] INTEGER NOT NULL, [LastPlayer] TEXT(32) NOT NULL)");
    Execute(connection,
            "CREATE TABLE [LatestPuzzle]([GameMoniker] TEXT(32) NOT NULL,[Player] TEXT(32) NOT NULL,[PuzzleIndex] INTEGER NOT NULL)");
    Execute(connection,
            "CREATE TABLE [BestScore]([GameMoniker] TEXT(32) NOT NULL,[Player] TEXT(32) NOT NULL,[PuzzleIndex] INTEGER NOT NULL, [Score] INTEGER NOT NULL)");

    QString dateTime;
    QTextStream(&dateTime) << QDateTime::currentDateTime().toTime_t();
    Execute(connection, "INSERT INTO Version (Created,ReleaseNumber) VALUES (?,?)",
            dateTime.toStdString().c_str(),
            mApplicationVersion.toStdString().c_str());

    Execute(connection, "INSERT INTO Settings (PlayMusic,LastPlayer ) VALUES (1,'')");

    saveDB(connection);
    success = true;
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
  return success;
}

void DataAccessAdapter::releaseConnection() {
  try {
    mConnection.clear();
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
}

bool DataAccessAdapter::openDB() {
  bool success = false;
  try {
    qInfo() << Q_FUNC_INFO <<  ": Attempting to open database " << qPrintable(mAppDbName);
    if (!QFile::exists(mAppDbName)) {
      createDB();
    }
    mConnection->Open(mAppDbName.toStdString().c_str());
    success = true;
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }

  qInfo() << Q_FUNC_INFO <<  ": Successfully opened " << qPrintable(mAppDbName);
  return success;
}

void DataAccessAdapter::saveDB(Connection const& sourceConnection) {
  try {
    qInfo() << Q_FUNC_INFO <<  ": Attempting to save database " << qPrintable(mAppDbName);
    Connection destinationConnection(mAppDbName.toStdString().c_str());
    Backup backup(destinationConnection, sourceConnection);
    backup.Step();
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
}

int DataAccessAdapter::getCurrentPuzzleBestScore(QString gameMoniker,  QString player,  int puzzleIndex)  const {
  int result = 0;
  try {
    QString sql = QString("SELECT Score FROM BestScore WHERE GameMoniker = '%1' AND Player = '%2' and PuzzleIndex=%3 ").
                  arg(gameMoniker.toStdString().c_str(),
                      player.toStdString().c_str(),
                      QString::number(puzzleIndex).toStdString().c_str());
    Statement statement;
    statement.Prepare(*mConnection.data(),  sql.toStdString().c_str());
    for (Row row : statement) {
      result =  row.GetInt(0);
    }
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
  return result;
}

void DataAccessAdapter::setCurrentPuzzleBestScore(QString gameMoniker, QString player, int puzzleIndex, int bestScore)  const {
  try {
    QString sql = QString("DELETE FROM BestScore  WHERE GameMoniker='%1' AND Player='%2' AND PuzzleIndex=%3 ").
                  arg(gameMoniker.toStdString().c_str(),
                      player.toStdString().c_str(),
                      QString::number(puzzleIndex).toStdString().c_str());
    Execute(*mConnection.data(), sql.toStdString().c_str());
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
  try {
    Execute(*mConnection.data(), "INSERT INTO BestScore (GameMoniker, Player, PuzzleIndex,Score) VALUES (?,?,?,?)",
            gameMoniker.toStdString().c_str(),
            player.toStdString().c_str(),
            QString::number(puzzleIndex).toStdString().c_str(),
            QString::number(bestScore).toStdString().c_str());
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
}

void DataAccessAdapter::setGameLastPuzzleIndex( QString gameMoniker,  QString player,  int puzzleIndex)  const {
  try {
    QString sql = QString("DELETE FROM LatestPuzzle  WHERE GameMoniker='%1' AND Player='%2' ").
                  arg(gameMoniker.toStdString().c_str(),
                      player.toStdString().c_str());
    Execute(*mConnection.data(), sql.toStdString().c_str());
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
  try {
    Execute(*mConnection.data(), "INSERT INTO LatestPuzzle (GameMoniker, Player, PuzzleIndex) VALUES (?,?,?)",
            gameMoniker.toStdString().c_str(),
            player.toStdString().c_str(),
            QString::number(puzzleIndex).toStdString().c_str());
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
}

int DataAccessAdapter::getGameLatestPuzzleIndex( QString gameMoniker,  QString player)  const {
  int result = 0;
  try {
    QString sql = QString("SELECT PuzzleIndex FROM LatestPuzzle WHERE GameMoniker = '%1' AND Player = '%2' ").
                  arg(gameMoniker.toStdString().c_str(),
                      player.toStdString().c_str());
    Statement statement;
    statement.Prepare(*mConnection.data(),  sql.toStdString().c_str());
    for (Row row : statement) {
      result =  row.GetInt(0);
    }
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
  return result;
}

bool DataAccessAdapter::shouldPlayMusic()  const {
  int result = 0;
  try {
    QString sql = QString("SELECT PlayMusic FROM Settings ");
    Statement statement;
    statement.Prepare(*mConnection.data(),  sql.toStdString().c_str());
    for (Row row : statement) {
      result =  row.GetInt(0);
    }
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
  return result == 0 ? false : true;
}

void DataAccessAdapter::toggleShouldPlayMusic()  const {
  bool currentPlayMusic =  shouldPlayMusic();
  int toggledPlayMusic = currentPlayMusic ? 0 : 1;
  try {
    QString sql = QString("UPDATE Settings SET PlayMusic = %1").arg(toggledPlayMusic);
    Execute(*mConnection.data(), sql.toStdString().c_str());
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
}

void DataAccessAdapter::setLastPlayer(const QString& lastPlayer)  const {
  try {
    QString sql = QString("UPDATE Settings SET LastPlayer = '%1' ").arg(lastPlayer);
    Execute(*mConnection.data(), sql.toStdString().c_str());
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
}

QString DataAccessAdapter::getLastPlayer()  const {
  QString result;
  try {
    QString sql = QString("SELECT LastPlayer FROM Settings");
    Statement statement;
    statement.Prepare(*mConnection.data(),  sql.toStdString().c_str());
    for (Row row : statement) {
      result =  row.GetString(0);
    }
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
  return result;
}

void DataAccessAdapter::populatePlayers(QStringList& players) const {
  try {
    players.clear();
    QString sql = QString("SELECT DISTINCT Player FROM LatestPuzzle ORDER BY Player ");
    Statement statement;
    statement.Prepare(*mConnection.data(),  sql.toStdString().c_str());
    for (Row row : statement) {
      players.append(row.GetString(0));
    }
  } catch (const std::exception& e) {
    qWarning() << Q_FUNC_INFO << "  Error:  " <<  e.what ();
  }
}
