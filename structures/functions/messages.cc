// Functions displaying common messages
// ------------------------------------


// Menues

void print_title(std::string title) {
    std::string underline(title.length(), '=');

    cout << endl;
    cout << title << endl;
    cout << underline << endl;
    if (dev_mode_on) {
        cout << "> Developer Mode" << endl;
    }
    cout << endl;
}


void print_dev_intro() {
    cout << "Developer Mode on:" << endl
         << "At each move, the \"> \"-prompt enables the following choices:" << endl
         << "* Pressing Enter: Show scores for all possible moves / Execute the best move." << endl
         << "* Entering a coordinate `x y`: Explore a specific move by printing a hypothetical board." << endl 
         << "    Scores and further moves will refer to that board." << endl;
}



// Error messages

void print_switch_default (int option) {
    cout << "Error in the code: The option " << option << " doesn't have a matching case." << endl;
}
