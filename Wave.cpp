#include "Wave.h"
#include<stdlib.h> 

Wave::Wave() {
    seqLength = 10;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    duration[0] = 500;
    duration[1] = 500;
    duration[2] = 500;
    duration[3] = 500;
    duration[4] = 500;
    duration[5] = 500;
    duration[6] = 500;
    duration[7] = 500;
    duration[8] = 500;
    duration[9] = 500;
    duration[10] = 500;

    tets[0] = 32;
    tets[1] = 40;
    tets[2] = 1;
    tets[3] = 7;
    tets[4] = 272;
    tets[5] = 336;
    tets[6] = 3044;
    tets[7] = 3556;
    tets[8] = 5632;
    tets[9] = 6144;
    tets[10] = 6480;
}