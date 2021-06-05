# First project: Building the core game from the ground up

## Aims of this project
* being able to play a whole game of gomoku on the command line by starting one program
* only human/human play for now, 2 players taking turns
* build in capability for more than 2 players
* with variable sized text based board and coordinate system
* place stones by entering coordinates
* declare a victor when a sequence of stones of length k is reached
* set up the beginning of the project folder structure


## Objectives
1. create a basic board class 
    * consisting of an array
    * with a set of symbols as possible values
        * by default it consists of "empty" symbols
    * squares are adressable via coordinates
    * output operator printing the current board

2. create a basic player class
    * that assign a new symbol to a new player instance
    * that can interactively place a "stone" (player symbol) on the board
    * that prints the board after placing a stone

3. increase robustness for accessing squares and placing stones
    * create a Board method inside() that checks if coordinates are pointing to squares within the board
    * make the Board method at() read-only
    * create a Board method place() which places a stone on the board at a coordinate
        * update the board test to use board.place()
        * update the Player method make_move() to use board.place() instead and check if the intended square is already occupied by another stone
    * create an input function which forces the user to enter integers and otherwise repeats the input request
        * update the test files to use that robust input function
        * update the player method make_move to include that function
    * make a descriptive template test file
    * check where making function arguments to const works