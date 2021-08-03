// Implementation of the Player-derived Computer class
// ---------------------------------------------------



// Constructor & Destructor
Computer::Computer (Board& board, const Symbol stone, const Algorithm algorithm) : Player (board, stone) {
    switch (algorithm) {
        case Algorithm::placeholder: this->algorithm_used = &Computer::placeholder; break;
        case Algorithm::minmax     : this->algorithm_used = &Computer::minmax;      break;
        
        default: cout << "Error when constructing a Computer object. "
                      << "This 'algorithm' argument hasn't been assigned yet." << endl; break;
    }
}

Computer::Computer (Board& board, const Symbol stone) : Player (board, stone) {
    *this = Computer(board, stone, Algorithm::placeholder);
}



// Actions on instances
void Computer::make_move () {
    // Making the coordinate selection
    Square chosen = (this->*algorithm_used) ();
    int x = chosen.x(); int y = chosen.y();
    if (x == -1 and y == -1) {   // In case the board is full and no further move can be made.
        return;
    }

    // Executing the move. Done by Player.
    cout << this->stone() << " at (" << x << "," << y << ")" << endl; 
    this->place_stone(x, y);
}
