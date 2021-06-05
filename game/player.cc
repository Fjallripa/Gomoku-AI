#include "player.hh"
#include "input.cc"

Player::Player(Board& board, const Symbol stone) {
    this->board = &board;
    this->stone = stone;
}

void Player::make_move () {
    int x, y = -1;
    while (not board->inside(x, y) or board->at(x, y) != empty) {
        input_coord(x, y);
    }
    board->place(x, y, stone);
    cout << *board;
}