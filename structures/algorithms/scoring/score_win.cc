// Implementation of the score_win() scoring method
// ================================================



/* The most basic scoring function. Just regocnizes a winning move and nothing else. */
int Computer::score_win (Square move, int max_score) {
    if (this->is_winner(move))   return max_score;
    else                         return 0;
}
