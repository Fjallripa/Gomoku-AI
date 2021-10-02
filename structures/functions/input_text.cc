// Definition of custom text input functions
// -----------------------------------------



// Declaration of internal functions doing the input handling
std::istream &get_text(std::istream &input_stream, std::string &text);
bool is_printable(std::string string);



// User facing text input functions
// --------------------------------
//      They are designed to provide a safe and complete input method for certain data types. 
    

// Input function for strings
std::string input_text (std::string info = "") {
    std::string text;
    do {
        cout << info;
        cin.clear();
    } while (not get_text(cin, text));
    return text;
}



// Definition of internal functions doing the input handling
// ---------------------------------------------------------


// Handling the input of strings
std::istream &get_text(std::istream &input_stream, std::string &text) {
    text = "";   // Intially set to "" for safety.
    
    // Read a line from the user.
    if (std::getline(input_stream, text)) {   // Normal input   
        // Get rid of any leading or trailing whitespace.
            text.erase(0, text.find_first_not_of(whitespace));
            text.erase(text.find_last_not_of(whitespace) + 1);
        
        // Check to see if the input only consisted of normal, printable text.
            if (not (input_stream.good() and is_printable(text))) {
                // If not, the fail flag will cause this input function to be called again.
                cout << "Please only enter normal text (printable ASCII characters)." << endl;
                input_stream.setstate(std::ios::failbit);
            }
    }
    else {   // Weird input, probably Ctrl-D
        cout << endl << "Assuming Ctrl-D was used, the program will now shut down." << endl;
        exit(0);
        // No other solution was found than quitting the program as getline or cin doesn't 
        // seem to accept any input after Ctrl-D and seemingly can't be restored.
    }

    return input_stream;   // The returned stream will tell if the input was successfull or has to be done again.
}


bool is_printable(std::string string) {
    return std::all_of(string.begin(), string.end(), 
        [](char character) { 
            return isgraph(character) or isblank(character); 
        }
    );
}
