// Declaration of the Group class
// ==============================



// Group provides a circular container for Players.
class Group {
    private:
        // Set by constructor
            Player* first_player;
        
        // Changed by public methods
            int number_of_players = 0;


    public:
        // Destructors
            ~Group ();

        
        // Display of internal objects
            Player* first () const;

            int length () const;


        // Actions on internal objects
            void append (Player* player);   // Changes Player.

            Player* pop ();   // Changes Player.
};
