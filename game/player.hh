// Declaration of the Player class
// -------------------------------


class Group;

const int winning_length = 5;

// Players act on the board and provide the interactive interface of the game.
class Player {
    private:
        Board* board;
        Symbol symbol;

        Square latest_move;
        
        Player* next_player;
        Player* previous_player;


    public:
        Player (Board& board, const Symbol stone);
        ~Player ();
        friend class Group;  


        Symbol stone () const;

        Square last_move () const;
        
        Player* next () const;

        Player* prev () const;


        void make_move ();   

        bool is_winner () const; 
};