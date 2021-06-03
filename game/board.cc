#include "board.hh"

Board::Board () {
    board.fill(empty);
}


Symbol& Board::at (int x, int y) {
    return board.at(edge_length * y + x);
}


std::ostream& operator<< (std::ostream& out, Board& board) {
    out << endl;
    for (int row = 0; row < edge_length; row++) {
        for (int col = 0; col < edge_length; col++) {
            out << " " << board.at(col, row);
        }
        out << endl;
    }
    out << endl;

    return out;
}
