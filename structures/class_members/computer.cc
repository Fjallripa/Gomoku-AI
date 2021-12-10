// Implementation of the Player-derived Computer class
// ===================================================
//     For algorithm (support) methods, see their respective .cc files.



// Algorithm support constants
const int algorithm_min_depth = 1;





// Internal methods
// ----------------

/* Handles the Developer Mode input prompt. */
void Computer::dev_choice (Player* player) {
    this->dev_choice(player, algorithm_min_depth);
}



/* Actual exection of Developer Mode input prompt */
void Computer::dev_choice (Player* player, int depth) {
    while (true) {   // In case of a bad input, the prompt repeats itself.
        // Input prompt
        std::string choice = input_text("> ");
        
        // If Enter was pressed, the game goes on.
        if (choice == "")   break;
        
        // If a coordinate of an empty square was entered, a hypothetical move on that square is done.
        int x; int y; std::istringstream stream(choice);
        if (get_coord(stream, x, y)) {
            if (this->board->at(x, y) == empty) {
                int score;
                if (this->algorithm_used == &Computer::placeholder)   score = 0;
                if (this->algorithm_used == &Computer::minimax)       score = this->minimax_score(x, y, player, true);
                if (this->algorithm_used == &Computer::miniscore) {
                    score = this->miniscore_score(x, y, player, depth, true).front();
                }

                cout << "depth " << depth << ": "
                     << player->stone() << "'s score if it was placed at (" << x << ", " << y << "): " << score << endl;
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





// Constructors
// ------------

/* Default constructor */
Computer::Computer (Board& board, const Symbol stone, const Algorithm algorithm) : Player (board, stone) {
    switch (algorithm) {
        case Algorithm::placeholder: this->algorithm_used = &Computer::placeholder; break;
        case Algorithm::minimax    : this->algorithm_used = &Computer::minimax;     break;
        case Algorithm::miniscore  : this->algorithm_used = &Computer::miniscore;   break;
        
        default: cout << "Error when constructing a Computer object. "
                      << "This 'algorithm' argument hasn't been assigned yet." << endl; break;
    }
}



/* Placeholder constructor (Implicitly assigns `placeholder()` algorithm.) */
Computer::Computer (Board& board, const Symbol stone) : Player (board, stone) {
    *this = Computer(board, stone, Algorithm::placeholder);
}





// Actions on internal objects
// ---------------------------

/* Places the computer player's symbol at a square chosen by its algorithm. */
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
