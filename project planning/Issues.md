# Known and potential issues

* board.at() doesn’t check if coordinates are valid.
    * ? What to do in that case?

* group.pop() is not well tested.
    * Risk of unknown issues arising should there be more group action in the future than building a group and circling through players during the game.

* input_coord() goes into an infinite loop when one presses Ctrl-D.
    * ? How should the correct behaviour look like?