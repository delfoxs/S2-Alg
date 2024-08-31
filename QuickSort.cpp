#include "QuickSort.h"

int QuickSort::choosePivot(int list[], int start, int end) {
    return list[start + (end - start) / 2];
}

int QuickSort::partition(int list[], int start, int end) {
    int pivot = choosePivot(list, start, end);
    while (start <= end) {
        while (list[start] < pivot) {
            ++start;
        }
        while (list[end] > pivot) {
            --end;
        }
        if (start <= end) {
            std::swap(list[start], list[end]);
            ++start;
            --end;
        }
    }
    return start;
}

void QuickSort::quickSort(int list[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(list, start, end);
        quickSort(list, start, pivotIndex - 1);
        quickSort(list, pivotIndex, end);
    }
}

void QuickSort::sort(std::vector<int>& list) {
    quickSort(&list[0], 0, list.size() - 1);
}
