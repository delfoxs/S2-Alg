#include "Reverser.h"

int Reverser::reverseDigit(int value) {
    if (value < 0)
        return -1;
    else if (value < 10)
        return value;
    else
        return (value % 10) * power(10, digits(value) - 1) + reverseDigit(value / 10);
}

std::string Reverser::reverseString(std::string characters) {
    if (characters.empty())
        return "";
    else
        return reverseString(characters.substr(1)) + characters[0];
}

int Reverser::power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    else
        return base * power(base, exponent - 1);
}

int Reverser::digits(int num) {
    if (num < 10)
        return 1;
    else
        return 1 + digits(num / 10);
}
