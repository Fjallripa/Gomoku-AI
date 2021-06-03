#include "../game/player.cc"

Board board;
Player player_a = Player(board, stone[0]);
Player player_b = Player(board, stone[1]);

void test_1 () {
    cout << "Testing player attributes:" << endl;
    player_a.make_move();
    player_b.make_move();
}



bool test_done;   // If a test is performed, this value is true. Otherwise it becomes false.

int main () {
    int input;
    do {
        test_done = true;
        cout << "test ";
        cin >> input;

        if      (input == 1) test_1();
        //else if (input == 2) test_2();
        //else if (input == 3) test_3();
        else test_done = false;
    } 
    while (not test_done);
}