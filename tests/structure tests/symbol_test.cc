// Tests of the Symbol type and structures
// ---------------------------------------



#include "../../structures/include.hh"   // Standard file that handles all inclusions.



// Testing if all the symbols and stones display correctly.
void test_1 () {
    cout << "Testing if all the symbols and stones display correctly:" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl;

    cout << "stones:  " << empty << stone[0] << stone[1] << stone[2] << stone[3] << endl;
    cout << "symbols: " << empty << x << o << d << p << endl;

    cout << endl;
}




int main () {
    
    // Menu for choosing which test to run
    bool continue_program = true;
    while (continue_program) {   // With this while-loop, the program returns to the menu after finishing a test.
        cout << endl;
        cout << "Tests of the Symbol type and structures" << endl;
        cout << "=======================================" << endl;
        cout << endl;

        cout << "0. Quit" << endl;
        cout << "1. Testing if all the symbols and stones display correctly" << endl;
        cout << endl;
        
        int choice = input_range(1, "Choose an option: ");
        cout << endl;
        cout << endl;

        switch (choice) {
            case 0: continue_program = false; break;
            case 1: test_1(); break;
            default: 
                cout << "Didn't find any matching test for " << choice << "." << endl; break;
        }  

        cout << endl;
    }
}
