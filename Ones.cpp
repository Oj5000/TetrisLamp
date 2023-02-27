#include "Ones.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

Ones::Ones() {
    seqLength = 20;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    // Set durations
    for (int i = 0; i < seqLength; i++) {
        duration[i] = 250;
    }

    // Randomly selected tets
    srand(time(0));

    // Take advantage of bit id's. We can use 2 ^ x to
    // randomly choose a tetromino.
    for (int i = 0; i < seqLength; i++) {
        tets[i] = pow(2, rand() % 14);
    }

}