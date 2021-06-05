#include "board.hh"

Board::Board () {
    board.fill(empty);
}


bool Board::inside (const int x, const int y) const {
    return (x >= 0 and x < edge_length
        and y >= 0 and y < edge_length);
}


Symbol Board::at (const int x,const int y) const {
    return this->board.at(edge_length * y + x);
}


bool Board::place (const int x, const int y, const Symbol symbol) {
    bool is_on_board = this->inside(x, y);
    if (is_on_board) {
        this->board.at(edge_length * y + x) = symbol;
    }
    return is_on_board;
}


std::ostream& operator<< (std::ostream& out, const Board& board) {
    out << endl;
    // The output has a coordinate system 
    // with the x-axis (col) increasing from left to right 
    // and the y-axis (row) increasing from bottom to top.
    for (int row = edge_length - 1; row >= 0 ; row--) {
        for (int col = 0; col < edge_length; col++) {
            out << " " << board.at(col, row);
        }
        out << endl;
    }
    out << endl;

    return out;
}
