#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Move.h"
using namespace std;
class Player {
public:
    virtual Move*makeMove() = 0;
    virtual string getName() = 0;
    virtual ~Player() {}
};

#endif