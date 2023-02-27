#include "Rain.h"
#include<stdlib.h> 

Rain::Rain() {
    seqLength = 17;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    duration[0] = 100;
    duration[1] = 100;
    duration[2] = 100;
    duration[3] = 100;
    duration[4] = 100;
    duration[5] = 100;
    duration[6] = 100;
    duration[7] = 100;
    duration[8] = 100;
    duration[9] = 100;
    duration[10] = 100;
    duration[11] = 100;
    duration[12] = 100;
    duration[13] = 100;
    duration[14] = 100;
    duration[15] = 100;
    duration[16] = 100;

    // Far left, top to bottom
    tets[0] = 32;
    tets[1] = 36;
    tets[2] = 20;
    tets[3] = 16 + 1024;
    tets[4] = 1024 + 4096;

    // Far right
    tets[5] = 8;
    tets[6] = 10;
    tets[7] = 66;
    tets[8] = 64 + 128;
    tets[9] = 128 + 512;
    tets[10] = 512 + 2048;
    tets[11] = 2048;

    // mid
    tets[12] = 1;
    tets[13] = 257;
    tets[14] = 256 + 8192;
    tets[15] = 8192 + 4096;
    tets[16] = 4096;
}