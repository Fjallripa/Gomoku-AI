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
3. Build the basic infrastructure around algorithm tests.
   * Build a new set of tests to stress-test the algorithms.
     + For `placeholder()`, use a 4x4 board and 4 players of which 2 are computers.
       - Passing the test would require that the function can place a stone at the next empty square in every situation and always return safely.
     + For `minmax()`, use a 3x3 board as well.
       - Passing the test would require that the function always can place stones and that it (in this Tic Tac Toe scenario) always plays the optimal move and never loses.
   * Find ways to improve the testing of the algorithms 
     - Eg. add a toggle somewhere to enable verbose developer logs.
       + These could tell about how the algorithm scores different options or which moves it considered.
     - Eg. find a way to make timing tests of the algorithms.

2. Build the basic infrastructure around algorithms.
   * Update all the other tests to the new test design language, including the `test_template.cc`.
   * Find a simple way to set the board size (quadratic) when constructing a board object.
     + Set the player_tests to a 5x5 board.
     + Set the minimal_game to a 30x30 board.
   * Make the algorithm of `Computer` choosable at its construction.
     + Make the current `Computer` placeholder algorithm a public member function `placeholder()` returning a square.
     + Find a way to make the algorithm choosable by adding a paramater to the `Computer` constructor.
       - Ideally, include the ability to provide the algorithm with custom arguments.
       - These could then be used for example to set weights or toggle certain aspects of the algorithm.
     + Build a new minmax algorithm `minmax()` that only uses win and loss as a scoring function.
       - Create a separate scoring function that only rewards a win.
       - Find a place to put that function. 

1. Make `Computer` a derived class of `Player`.
   * For clarity, also define `Human` as a derived class of `Player`.
   * Change `Player::make_move()` to a virtual method that takes in coordinates and handles the execution of the move. The derived methods will only handle coordinate selection and for the move call the base method.
   * For constructors and destructors, refer to the Player ones.
   * Implement different make_move() methods for the derived classes, while Human uses the old make_move() implementation.
   * Give Computer some silly placeholder implementation of make_move() for now. Later, it will call algorithm functions.
   * Change all the test and `minimal_game` to use Human instead of Player. Check if everything works.
     + Are there no problems with Group?
   * Make separate tests for `Player` and `Computer` to see if they are working as intended.
