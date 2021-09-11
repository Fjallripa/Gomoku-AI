// Implementation of the Player class
// ----------------------------------



// Constructor & Destructor

Player::Player (Board& board, const Symbol stone) : 
    board(&board), symbol(stone) {}


Player::~Player () {}



// Display of internal objects

Symbol Player::stone () const {
    return this->symbol;
}


Square Player::last_move () const {
    return this->latest_move;
}


Player* Player::next () const {
    return this->next_player;
}

Player* Player::prev () const {
    return this->previous_player;
}



// Actions on instances

void Player::place_stone (int x, int y) {
    // Executing the move
    this->board->place(x, y, this->stone());
    this->latest_move = Square(this->board, x, y);
    cout << *board;
}


/* Determines if the last move of a Player was a winning move. If so, it also updates the Board's winner value. */
bool Player::is_winner () const {
    
    bool win = this->is_winner(this->last_move());
    if (win) {
        this->board->set_winner(this->stone());
    }
    return win;
}


/* Actual evaluation of winner status. Is made to be player-independant and side effect free to be usable for analysis purposes. */
bool Player::is_winner (Square last_move) const {

    // Checking in each direction if the player has built a sequence of stones long enough to win.
    for (Direction direction : fore_directions) {
        Square square = last_move;
        int sequence_length = 1;   // last_move starts the sequence.
        bool inside_board = true;

        // Count how long the sequence extends in the fore direction.
        while (sequence_length < this->board->winning_length()) {
            inside_board = square.go(direction);
            if (not inside_board) {
                square.go(direction, -(sequence_length - 1));    // go back to square one.
                break;
            }
            if (square.symbol() != last_move.symbol()) {
                square.go(direction, -sequence_length);   // go back to square one.
                break;
            }
            sequence_length++;
        }

        // Count how long the sequence extends in the back direction.
        while (sequence_length < this->board->winning_length()) {
            inside_board = square.go(direction, -1);
            if (not inside_board or square.symbol() != last_move.symbol()) {
                break;
            }
            sequence_length++;
        }
        
        // For test purposes only.
        //cout << last_move.symbol() << ": " << direction << ", " << sequence_length << endl;

        // If the sequence is long enough, the winner is set.
        if (sequence_length >= this->board->winning_length()) {
            return true;
        }
    }

    // Else, no winner is set.
        return false;
}
