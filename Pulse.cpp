#include "Pulse.h"
#include<stdlib.h> 

Pulse::Pulse() {
    seqLength = 6;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    duration[0] = 2000;
    duration[1] = 1000;
    duration[2] = 2000;
    duration[3] = 1000;
    duration[4] = 2000;
    duration[5] = 1000;

    tets[0] = 0xFFFF;
    tets[1] = 0;
    tets[2] = 0xFFFF;
    tets[3] = 0;
    tets[4] = 0xFFFF;
    tets[5] = 0;
}