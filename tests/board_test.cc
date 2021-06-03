#include "../game/board.cc"


Board board;

void test_1 () {
    cout << "Testing coordinates:" << endl;
    cout << "(1, 1): " << board.at(1, 1) << endl;
    cout << "(0, 0): " << board.at(0, 0) << endl;
    cout << "(2, 2): " << board.at(2, 2) << endl;
    cout << "(2, 3): " << board.at(2, 3) << endl;
    cout << "(3, 2): " << board.at(3, 2) << endl;
}

void test_2 () {
    cout << "Testing board output:" << endl;
    cout << board << endl;
}

void test_3 () {
    cout << "Testing placing stones on board:" << endl;
    board.at(1, 1) = d; 
    cout << board << endl;
}



bool test_done;   // If a test is performed, this value is true. Otherwise it becomes false.

int main () {
    int input;
    do {
        test_done = true;
        cout << "test ";
        cin >> input;

        if      (input == 1) test_1();
        else if (input == 2) test_2();
        else if (input == 3) test_3();
        else test_done = false;
    } 
    while (not test_done);
}
    