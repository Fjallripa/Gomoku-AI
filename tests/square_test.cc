// Tests of the Square methods
// ---------------------------



#include "../structures/include.hh"   // Standard file that handles all inclusions.

Board board;



void test_1 () {
    cout << "Testing moving on the board with the Square class:" << endl;
    if (edge_length >= 5) {   // Test only works on an at least 5x5 board.
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


        // Testing different moves
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

        cout << "Going once around the board: ";
        square.go(downleft, 2);
        cout << square.symbol(); square.go(right, 4);
        cout << square.symbol(); square.go(up, 4);
        cout << square.symbol(); square.go(left, 4);
        cout << square.symbol(); square.go(down, 4);
        cout << endl;

        cout << "Going once more around the board: ";
        square.go(right, 2);
        cout << square.symbol(); square.go(upright, 2);
        cout << square.symbol(); square.go(upleft, 2);
        cout << square.symbol(); square.go(downleft, 2);
        cout << square.symbol(); square.go(downright, 2);
        cout << endl;

        cout << "Trying to go outside the board: ";
        square.go(down); cout << square.symbol();
        square.go(left, 10); cout << square.symbol();
        cout << endl;
        
        
    } else {
        cout << "The board must be at least 5x5 squares for this test to work." << endl;
    }
}




int main () {
    int input_number;
    const int max_number = 1;   // Change, depending on how many test functions there are to choose from.

    // Menu for choosing which test to run
    while (input_number < 1 or input_number > max_number) {
        input_int(input_number);
    }
    
    if      (input_number == 1) test_1();  
    //else if (input_number == 2) test_2();
    //else if (input_number == 3) test_3();
    else cout << "Didn't find any matching test for" << input_number << endl;
}
