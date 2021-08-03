// Implementation of the placeholder() algorithm
// ---------------------------------------------


// Silly placeholder coordinate selection (taking the first empty square available)
Square Computer::placeholder () {
    int x = 0; int y = 0;
    
    while (this->board->at(x, y) != empty) {
        // For testing purposes only
        // cout << "empty check: " << (this->board->at(x, y) != empty) << " at " << "(" << x << "," << y << ")" << endl;
        
        if (x < this->board->length() - 1) {
            x++;
        } else {
            x = 0;
            if (y < this->board->length() - 1) {
                y++;
            } else {   // In case there is no empty place left on the board.
                return Square(this->board, -1, -1);   // Illegal move, will be caught and not executed by Computer::make_move().
            }
        }
    }
    
    return Square(this->board, x, y);
}
