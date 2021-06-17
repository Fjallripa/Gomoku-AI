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
    while (not board->inside(x, y) or board->at(x, y) != empty) {
        std::ostringstream stone_info;
        stone_info << this->stone() << ": ";   // Shows which player is currently making the move.
        input_coord(x, y, stone_info.str());
    }
    board->place(x, y, this->stone());
    this->latest_move = Square(this->board, x, y);
    cout << *board;
}