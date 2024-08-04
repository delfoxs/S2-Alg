#include "Human.h"

#include <iostream>

#include "Move.h"

Human::Human(string name) : name(name) {}

Move* Human::makeMove() {
  string moveName;
  cout << "Enter move: ";
  cin >> moveName;

  if (moveName == "Rock")
    return new Rock();
  else if (moveName == "Paper")
    return new Paper();
  else if (moveName == "Scissors")
    return new Scissors();
  else if (moveName == "Monkey")
    return new Monkey();
  else if (moveName == "Robot")
    return new Robot();
  else if (moveName == "Pirate")
    return new Pirate();
  else if (moveName == "Ninja")
    return new Ninja();
  else if (moveName == "Zombie")
    return new Zombie();
  else {
    cerr << "Invalid move! Defaulting to Rock." << endl;
    return new Rock();
  }
}

string Human::getName() { return name; }