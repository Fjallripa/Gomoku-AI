// Implementation of the minmax() algorithm
// ---------------------------------------------



// Min-Max algorithm
Square Computer::minmax () {
    
    int x = -1; int y = -1;   // In case, the algorithm is asked to comment on a full board, these illegal coordinates will be caught by Computer::make_move().
    int x_try = x; int y_try = y;
    int best_score = -minmax_winning_score - 1;   // In its search, the algorithm starts off with the lowest possible assumption. "-1" important here in order to distinguish between the case "garanteed failure" and "full board".

    for (int square_number = 0; square_number < this->board->size(); square_number++) {
        x_try = square_number % this->board->length();
        y_try = square_number / this->board->length();

        if (this->board->at(x_try, y_try) == empty) {
            int current_score = this->minmax_score(x_try, y_try, this);
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

    return Square(this->board, x, y);
}



/* Min-Max score evaluator. 
Moves recursively down the whole game tree in order to calculate the score of the optimal move. */
int Computer::minmax_score (int x, int y, Player* player) {
    
    this->board->place(x, y, player->stone());   // Make temporary test move. Has to be undone before returning a score.
    Square test_move = Square(this->board, x, y);
    int best_score = -minmax_winning_score;   // In its search, the algorithm starts off with the lowest possible assumption.

    if (this->is_winner(test_move)) {
        best_score = minmax_winning_score;
    } 
    else {   // If it hasn't won with this move, the algorithm evaluates the best score the opponent can achieve.
        int best_opponent_score = 0;   // I.e. no one has won yet.
        int x_try; int y_try;

        for (int square_number = 0; square_number < this->board->size(); square_number++) {
            x_try = square_number % this->board->length();
            y_try = square_number / this->board->length();

            if (this->board->at(x_try, y_try) == empty) {
                int opponent_score = this->minmax_score(x_try, y_try, player->next());
                best_opponent_score = std::max(best_opponent_score, opponent_score);
            }
        }
        best_score = -best_opponent_score;
    }

    this->board->place(x, y, empty);   // Undo the temporary move.
    return best_score;
}
