// Implementation of the Group class
// ---------------------------------



// Constructor & Destructor
Group::~Group () {
      // Removing players one by one until the group is empty.
    while (this->length() > 0) {
        this->pop();
    }
}


// Display of internal objects
Player* Group::first () const {
    return this->first_player;
}


int Group::length () const {
    return this->number_of_players;
}


// Actions on instances
void Group::append (Player* new_player) {
    // If there are no players in the group
    if (this->number_of_players < 1) {   //  (< 1 for robustness)
        this->first_player             = new_player;
        
        // The single player is linked to itself.
        this->first()->next_player     = this->first(); 
        this->first()->previous_player = this->first();
    
    // If there's more than one player left in the group
    } else {
        // The old last player becomes the second-to-last.
        Player* old_last_player      = this->first()->prev();
        old_last_player->next_player = new_player;
        
        // The new player becomes the new last player.
        new_player->previous_player     = old_last_player;
        new_player->next_player         = this->first();
        this->first()->previous_player = new_player;
    }

    // The groups player count is incremented.
    this->number_of_players++;
}


Player* Group::pop () {
    // If there are no players in the group
    if (this->number_of_players < 1) {   // (< 1 for robustness)
        return nullptr;
    
    // If there's only one player left in the group
    } else if (this->number_of_players == 1) {
        // The groups only player gets stripped of its links.
        this->first()->previous_player = nullptr;
        this->first()->next_player     = nullptr;

        // Then this player is deleted from the group and returned by the function.
        Player* leaving_player     = this->first();
        this->first_player      = nullptr;
        this->number_of_players = 0;
        return leaving_player;
    
    // If there's more than one player left in the group
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
