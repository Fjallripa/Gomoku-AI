// Declaration of the Group class
// ------------------------------


// Group provides a circular container for Players.
class Group {
    private:
        Player* first_player;
        int number_of_players = 0;


    public:
        ~Group ();


        Player* first () const;

        int length () const;


        void append (Player* player);

        Player* pop ();
};
