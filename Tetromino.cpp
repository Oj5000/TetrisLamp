#include "Tetromino.h"
/**
* Basic class for controlling each Tetromino
*/
Tetromino::Tetromino(int GPIO_Pin, unsigned int id) : 
            id(id), GPIO_Pin(GPIO_Pin) {
  
}

/** Here we use a bitmask to determine if we should turn on.
* For example, if this tetromino has an id of 4, that's 0000 0100 in binary
* If our input val is 12, 0000 1100 we can do a logical AND to determine if it's on.
*                                     0000 1100
*                                  && 0000 0100 
*                                     =========
*                                     0000 0100 i.e. ON
* In this way, we can call the same function for all Tetrominoes with the same values 
* and this code will sort it all out for us
*/
void Tetromino::on(unsigned int val) {
  if (val & id) { // Turn on when asked
    digitalWrite(GPIO_Pin, HIGH);
  } else { // Turn off otherwise
    digitalWrite(GPIO_Pin, LOW);
  }
}

void Tetromino::off(unsigned int val) {
  if (val & id) {
    digitalWrite(GPIO_Pin, LOW);
  }
}