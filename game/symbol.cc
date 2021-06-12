#include "include.hh"


const int max_player_count = 4;   // If this number is changed, the initializations below have to be adapted as well.


// Symbols. The allowed values on the board
enum Symbol {empty, x, o, d, p};

std::ostream& operator<< (std::ostream& out, const Symbol symbol) {
    if  (symbol == empty) {out << ".";}
    else if (symbol == x) {out << "X";}
    else if (symbol == o) {out << "O";}
    else if (symbol == d) {out << "Δ";}
    else if (symbol == p) {out << "Π";}
    else {out << "! This symbol is not defined !\n";}

    return out;
}

// Stones. The symbols available to the players
const std::array<Symbol, max_player_count> stone = {x, o, d, p};   // Enables iteration when assigning stones to players (e.g. player.stone = stone[i];).




// Directions. serve as arguments for where to move on the board
enum Direction {up, upright, right, downright, down, downleft, left, upleft};

// To iterate through them, a container is needed as well.
const int direction_count = 8;
const std::array<Direction, direction_count> all_directions = 
    {up, upright, right, downright, down, downleft, left, upleft};

const std::array<std::string, direction_count> direction_string = 
    {"up       ", "upright  ", "right    ", "downright",
     "down     ", "downleft ", "left     ", "upleft   "};
        