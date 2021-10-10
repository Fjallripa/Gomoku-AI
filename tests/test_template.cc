// Tests of some structure
// -----------------------



#include "../../structures/include.hh"   // Standard file that handles all inclusions for you.


// Create common instances if necessary.
/* Initializations */



// Title of example test
void test_1 () {    // Store individual tests inside functions "void test_x ()"
    cout << "Title of example test:" << endl;
    cout << "----------------------" << endl;
    cout << endl;
    
    // Testing this
        /* Code */
    cout << endl;
    

    // Testing that
        /* Code */
    cout << endl;
}




// Alternative start of main() - when Developer Mode is relevant
/*
int main (int argument_count, char* argument_values[]) {
    // Option for enabling Developer Mode when starting the program
    if (argument_count > 1) {
        if (argument_values[1] == std::string_view{"-dev"}) {
            dev_mode_on = true;
        }
    }
*/

int main () {
    
    // Menu for choosing which test to run
    bool continue_program = true;
    while (continue_program) {   // With this while-loop, the program returns to the menu after finishing a test.
        // Title
        cout << endl;
        cout << "Tests of some structure" << endl;
        cout << "=======================" << endl;
        /* // Delete if Developer Mode isn't used in the test. 
        if (dev_mode_on) {
            cout << "> Developer Mode" << endl;
        } 
        */
        cout << endl;

        // Options
        cout << "0. Quit" << endl;
        cout << "1. Title of example test" << endl;
        //cout << "2. Title of another test" << endl;
        //cout << "3. Title of third test" << endl;
        //cout << "4. Title of fourth test" << endl;
        cout << endl;
        
        // User prompt
        int choice = input_range(1, "Choose an option: ");   // Adapt number to number of tests.
        cout << endl;
        cout << endl;

        // Test execution
        switch (choice) {
            case 0: continue_program = false; break;
            case 1: test_1(); break;
            //case 2: test_2(); break;
            //case 3: test_3(); break;
            //case 4: test_4(); break;
            default: 
                cout << "Didn't find any matching test for " << choice << "." << endl; break;
        }

        cout << endl;
    }
}
