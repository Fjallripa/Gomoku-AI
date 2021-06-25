// Tests of the Direction type and structures
// ---------------------------------------



#include "../structures/include.hh"   // Standard file that handles all inclusions.


int main () {
    // Testing if the three "direction arrays" work correctly
    
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
}
