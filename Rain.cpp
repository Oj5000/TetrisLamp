#include "Rain.h"
#include<stdlib.h> 

Rain::Rain() {
    seqLength = 12;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    duration[0] = 350;
    duration[1] = 350;
    duration[2] = 350;
    duration[3] = 350;
    duration[4] = 350;
    duration[5] = 350;
    duration[6] = 350;
    duration[7] = 350;
    duration[8] = 350;
    duration[9] = 350;
    duration[10] = 350;
    duration[11] = 350;
    duration[12] = 350;

    tets[0] = 32;
    tets[1] = 36;
    tets[2] = 20;
    tets[3] = 24;
    tets[4] = 42;
    tets[5] = 289;
    tets[6] = 8449;
    tets[7] = 8704;
    tets[8] = 2560;
    tets[9] = 8;
    tets[10] = 10;
    tets[11] = 66;
    tets[12] = 192;
}