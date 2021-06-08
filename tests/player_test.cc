#include "../game/player.cc"

Board board;
Group group;


void test_1 () {
    cout << "Testing player attributes:" << endl;
    Player player_a = Player(board, stone[0], group);
    Player player_b = Player(board, stone[1], group);

    player_a.make_move();
    player_b.make_move();
}




int main () {
    int input_number;
    const int max_number = 1;

    // Menu for choosing which test to run
    while (input_number < 1 or input_number > max_number) {
        input_int(input_number);
    }
    
    if      (input_number == 1) test_1();  
    //else if (input_number == 2) test_2();
    //else if (input_number == 3) test_3();
    else cout << "Didn't find any matching test for" << input_number << endl;

}