#include "Arduino.h" // MUST include this if you want access to the arduino functions!! This is auto-imported in .ino files but NOT c/cpp files
#include "RandomTetromino.h"
#include<stdlib.h> 

RandomTetromino::RandomTetromino() {
    seqLength = 20;

    duration = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    tets = (unsigned int*) malloc(seqLength * sizeof(unsigned int));
    
    int dmax = 800;
    int dmin = 100;
    int tmax = 16384;

    for (int i = 0; i < seqLength; i++) {
      duration[i] = random(dmin, dmax);
      tets[i] = random(1, tmax);
    }

}