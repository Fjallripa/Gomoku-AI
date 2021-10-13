// Tests of the Symbol type and structures
// =======================================


#include "../../structures/include.hh"   // Standard file that handles all inclusions.





// Functions for individual tests
// ------------------------------

/* Testing if all the symbols and stones display correctly. */
void test_1 () {
    
    print_subtitle("Testing if all the symbols and stones display correctly");

    cout << "symbols: " << empty << x << o << d << p << endl;
    cout << "stones:   " << stone[0] << stone[1] << stone[2] << stone[3] << endl;
    cout << endl;
}





// Menu for choosing a test
// ------------------------

int main () {
    while (true) {   // The program returns to the menu after finishing a test.
        
        print_title("Tests of the Symbol type and structures");

        // Options
        cout << "0. Quit" << endl;
        cout << "1. Testing if all the symbols and stones display correctly" << endl;
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
