#pragma once


#include "piece.hpp"
#include <QObject>
#include <QString>
#include <QList>

using SkillLevelAsText = std::vector< QString>;
using Colors = QStringList;


class Puzzle : public QObject {
  Q_OBJECT
  Q_ENUMS(SkillLevel)
  Q_PROPERTY(QString uniqueId READ uniqueId CONSTANT )
  Q_PROPERTY(SkillLevel skillLevel READ skillLevel CONSTANT)
  Q_PROPERTY(Pieces pieces READ pieces CONSTANT)
  Q_PROPERTY(Colors colors READ colors CONSTANT)


 signals:

 public:
  enum class SkillLevel {
    Easy,
    Moderate,
    Difficult
  };

  Puzzle(QString uniqueIdid, SkillLevel skillLevel, const Pieces* pieces, QObject* parent) noexcept(true) :
    QObject{parent},
    m_uniqueId{uniqueIdid},
    m_skillLevel{skillLevel},
    m_pieces{pieces},
    m_colors{new Colors{}} {
    //qDebug() << Q_FUNC_INFO << " called " ;
  }

  Puzzle(QString uniqueIdid, SkillLevel skillLevel, const Colors* colors, QObject* parent) noexcept(true) :
    QObject{parent},
    m_uniqueId{uniqueIdid},
    m_skillLevel{skillLevel},
    m_pieces{new Pieces{}},
  m_colors{colors} {
    //qDebug() << Q_FUNC_INFO << " called " ;
  }

  virtual ~Puzzle()  {
    //qDebug() << Q_FUNC_INFO << " called " ;
  }

  QString toText(SkillLevel scale) {
    if (mSkillLevelAsText.empty()) {
      mSkillLevelAsText.emplace_back (tr("Easy"));
      mSkillLevelAsText.emplace_back (tr("Moderate")) ;
      mSkillLevelAsText.emplace_back (tr("Difficult")); ;
    }
    return mSkillLevelAsText[toInt(scale)];
  }

  int toInt(SkillLevel skillLevel) const {
    return static_cast<int>(skillLevel);
  }

  SkillLevel skillLevel() const {
    return m_skillLevel;
  }

  const Pieces* pieces() const {
    return m_pieces;
  }

  const Colors* colors() const {
    return m_colors;
  }

  QString uniqueId() const {
    return m_uniqueId;
  }


 private:
  QString m_uniqueId;
  SkillLevel m_skillLevel;
  const Pieces* m_pieces;
  const Colors* m_colors;
  SkillLevelAsText mSkillLevelAsText;



};

