#include "symbol.cc"


const int edge_length = 31;
const int board_size = edge_length * edge_length;

// Board. Creates the game board and stores its current state.
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




// Square. Serves as a way to access and move around between the squares of the game board.
class Square {
    private:
        Board* board;
        std::array<int, 2> coordinates;

    public:
        Square (Board& board, int x, int y);

        int x ();
        int y ();

        Symbol symbol ();

        bool go (Direction direction, int steps);
};