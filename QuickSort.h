#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"

class QuickSort : public Sort {
private:
    int choosePivot(int list[], int start, int end);
    int partition(int list[], int start, int end);
    void quickSort(int list[], int start, int end);

public:
    void sort(std::vector<int>& list) override;
};

#endif
