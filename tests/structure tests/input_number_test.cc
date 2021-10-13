// Tests of the number input functions
// ===================================


#include "../../structures/include.hh"   // Standard file that handles all inclusions.





// Functions for individual tests
// ------------------------------

/* Testing the example given in the code source */
void test_1 () {
    
    print_subtitle("Testing example code");
    
    // Code adapted from http://www.cplusplus.com/forum/beginner/170685
    int myFace;
    cout << "Please rate my face from 1 to 10: ";

    while (!get_int(cin, myFace) or (myFace < 1) or (myFace > 10)) {
        cin.clear();
        cout << "Try again: ";
    }

    if (myFace > 7) {
        cout << "Thanks!\n";
    } else {
        cout << "Whatever, dude.\n";
    }
    cout << endl;
}



/* Testing secure integer input */
void test_2 () {
    
    print_subtitle("Testing secure integer input");
    
    int number = input_int("Just input some number: ");
    
    cout << "Yes, it's " << number << "." << endl;
    cout << endl;
}



/* Testing secure two-integer input */
void test_3 () {
    
    print_subtitle("Testing secure two-integer input");
    
    int number_1;
    int number_2;
    input_coord(number_1, number_2, "Input two numbers separated by a space: ");

    cout << "You chose (" << number_1 << ", " << number_2 << ")" << endl;
    cout << endl;
}



/* Testing secure integer range input */
void test_4 () {
    
    print_subtitle("Testing secure integer range input");
    
    cout << "Enter a number between 0 and 3:" << endl;
    int choice = input_range(3, "> ");
    cout << "Yes, it's " << choice << "." << endl;
    cout << endl;
        
    cout << "Enter a number between -1 and 10:" << endl;
    choice = input_range(-1, 10, "> ");
    cout << "Yes, it's " << choice << "." << endl;
    cout << endl;
}





// Menu for choosing a test
// ------------------------

int main () {
    while (true) {   // The program returns to the menu after finishing a test.
        
        print_title("Tests of the number input functions");
        
        // Options
        cout << "0. Quit" << endl;
        cout << "1. Example code" << endl;
        cout << "2. Secure integer input       - input_int()" << endl;
        cout << "3. Secure two-integer input   - input_coord()" << endl;
        cout << "4. Secure integer range input - input_range()" << endl;
        cout << endl;
        
        // User prompt
        int choice = input_range(4, "Choose an option: ");   //! Adapt number to number of tests.
        cout << endl;
        cout << endl;
        
        switch (choice) {
            case 0: return 0;   // Ending the program
            case 1: test_1(); break;
            case 2: test_2(); break;
            case 3: test_3(); break;
            case 4: test_4(); break;
            default: print_switch_default(choice); break;
        }
        cout << endl;
    }
}
