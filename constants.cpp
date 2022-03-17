#include "constants.h"

int getRandom(int low, int hi){
    return rand()%(hi-low+1)+low;
}
