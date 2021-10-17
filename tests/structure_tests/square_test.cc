// Tests of the Square methods
// ===========================


#include "../../structures/include.hh"   // Standard file that handles all inclusions.





// Functions for individual tests
// ------------------------------

/* (automated) Tests to move on the board with Square instances. 
Tests constructor, `square.symbol()`, `square.go()` in all directions 
and also its behavior at the egde of the board.*/
void test_1 () {
    
    print_subtitle("Testing to move on the board with Square instances");

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





// Menu for choosing a test
// ------------------------

int main () {
    while (true) {   // The program returns to the menu after finishing a test.
        
        print_title("Tests of the Square methods");

        // Options
        cout << "0. Quit" << endl;
        cout << "1. Moving on the board with Square objects" << endl;
        cout << endl;
        
        // User prompt
        int choice = input_range(1, "Choose an option: ");   //! Adapt number to number of tests.
        cout << endl;
        cout << endl;

        // Test execution
        switch (choice) {
            case 0: return 0;   // Ending the program
            case 1: test_1(); break;
            default: print_switch_default(choice); break;
        }
        cout << endl;
    }
}
