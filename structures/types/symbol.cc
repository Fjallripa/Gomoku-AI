// Definition of the Symbol type
// -----------------------------


// Symbols are the allowed values on the board.
enum Symbol {outside, empty, x, o, d, p};


const int max_player_count = 4;   // If this number is changed, the Symbol type may have to be adapted as well.

// Displaying the symbols
std::ostream& operator<< (std::ostream& out, const Symbol symbol) {
    switch (symbol) {
        case outside: out << "outside"; break;
        case empty  : out << "."; break;
        case x      : out << "X"; break;
        case o      : out << "O"; break;
        case d      : out << "Δ"; break;
        case p      : out << "Π"; break;
    
        default: out << "! This symbol is not defined !\n"; break;
    }
    
    return out;
}

// Stones are the symbols available to the Players.
const std::array<Symbol, max_player_count> stone = {x, o, d, p};   // Enables iteration when assigning stones to players (e.g. player.stone = stone[i];).
