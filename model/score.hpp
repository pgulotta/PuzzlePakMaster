#pragma once

#include <QObject>

class Score : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString gameMoniker READ gameMoniker CONSTANT)
  Q_PROPERTY(QString puzzleId READ puzzleId CONSTANT)
  Q_PROPERTY(QString player READ player CONSTANT)
  Q_PROPERTY(int bestScore READ bestScore CONSTANT)

 signals:


 public:
  explicit Score(QObject* parent = nullptr) :
    QObject(parent) {
    // qDebug() << Q_FUNC_INFO << " called " ;
  }

  QString gameMoniker() const {
    return m_gameMoniker;
  }

  QString player() const {
    return m_player;
  }

  int bestScore() const {
    return m_bestScore;
  }

  QString puzzleId() const {
    return m_puzzleId;
  }

 public slots:





 private:
  QString m_gameMoniker;
  QString m_puzzleId;
  QString m_player;
  int m_bestScore;



};

