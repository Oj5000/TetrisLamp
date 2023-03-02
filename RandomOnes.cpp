#include "RandomOnes.h"
#include <stdlib.h>
#include "Arduino.h"

RandomOnes::RandomOnes() {
    seqLength = 30;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    unsigned int tet_ids[14] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

    for (int i = 0; i < seqLength; i++) {
        duration[i] = 200;
        tets[i] = tet_ids[(unsigned int)random(0, 15)];
    }
}