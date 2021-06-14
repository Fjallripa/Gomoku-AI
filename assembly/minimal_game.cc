// Implementation of a bare-bones Gomoku game
// ------------------------------------------



#include "../game/include.hh"

Board board;
Group group;
std::vector<Player> players;
const int player_count = 2;  // Not more than max_player_count!



int main () {
    
    // Creating and adding players to the group
    for (int i = 0; i < player_count; i++) {
        players.emplace_back(board, stone[i]);
    }
    for (int i = 0; i < player_count; i++) {   // Separate for-loop needed to avoid pointer-problems
        group.append(&players[i]);
    }
    
    // Playing the game
    cout << endl << " " << player_count << "-PLAYER GOMOKU" << endl << endl;

    cout << board;
    Player* current_player = group.first();
    for (int i = 0; i < board_size; i++) {
        current_player->make_move();
        current_player = current_player->next();
    }
}