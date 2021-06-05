#include "include.hh"

const int player_count = 3;
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
