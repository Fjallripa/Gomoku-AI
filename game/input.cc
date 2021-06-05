// Code adapted from http://www.cplusplus.com/forum/beginner/170685/

#include "include.hh"


// Declaration of internal functions doing the input handling
std::istream &get_int(std::istream &ins, int &n);
std::istream &get_coord(std::istream &ins, int &x, int &y);




// User facing input functions
/* They are designed to provide a safe and complete input method for certain data types 
*/

//// Input function for single integers
void input_int (int &x) {
    cin.clear();
    while (not get_int(cin, x)) {
        cin.clear();
    }
}


//// Input function for two integers separated by whitespace (input for 2D-integer-coordinates)
void input_coord (int &x, int &y) {
    cin.clear();
    while (not get_coord(cin, x, y)) {
        cin.clear();
    }
}




// Definition of internal functions doing the input handling
// Handling the input of single integers
std::istream &get_int(std::istream &ins, int &n)
{
    n = 0;   // number to return, set to 0 for safety

    // Read a line (terminated by ENTER|NEWLINE) from the user
    std::string s;
    if (std::getline(ins, s))
    {
        // Get rid of any trailing whitespace
        s.erase(s.find_last_not_of(" \f\n\r\t\v") + 1);

        // Convert it to integer
        std::istringstream ss(s);
        ss >> n;

        // Check to see that there is nothing left over
        if (!ss.eof())
            ins.setstate(std::ios::failbit);
    }
    return ins;
}


// Handling the input of two integer coordinates
std::istream &get_coord(std::istream &ins, int &x, int &y)
{
    const std::string whitespace = " \f\n\r\t\v";
    x = 0; y = 0;   // coordinates to return, set to 0 for safety

    std::string input_string;
    std::string coor_1;   // first substring
    std::string coor_2;   // second one
    
    // Process input if there is any valid input
    if (std::getline(ins, input_string))   // Read a line (terminated by ENTER|NEWLINE) from the user
    {
        // Cut out the to numbers from the input
        input_string.erase(input_string.find_last_not_of(whitespace) + 1);   // Get rid of any trailing whitespace
        
        size_t split_point = input_string.find_last_of(whitespace) + 1;   // Find the split point
        coor_1 = input_string.substr(0, split_point);
        coor_2 = input_string.substr(split_point);
        
        coor_1.erase(coor_1.find_last_not_of(whitespace) + 1);   // Get rid of trailing whitespace for the first substring
        //out << "\"" << coor_1 << "\" \"" << coor_2 << "\"" << endl;

        // Convert strings to integers
        std::istringstream stream_1(coor_1);
        std::istringstream stream_2(coor_2);
        stream_1 >> x;
        stream_2 >> y;
        
        // Check to see that there is nothing left over
        if (not (stream_1.eof() and stream_2.eof())   // if there are bits left that are not integers
            or coor_1 == "" or coor_2 == "")    // if there was no input at all
        {
            ins.setstate(std::ios::failbit);
        }
    }
    
    return ins;
}
