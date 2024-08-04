#include "Referee.h"
#include "Move.h"
#include <vector>

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    if (move1 == move2) {
        delete move1;
        delete move2;
        return nullptr;
    }

    vector<pair<string, string>> rules = {
        {"Rock", "Scissors"},
        {"Scissors", "Paper"},
        {"Paper", "Rock"},
        {"Monkey","Ninja"},
        {"Monkey","Robot"},
        {"Robot","Ninja"},
        {"Robot","Zombie"},
        {"Pirate","Robot"},
        {"Pirate","Monkey"},
        {"Ninja","Pirate"},
        {"Ninja","Zombie"},
        {"Zombie","Pirate"},
        {"Zombie","Monkey"},
    };

    for (const auto& rule : rules) {
        if (move1->getName() == rule.first && move2->getName() == rule.second) {
            delete move1;
            delete move2;
            return player1;
        }
        else if (move1->getName() == rule.second && move2->getName() == rule.first) {
            delete move1;
            delete move2;
            return player2;
        }
    }

    delete move1;
    delete move2;
    return nullptr;
}