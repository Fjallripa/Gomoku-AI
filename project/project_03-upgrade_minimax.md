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
* Investigate restricting which squares to search on on larger boards.
* Find a system for how to organize and select between different algorithms, scoring functions and scoring parameters.
* Build rudimentary tools to
  + compare/evaluate the playing performance of different algorithm versions (e.g. automated game/tournament).
  + evaluate the time performance / efficiency of different algorithm versions (e.g. internal clocks, calculation step counters)
* Internal Improvements:
  + Make all input functions based on `input_text()`.
  + Make all classes copyable.
  + Make the Group class a proper container for players.
