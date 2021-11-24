// Implementation of the miniscore() algorithm
// ===========================================



// Algorithm support constants that need to be shared across miniscore methods.
const int miniscore_winning_score = max_int;
const int miniscore_max_depth     = 4;




//! Change description
/* Basic miniscore algorithm for the Computer class.
Scores each move based on the opponent's optimal countermove. 
The move with the weakest optimal countermove will be chosen. 
The algorithm ensures perfect play but has to explore the entire game tree for that.
Only recommended in cases as simple as Tic Tac Toe. */
Square Computer::miniscore () {
    // Header in Developer Mode
    if (dev_mode_on) {   // Title for list of possible moves.
        cout << "depth " << algorithm_min_depth << ": "
             << this->stone() << "'s scores of its possible moves:" << endl;
    }

    // Initial values
    int x = -1; int y = -1;   // In case, the algorithm is asked to comment on a full board, these illegal coordinates will be caught by Computer::make_move().
    int x_try = x; int y_try = y;
    int best_score = -miniscore_winning_score - 1;   // In its search, the algorithm starts off with the lowest possible assumption. "-1" important here in order to distinguish between the case "garanteed failure" and "full board".

    // Evaluates every move and selects the first best one.
    for (int square_number = 0; square_number < this->board->size(); square_number++) {
        x_try = square_number % this->board->length();
        y_try = square_number / this->board->length();

        if (this->board->at(x_try, y_try) == empty) {
            int current_score = this->miniscore_score(x_try, y_try, this, algorithm_min_depth);
            if (dev_mode_on) {   // Print score for each possible move.
                cout << "(" << x_try << ", " << y_try << "): " << current_score << endl;
            }
            if (current_score > best_score) {   // If the algorithm finds a move that is better than the previous best, it updates its "recommended move".
                best_score = current_score;
                x = x_try; y = y_try;
                if (current_score == miniscore_winning_score) {   // I.e. victory is guaranteed in optimal play.
                    break;   // The algorithm always quits after having found the first best move.
                }
            }
        }
        // In case failure is garuanteed in optimal play, the algorithm picks the first empty square, thereby "giving up".
    }

    // Returns move recommendation as a Square.
    if (dev_mode_on)   cout << endl;   // Making space after the list of possible moves.
    return Square(this->board, x, y);
}



/* miniscore score evaluator. 
Moves recursively down the whole game tree in order to calculate the score of the optimal move. */
int Computer::miniscore_score (int x, int y, Player* player, int current_depth, bool dev_details) {
    int new_depth = current_depth + 1;
    
    // Makes test move to evaluate opponent's optimal score in that scenario.
    this->board->place(x, y, player->stone());   // Make temporary test move. Has to be undone before returning a score.
    Square test_move = Square(this->board, x, y);
    int score;

    // Header in Developer Mode offering an input.
    if (dev_details) {
        cout << "depth " << current_depth << ": "
             << "Hypothetical move of " << player->stone() << " at (" << x << ", " << y << "):" << endl;
        cout << *(this->board);
        
        dev_choice(player->next(), new_depth);
        
        cout << "depth " << new_depth << ": "
             << player->next()->stone() << "'s scores of its possible moves:" << endl;
        if (current_depth == miniscore_max_depth) {
            cout << "Depth limit reached. These scores are based only on the current board." << endl;
        }
        else if (current_depth > miniscore_max_depth) {
            cout << "Depth limit exceeded. No scores are calculated down here." << endl;
        }
    }

    // Evaluating the score of the test move.
    if (current_depth > miniscore_max_depth or
        this->is_winner(test_move) or 
        this->board->is_full()) 
    {   // Checks wether the `test_move` is a winning one for `player`.
        score = score_win(test_move, minimax_winning_score);
    } 
    else {   // If it hasn't won with this move, the algorithm evaluates the best score the opponent can achieve.
        int best_opponent_score = -miniscore_winning_score;   // Again, starting with the lowest assumption.
        bool board_is_full = true;   // If below, now square is found to be empty, this value will remain true.
        int x_try; int y_try;

        // Evaluates every opponent move and selects the first best one.
        for (int square_number = 0; square_number < this->board->size(); square_number++) {
            x_try = square_number % this->board->length();
            y_try = square_number / this->board->length();

            if (this->board->at(x_try, y_try) == empty) {
                // Recursively evaluates opponent's score.
                int opponent_score = this->miniscore_score(x_try, y_try, player->next(), new_depth);
                
                // Prints opponent's score when asked for in Developer Mode.
                if (dev_details) {
                    cout << "(" << x_try << ", " << y_try << "): " << opponent_score << endl;
                }
                
                // Chooses best opponent score.
                best_opponent_score = std::max(best_opponent_score, opponent_score);
                board_is_full = false;
            }
        }

        // The score of the test move is negative that of the optimal countermove.
        score = -best_opponent_score;
    }

    // Offers a second input prompt in Developer Mode.
    if (dev_details) {
        cout << endl;   // Making space after the list of possible moves.
        dev_choice(player->next(), new_depth);
    }

    // Undoes the temporary move and returns its score.
    this->board->place(x, y, empty); 
    return score;
}
