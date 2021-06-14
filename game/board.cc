// Implementation of the Board class
// ---------------------------------



// Constructor & Destructor
Board::Board () {
    board.fill(empty);
}



// Display of internal objects
bool Board::inside (const int x, const int y) const {
    return (x >= 0 and x < edge_length
        and y >= 0 and y < edge_length);
}


Symbol Board::at (const int x,const int y) const {
    return this->board.at(edge_length * y + x);
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
        out << "   ";   // 3 spaces
        for (int col = 0; col < edge_length; col++) {
            out << " ";
            int x_digit_1 = col / 10;
            if (x_digit_1 == 0) {out << " ";}
            else                {out << x_digit_1;}
        }
        out << endl;
        out << "   ";   // 3 spaces
    } else {
        out << "  ";   // 2 spaces
    }

    for (int col = 0; col < edge_length; col++) {
        int x_digit_0 = col % 10;
        out << " " << x_digit_0;
    }
    out << endl << endl;

    return out;
}



// Actions on instances
bool Board::place (const int x, const int y, const Symbol symbol) {
    bool is_on_board = this->inside(x, y);
    if (is_on_board) {
        this->board.at(edge_length * y + x) = symbol;
    }
    return is_on_board;
}