#include "Computer.h"
#include "Move.h"

Move* Computer::makeMove() {
    return new Rock();
}

string Computer::getName() {
    return "Computer";
}