// Tests of the miniscore() algorithm
// ==================================


#include "../../structures/include.hh"   // Standard file that handles all inclusions for you.





// Functions for individual tests
// ------------------------------

/* Tic Tac Toe (2 Computers) 
As this test has a known outcome, an "expected board" is explicitly printed 
after the game ends in order to verify the behavior in case of future modifications. */
void test_1 () {
    
    print_subtitle("Tic Tac Toe (2 Computers)");
    
    Board board(3, 3);   // Creating a 3x3 board with a winning length of 3 stones.
    
    // Creating and adding computer players to the group
        const int computer_count = 2;
        std::vector<Computer> computer_players;
        for (int i = 0; i < computer_count; i++) {
            computer_players.emplace_back(board, stone[i], miniscore);
        }

        Group group;
        for (int i = 0; i < computer_count; i++) {
            group.append(&computer_players[i]);
        }

    // Playing the game
        Player* current_player = group.first();
        if (dev_mode_on)   print_dev_intro();
        
        cout << board;
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        
        board.congratulate();
        cout << endl;

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



/* Tic Tac Toe (1 Human, 1 Computer) 
The beginner is choosable. */
void test_2 () {
    
    print_subtitle("Tic Tac Toe (1 Human, 1 Computer)");
    
    Board board(3, 3);   // Creating a 3x3 board with a winning length of 3 stones.

    // Creating and adding computer players to the group
        Computer computer = Computer(board, x, miniscore);
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
                print_switch_default(choice); break;
        }
        
    // Playing the game
        Player* current_player = group.first();
        if (dev_mode_on)   print_dev_intro();
        
        cout << board;
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        
        board.congratulate();
        cout << endl;
}



/* Tests `miniscore()` on custom sized boards with custom winning lengths. */
void test_3 () {
    
    print_subtitle("miniscore() on a custom board");
    
    // Creating the board
        cout << "Create a board you want to test the algorithm on:" << endl;
        int board_length   = input_range(min_board_length, max_board_length, "length of board edge: ");
        int winning_length = input_range(min_winning_length, board_length, "length of winning sequence: ");

        Board board = Board(board_length, winning_length);

    // Creating and adding computer players to the group
        const int computer_count = 2;
        std::vector<Computer> computer_players;
        for (int i = 0; i < computer_count; i++) {
            computer_players.emplace_back(board, stone[i], miniscore);
        }

        Group group;
        for (int i = 0; i < computer_count; i++) {
            group.append(&computer_players[i]);
        }
    cout << endl;

    // Playing the game
        Player* current_player = group.first();
        if (dev_mode_on)   print_dev_intro();
        
        cout << board;
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        
        board.congratulate();
        cout << endl;
}



/* Tests if the depth limit functionality of `miniscore()` works as intended. */
void test_4 () {
    
    print_subtitle("Depth limit");
    
    cout << "The depth limit of `miniscore()` is " << miniscore_max_depth << "." << endl
         << "This means that the algorithm should not calculate more than " << miniscore_max_depth << " moves in advance." << endl;
        
    cout << endl
         << "Test if `miniscore()` observes the depth limmit on a 5x5 board:" << endl
         << endl;

    // Creating the game
        Board board(5, 4);
        Computer computer(board, x, miniscore);
        Human human(board, o);

        Group group;
        group.append(&computer);
        group.append(&human);

    // Playing the game
        Player* current_player = group.first();
        if (dev_mode_on)   print_dev_intro();

        cout << board;
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        
        board.congratulate();
        cout << endl;
}



/* Tests how `miniscore()` can handle a multi-player game. */
void test_5 () {

    print_subtitle("Multi-player");

    // Creating a 2x2 board and a 2-player-game just to quickly make sure now 
}





// Menu for choosing a test
// ------------------------

int main (int argument_count, char* argument_values[]) {
    // Option for enabling Developer Mode when starting the program
    if (argument_count > 1) {
        if (argument_values[1] == std::string_view{"-dev"}) {
            dev_mode_on = true;
        }
    }

    // Menu
    while (true) {   // The program returns to the menu after finishing a test.
        
        print_title("Tests of the miniscore() algorithm");
        
        // Options
        cout << "0. Quit" << endl
             << "1. Tic Tac Toe (2 Computers)" << endl
             << "2. Tic Tac Toe (1 Human, 1 Computer)" << endl
             << "3. miniscore() on a custom board" << endl
             << "4. Depth limit" << endl
             << "5. Multi-player" << endl
             << endl;
        
        // User prompt
        int choice = input_range(5, "Choose an option: ");   //! Adapt number to number of tests.
        cout << endl;
        cout << endl;

        // Test execution
        switch (choice) {
            case 0: return 0;   // Ending the program
            case 1: test_1(); break;
            case 2: test_2(); break;
            case 3: test_3(); break;
            case 4: test_4(); break;
            case 5: test_5(); break;
            default: print_switch_default(choice); break;
        }
        cout << endl;
    }
}
