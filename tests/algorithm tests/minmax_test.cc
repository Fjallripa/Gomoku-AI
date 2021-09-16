// Tests of the minmax() algorithm
// -------------------------------



#include "../../structures/include.hh"   // Standard file that handles all inclusions for you.


Board board(3);


// TicTacToe (2 Computers)
void test_1 () {
    // Title
    cout << "TicTacToe (2 Computers):" << endl
         << "------------------------" << endl
         << endl;
    
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



// Menu for choosing which test to run
int main () { 
    
    // Title
    cout << endl;
    cout << "Tests of the minmax() algorithm" << endl
        << "===============================" << endl;
    cout << endl;

    // Options
    cout << "0. Quit" << endl;
    cout << "1. TicTacToe (2 Computers)" << endl;
    cout << "2. TicTacToe (1 Human, 1 Computer)" << endl;
    cout << endl;
    
    // User prompt
    int choice = input_range(2, "Choose an option: ");   // Adapt number to number of tests.
    cout << endl;
    cout << endl;

    // Test execution
    switch (choice) {
        case 0: break;
        case 1: test_1(); break;
        case 2: test_2(); break;
        default: 
            cout << "Didn't find any matching test for " << choice << "." << endl; break;
    }

    cout << endl;
}
