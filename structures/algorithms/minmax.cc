// Implementation of the minmax() algorithm
// ---------------------------------------------



// Algorithm support constants that need to be shared across minmax methods.
const int minmax_winning_score = max_int;



// Min-Max algorithm
Square Computer::minmax () {
    if (dev_mode_on) {   // Title for list of possible moves.
        cout << this->stone() << "'s scores of its possible moves:" << endl;
    }

    int x = -1; int y = -1;   // In case, the algorithm is asked to comment on a full board, these illegal coordinates will be caught by Computer::make_move().
    int x_try = x; int y_try = y;
    int best_score = -minmax_winning_score - 1;   // In its search, the algorithm starts off with the lowest possible assumption. "-1" important here in order to distinguish between the case "garanteed failure" and "full board".

    for (int square_number = 0; square_number < this->board->size(); square_number++) {
        x_try = square_number % this->board->length();
        y_try = square_number / this->board->length();

        if (this->board->at(x_try, y_try) == empty) {
            int current_score = this->minmax_score(x_try, y_try, this);
            if (dev_mode_on) {   // Print score for each possible move.
                cout << "(" << x_try << ", " << y_try << "): " << current_score << endl;
            }
            if (current_score > best_score) {   // If the algorithm finds a move that is better than the previous best, it updates its "recommended move".
                best_score = current_score;
                x = x_try; y = y_try;
                if (current_score == minmax_winning_score) {   // I.e. victory is guaranteed in optimal play.
                    break;   // The algorithm always quits after having found the first best move.
                }
            }
        }
        // In case failure is garuanteed in optimal play, the algorithm picks the first empty square, thereby "giving up".
    }

    if (dev_mode_on)   cout << endl;   // Making space after the list of possible moves.
    return Square(this->board, x, y);
}



/* Min-Max score evaluator. 
Moves recursively down the whole game tree in order to calculate the score of the optimal move. */
int Computer::minmax_score (int x, int y, Player* player, bool dev_details) {
    
    this->board->place(x, y, player->stone());   // Make temporary test move. Has to be undone before returning a score.
    Square test_move = Square(this->board, x, y);
    int score;

    if (dev_details) {
        cout << "Hypothetical move of " << player->stone() << " at (" << x << ", " << y << "):" << endl;
        cout << *(this->board);
        dev_choice(player->next());
        cout << player->next()->stone() << "'s scores of its possible moves:" << endl;
    }

    if (this->is_winner(test_move)) {   // Checks wether the `test_move` is a winning one for `player`.
        score = minmax_winning_score;
    } 
    else {   // If it hasn't won with this move, the algorithm evaluates the best score the opponent can achieve.
        int best_opponent_score = -minmax_winning_score;   // Again, starting with the lowest assumption.
        bool board_is_full = true;   // If below, now square is found to be empty, this value will remain true.
        int x_try; int y_try;

        for (int square_number = 0; square_number < this->board->size(); square_number++) {
            x_try = square_number % this->board->length();
            y_try = square_number / this->board->length();

            if (this->board->at(x_try, y_try) == empty) {
                int opponent_score = this->minmax_score(x_try, y_try, player->next());
                if (dev_details) {   // Print score.
                    cout << "(" << x_try << ", " << y_try << "): " << opponent_score << endl;
                }
                best_opponent_score = std::max(best_opponent_score, opponent_score);
                board_is_full = false;
            }
        }
        if (board_is_full) {   // In case no empty square was found, the board is full and we have a draw.
            best_opponent_score = 0;
        }

        score = -best_opponent_score;
    }

    if (dev_details) {
        cout << endl;   // Making space after the list of possible moves.
        dev_choice(player->next());
    }
    this->board->place(x, y, empty);   // Undo the temporary move.
    return score;
}
