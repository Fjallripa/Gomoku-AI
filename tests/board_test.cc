// Tests of the Board methods
// --------------------------



#include "../structures/include.hh"   // Standard file that handles all inclusions.

Board board;


// Testing board.at()
void test_1 () {
    cout << "Testing to return symbols at given coordinates:" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;

    cout << "(1, 1): " << board.at(1, 1) << endl;
    cout << "(0, 0): " << board.at(0, 0) << endl;
    cout << "(2, 2): " << board.at(2, 2) << endl;
    cout << "(2, 3): " << board.at(2, 3) << endl;  // outside 3x3 board. In that case, will generate error and stop the program.
    cout << "(3, 2): " << board.at(3, 2) << endl;

    cout << endl;
}


// Testing board output operator
void test_2 () {
    cout << "Testing board output:" << endl;
    cout << "---------------------" << endl;

    cout << board;
}


// Testing board.place()
void test_3 () {
    cout << "Testing to place stones on board:" << endl;
    cout << "---------------------------------" << endl;

    board.place(edge_length, 0, x);
    board.place(0, 0, x);
    board.place(-1, 0, x);   // outside board, does not place
    board.place(0, -1, x);
    board.place(0, edge_length, x);
    board.place(edge_length, 0, x);
    board.place(2, 0, x);
    board.place(2, 0, o);   // replaces former stone
    board.place(1, 2, x);
    board.place(1, 2, empty);   // replaces former stone
    cout << board;
}




int main () {
    // Menu for choosing which test to run
    cout << endl;
    cout << "Tests of the Board methods" << endl;
    cout << "==========================" << endl;
    cout << endl;

    cout << "0. Quit" << endl;
    cout << "1. Testing board.at()" << endl;
    cout << "2. Testing board output operator" << endl;
    cout << "3. Testing board.place()" << endl;
    cout << endl;
    
    int choice = input_range(3, "Choose an option: ");
    cout << endl;
    cout << endl;

    switch (choice) {
        case 0: break;
        case 1: test_1(); break;
        case 2: test_2(); break;
        case 3: test_3(); break;
        default: 
            cout << "Didn't find any matching test for " << choice << "." << endl; break;
    }

    cout << endl;
}
