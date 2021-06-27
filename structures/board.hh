// Declaration of the Board class
// ------------------------------


const int edge_length = 30;
const int board_size = edge_length * edge_length;

// Board creates the game board and stores its current state.
class Board {
    private:
        std::array<Symbol, board_size> board;

        Symbol winner = empty;

    public:
        Board ();


        bool inside (const int x, const int y) const;

        Symbol at (const int x, const int y) const;

        //std::ostream& operator<< (std::ostream& out, const Board& board)

        void congratulate () const;


        bool place (const int x, const int y, const Symbol symbol);

        void set_winner (Symbol player);

};
