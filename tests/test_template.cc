// Tests of some structure
// =======================


#include "../../structures/include.hh"   // Standard file that handles all inclusions for you.





// Functions for individual tests
// ------------------------------

/* Description of example test */
void test_1 () {    // Store individual tests inside functions "void test_x ()"
    
    print_subtitle("Title of example test");
    
    // Testing this
        /* Code 
        */
    cout << endl;
    

    // Testing that
        /* Code 
        */
    cout << endl;
}



/* Description of another test */
void test_2 () {
    /* Same layout as test_1()
    */
}





// Menu for choosing a test
// ------------------------

int main (int argument_count, char* argument_values[]) {
    // Option for enabling Developer Mode when starting the program
    if (argument_count > 1) {
        if (argument_values[1] == std::string_view{"-dev"}) {
            dev_mode_on = true;
        }
    }

    // Menu
//int main () {   # Simple main()-start if dev mode isn't relevant.
    while (true) {   // The program returns to the menu after finishing a test.
        
        print_title("Tests of some structure");

        // Options
        cout << "0. Quit" << endl;
        cout << "1. Title of example test" << endl;
        cout << "2. Title of another test" << endl;
        //cout << "3. Title of third test" << endl;
        //...
        cout << endl;
        
        // User prompt
        int choice = input_range(1, "Choose an option: ");   //! Adapt number to number of tests.
        cout << endl;
        cout << endl;

        // Test execution
        switch (choice) {
            case 0: return 0;   // Ending the program
            case 1: test_1(); break;
            case 2: test_2(); break;
            //case 3: test_3(); break;
            //...
            default: print_switch_default(choice); break;
        }
        cout << endl;
    }
}
