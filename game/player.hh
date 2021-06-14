// Declaration of the Player class
// -------------------------------


class Group;

// Players act on the board and provide the interactive interface of the game.
class Player {
    private:
        Board* board;
        Symbol symbol;
        
        Player* next_player;
        Player* previous_player;


    public:
        Player (Board& board, const Symbol stone);
        ~Player ();
        friend class Group;  


        Symbol stone () const;
        
        Player* next () const;

        Player* prev () const;


        void make_move ();    
};