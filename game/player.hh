#include "board.cc"

class Group;

class Player {
    private:
        Board* board;
        Symbol symbol;
        
        Group* group;
        Player* next_player;
        Player* previous_player;

    public:
        Player (Board& board, const Symbol stone, Group& group);
        ~Player ();
        friend class Group;  

        Symbol stone () const;
        
        Player* next () const;

        Player* prev () const;
      
        void make_move ();    
};




class Group {
    private:
        Player* first_player;
        int number_of_players = 0;

    public:
        Player* first () const;

        int length () const;

        void append (Player* player);

        Player* pop ();
};