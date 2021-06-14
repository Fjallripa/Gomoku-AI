// Declaration of the Square class
// -------------------------------


// Squares serve as a way to access and move around between the squares of the game board.
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