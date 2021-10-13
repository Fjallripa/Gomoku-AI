// Definition of functions displaying common messages
// ==================================================


// Menues
// ------

/* Prints a string double-underlined and with spacing. Mentions Developer Mode if on. */
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



/* Prints a string underlined and with spacing. */
void print_subtitle(std::string subtitle) {
    std::string underline(subtitle.length() + 1, '-');
    
    cout << subtitle << ':' << endl;
    cout << underline << endl;
    cout << endl;
}



/* Prints a short description of what to enter at Developer Mode input prompts. */
void print_dev_intro() {
    cout << "Developer Mode on:" << endl
         << "At each move, the \"> \"-prompt enables the following choices:" << endl
         << "* Pressing Enter: Show scores for all possible moves / Execute the best move." << endl
         << "* Entering a coordinate `x y`: Explore a specific move by printing a hypothetical board." << endl 
         << "    Scores and further moves will refer to that board." << endl;
}




// Error messages
// --------------

// Standard error message that the default option of a switch statement calls indicating an error in the code.
void print_switch_default (int option) {
    cout << "Error in the code: The option " << option << " doesn't have a matching case." << endl;
}
