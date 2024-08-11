#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize) {
        return 1;
    }
    
    if (memo.find(numCrates) != memo.end()) {
        return memo[numCrates];
    }
    
    int remainingCrates1 = (numCrates + 1) / 2;
    int remainingCrates2 = numCrates / 2;
    int trucksNeeded1 = numTrucks(remainingCrates1, loadSize);
    int trucksNeeded2 = numTrucks(remainingCrates2, loadSize);
    int result = trucksNeeded1 + trucksNeeded2;
    
    memo[numCrates] = result;
    
    return result;
}
