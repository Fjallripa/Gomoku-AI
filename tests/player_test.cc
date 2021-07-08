// Tests of the Player methods
// ---------------------------



#include "../structures/include.hh"   // Standard file that handles all inclusions.

Board board;



// Testing basic Player methods
void test_1 () {
    cout << "1. Testing basic Player methods:" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    Human human_a = Human(board, stone[0]);
    Human human_b = Human(board, stone[1]);

    // Testing Player::stone()
        cout << "Testing Player::stone():" << endl;
        cout << "Human 'a': " << human_a.stone() << endl;
        cout << "Human 'b': " << human_b.stone() << endl;
    cout << endl << endl;
    
    
    // Testing Player::place_stone()
        cout << "Testing Player::place_stone():" << endl;
        
        cout << "Placing " << human_a.stone() << " at (1, 1):" << endl;
        human_a.place_stone(1, 1);
        
        cout << "Attempting to place " << human_b.stone() << " at (-1, -1):" << endl;
        human_b.place_stone(-1, -1);
        
        cout << "Placing " << human_b.stone() << " at (0, 1):" << endl;
        human_b.place_stone(0, 1);
    cout << endl;
    

    // Testing Human::make_move()
        cout << "Testing Human::make_move():" << endl;
        human_a.make_move();
        human_b.make_move();
    cout << endl;

    
    // Testing Player::last_move()
        cout << "Testing Player::last_move():" << endl;
        cout << "Latest move of " << human_a.last_move().symbol() 
             << " at (" << human_a.last_move().x() << ", " << human_a.last_move().y() << ")"
             << endl;
        cout << "Latest move of " << human_b.last_move().symbol() 
             << " at (" << human_b.last_move().x() << ", " << human_b.last_move().y() << ")"
             << endl;
    cout << endl;
}


// Testing Player and Group properties (manual constructors)
void test_2 () {
    cout << "2. Testing Player and Group properties (manual constructors):" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
    
    // Constructing the Players
    Human human_a = Human(board, stone[0]);
    Human human_b = Human(board, stone[1]);
    Human human_c = Human(board, stone[2]);
    

    // Building the group
        Group group;
        group.append(&human_a);
        group.append(&human_b);
        group.append(&human_c);


    // Testing the group's properties
        cout << "Testing Group properties with " << group.length() << " Players:" << endl;
        cout << "Player pointers: " << &human_a << " " << &human_b << " " << &human_c << endl;
        cout << "Group: first(): " << group.first() << "  length(): " << group.length() << endl;
        cout << "human_a: " << human_a.stone() << "  next(): " << human_a.next() << "  prev(): " << human_a.prev() << endl;
        cout << "human_b: " << human_b.stone() << "  next(): " << human_b.next() << "  prev(): " << human_b.prev() << endl;
        cout << "human_c: " << human_c.stone() << "  next(): " << human_c.next() << "  prev(): " << human_c.prev() << endl;
    cout << endl << endl;


    // Iterating through the group
        cout << "Iterating through the group:" << endl;
        Player* current_player = group.first();
        cout << "next():";
        for (int i = 0; i < 2 * group.length(); i++) {
            cout << " " << current_player;
            current_player = current_player->next();
        }
        cout << endl << "prev():";
        for (int i = 0; i < 2 * group.length(); i++) {
            cout << " " << current_player;
            current_player = current_player->prev();
        }
        cout << endl;
    cout << endl << endl;


    // Making moves while circling through the group twice
        cout << "Making moves while circling through the group twice:" << endl;
        cout << board;
        for (int i = 0; i < 2 * group.length(); i++) {
            current_player->make_move();
            current_player = current_player->next();
        }
    cout << endl;


    // Testing group deconstruction
        cout << "Testing group deconstruction:" << endl;
        
        // The Players are popped one by one.
        for (int step = 0; group.length() > 0; step++) {
            cout << "Step " << step << ":" << endl;
            
            // Displaying the current internal status of the group
                cout << "Group status:" << endl;
                cout << "first(): " << group.first() << "  length(): " << group.length() << endl;
                cout << "members:";
                Player* member = group.first();
                for (int member_count = 0; member_count < group.length(); member_count++) {
                    cout << " " << member->stone() << ":" << member;
                    member = member->next();
                }
            cout << endl << endl;
            
            // Popping one Player and checking if it got removed cleanly
                cout << "Popping one Player and checking if it got removed cleanly:" << endl;
                Player* lone_player = group.pop();
                cout << lone_player->stone() << ":" << lone_player 
                    << " - next(): " << lone_player->next()
                    << " - prev(): " << lone_player->prev()
                    << endl;
            cout << endl;
        }
}


// Testing Player and Group properties (looped constructors)
void test_3 () {
    cout << "3. Testing Player and Group properties (looped constructors):" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;

    // Constructing the Players
    std::vector<Human> human_players;
    for (int i = 0; i < 3; i++) {
        human_players.emplace_back(board, stone[i]);
    }

    // Building the group
    Group group;
    for (int i = 0; i < 3; i++) {   // Separate for-loop needed to avoid pointer-problems
        group.append(&human_players[i]);
    }
    

    // Testing the group's properties
        cout << "Player pointers: " << &human_players[0] << " " << &human_players[1] << " " << &human_players[2] << endl;
        cout << "Group: first(): " << group.first() << "  length(): " << group.length() << endl;
        for (int i = 0; i < 3; i++) {
            cout << "player: " << human_players[i].stone() << "  next(): " << human_players[i].next() << "  prev(): " << human_players[i].prev() << endl;
        }
    cout << endl << endl;


    // Iterating through the group
        cout << "Iterating through the group:" << endl;
        Player* current_player = group.first();
        cout << "next():";
        for (int i = 0; i < 2*group.length(); i++) {
            cout << " " << current_player;
            current_player = current_player->next();
        }
        cout << endl << "prev():";
        for (int i = 0; i < 2*group.length(); i++) {
            cout << " " << current_player;
            current_player = current_player->prev();
        }
        cout << endl;
    cout << endl << endl;


    // Making moves while circling through the group twice
        cout << "Making moves while circling through the group twice:" << endl;
        cout << board;
        for (int i = 0; i < 2 * group.length(); i++) {
            current_player->make_move();
            current_player = current_player->next();
        }
        cout << "Moves over." << endl;
    cout << endl;
}


// Testing basic gameplay
void test_4 () {
    cout << "Testing basic gameplay:" << endl;
    cout << "-----------------------" << endl;
    cout << endl;
    
    // Creating and adding players to the group
        cout << "Choose the number of human players: (max. " << max_player_count << ")" << endl;
        int player_count = input_range(max_player_count, "> ");
        
        std::vector<Human> human_players;
        for (int i = 0; i < player_count; i++) {
            human_players.emplace_back(board, stone[i]);
        }

        Group group;
        for (int i = 0; i < player_count; i++) {   // Separate for-loop needed to avoid pointer-problems
            group.append(&human_players[i]);
        }
    

    // Playing the game
        Player* current_player = group.first();
        cout << board;
        
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board_size; i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        board.congratulate();   
    cout << endl;
}




int main () {
    // Menu for choosing which test to run
    cout << endl;
    cout << "Tests of the Player methods" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cout << "0. Quit" << endl;
    cout << "1. Basic Player methods" << endl;
    cout << "2. Player and Group properties (manual constructors)" << endl;
    cout << "3. Player and Group properties (looped constructors)" << endl;
    cout << "4. Basic gameplay" << endl;
    cout << endl;
    
    int choice = input_range(0, 4, "Choose an option: ");
    cout << endl;
    cout << endl;

    switch (choice) {
        case 0: break;
        case 1: test_1(); break;
        case 2: test_2(); break;
        case 3: test_3(); break;
        case 4: test_4(); break;
        default: 
            cout << "Didn't find any matching test for " << choice << "." << endl; break;
    }

    cout << endl;
}
