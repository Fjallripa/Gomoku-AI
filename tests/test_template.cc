// Tests of some structure
// -----------------------



#include "../game/include.hh"   // Standard file that handles all inclusions for you.


// Create common instances if necessary.


// Store individual tests inside functions "void test_x ()"
void test_1 () {
    cout << "Title of example test:" << endl;
    /* Test stuff */
    cin.clear();
}




int main () {
    int input_number;
    const int max_number = 1;   // Change, depending on how many test functions there are to choose from.

    // Menu for choosing which test to run
    while (input_number < 1 or input_number > max_number) {
        input_int(input_number);
    }
    
    if      (input_number == 1) test_1();  
    //else if (input_number == 2) test_2();
    //else if (input_number == 3) test_3();
    else cout << "Didn't find any matching test for" << input_number << endl;
}
