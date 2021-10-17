// Implementation of the Square class
// ==================================



// Constructors
// ------------

/* Default constructor (takes a pointer to the board). */
Square::Square (Board* board, int x, int y) {
    this->board       = board;
    this->coordinates = {x, y};
}


/* Default constructor (takes a reference to the board). */
Square::Square (Board& board, int x, int y) {
    *this = Square(&board, x, y);
}


/* Empty constructor */
Square::Square () {
    *this = Square(nullptr, -1, -1);
}





// Display of internal objects
// ---------------------------

/* Returns the x-coordinate of the square. */
int Square::x () const {
    return this->coordinates[0];
}


/* Returns the y-coordinate of the square. */
int Square::y () const {
    return this->coordinates[1];
}


/* Returns the symbol of the square. */
Symbol Square::symbol () const {
    return this->board->at(this->x(), this->y());   // Returns symbol at this square.
}





// Actions on internal objects
// ---------------------------

/* Moves towards a new square on the board (change of internal `coordinates`). */
bool Square::go (Direction direction, int steps = 1) {
    // Selection of the new coordinates
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

    // Performing the move if it's inside the board
    bool still_inside = this->board->inside(x_new, y_new);
    if (still_inside) {   // Only moves to the new square if it is inside the board.
        this->coordinates = {x_new, y_new};
    }
    return still_inside;   // The return value tells if going to the new square worked or not.
}
