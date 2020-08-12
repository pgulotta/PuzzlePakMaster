#include "shapesfactory.hpp"
#include <QPointF>
#include <QScreen>
#include <QGuiApplication>


using ShapeId = Shape::Tag;


ShapesFactory::ShapesFactory(QObject* parent)  : QObject{parent} {
}

void ShapesFactory::setDrawUnit(qreal drawUnit) {
  m_drawUnit = drawUnit;
  mAcceptableVariance = drawUnit * 0.1f * static_cast<qreal>(QGuiApplication::primaryScreen()->devicePixelRatio());
  qDebug() << Q_FUNC_INFO << " m_drawUnit = " << m_drawUnit << "  mAcceptableVariance" << mAcceptableVariance;
  generateShapes();
}

void ShapesFactory::generateShapes() {
  QObject* parent = this;
  qreal unit = static_cast<qreal>(m_drawUnit);
  qreal zero = 0.0f;
  qreal unitX_1_0_5 = ( m_drawUnit * 1.05f);
  qreal unitX_1_5 = (unit * 1.5f);
  qreal unitX_1_7 = (unit * 1.732f);
  qreal unitX_2_1 = (unit * 2.121f);
  qreal unitX_2 =  (unit * 2.0f );
  qreal unitX_2_5 = (unit * 2.5f);
  qreal unitX_3 =  (unit * 3.0f );

  mShapes.clear();

  mShapes[ShapeId::Parallelogram_2x1] = new Shape( new Vertices{
    new QPointF( zero, zero),
    new QPointF( unitX_2_1, zero),
    new QPointF( unitX_2_1 + unitX_1_0_5, unitX_1_0_5),
    new QPointF( unitX_1_0_5, unitX_1_0_5)}, parent);

  mShapes[ShapeId::EquilateralTriangle_2] = new Shape( new Vertices{
    new QPointF( zero, zero ), new QPointF( unitX_2, zero), new QPointF( m_drawUnit,  unitX_1_7)}, parent);

  mShapes[ShapeId::Rectangle_2x1] = new Shape(  new Vertices{
    new QPointF( zero, zero), new QPointF( unitX_2, zero),
    new QPointF( unitX_2, m_drawUnit), new QPointF( zero, m_drawUnit)}, parent);

  mShapes[ShapeId::Parallelogram_2x1_5] = new Shape( new Vertices{
    new QPointF( zero, zero),
    new QPointF( unitX_1_5, zero),
    new QPointF( unitX_3, unitX_1_5),
    new QPointF( unitX_1_5, unitX_1_5)
  }, parent);

  mShapes[ShapeId::Rectangle_2x1_5] = new Shape(  new Vertices{
    new QPointF( zero, zero), new QPointF( unitX_2, zero),
    new QPointF( unitX_2, unitX_1_5), new QPointF( zero, unitX_1_5) }, parent);

  mShapes[ShapeId::Rhombus_2x2] = new Shape( new Vertices{
    new QPointF( zero, zero), new QPointF( unitX_2, zero),
    new QPointF( unitX_3, unitX_2), new QPointF( m_drawUnit, unitX_2) }, parent);

  mShapes[ShapeId::Rhombus_1x1] = new Shape( new Vertices{
    new QPointF( zero, zero), new QPointF( m_drawUnit, zero),
    new QPointF( unitX_2, m_drawUnit), new QPointF( m_drawUnit, m_drawUnit) }, parent);

  mShapes[ShapeId::Square_1x1] = new Shape(  new Vertices{
    new QPointF( zero, zero), new QPointF( m_drawUnit, zero),
    new QPointF( m_drawUnit, m_drawUnit), new QPointF( zero, m_drawUnit)}, parent);

  mShapes[ShapeId::Square_1_5x1_5] = new Shape(  new Vertices{
    new QPointF( zero, zero), new QPointF( unitX_1_5, zero),
    new QPointF( unitX_1_5, unitX_1_5), new QPointF( zero, unitX_1_5)}, parent);

  mShapes[ShapeId::Square_2x2] = new Shape(new Vertices{
    new QPointF( zero, zero), new QPointF( unitX_2, zero),
    new QPointF( unitX_2, unitX_2), new QPointF( zero, unitX_2)}, parent);

  mShapes[ShapeId::RightTriangle_1] = new Shape(  new Vertices{
    new QPointF( zero, zero),  new QPointF( zero, m_drawUnit), new QPointF( m_drawUnit, zero)}, parent);

  mShapes[ShapeId::RightTriangle_Small] = new Shape(  new Vertices{
    new QPointF( zero, zero),  new QPointF( zero, unitX_1_5), new QPointF( unitX_1_5, zero)}, parent);

  mShapes[ShapeId::RightTriangle_2] = new Shape( new Vertices{
    new QPointF( zero, zero),  new QPointF( zero, unitX_2), new QPointF( unitX_2, zero)}, parent);

  mShapes[ShapeId::RightTriangle_2_5] = new Shape( new Vertices{
    new QPointF( zero, zero),  new QPointF( zero, unitX_2_5), new QPointF( unitX_2_5, zero)}, parent);

  mShapes[ShapeId::RightTriangle_Large] = new Shape( new Vertices{
    new QPointF( zero, zero),  new QPointF( zero, unitX_3), new QPointF( unitX_3, zero)}, parent);

  mShapes[ShapeId::RightTriangle_Medium] = new Shape( new Vertices{
    new QPointF( zero, zero),  new QPointF( zero, unitX_2_1), new QPointF(unitX_2_1, zero)}, parent);

  emit shapesGenerated(m_drawUnit);
}

const Vertices* ShapesFactory::vertices(Shape::Tag tag) const {
  return mShapes.at(tag)->vertices();
}

QVariantList* ShapesFactory::verticesList(Shape::Tag tag)  const {
  return mShapes.at(tag)->verticesList();
}

void ShapesFactory::debugPrintAll() const {
  for (auto pair : mShapes ) {
    qDebug() << "Shape::Id=" << static_cast<qreal>(pair.first);
    std::for_each (pair.second->vertices()->cbegin(), pair.second->vertices()->cend(),
    [](const  QPointF * point) {
      qDebug() << "x=" << point->x() << "  y=" << point->y();
    });
  }
}



