# Gomoku-AI



## What this project is about
Gomoku-AI is a personal learning project to 
* build a comand-line-based Gomoku-like game (multiplayer m,n,k-game) with human as well as computer players, and around it 
* create an algorithm development platform for various game board algorithms including (hopefully) machine learning ones. It also serves to
* gather experience on larger-scale software development, version control and project management.

<img width="529" alt="Example of playing this game" src="https://user-images.githubusercontent.com/58792390/123403884-290f7400-d5a9-11eb-8216-c31f19d29950.png">
Example of playing on a 30x30 board with the goal to build a straight line of 5 symbols.



## [Roadmap](https://github.com/Fjallripa/Gomoku-AI/blob/main/project/Roadmap.md) (summary)


### [Completed](https://github.com/Fjallripa/Gomoku-AI/releases)

* 2021-10: [Tic Tac Toe](https://github.com/Fjallripa/Gomoku-AI/releases/tag/v1.0)
  + 3x3 board, 2 players (optionally computer players)
  + Computer players use the minimax algorithm. They cannot lose.
  + Internally: Now supports many algorithms and game variations.

* 2021-06: [Core Game](https://github.com/Fjallripa/Gomoku-AI/releases/tag/v0.1)
  + Text-based Gomoku-like game. Played by inputting coordinates.
  + 30x30 board, 3 human players
  + Internally: functionality neatly separated into classes, tests for all features
  

### Upcoming features
* limited-depth minimax with scoring function
* Core game expansion with computer players and new algorithm


### Longer-term plans
* gradient descent search for optimal scoring function
* alpha-beta-pruning algorithm
* remembering already calculated moves


### Whishlist
* real machine learning algorithms
