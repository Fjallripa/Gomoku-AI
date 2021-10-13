// Declaration of the Square class
// ===============================



// Square is an interface to read and move around between the squares of the game board.
class Square {
    private:
        // Set by constructor
            Board* board;
        
        // Changed by public methods
            std::array<int, 2> coordinates;


    public:
        // Constructors
            Square (Board* board, int x, int y);
            Square (Board& board, int x, int y);
            Square ();
        

        // Display of internal objects
            int x () const;
            int y () const;

            Symbol symbol () const;


        // Actions on internal objects
            bool go (Direction direction, int steps);
};
