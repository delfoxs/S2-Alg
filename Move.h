#ifndef MOVE_H
#define MOVE_H

#include <string>
using namespace std;
class Move {
 public:
  virtual string getName() = 0;
  virtual ~Move() {}
};

class Rock : public Move {
 public:
  string getName() override;
};

class Paper : public Move {
 public:
  string getName() override;
};

class Scissors : public Move {
 public:
  string getName() override;
};

class Monkey : public Move {
 public:
  string getName() override;
};

class Robot : public Move {
 public:
  string getName() override;
};

class Pirate : public Move {
 public:
  std::string getName() override;
};

class Ninja : public Move {
 public:
  string getName() override;
};

class Zombie : public Move {
 public:
  string getName() override;
};

#endif