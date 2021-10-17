# Gomoku-AI project roadmap



## Vision

* A program where one can play a Gomoku-like game against multiple other people or against computer players (varying from weak to very strong).

* A development platform to build, test, improve and learn about various game board algorithms.

* A coding project to 
  + learn about coding in general, how to build robust and maintainable software platforms, how to efficiently manage a software project and produce results quickly. 
  + learn about different algorithms, how to build and debug them, and how to build debug and performance measurement tools.
  + experiment with implementing, tweaking and debugging machine learning algorithms to learn how to work with them and possibly to create even stronger computer players.



## [Completed](https://github.com/Fjallripa/Gomoku-AI/releases)

* 2021-10: [Tic Tac Toe](https://github.com/Fjallripa/Gomoku-AI/releases/tag/v1.0)
  + Text-based, with keyboard input
  + Menu for choosing human and computer players
  + Minimax algorithm makes computer player play optimally. It cannot lose.
  + Ability to look into the algorithm with Developer Mode
  + Backend: Well organized code base and project structure makes implementing new algorithms or game variations easy.

* 2021-06: [Core Game](https://github.com/Fjallripa/Gomoku-AI/releases/tag/v0.1)
  + Interactive and text-based. Input coordinates to make moves.
  + 30x30 board, 3 players (easily changeable in source code)
  + Backend: 
    - Board, Group, Player and Square classes separate different elements of the game and allow for future upgrades.
    - Tests of all relevant components make the implementations robust.
  


## Upcoming features

* Make a new algorithm based on the current minimax that
  + can handle more than two players.
  + does the search to a limited depth.
  + uses a custom and swappable scoring function to evaluate game states where no-one has won yet.

* Investigate making rules restricting which squares to search on on larger boards.

* Create an expansion of the Core Game with computer players and the new algorithm.

* Miscellaneous/Fixes:
  + Make all input functions based on `input_text()`.



## Longer-term plans

* Implement a method to search for an optimal scoring function by playing computer players with slight variations in their scoring parameters against each other and using a gradient descent algorithm to hone in on a good set of scoring parameters.

* Implement an alpha-beta-pruning algorithm.

* Investigate making an algorithm that stores scores on already investigated squares and only updates those close to where a new move was made.

* Tools for comparing the efficiency of various algorithms/variants.

* Miscellaneous/Fixes:
  + Make the Group class a proper container for players.
  + Make all classes copyable.
  + Make human player inputs reversible as long as the next move hasn't been made.



## Whishlist

* Implement real machine learning algorithms, to learn how to work with them and to possibly build an even stronger computer player.

* Miscellaneous/Fixes:
  + Output that can be deleted
    - E.g. wrong input gets deleted instead of a new line prompt.
    - E.g. old board gets deleted and replaced with the new board.
