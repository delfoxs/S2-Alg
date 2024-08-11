#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize) {
        return 1;
    } else {
        int remainingCrates1 = (numCrates + 1) / 2;
        int remainingCrates2 = numCrates / 2;
        int trucksNeeded1 = numTrucks(remainingCrates1, loadSize);
        int trucksNeeded2 = numTrucks(remainingCrates2, loadSize);
        return trucksNeeded1 + trucksNeeded2;
    }
}
