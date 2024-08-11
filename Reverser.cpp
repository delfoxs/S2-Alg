#include "Reverser.h"

int Reverser::reverseDigit(int value) {
    if (value < 0) {
        return -1;
    } else if (value < 10) {
        return value;
    } else {
        int lastDigit = value % 10;
        int remainingDigits = value / 10;
        int reversed = reverseDigit(remainingDigits);
        return (lastDigit * pow(10, std::to_string(remainingDigits).length())) + reversed;
    }
}

std::string Reverser::reverseString(const std::string& characters) {
    if (characters.empty()) {
        return "";
    } else if (characters.length() == 1) {
        return characters;
    } else {
        char firstChar = characters[0];
        std::string remainingChars = characters.substr(1);
        std::string reversedRemainingChars = reverseString(remainingChars);
        if (reversedRemainingChars == "ERROR") {
            return "ERROR";
        }
        return reversedRemainingChars + firstChar;
    }
}
