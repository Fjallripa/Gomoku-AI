// Definition of the Direction type
// --------------------------------


// Directions serve as arguments for where to move on the board.
enum Direction {up, upright, right, downright, down, downleft, left, upleft};


// To iterate through them, a container is needed as well.
const int direction_count = 8;
const std::array<Direction, direction_count> all_directions = 
    {up, upright, right, downright, down, downleft, left, upleft};

const std::array<std::string, direction_count> direction_string = 
    {"up       ", "upright  ", "right    ", "downright",
     "down     ", "downleft ", "left     ", "upleft   "};