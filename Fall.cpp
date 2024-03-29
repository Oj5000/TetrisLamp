#include "Fall.h"
#include<stdlib.h> 

Fall::Fall() {
    seqLength = 53;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    // Set durations
    for (int i = 0; i < seqLength - 5; i++) {
        duration[i] = 250;
    }

    for (int i = seqLength - 5; i < seqLength - 1; i++) {
        duration[i] = 75;
    }

    duration[seqLength - 1] = 2000;

    tets[0] = 32;

    tets[1] = 4;
    tets[2] = 16;
    tets[3] = 1024;
    tets[4] = 4096; 

    // 4096, 2048
    tets[5] = 4096 + 32;
    tets[6] = 4096 + 8;
    tets[7] = 4096 + 2;
    tets[8] = 4096 + 256;
    tets[9] = 4096 + 8192;
    tets[10] = 4096 + 2048; // 6144

    // 4096, 2048, 512
    tets[11] = 6144 + 8;
    tets[12] = 6144 + 2;
    tets[13] = 6144 + 64;
    tets[14] = 6144 + 128;
    tets[15] = 6144 + 512;

    // 4096, 2048, 512, 128
    tets[16] = 6656 + 32;
    tets[17] = 6656 + 1;
    tets[18] = 6656 + 256;
    tets[19] = 6656 + 64;
    tets[20] = 6656 + 128;

    // 4096, 2048, 512, 128, 8192
    tets[21] = 6784;
    tets[22] = 6784 + 8;
    tets[23] = 6784 + 2;
    tets[24] = 6784 + 256;
    tets[25] = 6784 + 8192;

    // 4096, 2048, 512, 128, 8192, 64
    tets[26] = 14976 + 32;
    tets[27] = 14976 + 1;
    tets[28] = 14976 + 2;
    tets[29] = 14976 + 64; 

    // 4096, 2048, 512, 128, 8192, 64, 1024
    tets[30] = 15040 + 8;
    tets[31] = 15040 + 2;
    tets[32] = 15040 + 256;
    tets[33] = 15040 + 1024;

    // 4096, 2048, 512, 128, 8192, 64, 1024, 256
    tets[34] = 16064 + 32;
    tets[35] = 16064 + 1;
    tets[36] = 16064 + 256;

    // 4096, 2048, 512, 128, 8192, 64, 1024, 256, 16
    tets[37] = 16320 + 32;
    tets[38] = 16320 + 4;
    tets[39] = 16320 + 16;

    // 4096, 2048, 512, 128, 8192, 64, 1024, 256, 16, 2
    tets[40] = 16336 + 8;
    tets[41] = 16336 + 2;

    // 4096, 2048, 512, 128, 8192, 64, 1024, 256, 16, 2, 1
    tets[42] = 16338 + 8;
    tets[43] = 16338 + 1;

    // 4096, 2048, 512, 128, 8192, 64, 1024, 256, 16, 2, 1, 4
    tets[44] = 16339 + 32;
    tets[45] = 16339 + 4;

    // 4096, 2048, 512, 128, 8192, 64, 1024, 256, 16, 2, 1, 4, 8
    tets[46] = 16343 + 8;

    // 4096, 2048, 512, 128, 8192, 64, 1024, 256, 16, 2, 1, 4, 8, 32
    tets[47] = 16351 + 32;

    // Begin classic tetris screen wipe (up)
    tets[48] = 6656;
    tets[49] = 6656 + 9344; // Going up
    tets[50] = 6656 + 9344 + 336;
    tets[51] = 6656 + 9344 + 336 + 7;
    tets[52] = 6656 + 9344 + 336 + 7 + 40;
}