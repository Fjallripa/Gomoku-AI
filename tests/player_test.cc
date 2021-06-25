// Tests of the Player methods
// ---------------------------



#include "../structures/include.hh"   // Standard file that handles all inclusions.

Board board;


void test_1 () {   // Testing player make_move() method
    cout << "Testing player make_move() method:" << endl;
    Player player_a = Player(board, stone[0]);
    Player player_b = Player(board, stone[1]);

    player_a.make_move();
    cout << "Latest move of " << player_a.last_move().symbol() 
    << " at (" << player_a.last_move().x() << ", " << player_a.last_move().y() << ")"
    << endl << endl;
    
    player_b.make_move();
    cout << "Latest move of " << player_b.last_move().symbol() 
    << " at (" << player_b.last_move().x() << ", " << player_b.last_move().y() << ")"
    << endl << endl;
}


void test_2 () {   // Testing player and group properties (manual constructors)
    cout << "Testing player and group properties (manual constructors):" << endl << endl;
    Player player_a = Player(board, stone[0]);
    Player player_b = Player(board, stone[1]);
    Player player_c = Player(board, stone[2]);
    
    Group group;
    group.append(&player_a);
    group.append(&player_b);
    group.append(&player_c);

    cout << "Player pointers: " << &player_a << " " << &player_b << " " << &player_c << endl;
    cout << "Group: first(): " << group.first() << "  length(): " << group.length() << endl;
    cout << "player_a: " << player_a.stone() << "  next(): " << player_a.next() << "  prev(): " << player_a.prev() << endl;
    cout << "player_b: " << player_b.stone() << "  next(): " << player_b.next() << "  prev(): " << player_b.prev() << endl;
    cout << "player_c: " << player_c.stone() << "  next(): " << player_c.next() << "  prev(): " << player_c.prev() << endl;
    cout << endl;


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
    cout << endl << endl;


    cout << "Making moves:" << endl;
    cout << board;
    for (int i = 0; i < 2 * group.length(); i++) {
        current_player->make_move();
        current_player = current_player->next();
    }


    cout << "Testing group deconstruction:" << endl;
    // The Players are popped one by one.
    int step = 0;
    while (group.length() > 0) {
        cout << "Step " << step << ":" << endl;
        cout << "first(): " << group.first() << "  length(): " << group.length() << endl;
        
        cout << "members:";
        Player* member = group.first();
        for (int member_count = 0; member_count < group.length(); member_count++) {
            cout << " " << member->stone() << ":" << member;
            member = member->next();
        }
        cout << endl;
        
        Player* lone_player = group.pop();
        cout << lone_player->stone() << ":" << lone_player 
             << " - next(): " << lone_player->next()
             << " - prev(): " << lone_player->prev()
             << endl;
        
        cout << endl;
        step++;
    }
}


void test_3 () {   // Testing player and group properties (looped constructors)
    cout << "Testing player and group properties (looped constructors):" << endl << endl;
    std::vector<Player> players;
    for (int i = 0; i < 3; i++) {
        players.emplace_back(board, stone[i]);
    }

    Group group;
    for (int i = 0; i < 3; i++) {   // Separate for-loop needed to avoid pointer-problems
        group.append(&players[i]);
    }
    
    cout << "Player pointers: " << &players[0] << " " << &players[1] << " " << &players[2] << endl;
    cout << "Group: first(): " << group.first() << "  length(): " << group.length() << endl;
    for (int i = 0; i < 3; i++) {
        cout << "player: " << players[i].stone() << "  next(): " << players[i].next() << "  prev(): " << players[i].prev() << endl;
    }
    cout << endl;


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
    cout << endl << endl;


    cout << "Making moves:" << endl;
    cout << board;
    for (int i = 0; i < 2 * group.length(); i++) {
        current_player->make_move();
        current_player = current_player->next();
    }
    cout << "Moves over." << endl;
}


void test_4 () {   // Testing basic gameplay
    cout << "Testing basic gameplay:" << endl << endl;
    
    cout << "Choose the number of players: ";
    int player_count = 0;
    while (player_count < 1 or player_count > max_player_count) {
        input_int(player_count);
    }
    
    // Creating and adding players to the group
    std::vector<Player> players;
    for (int i = 0; i < player_count; i++) {
        players.emplace_back(board, stone[i]);
    }

    Group group;
    for (int i = 0; i < player_count; i++) {   // Separate for-loop needed to avoid pointer-problems
        group.append(&players[i]);
    }
    
    // Playing the game
    cout << board;
    Player* current_player = group.first();
    current_player->make_move();
    for (int i = 1; i < board_size and not current_player->is_winner(); i++) {
        current_player = current_player->next();
        current_player->make_move();
    }
    board.congratulate();
}




int main () {
    int input_number;
    const int max_number = 4;

    // Menu for choosing which test to run
    while (input_number < 1 or input_number > max_number) {
        input_int(input_number);
    }
    
    if      (input_number == 1) test_1();  
    else if (input_number == 2) test_2();
    else if (input_number == 3) test_3();
    else if (input_number == 4) test_4();
    else cout << "Didn't find any matching test for" << input_number << endl;
}
