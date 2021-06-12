#include "board.hh"



// Implementation of the Board class
// ---------------------------------

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
        out << " ";
        int y_digit_0 = row % 10;
        int y_digit_1 = row / 10;
        if (edge_length > 10) {
            if (y_digit_1 == 0) {out << " ";}
            else                {out << y_digit_1;}
        }
        out << y_digit_0;

        for (int col = 0; col < edge_length; col++) {
            out << " " << board.at(col, row);
        }
        out << endl;
    }
    if (edge_length > 10) {
        out << "   ";   // 3 Zeichen Platz
        for (int col = 0; col < edge_length; col++) {
            out << " ";
            int x_digit_1 = col / 10;
            if (x_digit_1 == 0) {out << " ";}
            else                {out << x_digit_1;}
            
        }
        out << endl;
        out << "   ";   // 3 Zeichen Platz
    } else {
        out << "  ";   // 2 Zeichen Platz
    }
    for (int col = 0; col < edge_length; col++) {
        int x_digit_0 = col % 10;
        out << " " << x_digit_0;
    }
    out << endl << endl;

    return out;
}




// Implementation of the Square class
// ----------------------------------

Square::Square (Board& board, int x, int y) {
    this->board       = &board;
    this->coordinates = {x, y};
}


int Square::x () {
    return this->coordinates[0];
}

int Square::y () {
    return this->coordinates[1];
}


Symbol Square::symbol () {
    return this->board->at(this->x(), this->y());   // Returns symbol at this square.
}


bool Square::go (Direction direction, int steps = 1) {
    int x_new = this->x();
    int y_new = this->y();
    switch (direction) {
        case up:                        y_new += steps; break;
        case upright:   x_new += steps; y_new += steps; break;
        case right:     x_new += steps;                 break;
        case downright: x_new += steps; y_new -= steps; break;
        case down:                      y_new -= steps; break;
        case downleft:  x_new -= steps; y_new -= steps; break;
        case left:      x_new -= steps;                 break;
        case upleft:    x_new -= steps; y_new += steps; break;
        default:        return false;                   break;
    }

    bool still_inside = this->board->inside(x_new, y_new);
    if (still_inside) {   // Only moves to the new square if it is inside the board.
        this->coordinates = {x_new, y_new};
    }
    return still_inside;   // The return value tells if going to the new square worked or not.
}