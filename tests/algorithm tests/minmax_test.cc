// Tests of the minmax() algorithm
// -------------------------------



#include "../../structures/include.hh"   // Standard file that handles all inclusions for you.


// Test related functions
void dev_intro_text() {
    cout << "Developer Mode on:" << endl
         << "At each move, the \"> \"-prompt enables the following choices:" << endl
         << "* Pressing Enter: Show scores for all possible moves / Execute the best move." << endl
         << "* Entering a coordinate `x y`: Explore a specific move by printing a hypothetical board." << endl 
         << "    Scores and further moves will refer to that board." << endl;
}



// TicTacToe (2 Computers)
void test_1 () {
    // Title
    cout << "TicTacToe (2 Computers):" << endl
         << "------------------------" << endl
         << endl;
    
    Board board(3, 3);   // Creating a 3x3 board with a winning length of 3 stones.
    
    // Creating and adding computer players to the group
        const int computer_count = 2;
        std::vector<Computer> computer_players;
        for (int i = 0; i < computer_count; i++) {
            computer_players.emplace_back(board, stone[i], minmax);
        }

        Group group;
        for (int i = 0; i < computer_count; i++) {
            group.append(&computer_players[i]);
        }

    // Playing the game
        if (dev_mode_on)   dev_intro_text();
        cout << board;
        Player* current_player = group.first();
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        board.congratulate();

    // Comparing test results
        cout << endl;
        cout << "Compare the latest board with how it should look like:" << endl;
        cout << "\"        " << endl
             << "X at (2,2)" << endl
             << "          " << endl
             << " 2 X O X  " << endl
             << " 1 O O X  " << endl
             << " 0 X X O  " << endl
             << "   0 1 2  " << endl
             << "          " << endl
             << "Draw.     " << endl
             << "\"        " << endl;
    
    cout << endl;
}


// TicTacToe (1 Human, 1 Computer)
void test_2 () {
    // Title
    cout << "TicTacToe (1 Human, 1 Computer):" << endl
         << "--------------------------------" << endl
         << endl;
    
    Board board(3, 3);   // Creating a 3x3 board with a winning length of 3 stones.

    // Creating and adding computer players to the group
        Computer computer = Computer(board, x, minmax);
        Human human       = Human(board, o);

        cout << "Who should begin?" << endl;
        cout << "1. computer (X)" << endl;
        cout << "2. user (O)" << endl;
        cout << endl;

        int choice = input_range(1, 2, "Choose an option: ");
        cout << endl;

        Group group;
        switch (choice) {
            case 1:
                group.append(&computer);
                group.append(&human);
                break;
            case 2:
                group.append(&human);
                group.append(&computer);
                break;
            default:
                cout << "Error in the code: The option " << choice << " doesn't have a matching case." << endl;
                break;
        }
        
    // Playing the game
        if (dev_mode_on)   dev_intro_text();
        cout << board;
        Player* current_player = group.first();
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        board.congratulate();
    
    cout << endl;
}



// minmax() on different sized boards
void test_3 () {
    // Title
    cout << "minmax() on a custom board:" << endl
         << "---------------------------" << endl
         << endl;
    
    // Creating the board
        cout << "Create a board you want to test the algorithm on:" << endl;
        int board_length   = input_range(min_board_length, max_board_length, "length of board edge: ");
        int winning_length = input_range(min_winning_length, board_length, "length of winning sequence: ");

        Board board = Board(board_length, winning_length);

    // Creating and adding computer players to the group
        const int computer_count = 2;
        std::vector<Computer> computer_players;
        for (int i = 0; i < computer_count; i++) {
            computer_players.emplace_back(board, stone[i], minmax);
        }

        Group group;
        for (int i = 0; i < computer_count; i++) {
            group.append(&computer_players[i]);
        }
    cout << endl;

    // Playing the game
        if (dev_mode_on)   dev_intro_text();
        cout << board;
        Player* current_player = group.first();
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        board.congratulate();
    
    cout << endl;
}




int main (int argument_count, char* argument_values[]) {
    // Option for enabling developer options when starting the program
    if (argument_count > 1) {
        if (argument_values[1] == std::string_view{"-dev"}) {
            dev_mode_on = true;
        }
    }
    

    // Menu for choosing which test to run
    bool continue_program = true;
    while (continue_program) {   // With this while-loop, the program returns to the menu after finishing a test.
        // Title
        cout << endl;
        cout << "Tests of the minmax() algorithm" << endl
            << "===============================" << endl;
        if (dev_mode_on) {
            cout << "> Developer Mode" << endl;
        }
        cout << endl;

        // Options
        cout << "0. Quit" << endl;
        cout << "1. TicTacToe (2 Computers)" << endl;
        cout << "2. TicTacToe (1 Human, 1 Computer)" << endl;
        cout << "3. minmax() on a custom board" << endl;
        cout << endl;
        
        // User prompt
        int choice = input_range(3, "Choose an option: ");   // Adapt number to number of tests.
        cout << endl;
        cout << endl;

        // Test execution
        switch (choice) {
            case 0: continue_program = false; break;
            case 1: test_1(); break;
            case 2: test_2(); break;
            case 3: test_3(); break;
            default: 
                cout << "Didn't find any matching test for " << choice << "." << endl; break;
        }

        cout << endl;
    }
}
