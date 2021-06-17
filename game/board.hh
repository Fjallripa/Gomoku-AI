// Declaration of the Board class
// ------------------------------


const int edge_length = 3;
const int board_size = edge_length * edge_length;

// Board creates the game board and stores its current state.
class Board {
    private:
        std::array<Symbol, board_size> board;    


    public:
        Board ();


        bool inside (const int x, const int y) const;

        Symbol at (const int x, const int y) const;

        //std::ostream& operator<< (std::ostream& out, const Board& board)


        bool place (const int x, const int y, const Symbol symbol);    
};