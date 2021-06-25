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
7. declare a victor when a sequence of stones of length k is reached
    * create a Player `bool is_winner()` method that checks if the latest stone is part of a k-stone sequence
        - counts the length of an uninterrupted sequence of the player's stones in each of the 8 directions
        - returns true if there's one sequence that exceeds length k
    * to facilitate the sequence search, a new class `Square` is introduced together with an enum type `Direction`
        - the constructor takes in a coordinate and stores it
        - a `Symbol symbol()` method accesses the Board at() method
        - a `bool go(direction, steps=1)` method uses a Direction and optionally a number of steps to change the internal coordinates or return false if the edge of the board is reached.
        - the Direction type contains eight values, one for each direction
        - optionally introduce a new Symbol value `invalid` to be used by functions that return Symbol and sometimes need to communicate that they don't point inside the board anymore.
    * update the game loop to check if the last move made that player a winner
    * implement a Board method that congratulates the winner or declares a draw after the game loop is terminated
    * make the Player is_winner() method update a Board object `Symbol winner` that is later used to declare a winner or draw

6. put the basic game in an own file
    * create new `assembly` folder containing just the game, not any test infrastructure
    * print a title for the game
    * display info about who's turn it is
    * use the latest player test as basis for the game code

5. build a coordinate system and standalone game
    * change the Board output operator to also print the x- and y-axis coordinates below and left to the board
    * the coordinate axes adapt to the size of the board
    * make it capable of displaying two-digit coordinates but use one-digit coordinates when possible

4. create a Group class for Players
    * the group is a double linked circular list of Players
        - this allows the continued circling through players with player->next during the game
        - the group is circular so first->prev is last and the last next is the first
        - adding to the group is always done to the last element (first->prev) updating the respective links
        - the group has a first player and each player refers to the next one and the previous one
    * Players have a link to the previous player and the next one
        - when instantiating a new player, it is added to the group via the group.append() method
        - and its player->prev and player->next pointers are defined
    * a very basic game is created
        - 4 players take turns on a 10x10 board
        - the basic gameplay code performing the player cycling and stone placement is developed
        - a limit to when the board is full is introduced

3. increase robustness for accessing squares and placing stones
    * create a Board method inside() that checks if coordinates are pointing to squares within the board
    * make the Board method at() read-only
    * create a Board method place() which places a stone on the board at a coordinate
        - update the board test to use board.place()
        - update the Player method make_move() to use board.place() instead and check if the intended square is already occupied by another stone
    * create an input function which forces the user to enter integers and otherwise repeats the input request
        - update the test files to use that robust input function
        - update the player method make_move to include that function
    * make a descriptive template test file
    * check where making function arguments to const works

2. create a basic player class
    * that assign a new symbol to a new player instance
    * that can interactively place a "stone" (player symbol) on the board
    * that prints the board after placing a stone
    
1. create a basic board class 
    * consisting of an array
    * with a set of symbols as possible values
        - by default it consists of "empty" symbols
    * squares are adressable via coordinates
    * output operator printing the current board
