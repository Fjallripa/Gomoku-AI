// Implementation of the Board class
// =================================



// Constructors
// ------------

/* Default constructor */
Board::Board (const int edge_length) {
    int winning_length;
    if (edge_length >= 5) {
        winning_length = 5;
    } else {
        winning_length = edge_length;
    }

    *this = Board(edge_length, winning_length);
}



/* Constructor with custom length of winning sequence */
Board::Board (const int edge_length,  int winning_length) {
    bool good_edge_length    = edge_length >= min_board_length  and  edge_length <= max_board_length;
    bool good_winning_length = winning_length >= min_winning_length  and  winning_length <= edge_length;

    if (good_edge_length and good_winning_length) {
        this->board_length = edge_length;
        this->board_size   = edge_length * edge_length;
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





// Display of internal objects
// ---------------------------

/* Returns internal `board_length`. */
int Board::length () const {
    return this->board_length;
}


/* Returns internal `board_size`. */
int Board::size () const {
    return this->board_size;
}


/* Returns internal `length_of_winning_sequence`. */
int Board::winning_length () const {
    return this->length_of_winning_sequence;
}


/* Checks wether a coordinate is inside the board. */
bool Board::inside (const int x, const int y) const {
    return (x >= 0 and x < this->length()
        and y >= 0 and y < this->length());
}



/* Returns symbol of a specific square. */
Symbol Board::at (const int x,const int y) const {
    if (this->inside(x, y)) {
        return this->board_array.at(this->length() * y + x);
    } else {
        return outside;
    }
    
}



/* Returns a picture of the board. */
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



/* Prints a congratulation to the winner or declares a draw. */
void Board::congratulate () const {
    if (this->winner == empty) {
        cout << "Draw." << endl;
    } else {
        cout << this->winner << " has won!" << endl;
    }
    cout << endl;
}





// Actions on internal objects
// ---------------------------

/* Sets the symbol on a specific square on the board. */
bool Board::place (const int x, const int y, const Symbol symbol) {
    bool is_on_board = this->inside(x, y);
    if (is_on_board) {
        this->board_array.at(this->length() * y + x) = symbol;
    }
    return is_on_board;
}



/* Sets the board's winner. */
void Board::set_winner (Symbol player) {
    this->winner = player;
}
