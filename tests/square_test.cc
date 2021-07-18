// Tests of the Square methods
// ---------------------------



#include "../structures/include.hh"   // Standard file that handles all inclusions.



// Testing to move on the board with Square objects
void test_1 () {
    cout << "Testing to move on the board with Square objects:" << endl;
    cout << "-------------------------------------------------" << endl;
    
    Board board = Board(5);

    // Preparing the  board with symbols to detect
        board.place(2, 3, p); board.place(2, 4, d);   // up
        board.place(3, 3, x); board.place(4, 4, o);   // upright
        board.place(3, 2, x); board.place(4, 2, p);   // right
        board.place(3, 1, o); board.place(4, 0, d);   // downright
        board.place(2, 1, o); board.place(2, 0, x);   // down
        board.place(1, 1, d); board.place(0, 0, p);   // downleft
        board.place(1, 2, d); board.place(0, 2, o);   // left
        board.place(1, 3, p); board.place(0, 4, x);   // upleft
        cout << board;


    // Testing out the all_directions array and the go() method
        cout << "Testing out the all_directions array and the go() method:" << endl;
        Square square = Square(board, 2, 2);
    
        cout << "center: (" << square.symbol() << ")" << endl;
        
        int i = 0;               
        for (Direction direction : all_directions) {
            cout << direction_string[i] << ": ("; 
            square.go(direction);      cout << square.symbol() << ", ";
            square.go(direction);      cout << square.symbol() << ", ";
            square.go(direction, -2);  cout << square.symbol() << ")" << endl;
            i++;
        }
        cout << endl;


    // Moving around the board
        // Going once around the board
            cout << "Going once around the board     : ";
            square.go(downleft, 2);
            cout << square.symbol(); square.go(right, 4);
            cout << square.symbol(); square.go(up, 4);
            cout << square.symbol(); square.go(left, 4);
            cout << square.symbol(); square.go(down, 4);
        cout << endl;

        // Going once more around the board
            cout << "Going once more around the board: ";
            square.go(right, 2);
            cout << square.symbol(); square.go(upright, 2);
            cout << square.symbol(); square.go(upleft, 2);
            cout << square.symbol(); square.go(downleft, 2);
            cout << square.symbol(); square.go(downright, 2);
        cout << endl;

        // Trying to go outside the board
            cout << "Trying to go outside the board  : ";
            square.go(down); cout << square.symbol();
            square.go(left, 10); cout << square.symbol() << endl;
        cout << endl;
}




int main () {
    // Menu for choosing which test to run
    cout << endl;
    cout << "Tests of the Square methods" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cout << "0. Quit" << endl;
    cout << "1. Moving on the board with Square objects" << endl;
    cout << endl;
    
    int choice = input_range(1, "Choose an option: ");
    cout << endl;
    cout << endl;

    switch (choice) {
        case 0: break;
        case 1: test_1(); break;
        default: 
            cout << "Didn't find any matching test for " << choice << "." << endl; break;
    }

    cout << endl;
}
