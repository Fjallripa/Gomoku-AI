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




int main () {
    // Menu for choosing which test to run
    cout << endl;
    cout << "Tests of some structure" << endl;
    cout << "=======================" << endl;
    cout << endl;

    cout << "0. Quit" << endl;
    cout << "1. Title of example test" << endl;
    //cout << "2. Title of another test" << endl;
    //cout << "3. Title of third test" << endl;
    //cout << "4. Title of fourth test" << endl;
    cout << endl;
    
    int choice = input_range(1, "Choose an option: ");   // Adapt number to number of tests.
    cout << endl;
    cout << endl;

    switch (choice) {
        case 0: break;
        case 1: test_1(); break;
        //case 2: test_2(); break;
        //case 3: test_3(); break;
        //case 4: test_4(); break;
        default: 
            cout << "Didn't find any matching test for " << choice << "." << endl; break;
    }

    cout << endl;
}
