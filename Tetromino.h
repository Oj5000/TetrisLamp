#ifndef TETROMINO_H
#define TETROMINO_H

#include "Arduino.h"
// At the moment I have no idea how the timings will work
class Tetromino
{
  private: 
    unsigned int id; // Int value we will use as a binary value later
    int GPIO_Pin; // Corresponding GPIO pin

  public: 
    Tetromino(int GPIO_Pin, unsigned int id);

    void on(unsigned int val);
    void off(unsigned int val);
};

#endif