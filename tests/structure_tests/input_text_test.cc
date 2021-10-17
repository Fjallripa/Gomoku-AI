// Tests of the text input functions
// =================================


#include "../../structures/include.hh"   // Standard file that handles all inclusions for you.





// Functions for individual tests
// ------------------------------

/* (interactive) Tests secure text input with `input_text()`. */
void test_1 () {

    print_subtitle("Testing basic text input");
    
    std::string text = input_text("Just type some text: ");
    cout << "Result: \"" << text << "\"" << endl;
    cout << endl;
}





// Menu for choosing a test
// ------------------------

int main () {
    while (true) {   // The program returns to the menu after finishing a test.
        
        print_title("Tests of the text input functions");

        // Options
        cout << "0. Quit" << endl;
        cout << "1. Basic text input - input_text()" << endl;
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
