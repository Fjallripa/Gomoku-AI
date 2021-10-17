// All inclusions of libraries and project files in one place
// ==========================================================
//      Only include this file when assembling a test or game.



// STL libraries
#include <limits>

#include <array>
#include <vector>

#include <iostream>
#include <sstream>
#include <string>


// Abbreviations
using std::cout;
using std::cin;
using std::endl;


// Project files
#include "global_objects.cc"

#include "types/symbol.cc"
#include "types/direction.cc"
#include "types/algorithm.cc"

#include "functions/input_numbers.cc"
#include "functions/input_text.cc"
#include "functions/messages.cc"

#include "class_headers/board.hh"
#include "class_headers/square.hh"
#include "class_headers/player.hh"
#include "class_headers/group.hh"

#include "class_members/board.cc"
#include "class_members/square.cc"
#include "class_members/player.cc"
#include "class_members/human.cc"
#include "class_members/computer.cc"
#include "class_members/group.cc"

#include "algorithms/placeholder.cc"
#include "algorithms/minimax.cc"
