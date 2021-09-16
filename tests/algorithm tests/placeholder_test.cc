// Tests of of the placeholder() algorithm
// ---------------------------------------



#include "../../structures/include.hh"   // Standard file that handles all inclusions for you.

Board board(5);



// Automatic test (4 Computers, 5x5 board)
void test_1 () {
    cout << "Automatic test (4 Computers, 5x5 board)" << endl;
    cout << "---------------------------------------" << endl;
    cout << endl;
    
    // Creating and adding computer players to the group
        const int computer_count = 4;
        std::vector<Computer> computer_players;
        for (int i = 0; i < computer_count; i++) {
            computer_players.emplace_back(board, stone[i]);
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
        cout << "\          " << endl
             << "...        " << endl
             << "X at (0,4) " << endl
             << "           " << endl
             << "4 X . . . ." << endl
             << "3 Π X O Δ Π" << endl
             << "2 Δ Π X O Δ" << endl
             << "1 O Δ Π X O" << endl
             << "0 X O Δ Π X" << endl
             << "0 1 2 3 4  " << endl
             << "           " << endl
             << "X has won! " << endl
             << "\"         " << endl;
    
    cout << endl;
}


// Manual test (choose number of Humans and Computers)
void test_2 () {
    cout << "Manual test (choose number of Humans and Computers):" << endl;
    cout << "----------------------------------------------------" << endl;
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
        cout << "Test now if the placeholder() algorithm behaves correctly." << endl
            << "Does it in every situation place a stone at the first square that is empty?" << endl;
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
    cout << "Tests of the placeholder() algorithm" << endl;
    cout << "====================================" << endl;
    cout << endl;

    cout << "0. Quit" << endl;
    cout << "1. Automatic test (4 Computers, 5x5 board)" << endl;
    cout << "2. Manual test (choose number of Humans and Computers)" << endl;
    cout << endl;
    
    int choice = input_range(2, "Choose an option: ");   // Adapt number to number of tests.
    cout << endl;
    cout << endl;

    switch (choice) {
        case 0: break;
        case 1: test_1(); break;
        case 2: test_2(); break;
        default: 
            cout << "Didn't find any matching test for " << choice << "." << endl; break;
    }

    cout << endl;
}
