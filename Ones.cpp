#include "Ones.h"
#include <stdlib.h>
#include "Arduino.h"

Ones::Ones() {
    seqLength = 15;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    unsigned int tet_ids[14] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

    // Set durations
    for (int i = 0; i < seqLength; i++) {
        duration[i] = 250;
    }

    for (int i = 0; i < seqLength; i++) {
      tets[i] = tet_ids[i]-1;
    }

    tets[seqLength-1] = 0xFFFF;
}