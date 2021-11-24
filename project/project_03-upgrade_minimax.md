# Third project: Building an upgraded version of the minimax() algorithm that is able to play Gomoku



## Aims of this project
* Make a new algorithm `miniscore()` based on the current `minimax()` that
  + can handle more than two players.
  + does the search to a limited (custom) depth.
  + uses a custom and swappable scoring function to evaluate game states where no-one has won yet.
* Build an actual scoring function (or multiple) that
  + acts as a function on a given game state (i.e. only takes the current Board as an input).
  + rewards longer and more unrestricted sequences.
  + takes the opponent's position into account by substracting its score from the own score.
  + is customizable through function arguments.
* Build a new game `freestyle_gomoku.cc` where
  + the board size and winning length are customizable.
  + the players and the algorithms used are customizable.
* Investigate restricting which squares to search on on larger boards.
* Find a system for how to organize and select between different algorithms, scoring functions and scoring parameters.
* Build rudimentary tools to
  + compare/evaluate the playing performance of different algorithm versions (e.g. automated game/tournament).
  + evaluate the time performance / efficiency of different algorithm versions (e.g. internal clocks, calculation step counters)
* Internal Improvements:
  + Make all input functions based on `input_text()`.
  + Make all classes copyable.
  + Make the Group class a proper container for players.



## Objectives
1. Build a rudimentary `miniscore()`.
   * Make a copy of `minimax()` work under a Computer method `miniscore()`.
     + Copy over the `minimax()` internals as well as the `minimax_score()` ones to `miniscore_score()`.
     + Create a new `Algorithm` value and update the Computer constructor.
     + Create `miniscore_test.cc` and copy over the Tic Tac Toe test from `minmax_test.cc`.
     + Make sure every component works under the new name.
   * Introduce a depth limit and a trivial scoring function.
     + In preparation for scoring functions, `Board` needs an `is_full()` method that efficiently checks wether theres no `empty` square left.
       - `bool is_full ()` is implemented by checking wether a private Board object `empty_square_count` is 0.
       - `empty_square_count` gets updated everytime `place()` is executed.
       - Create a new test inside `board_test.cc` to verify `is_full()`'s behaviour.
     + Replace the built-in win-, lose- and full-scores with a scoring function that
       - is a Computer method `score_win()`.
       - yields maximum points in case of victory and zero points else.
       - doesn't care about customizability or swappability yet.
     + Test if `miniscore()` still performs as `minimax()`.
     + Build in a recursive depth counter as a function argument.
       - When level 0 is reached or the board is full, `score_win()` is called.
       - Set the depth argument during construction (customizability comes later).
     + Build a new test inside `miniscore_test.cc` for the depth limit functionality.
       - Use a 5x5 board.
       - Check with Developer Mode if it performs as expected.
   * Make `miniscore()` multi-player capable.
     + Change the return type of `miniscore_score()` to a container holding the scores of all the other players.
     + In the algorithm, the container that contains the biggest overall value corresponds to the largest score and gets returned.
     + Find a way to add the score of the current player considered by `miniscore_score()` and to remove the score of the player considered one depth level above before returning the container.
     + Build a new test inside `miniscore_test.cc` for that multiplayer feature.
       - Use a 6x6 board, 3 players, and a winning length of 3.
       - Adapt Developer Mode inside `miniscore()` to aptly display all player's scores.
       - Check with Developer Mode if the new feature performs as expected.
