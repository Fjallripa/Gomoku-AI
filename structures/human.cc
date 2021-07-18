
Human::Human (Board& board, const Symbol stone) : Player (board, stone) {}


void Human::make_move () {
    // Requesting user coordinate input
    int x = -1; int y = -1;
    while (this->board->at(x, y) != empty) {   // while on a square with a stone or outside the board
        std::ostringstream stone_info;
        stone_info << this->stone() << ": ";   // Shows which player is currently making the move.
        input_coord(x, y, stone_info.str());   // safe user input
    }

    // Executing the move. Done by Player.
    this->place_stone(x, y);
}
