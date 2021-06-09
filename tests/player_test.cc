#include "../game/player.cc"

Board board;
Group group;


void test_1 () {
    cout << "Testing player make_move() method:" << endl;
    Player player_a = Player(board, stone[0], group);
    Player player_b = Player(board, stone[1], group);

    player_a.make_move();
    player_b.make_move();
}


void test_2 () {
    cout << "Testing player and group properties (manual constructors):" << endl << endl;
    Player player_a = Player(board, stone[0], group);
    Player player_b = Player(board, stone[1], group);
    Player player_c = Player(board, stone[2], group);
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
    for (int i = 0; i < group.length(); i++) {
        cout << " " << current_player;
        current_player = current_player->next();
    }
    cout << endl << "prev():";
    for (int i = 0; i < group.length(); i++) {
        cout << " " << current_player;
        current_player = current_player->prev();
    }
    cout << endl << endl;

    cout << "Making moves:" << endl;
    cout << board;
    for (int i = 0; i < group.length(); i++) {
        current_player->make_move();
        current_player = current_player->next();
    }
}


void test_3 () {
    cout << "Testing player and group properties (looped constructors):" << endl << endl;
    std::vector<Player> players;
    for (int i = 0; i < 3; i++) {
        players.emplace_back(board, stone[i], group);
    }
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
    for (int i = 0; i < board_size; i++) {
        current_player->make_move();
        current_player = current_player->next();
    }
}


void test_4 () {
    cout << "Testing basic gameplay:" << endl << endl;
    
    cout << "Choose the number of players: ";
    int player_count = 0;
    while (player_count < 1 or player_count > max_player_count) {
        input_int(player_count);
    }
    
    // Creating and adding players to the group
    std::vector<Player> players;
    for (int i = 0; i < player_count; i++) {
        players.emplace_back(board, stone[i], group);
    }
    for (int i = 0; i < player_count; i++) {   // Separate for-loop needed to avoid pointer-problems
        group.append(&players[i]);
    }
    
    // Playing the game
    cout << board;
    Player* current_player = group.first();
    for (int i = 0; i < board_size; i++) {
        current_player->make_move();
        current_player = current_player->next();
    }
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