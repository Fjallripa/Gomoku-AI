// Tests of the input functions
// ----------------------------



#include "../../structures/include.hh"   // Standard file that handles all inclusions.



// Testing the example given in the code source
void test_1 () {
    cout << "1. Testing example code:" << endl;
    cout << "------------------------" << endl;
    cout << endl;
    
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


// Testing secure integer input
void test_2 () {
    cout << "2. Testing secure integer input:" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    
    int number;
    input_int(number, "Just input some number: ");
    
    cout << "Yes, it's " << number << "." << endl;
    cout << endl;
}


// Testing secure two-integer input
void test_3 () {
    cout << "3. Testing secure two-integer input:" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;

    int number_1;
    int number_2;

    input_coord(number_1, number_2, "Input two numbers separated by a space: ");

    cout << "You chose (" << number_1 << ", " << number_2 << ")" << endl;
    cout << endl;
}


// Testing secure integer range input
void test_4 () {
    cout << "4. Testing secure integer range input:" << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;

    cout << "Enter a number between 0 and 3:" << endl;
    int choice = input_range(3, "> ");
    cout << "Yes, it's " << choice << "." << endl;
    cout << endl;
        
    cout << "Enter a number between -1 and 10:" << endl;
    choice = input_range(-1, 10, "> ");
    cout << "Yes, it's " << choice << "." << endl;
    cout << endl;
}




int main () {
    // Menu for choosing which test to run
    cout << endl;
    cout << "Tests of the input functions" << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "0. Quit" << endl;
    cout << "1. Example code" << endl;
    cout << "2. Secure integer input       - input_int()" << endl;
    cout << "3. Secure two-integer input   - input_coord()" << endl;
    cout << "4. Secure integer range input - input_range()" << endl;
    cout << endl;
    
    int choice = input_range(4, "Choose an option: ");
    cout << endl;
    cout << endl;
    
    switch (choice) {
        case 0: break;
        case 1: test_1(); break;
        case 2: test_2(); break;
        case 3: test_3(); break;
        case 4: test_4(); break;
        default: 
            cout << "Didn't find any matching test for " << choice << "." << endl; break;
    }

    cout << endl;
}
