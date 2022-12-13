#include "RandomTetromino.h"
#include<stdlib.h>
#include <time.h>

RandomTetromino::RandomTetromino() {
    seqLength = 20;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    int srand(time(0));
    int dmax = 1000;
    int dmin = 100;
    int tmax = 0x3FFF;

    for (int i = 0; i < seqLength; i++) {
      duration[i] = rand()%(dmax-dmin + 1) + dmin;
      tets[i] = rand()%(tmax) + 1;
    }

}