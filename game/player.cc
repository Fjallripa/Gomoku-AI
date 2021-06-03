#include "player.hh"

Player::Player(Board& board, Symbol stone) {
    (*this).board = &board;
    (*this).stone = stone;
}

void Player::make_move () {
    int x, y;
    cin >> x >> y;
    board->at(x, y) = this->stone;
    cout << *board;
}