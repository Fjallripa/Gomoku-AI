#include "board.cc"

class Player {
    private:
        Board *board;

    public:
        Player(Board& board, const Symbol stone);
        Symbol stone;

        void make_move ();
};