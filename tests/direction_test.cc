// Tests of the Direction type and structures
// ---------------------------------------



#include "../game/include.hh"


int main () {
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