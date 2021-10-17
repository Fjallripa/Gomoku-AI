// Tests of the Direction type and structures
// ==========================================


#include "../../structures/include.hh"   // Standard file that handles all inclusions.





// Functions for individual tests
// ------------------------------

/* (automated) Tests if the three "direction arrays" work correctly. */
void test_1 () {
    
    print_subtitle("Testing if the three \"direction arrays\" work correctly");
    
    cout << "all_directions:  ";
    for (Direction direction : all_directions) {
        cout << direction << ", ";
    }
    cout << endl;

    cout << "fore_directions:  ";
    for (Direction direction : fore_directions) {
        cout << direction << ", ";
    }
    cout << endl;

    cout << "direction_string:  ";
    for (std::string direction : direction_string) {
        cout << endl << "\"" << direction << "\", ";
    }
    cout << endl;

    cout << endl;
}





// Menu for choosing a test
// ------------------------

int main () {
    while (true) {   // The program returns to the menu after finishing a test.
        
        print_title("Tests of the Direction type and structures");
        
        // Options
        cout << "0. Quit" << endl;
        cout << "1. Testing if the three \"direction arrays\" work correctly" << endl;
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
