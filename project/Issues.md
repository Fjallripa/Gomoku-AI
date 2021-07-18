# Known and potential issues





## Mostly solved
* `group.pop()` is not well tested.
    * Risk of unknown issues arising should there be more group action in the future than building a group and circling through players during the game.
    * **Solved:** `test_2()` in `player_test.cc` now tests `group.pop()` manually.
    

* `input_coord()` goes into an infinite loop when one presses Ctrl-D.
    * ? How should the correct behaviour look like?
    * => Ideally, the function would ignore Ctrl-D and reiterate its input prompt.
    * This couldn't be achieved yet. See the code for details.
    * **Partly solved:** program now closes if Ctrl-D is pressed (similar to Ctrl-C).



## Solved
* `board.at()` doesn’t check if coordinates are valid.
    * It now returns an array value only if `board.inside()` is true and otherwise returns the Symbol `outside`.
    * If the calling function doesn't do an `inside()` check, the bug will become obvious once the result is outputted.
