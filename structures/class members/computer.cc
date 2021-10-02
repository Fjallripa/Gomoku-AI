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


// Internal developer menu
void Computer::dev_choice (Player* player) {
    while (true) {
        std::string choice = input_text("> ");
        
        if (choice == "")   break;
        
        int x; int y; std::istringstream stream(choice);
        if (get_coord(stream, x, y)) {
            if (this->board->at(x, y) == empty) {
                int score = this->minmax_score(x, y, player, true);
                cout << player->stone() << "'s score if it was placed at (" << x << ", " << y << "): " << score << endl;
                cout << *(this->board);
                break;
            } else {
                cout << "Choose an empty square." << endl;
            }
        } else {
            cout << "Press Enter or choose an empty square (\"x y\")." << endl;
        }
    }
}



// Actions on instances
void Computer::make_move () {
    if (dev_mode_on)   dev_choice(this);   // Choose wether to display the scores for all possible moves or to check out one specific move.

    // Making the coordinate selection
    Square chosen = (this->*algorithm_used) ();
    int x = chosen.x(); int y = chosen.y();
    if (x == -1 and y == -1) {   // In case the board is full and no further move can be made.
        return;
    }
    if (this->board->at(x, y) != empty) {
        cout << "Error: The algorithm of this Computer player recommended a to place a stone at (" 
             << x << "," << y << "), but this is not an available square. If you're the developer, please check this out." 
             << endl;
        input_text("Press a key if you want to continue the game. ");
        return;
    }

    if (dev_mode_on)   dev_choice(this);   // Choose wether to proceed or to check out one of the possible moves.

    // Executing the move. Done by Player.
    cout << "Placing " << this->stone() << " at (" << x << "," << y << ")" << endl;
    this->place_stone(x, y);
}
