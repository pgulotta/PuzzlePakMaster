#include "monochrometangramsiterator.hpp"
#include "model/constants.hpp"


MonochromeTangramsIterator::MonochromeTangramsIterator(const ShapesFactory& shapesFactory, const QString& moniker):
  GameIterator{shapesFactory, moniker} {
  // qDebug() << Q_FUNC_INFO;
}

void MonochromeTangramsIterator::generatePuzzles(QObject* parent) {
  Constants constants;
  qreal unit = mShapesFactory.drawUnit();

  QColor lightYellow{Qt::yellow};
  lightYellow = lightYellow.lighter();

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.43f, unit * 2.09f, 90, lightYellow, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 0.92f, unit * 1.34f, 135,  lightYellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.61f, unit * 2.08f, 180, lightYellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 0.92f, unit * 3.44f, 225, lightYellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.88f, unit * 1.16f, 45, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.60f,  unit * 1.68f, 135, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 0.52f, unit * 2.96f, 90, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 2.94f, unit * 2.21f, 45, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.88f, unit * 3.25f, 135, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.01f, unit * 0.70f, 0, Qt::black, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -0.76f,  unit * 1.44f, 90, Qt::black, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 1.46f, unit * 0.70f, 0, Qt::black, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.46f, unit * 2.20f, 90, Qt::black, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.41f, unit * 2.64f, 45, Qt::black, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));


  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.01, unit * 1.81f, 180, constants.Orange, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.05,  unit * 1.78f, 0,  constants.Orange, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.47f, unit * 3.74f, 225, constants.Orange, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 0.46f, unit * 0.72f, 45,  constants.Orange, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.75f, unit * 1.03f, 45, Qt::darkBlue,  mShapesFactory.verticesList( Shape::Tag::RightTriangle_2), parent ),
    new Piece(unit * 0.75f, unit * 2.02f, 0, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::Square_2x2), parent),
    new Piece(unit * 0.2f, unit * 4.0f, 90, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.25f, unit * 4.0f, 270, Qt::darkBlue, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.50f, unit * 1.72, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 3.07f, unit * 1.28 * 1.02f, 0,  Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.51f, unit * 1.72f, 45, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.57f, unit * 1.28f * 1.02f, 90, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.55f, unit * 2.76f, 270, Qt::yellow, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.54f, unit * 2.76f, 90, Qt::yellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 2.98f, unit * 0.05f, 180, Qt::darkMagenta, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.0f,  unit * 3.0f, 0,  Qt::darkMagenta, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.07f, unit * 4.94f, 225,  Qt::darkMagenta, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.03f, unit * 6.22f, 315,  Qt::darkMagenta, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 2.5f, unit * 6.22f, 315,  Qt::darkMagenta, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 3.94f, unit * 6.22f, 315,  Qt::darkMagenta, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece( unit * 1.59f, unit * 0.52f, 45, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.15, unit * 1.57f, 0, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 2.64f, unit * 1.57f, 90, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.18f, unit * 1.57f, 270, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.92f, unit * 3.05f, 0, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.15f, unit * 4.54f, 0, Qt::darkCyan, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.11f, unit * 4.56f, 180, Qt::darkCyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.24f, unit * 0.20f, 0,  Qt::black, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * -0.24f, unit * 1.68f, 0,  Qt::black, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -0.99f, unit * 2.41f, 90,  Qt::black, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit *  0.37f, unit * 3.16f, 45,  Qt::black, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit *  2.75f, unit * 0.82f, 315,  Qt::black, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit *  1.68f, unit * -0.85f, 225,  Qt::black, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit *  1.24f, unit *  0.19f, 270,  Qt::black, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.11f, unit * 0.49f, 45, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 0.35f, unit * 2.93f, 45, constants.DeepRed, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.80f, unit * 1.86f, 225, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * -0.25f, unit * 4.42f, 0, constants.DeepRed, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.07f, unit * 3.66f, 225, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -0.93f, unit * 7.03f, 90, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 0.42f, unit * 8.39f, 45, constants.DeepRed, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.11f, unit * 0.61f, 90, Qt::darkBlue, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.86f, unit * 0.61f, 0, Qt::darkBlue, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.09f, unit * 2.84f, 45, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 3.14f, unit * 2.88f, 45, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.13f, unit * 2.88f, 225, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.51f,  unit * 4.61f, 135, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 2.52f, unit * 4.83f, 45, Qt::darkBlue, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 2.85f, unit * .86f, 45, Qt::white, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.5f,  unit * 3.74f, 90, Qt::white, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 2.85f, unit * 2.99f, 135,  Qt::white, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * .01f, unit * 2.7f, 45, Qt::white, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 5.1f, unit * 2.7f, 45, Qt::white, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 2.57f,  unit * 3.7f, 180, Qt::white, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 2.85f, unit * 5.06f, 225, Qt::white, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 3.5f, unit * 0.33f, 45, constants.Purple, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.5f, unit * 1.08f, 0, constants.Purple, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 2.75f, unit * 3.2f, 315, constants.Purple, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.02f, unit * 2.5f, 135, constants.Purple, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 0.64f,  unit * 5.3f, 135, constants.Purple, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.13f, unit * 6.8f, 180, constants.Purple, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.45f, unit * 4.95f, 315,  constants.Purple, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.26f, unit * 0.32f, 90, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.24f, unit *  0.32f, 0,  constants.Brown, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 2.72f, unit *  0.32f, 0, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.51f, unit * 1.80f, 0, constants.Brown, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.52f, unit * 1.77f, 180, constants.Brown, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.28f, unit * 4.77f, 0, constants.Brown, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 0.22f, unit * 5.20f, 45, constants.Brown,  mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 3.92f, unit * 2.43f, 135, Qt::gray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 3.5f, unit * 0.51f, 270, Qt::gray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.5f, unit * 2.01f, 0, Qt::gray, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 3.48f, unit * 3.5f, 0, Qt::gray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 2.74f, unit * 4.22f, 90, Qt::gray, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 0.5f, unit * 0.5f, 180, Qt::gray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.5f, unit * 3.5f, 90, Qt::gray, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  // 9
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.65f, unit * 0.98f, 45, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.04f, unit * 2.47f, 0, Qt::darkGreen, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 0.06f,  unit * 3.97f, 0, Qt::darkGreen, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 2.76f, unit * 3.08f, 315, Qt::darkGreen, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.44f, unit * 1.72f, 225, Qt::darkGreen, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 2.43f, unit * 5.93f, 135, Qt::darkGreen, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.07f, unit * 5.62f, 180, Qt::darkGreen, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  // 8
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 0.15f, unit * 0.86f, 135, constants.Amber, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 0.19f, unit * 2.12f, 90, constants.Amber, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.12f, unit * 1.07f, 135, constants.Amber, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 0.75f, unit * 3.73f, 45, constants.Amber, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.45f, unit * 4.48f, 0, constants.Amber, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 3.19f, unit * 4.5f, 270, constants.Amber, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.06f, unit * 4.47f, 225, constants.Amber, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  // 7
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.33f, unit * 1.77f, 0, Qt::red, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * -0.32f, unit * 0.27f, 180, Qt::red, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.18f, unit  * 0.27f, 270, Qt::red, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.18f, unit * 0.28f, 90, Qt::red, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.61f, unit * 2.14f, 135, Qt::red, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.93f,  unit * 3.93f, 90, Qt::red, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 1.18f, unit * 4.66f, 180, Qt::red, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
  }, parent)));

  // 6
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.52f, unit * 0.40f, 0, Qt::magenta, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 0.78f, unit * 0.73f, 315, Qt::magenta, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -1.01f, unit * 2.12f, 135, Qt::magenta, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.72f,  unit * 2.75f, 0, Qt::magenta, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 3.24f, unit * 4.24f, 0, Qt::magenta, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 0.81f, unit * 4.98f, 45, Qt::magenta, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.12f, unit * 4.20f, 225, Qt::magenta, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
  }, parent)));
  // 5
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 2.39f, unit * -0.23f, 225, Qt::darkYellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * -0.02f,  unit * 0.52f, 0, Qt::darkYellow, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * -0.01f, unit * 0.53f, 270, Qt::darkYellow, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.99f, unit * 2.55f, 90, Qt::darkYellow, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.18f, unit * 4.8f, 45, Qt::darkYellow, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 2.12f, unit * 5.86f, 45, Qt::darkYellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 0.75f, unit * 4.05f, 225, Qt::darkYellow, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
  }, parent)));

  // 4
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -1.06f,  unit * 0.55f, 90, constants.Pink, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 0.12f, unit * 1.74f, 315, constants.Pink, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * -0.30f, unit * 2.81f, 270, constants.Pink, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.17f, unit * 4.30f, 90, constants.Pink, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.68f, unit * 2.81f, 0, constants.Pink, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 4.17f, unit * 4.30f, 0, constants.Pink, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 2.7f, unit * 5.81f, 270, constants.Pink, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));


  // 3
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.72f,  unit * 0.53f, 90, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 1.53f, unit * -0.21f, 0, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * -0.01f, unit * 4.00f, 270, constants.Indigo, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.47f, unit * 3.39f, 135, constants.Indigo, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.95f, unit * 0.2f, 135, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 2.29f, unit * 1.99f, 315, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.48f, unit * 5.52f, 90, constants.Indigo, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  // 2
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * -0.10f,  unit * 0.57f, 135, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1), parent),
    new Piece(unit * 2.21f, unit * 0.66f, 45, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.03f, unit * 1.38f, 180, Qt::darkGray, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * -0.03f, unit * 4.38f, 0, Qt::darkGray, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.42f, unit * 6.30f, 45, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.47f, unit * 5.86f, 90, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 2.97f, unit * 5.86f, 270, Qt::darkGray, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  // 1
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece( unit * 0.55f,  unit * 0.54f, 45, Qt::green, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 1.27, unit * 0.23f, 90, Qt::green, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 1.60f, unit * 1.60f, 315, Qt::green, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 1.36f, unit * 2.14f, 45, Qt::green, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * -0.20f, unit * 2.98f, 135, Qt::green, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 0.82f, unit * 6.19f, 45, Qt::green, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 2.63f, unit * 4.82f, 315, Qt::green, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));

  // 0
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Pieces{
    new Piece(unit * 1.51f, unit * 0.95f, 45, Qt::cyan, mShapesFactory.verticesList(Shape::Tag::Square_1_5x1_5), parent),
    new Piece(unit * 0.25f, unit * 2.5f, 45, Qt::cyan, mShapesFactory.verticesList(Shape::Tag::Parallelogram_2x1_5), parent),
    new Piece(unit * 2.27f, unit * 0.66f, 90, Qt::cyan, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 1.22f, unit * 3.73f, 270, Qt::cyan, mShapesFactory.verticesList( Shape::Tag::RightTriangle_Large), parent),
    new Piece(unit * 3.49f, unit * 4.94f, 225, Qt::cyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
    new Piece(unit * 3.16f, unit * 3.58f, 180, Qt::cyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Medium), parent),
    new Piece(unit * 3.48f, unit * 2.83f, 135, Qt::cyan, mShapesFactory.verticesList(Shape::Tag::RightTriangle_Small), parent),
  }, parent)));
}

