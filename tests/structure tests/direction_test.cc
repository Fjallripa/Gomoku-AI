// Tests of the Direction type and structures
// ---------------------------------------



#include "../../structures/include.hh"   // Standard file that handles all inclusions.



// Testing if the three "direction arrays" work correctly
void test_1 () {
    cout << "Testing if the three \"direction arrays\" work correctly" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl;

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




int main () {
    // Menu for choosing which test to run
    cout << endl;
    cout << "Tests of the Direction type and structures" << endl;
    cout << "==========================================" << endl;
    cout << endl;

    cout << "0. Quit" << endl;
    cout << "1. Testing if the three \"direction arrays\" work correctly" << endl;
    cout << endl;
    
    int choice = input_range(1, "Choose an option: ");
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
