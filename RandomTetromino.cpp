#include "RandomTetromino.h"
#include <stdlib.h>
#include <time.h>

RandomTetromino::RandomTetromino() {
    seqLength = 20;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));

    srand(time(0));
    
    int dmax = 800;
    int dmin = 100;
    int tmax = 16383;

    for (int i = 0; i < seqLength; i++) {
      duration[i] = (rand() % dmax) + dmin;
      tets[i] = (rand() % tmax) + 1;
    }

}