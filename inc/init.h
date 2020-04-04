#ifndef INIT_H
# define INIT_H

#include <vector>

#include "card.h"
#include "opts.h"
#include "player.h"

vector<Card> init_cards(const Settings &settings);
vector<Player> init_players(const Settings &settings);

#endif
