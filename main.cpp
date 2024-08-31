#include <iostream>
#include <vector>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::vector<int> list;
    int num;
    while (std::cin >> num) {
        list.push_back(num);
    }

    BubbleSort bubbleSort;
    QuickSort quickSort;

    bubbleSort.sort(list);
    quickSort.sort(list);

    int target = 1;
    int result = RecursiveBinarySearch::binarySearch(&list[0], 0, list.size() - 1, target);

    std::cout << (result != -1 ? "true" : "false");
    for (int num : list) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
