#ifndef REVERSER_H
#define REVERSER_H

#include <string>

class Reverser {
public:
    int reverseDigit(int value);
    std::string reverseString(std::string characters);

private:
    int power(int base, int exponent);
    int digits(int num);
};

#endif
