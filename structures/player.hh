// Declaration of the Player class
// -------------------------------


// Players act on the board and provide the interactive interface of the game.
class Player {
    protected:
        Board* board;
        Symbol symbol;

        Square latest_move;
        
        Player* next_player;
        Player* previous_player;


    public:
        Player (Board& board, const Symbol stone);
        virtual ~Player () = 0;
        friend class Group;  


        Symbol stone () const;

        Square last_move () const;
        
        Player* next () const;
        Player* prev () const;


        void place_stone (int x, int y);
        virtual void make_move () = 0; 

        bool is_winner () const; 
};



// Human players.
class Human : public Player {
    public:
        Human (Board& board, const Symbol stone);
        

        void make_move ();
};



// Computer players.
class Computer : public Player {
    public:
        Computer (Board& board, const Symbol stone);
        

        void make_move ();
};
