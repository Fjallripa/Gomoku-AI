// Declaration of the Board class
// ------------------------------


// global Board constants
const int min_board_length = 1;
const int max_board_length = 100;
const int max_board_size = max_board_length * max_board_length;

const int min_winning_length = 1;


// Board creates the game board and stores its current state.
class Board {
    private:
        std::array<Symbol, max_board_size> board_array;
        int board_length;
        int board_size;

        int length_of_winning_sequence;
        Symbol winner = empty;


    public:
        Board (const int edge_length, int winning_length);
        Board (const int edge_length);
        

        int length () const;
        int size () const;

        int winning_length () const;
        
        bool inside (const int x, const int y) const;

        Symbol at (const int x, const int y) const;

        // std::ostream& operator<< (std::ostream& out, const Board& board);

        void congratulate () const;


        bool place (const int x, const int y, const Symbol symbol);

        void set_winner (Symbol player);
};
