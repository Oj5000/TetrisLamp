# Animated Tetris Lamp Board

This project makes creative use of a commercial Tetris 'Stackable' lamp, whereby a base block (usually the straight piece) lights up when powered and other pieces can be illuminated by stacking on top of each other, provided at least one is stacked on the base block. This product has an irritating flaw in that it easily topples over, making it less appealing to have turned on.

The project uses an Arduino nano to control each lamp made up from two sets of 7 Tetrominos (Tetrominoes?), mounted on a board for display. 

## Electronics

Remove the input powerboard from the base Tetromino. This provides the +5v required to drive all Tetrominos and the Arduino nano.

Connect the Arduino's 5v pin to the 5v rail and one of the ground pins to ground. I make use of an N-channel, logic level MOSFET to drive the Tetromino switching, with the input to the Gate pin of the MOSFET attached to the output of a voltage divider from two of the same resitor values (2.2k). This voltage divider also acts as a pull-down resistor to maintain digital state. The Source pin of the MOSFET should also be connected to ground. The Drain pin should be connected to the ground of the Tetromino.

The Tetromios can then be mounted however you wish.

## Light patterns

The code defines each Tetromino as an output for many of the digital GPIO pins and is allocated a binary ID - this is abstracted away within the Tetromino object. Each Tetromino is then determined to be on or off using bit masking, enabling any combination of Tetromino to be on or off with the same command.

The patterns are simply arrays of bit-mask ID's and time delays.