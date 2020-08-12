#pragma once

#include <QObject>
#include <QDebug>
#include <QColor>


class GameMetaData : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString moniker READ moniker CONSTANT )
  Q_PROPERTY(QString title READ title CONSTANT )
  Q_PROPERTY(QString imageSource READ imageSource CONSTANT  )
  Q_PROPERTY(QString pageSource READ pageSource CONSTANT  )
  Q_PROPERTY(QString musicSource READ musicSource CONSTANT  )
  Q_PROPERTY(QString helpText READ helpText CONSTANT  )

 signals:


 public:
  explicit GameMetaData(QObject* parent = nullptr) :
    QObject{parent} {
    // qDebug() << Q_FUNC_INFO << " called " ;
  }

  //  virtual ~GameMetaData()  {
  //     qDebug() << Q_FUNC_INFO << " called " ;
  //  }

  GameMetaData(const QString& moniker, QString title, QString imageSource, QString pageSource, QString musicSource, QString helpText,
               QObject* parent = nullptr):
    QObject{parent},
    m_moniker {moniker},
    m_title{title},
    m_imageSource {imageSource},
    m_pageSource {pageSource },
    m_musicSource {musicSource},
    m_helpText {helpText}
  { }

  QString title() const {
    return m_title;
  }

  QString imageSource() const {
    return m_imageSource;
  }

  QString pageSource() const {
    return m_pageSource;
  }


  QString musicSource() const {
    return m_musicSource;
  }

  QString moniker() const {
    return m_moniker;
  }

  QString helpText() const {
    return m_helpText;
  }

 private:
  QString m_moniker;
  QString m_title;
  QString m_imageSource;
  QString m_pageSource;
  QString m_musicSource;
  QString m_helpText;


};


