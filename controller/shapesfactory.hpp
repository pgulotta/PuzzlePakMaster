#pragma once


#include "model/shape.hpp"
#include <QObject>
#include <map>



using Shapes = std::map<Shape::Tag, const Shape*>;


class ShapesFactory : public QObject
{
  Q_OBJECT

signals:
  void shapesGenerated( qreal drawUnit );

public:
  void setDrawUnit( qreal drawUnit ) ;

  explicit ShapesFactory( QObject* parent = nullptr );
  virtual ~ShapesFactory() {}
  const Vertices* vertices( Shape::Tag tag ) const;
  QVariantList* verticesList( Shape::Tag tag ) const ;
  void debugPrintAll() const;

  qreal drawUnit() const
  {
    return m_drawUnit;
  }

  qreal acceptableVariance() const
  {
    return mAcceptableVariance;
  }

private:
  void generateShapes();

  Shapes mShapes;
  qreal m_drawUnit{0.0f};
  qreal mAcceptableVariance{0.0f};


};

