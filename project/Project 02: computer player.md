# Second project: Build a perfect TicTacToe computer player
  
## Aims of this project 
* Make `Computer` a derived class of `Player` that has another `make_move()` method using an algorithm to determine its next move.
* Build a minmax algorithm that only uses win and loss as a scoring function.
    + Keep in mind the need to in principle function for a variable sized board and more than two players.
* Build the basic project structures around algorithms and scoring functions.
* Adapt tests and a new game to handle the Computer player.
    + If possible, test individual parts of the algorithm and scoring function to quickly detect bugs.
    + Make at least one test demonstrating how the Computer player cannot fail at TicTacToe.
* Find a way to analyze the algorithms performance and to debug it.
    + Build basic tools for analyzing how fast the algorithm is, both in terms of time and steps.
    + Also build a basic tool for looking into how the algorithm scores different options and chooses between them.


## Objectives
1. Make `Computer` a derived class of `Player`.
   * For clarity, also define `Human` as a derived class of `Player`.
   * Change `Player::make_move()` to a virtual method that takes in coordinates and handles the execution of the move. The derived methods will only handle coordinate selection and for the move call the base method.
   * For constructors and destructors, refer to the Player ones.
   * Implement different make_move() methods for the derived classes, while Human uses the old make_move() implementation.
   * Give Computer some silly placeholder implementation of make_move() for now. Later, it will call algorithm functions.
   * Change all the test and `minimal_game` to use Human instead of Player. Check if everything works.
       + Are there no problems with Group?
   * Make separate tests for `Player` and `Computer` to see if they are working as intended.




Ideas: (temporary)

* Player declared as usual
  * but `private` is now `protected` so that its elements are accessible to derived classes
  * and `make_move()` is ommitted
  * additionally:
    `class Human : public Player`
    `class Computer : public Player`
  * they have to declare their own constructors
    `Human (Board& board, const Symbol stone) : Player (board, stone);
    `Computer (Board& board, const Symbol stone) : Player (board, stone);
  * as well as the `make_move()` method:
    `void make_move ();`

* Implementation of Player methods as usual
  * except for make_move():
    `void Human::make_move () {...}`
    `void Computer::make_move () {...}`


? Do they have to declare friendship to Group as well? (make_move() is not used by Group)
? Has (an empty) `Player::make_move()` to be implemented?
-> Idea: define a `void Player::make_move(int x, int y);` that handles the last, common part of placing the stone and updating `latest_move`.
  + gives Player a meaningful stone placing method for eg. testing purposes
  + compiler can detect difference to derived methods `make_move()`
  + prevents code duplication by handling the common part of actually placing the stone (only coordinate selection differs)