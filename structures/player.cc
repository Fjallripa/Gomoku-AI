// Implementation of the Player class
// ----------------------------------



// Constructor & Destructor
Player::Player (Board& board, const Symbol stone) {
    this->board  = &board;
    this->symbol = stone;
}

Player::~Player () {
    this->board = nullptr;
}



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
void Player::make_move () {
    int x = -1; int y = -1;

    // Requesting player coordinate input
    while (not board->inside(x, y) or board->at(x, y) != empty) {
        std::ostringstream stone_info;
        stone_info << this->stone() << ": ";   // Shows which player is currently making the move.
        input_coord(x, y, stone_info.str());
    }

    // Executing the move
    board->place(x, y, this->stone());
    this->latest_move = Square(this->board, x, y);
    cout << *board;
}


bool Player::is_winner () const {
    // Checking in each direction if the player has built a sequence of stones long enough to win.
    for (Direction direction : fore_directions) {
        Square square = this->last_move();
        int sequence_length = 1;   // last_move starts the sequence.
        bool inside_board = true;

        // Count how long the sequence extends in the fore direction.
        while (sequence_length < winning_length) {
            inside_board = square.go(direction);
            if (not inside_board or square.symbol() != this->stone()) {
                square.go(direction, -sequence_length);   // i.e. go back to square one.
                break;
            }
            sequence_length++;
        }

        // Count how long the sequence extends in the back direction.
        while (sequence_length < winning_length) {
            inside_board = square.go(direction, -1);
            if (not inside_board or square.symbol() != this->stone()) {
                break;
            }
            sequence_length++;
        }
        
        // For test purposes only.
        //cout << this->stone() << ": " << direction << ", " << sequence_length << endl;

        // If the sequence is long enough, the winner is set.
        if (sequence_length >= winning_length) {
            board->set_winner(this->stone());
            return true;
        }
    }

    // Else, no winner is set.
        return false;
}