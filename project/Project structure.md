## Finding a suitable file and folder structure for the project

### Breaking down the old structure
Looking at vagabunden_schach_v1_2.cc:

* libraries
* constants/parameters

* board class, tile class
* extra board & tile output methods

* "available move check" method
* score functions
* best move function

* Player, Human, Computer classes

* main()-function
    * player setup
    * game menu & game modes
    * game
    * (benchmark)


    
### Idea for a folder structure
```
* game/
    * compiled programs/   (now compiled/)
    * parameters/
    * board/               (-)
    * players/             (-)
    * scoring/
    * algorithms/
    * game/                (now structures/)
    * assembly/            (now games/)
```
