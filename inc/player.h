#ifndef PLAYER_H
# define PLAYER_H

#include <vector>

using namespace std;

struct Player {
	int num_cards;            // The number of cards this player has.
	vector<bool> categories;  // The categories of which this player has at least one card.
};

#endif
