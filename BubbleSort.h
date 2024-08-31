#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sort.h"

class BubbleSort : public Sort {
public:
    void sort(std::vector<int>& list) override;
};

#endif
