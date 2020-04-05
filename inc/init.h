#ifndef INIT_H
# define INIT_H

#include <vector>

#include "settings.h"
#include "state.h"

State init_state(const Settings &settings);
vector<Card> init_cards(const Settings &settings);
vector<Player> init_players(const Settings &settings);

#endif
