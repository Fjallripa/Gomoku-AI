// Declaration of the Player class
// ===============================



// Player is the base class that acts on the board.
class Player {
    protected:
        // Set by constructor
            Board* board;
            Symbol symbol;

        // Changed by public methods
            Square latest_move;
        
        // Changed by Group methods
            Player* next_player;
            Player* previous_player;


    public:
        friend class Group;
        
        // Constructors & Destructors  
            Player (Board& board, const Symbol stone);
            virtual ~Player () = 0;

           
        // Display of internal objects
            Symbol stone () const;

            Square last_move () const;
            
            Player* next () const;
            Player* prev () const;

            bool is_winner () const;   // Changes Board.
            bool is_winner (Square last_move) const;
        

        // Actions on internal objects
            void place_stone (int x, int y);   // Changes Board.
            virtual void make_move () = 0;     // Changes Board. 
};




// Human players make moves via text-based user input.
class Human : public Player {
    public:
        // Constructors    
            Human (Board& board, const Symbol stone);

        // Actions on internal objects
            void make_move ();   // Changes Board.
};




// Computer players make moves chosen by their algorithms.
class Computer : public Player {
    private:
        // Set by constructor
            Square (Computer::*algorithm_used) ();

        // Internal method
            void dev_choice(Player* player);   // Changes Board.

    
    public:
        // Constructors    
            Computer (Board& board, const Symbol stone, const Algorithm algorithm);
            Computer (Board& board, const Symbol stone);


        // Actions on internal objects
            void make_move ();   // Changes Board.


        // Algorithms. Implementations in 'algorithms/' folder
            Square placeholder ();
            Square minimax ();
            Square miniscore ();


        // Algorithm support methods. Found insde the respective algorithm files.
            int minimax_score (int x, int y, Player* player, bool dev_details = false);
            int miniscore_score (int x, int y, Player* player, bool dev_details = false);
};
