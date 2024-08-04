#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    std::string playerName;

    // Get player's name
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    // Initialize players and referee
    Human player1(playerName);
    Computer player2;
    Referee referee;

    // Run the game
    char playAgain;
    do {
        // Referee manages the game and determines the winner
        Player* winner = referee.refGame(&player1, &player2);

        if (winner == nullptr) {
            std::cout << "It's a tie!" << std::endl;
        } else {
            std::cout << winner->getName() << " wins!" << std::endl;
        }

        // Ask if players want to play again
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}