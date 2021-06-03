#include "include.hh"
#include "symbol.cc"


const int edge_length = 3;
const int board_size = edge_length * edge_length;

class Board {
    private:
        std::array<Symbol, board_size> board;    

    public:
        Board ();

        Symbol& at (int x, int y);

        std::ostream& operator<< (std::ostream& out);
        
};
