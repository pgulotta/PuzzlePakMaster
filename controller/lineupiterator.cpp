#include "lineupiterator.hpp"
#include "model/constants.hpp"


LineUpIterator::LineUpIterator(const ShapesFactory& shapesFactory, const QString& moniker):
  GameIterator{shapesFactory, moniker} {
  //qDebug() << Q_FUNC_INFO;
}

void LineUpIterator::generatePuzzles(QObject* parent) {
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
                                                        new Colors{"green", "red", "blue"}, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
                                                        new Colors{"green", "yellow", "cyan"}, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
                                                        new Colors{"red", "blue", "white"}, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
                                                        new Colors{"white", "lightGray", "darkGray"}, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
                                                        new Colors{"black", "darkMagenta", "darkCyan"}, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
                                                        new Colors{ "green", "red", "red", "red"}, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "blue",
    "blue",
    "red",
    "red",
  }, parent)));
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "black",
    "yellow",
    "yellow",
    "black",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "darkCyan"
    "darkgoldenrod",
    "cyan",
    "darkCyan"
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "cyan",
    "red",
    "green",
    "yellow",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "yellow",
    "blue",
    "green",
    "red",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "black",
    "yellow",
    "blue",
    "red",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "white",
    "white",
    "blue",
    "blue",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "black",
    "darkGreen",
    "darkBlue",
    "darkMagenta",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "green",
    "red",
    "green",
    "red",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "blue",
    "blue",
    "white",
    "white",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "white",
    "black",
    "white",
    "black",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "darkRed",
    "darkRed",
    "sandybrown",
    "darkRed",
    "darkRed",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "black",
    "darkMagenta",
    "darkMagenta",
    "darkMagenta",
    "black",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "green",
    "red",
    "white",
    "yellow",
    "black",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "darkRed",
    "darkCyan"
    "darkGray",
    "darkgoldenrod",
    "darkMagenta",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "darkgoldenrod",
    "darkgoldenrod",
    "yellow",
    "darkgoldenrod",
    "darkgoldenrod",
  }, parent)));
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "white",
    "black",
    "white",
    "black",
    "white",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "black",
    "yellow",
    "red",
    "green",
    "red",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "yellow",
    "cyan",
    "cyan",
    "yellow",
    "cyan",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "green",
    "green",
    "yellow",
    "yellow",
    "green",
    "green",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "white",
    "red",
    "blue",
    "white",
    "red",
    "blue",
  }, parent)));
  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "green",
    "red",
    "blue",
    "green",
    "yellow",
    "cyan",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "white",
    "white",
    "blue",
    "white",
    "blue",
    "blue",
  }, parent)));

  mPuzzles.push_back(std::shared_ptr<Puzzle>(new Puzzle(GameIterator::createUniqueId(), Puzzle::SkillLevel::Easy,
  new Colors{
    "black",
    "darkRed",
    "darkGreen",
    "darkgoldenrod",
    "darkBlue",
    "darkMagenta",
  }, parent)));


}
