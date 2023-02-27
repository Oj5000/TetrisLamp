#include "Pulse.h"
#include<stdlib.h> 

Pulse::Pulse() {
    seqLength = 4;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    duration[0] = 1000;
    duration[1] = 500;
    duration[2] = 1000;
    duration[3] = 500;

    tets[0] = 0xFFFF;
    tets[1] = 0;
    tets[2] = 0xFFFF;
    tets[3] = 0;
}