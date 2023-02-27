#include "Wave.h"
#include<stdlib.h> 

Wave::Wave() {
    seqLength = 8;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    duration[0] = 120;
    duration[1] = 120;
    duration[2] = 120;
    duration[3] = 120;
    duration[4] = 120;
    duration[5] = 120;
    duration[6] = 120;
    duration[7] = 120;

    tets[0] = 40; // Top

    tets[1] = 7; // Going down
    tets[2] = 336;
    tets[3] = 9344;

    tets[4] = 6656; // Bottom

    tets[5] = 9344; // Going up
    tets[6] = 336;
    tets[7] = 7;

}