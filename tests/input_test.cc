// Tests of the input functions
// ----------------------------



#include "../game/include.hh"

void test_1 () {
    // Code adapted from http://www.cplusplus.com/forum/beginner/170685/
    int myFace;
    cout << "Please rate my face from 1 to 10: ";

    while (!get_int(cin, myFace) or (myFace < 1) or (myFace > 10))
    {
        cin.clear();
        cout << "Try again: ";
    }

    if (myFace > 7)
        cout << "Thanks!\n";
    else
        cout << "Whatever, dude.\n";
}


void test_2 () {
    cout << "Testing secure integer input (here from 1 to 3):" << endl;
    
    int number = 0;
    const int max_number = 3;
    
    while (number < 1 or number > max_number) {
        input_int(number);
    }
    cout << "You chose option " << number << endl;
    cout << endl;


    input_int(number, "Now, just input some number: ");
    cout << "Yes, it's " << number << "." << endl;
}


void test_3 () {
    cout << "Testing secure two-integer input:" << endl;
    
    int number_1;
    int number_2;

    input_coord(number_1, number_2, "Input two numbers separated by a space: ");

    cout << "You chose (" << number_1 << ", " << number_2 << ")" << endl;
    
}




int main () {
    int input_number;
    const int max_number = 3;

    // Menu for choosing which test to run
    while (input_number < 1 or input_number > max_number) {
        input_int(input_number);
    }
    
    if      (input_number == 1) test_1();  
    else if (input_number == 2) test_2();
    else if (input_number == 3) test_3();
    else cout << "Didn't find any matching test for" << input_number << endl;

}