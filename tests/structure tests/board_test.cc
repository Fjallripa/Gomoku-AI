// Tests of the Board methods
// --------------------------



#include "../../structures/include.hh"   // Standard file that handles all inclusions.



// Testing basic Board display methods
void test_1 () {
    cout << "Testing basic Board display methods:" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;

    // Testing the Board constructor
        cout << "Testing the Board constructor:" << endl;
        Board board_3      = Board(3);
        Board board_8      = Board(8);
        
        Board board_min    = Board(min_board_length);
        Board board_max    = Board(max_board_length);
        
        // Testing if the constructor, board.length() and board.size() work
            cout << "Boards created:" << endl;
            cout << "3x3     board: board.length() =   " << board_3.length() << ", board.size() =     " << board_3.size() << endl;
            cout << "8x8     board: board.length() =   " << board_8.length() << ", board.size() =    " << board_8.size() << endl;
            cout << min_board_length << "x" << min_board_length << "     board: board.length() =   " << board_min.length() << ", board.size() =     " << board_min.size() << endl;
            cout << max_board_length << "x" << max_board_length << " board: board.length() = " << board_max.length() << ", board.size() = " << board_max.size() << endl;
        cout << endl;

        // Opportunity to test constructing other board sizes
            cout << "Create an own board:" << endl;
            cout << "A board length between " << min_board_length << " and " << max_board_length << " will work, else the constructor terminates the program and complains." << endl;
            int size = input_int("Enter the board length: ");
            Board board_input = Board(size);
            cout << size << "x" << size << " board: board.length() = " << board_input.length() << ", board.size() = " << board_input.size() << endl;
        cout << endl;
    cout << endl;


    // Testing board.inside()
        cout << "Testing inside():" << endl;
        std::vector board_list = {board_min, board_3, board_8, board_max};
        for (Board board : board_list) {   // Looping through all the previously created boards
            cout << std::boolalpha
                << "(x, y) inside " << board.length() << "x" << board.length() << " board:";
            cout << endl;

            // Testing coordinates that should be inside the board
                cout << "Should be inside: " << endl;
                std::vector x_s = {0, board.length() - 1, board.length() - 1, 0, board.length() / 2};
                std::vector y_s = {0, board.length() - 1, 0, board.length() - 1, board.length() / 2};
                for (int i = 0; i < x_s.size(); i++) {
                    cout << "(" << x_s[i] << "," << y_s[i] << "):" << board.inside(x_s[i], y_s[i]) << ", ";
                }
            cout << endl;
            
            // Testing coordinates that shouldn't be inside
                cout << "Shouldn't be inside: " << endl;
                std::vector x_s2 = {-1, board.length(), board.length(), 0, board.length() - 1, -1, board.length() / 2, board.length() * 2};
                std::vector y_s2 = {-1, board.length(), 0, board.length(), -1, board.length() - 1, board.length() * 2, board.length() / 2};
                for (int i = 0; i < x_s2.size(); i++) {
                    cout << "(" << x_s2[i] << "," << y_s2[i] << "):" << board.inside(x_s2[i], y_s2[i]) << ", ";
                }
            cout << endl;

            cout << endl;
        }
    cout << endl;


    // Testing board.at()
        cout << "Testing at() - returns symbols at given coordinates:" << endl;
        for (Board board : board_list) {
            cout << std::boolalpha
                << "Symbol of " << board.length() << "x" << board.length() << " board at (x, y):";
            cout << endl;

            // Testing coordinates that should be inside the board
                cout << "Should be \".\": " << endl;
                std::vector x_s = {0, board.length() - 1, board.length() - 1, 0, board.length() / 2};
                std::vector y_s = {0, board.length() - 1, 0, board.length() - 1, board.length() / 2};
                for (int i = 0; i < x_s.size(); i++) {
                    cout << "(" << x_s[i] << "," << y_s[i] << "): " << board.at(x_s[i], y_s[i]) << " , ";
                }
            cout << endl;
            
            // Testing coordinates that shouldn't be inside
                cout << "Should be \"outside\": " << endl;
                std::vector x_s2 = {-1, board.length(), board.length(), 0, board.length() - 1, -1, board.length() / 2, board.length() * 2};
                std::vector y_s2 = {-1, board.length(), 0, board.length(), -1, board.length() - 1, board.length() * 2, board.length() / 2};
                for (int i = 0; i < x_s2.size(); i++) {
                    cout << "(" << x_s2[i] << "," << y_s2[i] << "): " << board.at(x_s2[i], y_s2[i]) << " , ";
                }
            cout << endl;

            cout << endl;
        }
}


// Testing board output operator
void test_2 () {
    cout << "Testing board output:" << endl;
    cout << "---------------------" << endl;
    cout << endl;

    int size = input_int("Enter the board length: ");
    Board board = Board(size);
    
    cout << board;
}


// Testing board.place()
void test_3 () {
    cout << "Testing to place stones on board:" << endl;
    cout << "---------------------------------" << endl;
    cout << endl;

    Board board = Board(3);

    std::vector symbols = {x, p,              d, o,                  x,                  empty, o,              p,  x, o,  x, empty,          d};
    std::vector x_s = {0, board.length() - 1, 0, board.length() - 1, board.length() / 2, 0, board.length() / 2, -1, 0, -1, board.length(), 0, board.length()};
    std::vector y_s = {0, board.length() - 1, board.length() - 1, 0, board.length() / 2, 0, board.length() / 2, -1, -1, 0, 0, board.length(), board.length()};
    for (int i = 0; i < symbols.size(); i++) {
        cout << "Attempting to place " << symbols[i] << " at (" << x_s[i] << "," << y_s[i] << "):" << endl;
        board.place(x_s[i], y_s[i], symbols[i]);
        cout << board;
    }
    cout << endl;
}


// Testing winner congratulation
void test_4 () {
    cout << "Testing winner congratulation:" << endl;
    cout << "------------------------------" << endl;
    cout << endl;

    Board board = Board(1);

    cout << "Not setting a winner     : ";                            board.congratulate();
    cout << "Setting x as winner      : ";   board.set_winner(x);     board.congratulate();
    cout << "Setting Δ as winner      : ";   board.set_winner(d);     board.congratulate();
    cout << "Setting \"empty\" as winner: "; board.set_winner(empty); board.congratulate();
    cout << endl;
}


// Testing constructors with winning length
void test_5 () {
    cout << "Testing winning_length():" << endl;
    cout << "-------------------------" << endl;
    cout << endl;

    // Custom edge length and automatic winning length
        cout << "Construct a board with custom edge length and automatic winning length:" << endl;
        int edge_length    = input_int("edge length   : ");
        
        Board board = Board(edge_length);
        cout << "board.length(): " << board.length() << ", board.winning_length(): " << board.winning_length() << endl;
    cout << endl;

    // Custom edge length and custom winning length
        cout << "Construct a board with custom edge length and custom winning length:" << endl;
        edge_length        = input_int("edge length   : ");
        int winning_length = input_int("winning length: ");
        
        board = Board(edge_length, winning_length);
        cout << "board.length(): " << board.length() << ", board.winning_length(): " << board.winning_length() << endl;
    cout << endl;
}




int main () {
    
    // Menu for choosing which test to run
    bool continue_program = true;
    while (continue_program) {   // With this while-loop, the program returns to the menu after finishing a test.
        cout << endl;
        cout << "Tests of the Board methods" << endl;
        cout << "==========================" << endl;
        cout << endl;

        cout << "0. Quit" << endl;
        cout << "1. Testing board.at()" << endl;
        cout << "2. Testing board output operator" << endl;
        cout << "3. Testing board.place()" << endl;
        cout << "4. Testing winner congratulation" << endl;
        cout << "5. Testing constructors with winning length" << endl;
        cout << endl;
        
        int choice = input_range(5, "Choose an option: ");
        cout << endl;
        cout << endl;

        switch (choice) {
            case 0: continue_program = false; break;
            case 1: test_1(); break;
            case 2: test_2(); break;
            case 3: test_3(); break;
            case 4: test_4(); break;
            case 5: test_5(); break;
            default: 
                cout << "Didn't find any matching test for " << choice << "." << endl; break;
        }

        cout << endl;
    }
}
