// Tests of the Player methods
// ---------------------------



#include "../structures/include.hh"   // Standard file that handles all inclusions.

Board board(5);



// Testing basic Player methods
void test_1 () {
    cout << "1. Testing basic Player methods:" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    
    Human human_a = Human(board, stone[0]);
    Human human_b = Human(board, stone[1]);
    Computer computer = Computer(board, stone[2]);


    // Testing Player::stone()
        cout << "Testing Player::stone():" << endl;
        cout << "Human 'a': " << human_a.stone() << endl;
        cout << "Human 'b': " << human_b.stone() << endl;
        cout << "Computer :  " << computer.stone() << endl;
    cout << endl << endl; 
    
    
    // Testing Player::place_stone()
        cout << "Testing Player::place_stone():" << endl;
        
        cout << "Placing " << human_a.stone() << " at (1, 1):" << endl;
        human_a.place_stone(1, 1);
        
        cout << "Attempting to place " << human_b.stone() << " at (-1, -1):" << endl;
        human_b.place_stone(-1, -1);
        
        cout << "Placing " << human_b.stone() << " at (0, 1):" << endl;
        human_b.place_stone(0, 1);

        cout << "Placing " << computer.stone() << " at (2, 2):" << endl;
        computer.place_stone(2, 2);
    cout << endl;
    

    // Testing Human::make_move()
        cout << "Testing Human::make_move():" << endl;
        human_a.make_move();
        human_b.make_move();
    cout << endl;


    // Testing Computer::make_move()
        cout << "Testing Computer::make_move():" << endl;
        computer.make_move();
    cout << endl;

    
    // Testing Player::last_move()
        cout << "Testing Player::last_move():" << endl;
        cout << "Latest move of " << human_a.last_move().symbol() 
             << " at (" << human_a.last_move().x() << ", " << human_a.last_move().y() << ")"
             << endl;
        cout << "Latest move of " << human_b.last_move().symbol() 
             << " at (" << human_b.last_move().x() << ", " << human_b.last_move().y() << ")"
             << endl;
        cout << "Latest move of " << computer.last_move().symbol() 
             << " at (" << computer.last_move().x() << ", " << computer.last_move().y() << ")"
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
    Computer computer = Computer(board, stone[3]);
    

    // Building the group
        Group group;
        group.append(&human_a);
        group.append(&human_b);
        group.append(&human_c);
        group.append(&computer);


    // Testing the group's properties
        cout << "Testing Group properties with " << group.length() << " Players:" << endl;
        cout << "Player pointers: " << &human_a << " " << &human_b << " " << &human_c << " " << &computer << endl;
        cout << "Group: first(): " << group.first() << "  length(): " << group.length() << endl;
        cout << "human_a : " << human_a.stone() << "  next(): " << human_a.next() << "  prev(): " << human_a.prev() << endl;
        cout << "human_b : " << human_b.stone() << "  next(): " << human_b.next() << "  prev(): " << human_b.prev() << endl;
        cout << "human_c : " << human_c.stone() << "  next(): " << human_c.next() << "  prev(): " << human_c.prev() << endl;
        cout << "computer: " << computer.stone() << "  next(): " << computer.next() << "  prev(): " << computer.prev() << endl;
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
        // Select the number of Human and Computer players. Sum must not be larger than max_player_count.
        const int human_count = 2;
        const int computer_count = 2;
        const int player_count = human_count + computer_count;

        std::vector<Human> human_players;
        for (int i = 0; i < human_count; i++) {
            human_players.emplace_back(board, stone[i]);
        }
        std::vector<Computer> computer_players;
        for (int i = human_count; i < player_count; i++) {
            computer_players.emplace_back(board, stone[i]);
        }


    // Building the group
        Group group;
        for (int i = 0; i < human_count; i++) {   // Separate for-loop needed to avoid pointer-problems
            group.append(&human_players[i]);
        }
        for (int i = 0; i < computer_count; i++) {
            group.append(&computer_players[i]);
        }
    

    // Testing the group's properties
        cout << "Player pointers: ";
        Player* current_player = group.first();
        for (int i = 0; i < group.length(); i++) {
            cout << " " << current_player;
            current_player = current_player->next();
        }
        cout << endl;

        cout << "Group: first(): " << group.first() << "  length(): " << group.length() << endl;
        current_player = group.first();
        for (int i = 0; i < group.length(); i++) {
            cout << "player: " << current_player->stone() << "  next(): " << current_player->next() << "  prev(): " << current_player->prev() << endl;
            current_player = current_player->next();
        }
    cout << endl << endl;


    // Iterating through the group
        cout << "Iterating through the group:" << endl;
        current_player = group.first();
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
        current_player = group.first();
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
        cout << "Choose the number of human and computer players:" << endl;
        cout << "(max. " << max_player_count << " total)" << endl;
        
        int human_count = input_range(max_player_count, "humans: ");
        
        int computer_count = 0;
        if (human_count < max_player_count) {
            computer_count = input_range(max_player_count - human_count, "computers: ");
        } else {
            cout << "no computers" << endl;
        }
        
        int player_count = human_count + computer_count;
        
        std::vector<Human> human_players;
        for (int i = 0; i < human_count; i++) {
            human_players.emplace_back(board, stone[i]);
        }
        std::vector<Computer> computer_players;
        for (int i = human_count; i < player_count; i++) {
            computer_players.emplace_back(board, stone[i]);
        }

        Group group;
        for (int i = 0; i < human_count; i++) {   // Separate for-loop needed to avoid pointer-problems
            group.append(&human_players[i]);
        }
        for (int i = 0; i < computer_count; i++) {
            group.append(&computer_players[i]);
        }
    

    // Playing the game
    cout << board;
    if (player_count > 0) {
        Player* current_player = group.first();
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        board.congratulate();
    }   
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
    
    int choice = input_range(4, "Choose an option: ");
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
