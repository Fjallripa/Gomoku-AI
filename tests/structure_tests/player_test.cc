// Tests of the Player methods
// ===========================


#include "../../structures/include.hh"   // Standard file that handles all inclusions.





// Functions for individual tests
// ------------------------------

/* (semi-automated) Tests basic Playeer, Human and Computer methods.
Tests all three constructors, `player.stone()`, `player.place_stone()`, 
`human.make_move()`, `computer.make_move()` and `player.last_move()`. */
void test_1 () {
    
    print_subtitle("Testing basic Player methods");
    
    Board board(5);
    
    
    // Constructing the Players
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



/* (semi-automated) Tests Player and Group properties (with manual constructors).
+ Tests group construction with `group.append()`, `group.length`, Player pointers, 
`group.first()`, `player.next()` and  `player.prev()`. 
+ Tests repeated iterations through the group in both directions and making moves 
with the different Players of the group but the same `&player->make_move()` method.
+ Tests group deconstruction with `group.pop()`. */
void test_2 () {
    
    print_subtitle("Testing Player and Group properties (manual constructors)");
    
    Board board(5);

    // Constructing the Players
    Human human_a = Human(board, stone[0]);
    Human human_b = Human(board, stone[1]);
    Human human_c = Human(board, stone[2]);
    Computer computer = Computer(board, stone[3]);


    // Checking if the Group related methods are empty initially
    cout << "Testing if the Group related methods are empty initially:" << endl
         << "human_a : group(): " << human_a.group() << "  next(): " << human_a.next() << "  prev(): " << human_a.prev() << endl
         << "computer: group(): " << computer.group() << "  next(): " << computer.next() << "  prev(): " << computer.prev() << endl
         << endl;

    // Building the group
        Group group;
        group.append(&human_a);
        group.append(&human_b);
        group.append(&human_c);
        group.append(&computer);


    // Testing the group's properties
        cout << "Testing Group properties with " << group.length() << " Players:" << endl;
        cout << "Player pointers: " << &human_a << " " << &human_b << " " << &human_c << " " << &computer << endl;
        cout << "Group: " << &group << "  first(): " << group.first() << "  length(): " << group.length() << endl;
        cout << "human_a : " << human_a.stone() << "  next(): " << human_a.next() << "  prev(): " << human_a.prev() << "  group(): " << human_a.group() << endl;
        cout << "human_b : " << human_b.stone() << "  next(): " << human_b.next() << "  prev(): " << human_b.prev() << "  group(): " << human_b.group() << endl;
        cout << "human_c : " << human_c.stone() << "  next(): " << human_c.next() << "  prev(): " << human_c.prev() << "  group(): " << human_c.group() << endl;
        cout << "computer: " << computer.stone() << "  next(): " << computer.next() << "  prev(): " << computer.prev() << "  group(): " << computer.group() << endl;
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
                    << " - group(): " << lone_player->group()
                    << " - next(): " << lone_player->next()
                    << " - prev(): " << lone_player->prev()
                    << endl;
            cout << endl;
        }
}



/* (automated) Tests Player and Group properties (with looped constructors).
+ Same as the previous test with the only difference being that 2 Humans 
and 2 Computers are first constructed within a loop placing them 
into respective vectors (`vector.emplace_back()`). They then get added 
to the group with loops appending each element of the vector.
+ Only `group.pop()` doesn't get tested again. */
void test_3 () {
    
    print_subtitle("Testing Player and Group properties (looped constructors)");

    Board board(5);
    
    
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



/* (interactive) Tests basic gameplay.
A 5x5 board is used and a custom number of human and computer players 
(default `placeholder()` algorithm) are put into a group 
and used to play a basic game. */
void test_4 () {
    
    print_subtitle("Testing basic gameplay");

    Board board(5);

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
    Player* current_player = group.first();
    cout << board;

    if (player_count > 0) {
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        board.congratulate();
    }
}





// Menu for choosing a test
// ------------------------

int main () {
    while (true) {   // The program returns to the menu after finishing a test.
        
        print_title("Tests of the Player methods");

        // Options
        cout << "0. Quit" << endl;
        cout << "1. Basic Player methods" << endl;
        cout << "2. Player and Group properties (manual constructors)" << endl;
        cout << "3. Player and Group properties (looped constructors)" << endl;
        cout << "4. Basic gameplay" << endl;
        cout << endl;
        
        // User prompt
        int choice = input_range(4, "Choose an option: ");   //! Adapt number to number of tests.
        cout << endl;
        cout << endl;

        // Test execution
        switch (choice) {
            case 0: return 0;   // Ending the program
            case 1: test_1(); break;
            case 2: test_2(); break;
            case 3: test_3(); break;
            case 4: test_4(); break;
            default: print_switch_default(choice); break;
        }
        cout << endl;
    }
}
