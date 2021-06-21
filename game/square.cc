// Implementation of the Square class
// ----------------------------------



// Constructor & Destructor
Square::Square (Board* board, int x, int y) {
    this->board       = board;
    this->coordinates = {x, y};
}

Square::Square (Board& board, int x, int y) {
    *this = Square(&board, x, y);
}

Square::Square () {
    *this = Square(nullptr, -1, -1);
}



// Display of internal objects
int Square::x () const {
    return this->coordinates[0];
}

int Square::y () const {
    return this->coordinates[1];
}


Symbol Square::symbol () const {
    return this->board->at(this->x(), this->y());   // Returns symbol at this square.
}



// Actions on instances
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
