// Definition of the Symbol type
// -----------------------------


// Symbols are the allowed values on the board.
enum Symbol {empty, x, o, d, p};


const int max_player_count = 4;   // If this number is changed, the Symbol type may have to be adapted as well.

std::ostream& operator<< (std::ostream& out, const Symbol symbol) {
    if  (symbol == empty) {out << ".";}
    else if (symbol == x) {out << "X";}
    else if (symbol == o) {out << "O";}
    else if (symbol == d) {out << "Δ";}
    else if (symbol == p) {out << "Π";}
    else {out << "! This symbol is not defined !\n";}

    return out;
}

// Stones are the symbols available to the Players.
const std::array<Symbol, max_player_count> stone = {x, o, d, p};   // Enables iteration when assigning stones to players (e.g. player.stone = stone[i];).