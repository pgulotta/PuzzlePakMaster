#include "tangramsiterator.hpp"
#include "model/constants.hpp"
#include <memory>

TangramsIterator::TangramsIterator(const ShapesFactory& shapesFactory, const QString& moniker):
  GameIterator{shapesFactory, moniker} {
  //qDebug() << Q_FUNC_INFO;
}

void TangramsIterator::generatePuzzles(QObject* parent) {
  Constants constants;
  qreal unit = mShapesFactory.drawUnit();
  QColor darkBlue(Qt::darkBlue);
  QColor darkMagenta(Qt::darkMagenta);

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.44f, unit * 2.09f, 90, Qt::red, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 0.93f, unit * 1.33f, 135,  Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.60f, unit * 2.10f, 180, Qt::magenta, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 0.91f, unit * 3.48f, 225, Qt::white, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent)
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.75f, unit * 1.03f, 45, Qt::blue,  mShapesFactory.verticesList( Shape::Tag::RightTriangle_2), parent ),
    new Piece(unit * 0.75f, unit * 2.02f, 0, Qt::red, mShapesFactory.verticesList(Shape::Tag::Square_2x2), parent),
    new Piece(unit * 0.2f, unit * 4.0f, 90, Qt::blue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.25f, unit * 4.0f, 270, Qt::red, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent)
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.02f, unit * 0.69f, 0, Qt::blue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -0.78f,  unit * 1.45f, 90, Qt::cyan, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 1.48f, unit * 0.70f, 0, Qt::magenta, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.48f, unit * 2.21f, 90, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.41f, unit * 2.66f, 45, Qt::green, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent)
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.89f, unit * 1.14f, 45, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.60f,  unit * 1.68f, 135, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 0.51f, unit * 2.96f, 90, Qt::darkGreen, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 2.95f, unit * 2.21f, 45, Qt::darkMagenta, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.88f, unit * 3.27f, 135, Qt::darkYellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent)
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.94f, unit, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 0.5f, unit * 2.0f * 1.02f, 0, Qt::green, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.94f, unit * 2.46f, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 2.0f, unit * 2.0f * 1.02f, 90, Qt::green, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.5f, unit * 3.45f, 270, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.5f, unit * 3.5f, 90, constants.Amber, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent)
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.45f, unit * 0.13f, -15, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.68f, unit * 1.80f, 0, Qt::blue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 2.00f, unit * 2.55f, 315, Qt::green, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.62f, unit * 2.25f, 315, constants.Orange, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 0.85f, unit * 4.28f, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * -0.72f, unit * 4.54f, 135, Qt::darkRed, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.40f,  unit * 6.66f, 45, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 2.85f, unit * .86f, 45, darkBlue.lighter(130), mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.5f, unit * 3.74f, 90, darkBlue.lighter(160), mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 2.85f, unit * 2.99f, 135,  darkBlue.lighter(200), mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * .01f, unit * 2.7f, 45, darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 5.1, unit * 2.7f, 45, darkBlue, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 2.57f, unit * 3.7f, 180, darkBlue.lighter(180), mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 2.85f, unit * 5.06f, 225, darkBlue.darker(130), mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 3.92f, unit * 2.43f, 135, constants.Orange, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 3.5f, unit * 0.51f, 270, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.5f, unit * 2.01f, 0, Qt::darkRed, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 3.49f, unit * 3.5f, 0, Qt::blue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 2.74f, unit * 4.22f, 90, Qt::darkMagenta, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 0.5f, unit * 0.49f, 180, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.5f, unit * 3.5f, 90, Qt::green, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 2.87f, unit * 0.62f, 0, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * -0.14f, unit * 0.64f, 90, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.03f, unit * 2.88f, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 3.17f, unit * 2.90f, 45, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.13f, unit * 2.92f, 225, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.48f,  unit * 4.64f, 135, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 2.50f, unit * 4.86f, 45, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.24f, unit * 1.20f, 0,  Qt::white, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * -0.24f, unit * 2.68f, 0,  Qt::yellow,  mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -0.99f, unit * 3.41f, 90, Qt::gray, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit *  0.38f, unit * 4.15f, 45,  constants.Amber, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit *  2.76f, unit * 1.82f, 315,  constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit *  1.68f, unit * 0.14f, 225,  Qt::cyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit *  1.24f, unit * 1.19f, 270,  Qt::green, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 2.98f, unit * 0.05f, 180, constants.Indigo.darker(125), mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.0f,  unit * 3.0f, 0, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.07f, unit * 4.93f, 225, darkMagenta.lighter(125), mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.03f, unit * 6.22f, 315, darkMagenta, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 2.5f, unit * 6.22f, 315, darkMagenta, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 3.94f, unit * 6.22f, 315, darkMagenta, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.45f, unit * -0.4f, 225, Qt::gray, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * -0.01f, unit * 2.08f, 45,  Qt::black, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * -0.24f, unit * 3.04f, 135, Qt::white,  mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.46f, unit * 4.11f, 45, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.59f, unit *  4.11f, 90,  Qt::black, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.58f, unit *  2.61f, 0,  Qt::white, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 3.58f, unit *  1.10f, 180, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.59f, unit * 0.50f, 45, Qt::darkMagenta, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.15, unit * 1.57f, 0, Qt::darkGreen, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 2.66f, unit * 1.57f, 90, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.16f, unit * 1.56f, 270, Qt::darkRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.92f, unit * 3.06f, 0, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.15f, unit * 4.56f, 0, Qt::darkGray, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.13f, unit * 4.58f, 180, Qt::darkYellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.34, unit * 0.09f, 325, Qt::red, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 0.6f, unit * 1.38f, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * -0.47f, unit * 2.43f, 135, Qt::white, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.91f, unit * 2.77f, 315, constants.Pink, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * -1.24f, unit * 4.86f, 135, Qt::magenta, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.65f, unit * 6.65f, 315, Qt::cyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.26f, unit * 7.88f, 45, constants.Amber, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.16f, unit * 0.19f, 0, constants.Orange.darker(150), mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.67f, unit * 0.19f, 180, Qt::darkGreen, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.60f, unit * 2.13f, 315, constants.Brown,  mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * -0.67, unit * 4.17f, 45, Qt::darkYellow, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 1.67f, unit * 3.17f, 0, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 0.18f, unit * 4.71f, 270, Qt::gray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.67f, unit * 6.20f, 90, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 3.5f, unit * 0.32f, 45, constants.Amber, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.5f, unit * 1.08f, 0, Qt::darkYellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 2.75f, unit * 3.2f, 315, Qt::darkRed, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.02f, unit * 2.5f, 135, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 0.64f,  unit * 5.3f, 135, constants.Pink, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.13f, unit * 6.8f, 180, Qt::darkMagenta, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.45f, unit * 4.95f, 315,  constants.Indigo, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.74f, unit * 0.30f, 90,  Qt::green, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 2.24f, unit *  0.30f, 0, constants.Amber, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 3.73f, unit *  0.30f, 0,  Qt::cyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.51f, unit * 1.80f, 0, Qt::yellow, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.52f, unit * 1.79f, 180, constants.Orange, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.28f, unit * 4.78f, 0,  constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 1.22f, unit * 5.21f, 45, constants.Pink,  mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.11f, unit * 0.49f, 45, Qt::red, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 0.35f, unit * 2.91f, 45, Qt::cyan, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.80f, unit * 1.86f, 225, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * -0.25f, unit * 4.42f, 0, Qt::green, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.07f, unit * 3.67f, 225, constants.Purple, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -0.93f, unit * 7.06f, 90, constants.Orange, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 0.42f, unit * 8.44f, 45, Qt::blue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  // 9
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.65f, unit * 0.96f, 45, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.04f, unit * 2.48f, 0, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 0.06f,  unit * 4.02f, 0, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 2.76f, unit * 3.09f, 315, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.44f, unit * 1.72f, 225, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 2.43f, unit * 5.95f, 135, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.06f, unit * 5.62f, 180, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  // 8
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.13f, unit * 0.83f, 135, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 0.19f, unit * 2.12f, 90, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.14f, unit * 1.07f, 135, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 0.73f, unit * 3.74f, 45, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.45f, unit * 4.5f, 0, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 3.2f, unit * 4.5f, 270, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.03f, unit * 4.51f, 225, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  // 7
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.33f, unit * 1.74f, 0, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * -0.33f, unit * 0.23f, 180, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.18f, unit * 0.25f, 270, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.21f, unit * 0.23f, 90, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.63f, unit * 2.16f, 135, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.95f,  unit * 3.98f, 90, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 1.21f, unit * 4.74f, 180, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  // 6
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.54f, unit * 0.40f, 0, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 0.78f, unit * 0.72f, 315, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -1.01f, unit * 2.12f, 135, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.73f,  unit * 2.74f, 0, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 3.24f, unit * 4.25f, 0, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 0.81f, unit * 5.0f, 45, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.12f, unit * 4.26f, 225, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  // 5
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 2.4f, unit * -0.23f, 225, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -0.04f,  unit * 0.52f, 0, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * -0.05f, unit * 0.53f, 270, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.99f, unit * 2.55f, 90, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.17f, unit * 4.8f, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 2.1f, unit * 5.86f, 45, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.72f, unit * 4.05f, 225, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  // 4
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -1.09f,  unit * 0.56f, 90, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 0.11f, unit * 1.74f, 315, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * -0.33f, unit * 2.81f, 270, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.18f, unit * 4.31f, 90, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.68f, unit * 2.8f, 0, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 4.18f, unit * 4.31f, 0, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 2.67f, unit * 5.82f, 270, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  // 3
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.73f,  unit * 0.53f, 90, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 1.53f, unit * -0.21f, 0, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * -0.01f, unit * 4.01f, 270, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.50f, unit * 3.39f, 135, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.98f, unit * 0.2f, 135, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 2.28f, unit * 1.99f, 315, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.53f, unit * 5.54f, 90, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  // 2
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.12f,  unit * 0.53f, 135, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 2.20f, unit * 0.64f, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.03f, unit * 1.38f, 180, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * -0.03f, unit * 4.38f, 0, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.44f, unit * 6.30f, 45, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.51f, unit * 5.86f, 90, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.02f, unit * 5.86f, 270, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  // 1
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece( unit * 0.5f,  unit * 0.5f, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.28, unit * 0.18f, 90, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.58f, unit * 1.58f, 315, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.37f, unit * 2.12f, 45, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * -0.21f, unit * 3.0f, 135, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.88f, unit * 6.16f, 45, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.66f, unit * 4.8f, 315, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  // 0
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.5f,  unit * 0.95f, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 0.25f, unit * 2.5f, 45, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 2.3f,   unit * 0.66f, 90, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.22f, unit * 3.75f, 270, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.5f, unit * 4.95f, 225, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.16f, unit * 3.58f, 180, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 3.48f,  unit * 2.8f, 135, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

}

