// Implementation of a TicTacToe game with optional computer players
// -----------------------------------------------------------------


#include "../structures/include.hh"   // Standard file that handles all inclusions.



enum PlayerSetup {human_v_human, computer_v_human, human_v_computer, computer_v_computer};



void game (PlayerSetup setup) {
    // Creating the TicTacToe board
        Board board(3);

    // Creating the players
        Human human1(board, stone[0]);
        Human human2(board, stone[1]);
        Computer computer1(board, stone[0], minmax);
        Computer computer2(board, stone[1], minmax);
        
        Group players;
        if (setup == human_v_human or setup == human_v_computer) {
            players.append(&human1);
        } else {
            players.append(&computer1);
        }
        if (setup == human_v_human or setup == computer_v_human) {
            players.append(&human2);
        } else {
            players.append(&computer2);
        }

    // Playing the game
        if (dev_mode_on)   print_dev_intro();

        cout << board;
        Player* current_player = players.first();
        current_player->make_move();
        for (int i = 1; not current_player->is_winner() and i < board.size(); i++) {
            current_player = current_player->next();
            current_player->make_move();
        }
        board.congratulate();
}



int main (int argument_count, char* argument_values[]) {
    // Option for enabling Developer Mode when starting the program
    if (argument_count > 1) {
        if (argument_values[1] == std::string_view{"-dev"}) {
            dev_mode_on = true;
        }
    }


    // Menu for choosing with which players to play
    while (true) {   // With this while-loop, the program returns to the menu after finishing a game.
        // Title
        print_title("Tic Tac Toe");

        // Options
        cout << "0. Quit" << endl;
        cout << "1. human v. human   " << endl;
        cout << "2. human v. computer" << endl;
        cout << "3. computer v. computer" << endl;
        cout << endl;

        // User prompt
        int choice = input_range(3, "Choose an option: ");
        cout << endl;
        cout << endl;

        // Player selection
        PlayerSetup players;
        switch (choice) {
            int beginner;
            
            case 0: return 0;   // Ending the program
            case 1: players = human_v_human; break;
            case 2:
                cout << "Who should begin?" << endl;
                cout << "1. human (X)" << endl;
                cout << "2. computer (O)" << endl;
                beginner = input_range(1, 2, "> ");
                cout << endl;

                switch (beginner) {
                    case 1: players = human_v_computer; break;
                    case 2: players = computer_v_human; break;
                    default: print_switch_default(beginner); break;
                }
                break;
            case 3: players = computer_v_computer; break;
            default: print_switch_default(choice); break;
        }

        // Executing the game
        game(players);
        cout << endl;
    }
}
