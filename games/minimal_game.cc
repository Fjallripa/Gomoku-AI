// Implementation of a bare-bones Gomoku game
// ------------------------------------------



#include "../structures/include.hh"   // Standard file that handles all inclusions.

Board board;
Group group;
std::vector<Human> human_players;
const int player_count = 2;  // Not more than max_player_count!



int main () { 
    // Creating and adding players to the group
    for (int i = 0; i < player_count; i++) {
        human_players.emplace_back(board, stone[i]);
    }
    for (int i = 0; i < player_count; i++) {   // Separate for-loop needed to avoid pointer-problems
        group.append(&human_players[i]);
    }
    

    // Playing the game
    Player* current_player = group.first();
    
    cout << endl << " " << player_count << "-PLAYER GOMOKU" << endl << endl;
    cout << board;
    
    current_player->make_move();
    for (int i = 1; not current_player->is_winner() and i < board_size; i++) {
        current_player = current_player->next();
        current_player->make_move();
    }
    board.congratulate();
    cout << endl;
}
