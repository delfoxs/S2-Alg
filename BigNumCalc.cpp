#include "BigNumCalc.h"
#include <iostream>
#include <algorithm>

BigNumCalc::BigNumCalc() {}

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> bigNum;
    for (char ch : numString) {
        // Convert character to integer and add to list
        bigNum.push_back(ch - '0');
    }
    return bigNum;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    // Handle addition of big numbers
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int carry = 0;

    // Iterate through both lists
    while (it1 != num1.rend() || it2 != num2.rend()) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1;
            ++it1;
        }
        if (it2 != num2.rend()) {
            sum += *it2;
            ++it2;
        }

        // Calculate the new carry and the digit
        carry = sum / 10;
        result.push_front(sum % 10);
    }

    // If there's a remaining carry, add it to the front
    if (carry > 0) {
        result.push_front(carry);
    }

    return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    // Handle subtraction of big numbers
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int borrow = 0;

    // Iterate through both lists
    while (it1 != num1.rend() || it2 != num2.rend()) {
        int diff = borrow;
        if (it1 != num1.rend()) {
            diff += *it1;
            ++it1;
        }
        if (it2 != num2.rend()) {
            diff -= *it2;
            ++it2;
        }

        // Check for borrow and add the result digit
        if (diff < 0) {
            borrow = -1;
            diff += 10;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
    }

    // Remove leading zeros if any
    while (!result.empty() && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    // Only handle multiplication with a single-digit number
    std::list<int> result(1, 0);
    if (num2.size() != 1) {
        return result;
    }

    // Variables for the multiplier and carry
    int multiplier = num2.front();
    int carry = 0;

    // Iterate through num1 in reverse order
    std::list<int>::reverse_iterator it1 = num1.rbegin();
    std::list<int>::reverse_iterator resultIt = result.rbegin();

    // Perform multiplication and carry over
    while (it1 != num1.rend() || carry > 0) {
        int product = carry;
        if (it1 != num1.rend()) {
            product += (*it1) * multiplier;
            ++it1;
        }

        // Calculate the current digit and carry
        if (resultIt == result.rend()) {
            result.push_front(product % 10);
            resultIt = result.rbegin();
        } else {
            *resultIt += product % 10;
        }
        carry = product / 10;

        // Handle carry over for existing digits
        if (carry > 0 && resultIt != result.rend()) {
            if (++resultIt == result.rend()) {
                result.push_front(0);
            }
        }
    }

    // Reverse the result list for the final output
    result.reverse();
    return result;
}
