#pragma once


#include "shape.hpp"
#include <QObject>
#include <QString>
#include <QList>
#include <QDebug>
#include <QColor>
#include <QVariant>

class Piece;
using Pieces = QList<Piece*>;


class Piece : public QObject
{
  Q_OBJECT
  Q_ENUMS( Shape::Tag )
  Q_PROPERTY( qreal xPosition READ xInitialPosition CONSTANT )
  Q_PROPERTY( qreal yPosition READ yInitialPosition CONSTANT )
  Q_PROPERTY( qreal width READ width CONSTANT )
  Q_PROPERTY( qreal height READ height CONSTANT )
  Q_PROPERTY( qreal rotation READ rotation CONSTANT )
  Q_PROPERTY( QColor fillColor READ fillColor CONSTANT )
  Q_PROPERTY( QVariantList vertices READ vertices CONSTANT )


signals:

public:
  Piece( qreal xPosition, qreal yPosition, qreal rotation, QColor fillColor, QVariantList* vertices, QObject* parent ):
    QObject{parent},
    m_xPosition{xPosition},
    m_yPosition{yPosition},
    m_rotation{rotation},
    m_fillColor{fillColor},
    m_vertices{vertices}
  {
    //qDebug() << Q_FUNC_INFO << " called " ;
    calculatePolygonDimensions();
  }

  //  virtual ~Piece() {
  //    qDebug() << Q_FUNC_INFO << " called " ;
  //  }

  qreal xInitialPosition() const
  {
    return m_xPosition;
  }

  qreal yInitialPosition() const
  {
    return m_yPosition;
  }

  QColor fillColor() const
  {
    return m_fillColor;
  }

  QVariantList vertices() const
  {
    return *m_vertices;
  }

  qreal rotation() const
  {
    return m_rotation;
  }

  qreal width() const
  {
    return m_width;
  }

  qreal height() const
  {
    return m_height;
  }

private:
  void calculatePolygonDimensions()
  {
    if ( m_vertices == nullptr ) {
      return;
    }

    QPointF point = m_vertices->at( 0 ).toPointF();
    qreal minWidth = point.x();
    qreal maxWidth = point.x();
    qreal minHeight = point.y();
    qreal maxHeight = point.y();
    int count = m_vertices->count();

    for ( int i = 1; i < count; i++ ) {
      point = m_vertices->at( i ).toPointF();
      minWidth = std::min( minWidth,  point.x() );
      maxWidth = std::max( maxWidth,  point.x() );
      minHeight = std::min( minHeight,  point.y() );
      maxHeight = std::max( maxHeight, point.y() );
    }

    m_width = maxWidth - minWidth;
    m_height = maxHeight - minHeight;
  }

private:
  qreal m_xPosition;
  qreal m_yPosition;
  qreal m_width;
  qreal m_height;
  qreal m_rotation;
  QColor m_fillColor;
  QVariantList* m_vertices;




};

