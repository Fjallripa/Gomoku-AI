
Computer::Computer (Board& board, const Symbol stone) : Player (board, stone) {}


void Computer::make_move () {
    // Silly placeholder coordinate selection (taking the first empty square available)
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
            } else {   // no empty place left on the board
                return;
            }
        }
    }

    // Executing the move. Done by Player.
    cout << this->stone() << " at (" << x << "," << y << ")" << endl; 
    this->place_stone(x, y);
}
