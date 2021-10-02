// Tests of the text input functions
// ---------------------------------



#include "../../structures/include.hh"   // Standard file that handles all inclusions for you.



// Testing basic text input
void test_1 () {    // Store individual tests inside functions "void test_x ()"
    cout << "Testing basic text input:" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    
    std::string text = input_text("Just type some text: ");
    cout << "Result: \"" << text << "\"" << endl;
    cout << "Program ends here." << endl;
    cout << endl;
    
    cout << endl;
}




int main () {
    // Menu for choosing which test to run
    cout << endl;
    cout << "Tests of the text input functions" << endl;
    cout << "=================================" << endl;
    cout << endl;

    cout << "0. Quit" << endl;
    cout << "1. Basic text input - input_text()" << endl;
    cout << endl;
    
    int choice = input_range(1, "Choose an option: ");   // Adapt number to number of tests.
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
