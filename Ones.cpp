#include "Ones.h"
#include<stdlib.h>
#include<time.h>

Ones::Ones() {
    seqLength = 20;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tet_id = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    tet_id[0] = 1;

    for (int i = 1; i < 14; i++) {
        tet_id[i] = tet_id[i-1] * 2;
    }

    // Set durations
    for (int i = 0; i < seqLength; i++) {
        duration[i] = 250;
    }

    // Randomly selected tets
    srand(time(0));

    for (int i = 0; i < seqLength; i++) {
        tets[i] = tet_id[rand() % 14];
    }

}