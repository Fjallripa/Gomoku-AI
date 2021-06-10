#include "symbol.cc"


const int edge_length = 100;
const int board_size = edge_length * edge_length;

class Board {
    private:
        std::array<Symbol, board_size> board;    

    public:
        Board ();

        bool inside (const int x, const int y) const;

        Symbol at (const int x, const int y) const;

        bool place (const int x, const int y, const Symbol symbol);

        //std::ostream& operator<< (std::ostream& out, const Board& board)
        
};
