#include <iostream>
#include <vector>

// Include your function definition here
#include "klargest.cpp"

int main() {
    std::vector<int> values = {3, 2, 1, 5, 6, 4};
    int k = 2;
    std::cout << "The " << k << "th largest element is " << kth_largest(values, k) << std::endl;
    return 0;
}
