// Definition of custom input functions
// ------------------------------------



// Code adapted from http://www.cplusplus.com/forum/beginner/170685/

// Declaration of internal functions doing the input handling
std::istream &get_int(std::istream &ins, int &n);
std::istream &get_coord(std::istream &ins, int &x, int &y);




// User facing input functions
// ---------------------------
    // They are designed to provide a safe and complete input method for certain data types. 
    

// Input function for single integers
void input_int (int &x, std::string info = "") {
    do {
        cout << info;
        cin.clear();
    } while (not get_int(cin, x));
}


// Input function for two integers separated by whitespace (input for 2D-integer-coordinates)
void input_coord (int &x, int &y, std::string info = "") {
    do {
        cout << info;
        cin.clear();
    } while (not get_coord(cin, x, y));
}


// Input function where only a specified range of integers is allowed, e.g. menu selection.
int input_range (int min, int max, std::string input_prompt = "") {
    int input_number = min - 1;

    input_int(input_number, input_prompt);
    while (input_number < min or input_number > max) {   // while-loop to complain in case of bad input and ask again.
        cout << "You have to enter an integer between " << min << " and " << max << "." << endl;
        input_int(input_number, input_prompt);
    }

    return input_number;
}

int input_range (int max,  std::string input_prompt = "") {
    return input_range(0, max, input_prompt);
}




// Definition of internal functions doing the input handling
// ---------------------------------------------------------

// Handling the input of single integers
std::istream &get_int(std::istream &ins, int &number) {
    number = 0;   // Number to return, set to 0 for safety.
    std::string input_string;

    // Read a line from the user.
    if (std::getline(ins, input_string)) {       
        // Get rid of any trailing whitespace.
        input_string.erase(input_string.find_last_not_of(" \f\n\r\t\v") + 1);
        
        // Hand over input. If the trailing characters are not digits, nothing will happen.
        std::istringstream stream(input_string);
        stream >> number;

        // Check to see if something is left over or there was no input at all.
        if (!stream.eof() or input_string == "") {
            // If not, the fail flag will cause this input function to be called again.
            ins.setstate(std::ios::failbit);
        }
    }
    else {
        cout << endl << "Assuming Ctrl-D was used, the program will now shut down." << endl;
        exit(0);
        // No other solution was found than quitting the program as getline or cin doesn't 
        // seem to accept any input after Ctrl-D and seemingly can't be restored.
    }

    return ins;
}


// Handling the input of two integer coordinates
std::istream &get_coord(std::istream &ins, int &x, int &y) {
    const std::string whitespace = " \f\n\r\t\v";
    x = 0; y = 0;   // coordinates to return, set to 0 for safety

    std::string input_string;
    std::string coor_1;   // first substring
    std::string coor_2;   // second one
    
    // Process input if there is any valid input
    if (std::getline(ins, input_string))   // Read a line (terminated by ENTER|NEWLINE) from the user.
    {
        // Cut out the to numbers from the input.
        input_string.erase(input_string.find_last_not_of(whitespace) + 1);   // Get rid of any trailing whitespace.
        
        size_t split_point = input_string.find_last_of(whitespace) + 1;   // Find the split point.
        coor_1 = input_string.substr(0, split_point);
        coor_2 = input_string.substr(split_point);
        
        coor_1.erase(coor_1.find_last_not_of(whitespace) + 1);   // Get rid of trailing whitespace for the first substring.
        

        // Convert strings to integers
        std::istringstream stream_1(coor_1);
        std::istringstream stream_2(coor_2);
        stream_1 >> x;
        stream_2 >> y;
        
        // Check to see that there is nothing left over.
        if (not (stream_1.eof() and stream_2.eof())   // if there are bits left that are not integers
            or coor_1 == "" or coor_2 == "")    // if there was no input at all
        {
            ins.setstate(std::ios::failbit);
        }
    } 
    else {
        cout << endl << "Assuming Ctrl-D was used, the program will now shut down." << endl;
        exit(0);
        // No other solution was found than quitting the program as getline or cin doesn't 
        // seem to accept any input after Ctrl-D and seemingly can't be restored. 
    } 
    
    return ins;
}
