#include "RecursiveBinarySearch.h"

int RecursiveBinarySearch::binarySearch(int list[], int start, int end, int target) {
    if (start <= end) {
        int mid = start + (end - start) / 2;
        if (list[mid] == target) {
            return mid;
        }
        if (list[mid] < target) {
            return binarySearch(list, mid + 1, end, target);
        }
        return binarySearch(list, start, mid - 1, target);
    }
    return -1;
}
