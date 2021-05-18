# Gomoku-AI

## Aims of this project
* devolop and test different gomoku-playing algorithms
* build an interactive and flexible testbed for testing, evaluating and comparing different algorithms


## Whishlist of features
### one program to play gomoku and test gomoku algorithms
  * variable winning lengths
  * variable sized gomoku board
  * rules: freestyle, (m,n,k)-game
  * text based with visible but compact coordinate system
  * interactive (play via placing stones at coordinates)
  * multiple game modes such as person/person, person/computer, computer/computer

### interchangeable algorithms
  * tree-search algorithms
    * simple min-max algorithm
    * alpha-beta-pruning
  * evaluation functions
    * only win or loose yield points (practical for very small boards only)
    * own scores for different board patterns
  * scoring algorithms
    * all legal places are scored
    * only places adjacent to stones are scored (+some rule restricting legal moves)
    * only places relevant to a current move are scored/updated

### debugging and analysis
  * different parts of the program are stored in different files so that they can be used interchangeably and developed independantly
    * eg. different files for the board, the game, the algorithm, the scoring algorithm etc.
  * select different debug tools through terminal arguments when running program
    * toggle for auto/manual next move
    * toggle showing score of current board
    * toggle showing score map of individual moves
    * toggle showing heat map of legal moves
    * tool for manually navigating through evaluation tree and presenting scores there
    * toggle showing calculation time for various subroutines
    * toggle highlighting latest moves

### exciting and unlikely expansions
  * real Gomuku rules or other variations
  * try out machine learning algorithms on this game
  * more than two players in a game (eg. 3- or 4-player gomoku)
