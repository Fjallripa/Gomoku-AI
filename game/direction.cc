// Definition of the Direction type
// --------------------------------


// Directions serve as arguments for where to move on the board.
enum Direction {up, upright, right, downright, down, downleft, left, upleft};


// To iterate through them, a container is needed as well.
const int direction_count = 8;
const std::array<Direction, direction_count> all_directions = 
    {up, upright, right, downright, down, downleft, left, upleft};

const int fore_direction_count = 4;
const std::array<Direction, fore_direction_count> fore_directions = 
    {up, upright, right, downright};


// Displaying directions
std::ostream& operator<< (std::ostream& out, const Direction direction) {
    switch (direction) {
        case up:        out << "up";        break;
        case upright:   out << "upright";   break;
        case right:     out << "right";     break;
        case downright: out << "downright"; break;
        case down:      out << "down";      break;
        case downleft:  out << "downleft";  break;
        case left:      out << "left";      break;
        case upleft:    out << "upleft";    break;
        
        default: out << "! This symbol is not defined !\n"; break;
    }

    return out;
}

const std::array<std::string, direction_count> direction_string = 
    {"up       ", "upright  ", "right    ", "downright",
     "down     ", "downleft ", "left     ", "upleft   "};