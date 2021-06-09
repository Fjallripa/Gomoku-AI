#include "player.hh"
#include "input.cc"



// Implementation of the Player class
// ----------------------------------

// Constructor & Destructor
Player::Player (Board& board, const Symbol stone, Group& group) {
    this->board  = &board;
    this->symbol = stone;
    this->group  = &group;
    //this->group->append(this);
}

Player::~Player () {
    //this->group->pop();  // next_player and previous_player are already removed by this function.
    this->group = nullptr;
    this->board = nullptr;
}


// Display of internal objects
Symbol Player::stone () const {
    return this->symbol;
}


Player* Player::next () const {
    return this->next_player;
}


Player* Player::prev () const {
    return this->previous_player;
}


// Actions on instances
void Player::make_move () {
    int x = -1; int y = -1;
    while (not board->inside(x, y) or board->at(x, y) != empty) {
        input_coord(x, y);
    }
    board->place(x, y, this->stone());
    cout << *board;
}




// Implementation of the Group class
// ---------------------------------

// Display of internal objects
Player* Group::first () const {
    return this->first_player;
}


int Group::length () const {
    return this->number_of_players;
}


// Actions on instances
void Group::append (Player* new_player) {
    if (this->number_of_players < 1) {   // if there are no players in the group (< 1 for robustness)
        this->first_player             = new_player;
        
        // The single player is linked to itself.
        this->first()->next_player     = this->first(); 
        this->first()->previous_player = this->first();
    
    } else {
        // The old last player becomes the second-to-last.
        Player* old_last_player      = this->first()->prev();
        old_last_player->next_player = new_player;
        
        // The new player becomes the new last player.
        new_player->previous_player     = old_last_player;
        new_player->next_player         = this->first();
        this->first()->previous_player = new_player;
    }
    this->number_of_players++;  // The groups player count is incremented.
}


Player* Group::pop () {
    if (this->number_of_players < 1) {   // if there are no players in the group (< 1 for robustness)
        return nullptr;
    
    } else if (this->number_of_players == 1) {   // if there's only one player left in the group
        // The groups only player gets stripped of its links.
        this->first()->previous_player = nullptr;
        this->first()->next_player     = nullptr;

        // Then this player is deleted from the group and returned by the function.
        Player* leaving_player     = this->first();
        this->first_player      = nullptr;
        this->number_of_players = 0;
        return leaving_player;
    
    } else {
        // Removal of the group's last player
        Player* leaving_player  = this->first()->prev();
        Player* new_last_player = leaving_player->prev();
        
        // The second-to-last player is linked to the first player, closing the ring.
        this->first()->previous_player = new_last_player;
        new_last_player->next_player   = this->first();
        this->number_of_players--;   // The groups player count is decremented.
        
        // The leaving player is stripped of its links and returned by the function.
        leaving_player->previous_player = nullptr;
        leaving_player->next_player     = nullptr;
        return leaving_player;
    }

}