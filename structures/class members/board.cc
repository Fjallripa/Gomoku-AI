// Implementation of the Board class
// ---------------------------------



// Constructor & Destructor
Board::Board (const int edge_length,  int winning_length) {
    bool good_edge_length    = edge_length > 0  and  edge_length <= max_board_length;
    bool good_winning_length = winning_length > 0  and  winning_length <= edge_length;

    if (good_edge_length and good_winning_length) {
        this->board_length = edge_length;
        this->board_size  = edge_length * edge_length;
        this->length_of_winning_sequence = winning_length;
        board_array.fill(empty);

    } else {
        if (not good_edge_length) {
            cout << "The board must be between 1x1 and 100x100 squares." << endl;
        }
        if (not good_winning_length) {
            cout << "The length of the winning sequence must be set between 1 and the edge length of the board." << endl;
        }
        cout << endl;
        exit(1);
    }
}

Board::Board (const int edge_length) {
    int winning_length;
    if (edge_length >= 5) {
        winning_length = 5;
    } else {
        winning_length = edge_length;
    }

    *this = Board(edge_length, winning_length);
}



// Display of internal objects
int Board::length () const {
    return this->board_length;
}

int Board::size () const {
    return this->board_size;
}


int Board::winning_length () const {
    return this->length_of_winning_sequence;
}


bool Board::inside (const int x, const int y) const {
    return (x >= 0 and x < this->length()
        and y >= 0 and y < this->length());
}


Symbol Board::at (const int x,const int y) const {
    if (this->inside(x, y)) {
        return this->board_array.at(this->length() * y + x);
    } else {
        return outside;
    }
    
}


std::ostream& operator<< (std::ostream& out, const Board& board) {
    out << endl;
    // The output has a coordinate system 
    // with the x-axis (col) increasing from left to right 
    // and the y-axis (row) increasing from bottom to top.
    
    for (int row = board.length() - 1; row >= 0 ; row--) {
        // Printing the y-axis
        out << " ";
        int y_digit_0 = row % 10;
        int y_digit_1 = row / 10;
        if (board.length() > 10) {
            out << y_digit_1;
        }
        out << y_digit_0;

        // Printing the board squares themselves
        for (int col = 0; col < board.length(); col++) {
            out << " " << board.at(col, row);
        }
        out << endl;
    }

    // Printing the x-axis
    if (board.length() > 10) {
        out << "   ";   // 3 spaces
        for (int col = 0; col < board.length(); col++) {
            out << " ";
            int x_digit_1 = col / 10;
            out << x_digit_1;
        }
        out << endl;
        out << "   ";   // 3 spaces
    } else {
        out << "  ";   // 2 spaces
    }

    for (int col = 0; col < board.length(); col++) {
        int x_digit_0 = col % 10;
        out << " " << x_digit_0;
    }
    
    
    out << endl << endl;
    return out;
}


void Board::congratulate () const {
    if (this->winner == empty) {
        cout << "Draw." << endl;
    } else {
        cout << this->winner << " has won!" << endl;
    }
    cout << endl;
}



// Actions on instances
bool Board::place (const int x, const int y, const Symbol symbol) {
    bool is_on_board = this->inside(x, y);
    if (is_on_board) {
        this->board_array.at(this->length() * y + x) = symbol;
    }
    return is_on_board;
}


void Board::set_winner (Symbol player) {
    this->winner = player;
}
