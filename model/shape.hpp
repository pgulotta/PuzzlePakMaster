#pragma once



#include <QObject>
#include <QString>
#include <QList>
#include <QDebug>
#include <QPointF>

using Vertices = QList<QPointF*>;


class Shape : public QObject {
  Q_OBJECT

 signals:

 public:
  enum class Tag {
    EquilateralTriangle_2,
    Rectangle_2x1,
    Parallelogram_2x1,
    Parallelogram_2x1_5,
    Rectangle_2x1_5,
    Rhombus_2x2,
    Rhombus_1x1,
    Square_1x1,
    Square_1_5x1_5,
    Square_2x2,
    RightTriangle_1,
    RightTriangle_2,
    RightTriangle_2_5,
    RightTriangle_Small,
    RightTriangle_Medium,
    RightTriangle_Large,

  };

  Shape( Vertices* vertices, QObject* parent) :
    QObject{parent},
    m_vertices{vertices} {
    // qDebug() << Q_FUNC_INFO << " called " ;
    m_verticesList = new QVariantList();
    std::for_each(vertices->cbegin(), vertices->cend(),
    [this](const  QPointF * point) {
      m_verticesList->append( *point);
    });

  }

  const Vertices* vertices() const {
    return m_vertices;
  }

  QVariantList* verticesList() const {
    return m_verticesList;
  }

  //  virtual ~Shape()  {
  //    qDebug() << Q_FUNC_INFO << " called " ;
  //  }

 private:
  Vertices* m_vertices;
  QVariantList* m_verticesList;

};
