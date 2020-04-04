#ifndef CARD_H
# define CARD_H

#include <vector>

using namespace std;

struct Card {
	int category;          // The category (id) this card belongs to.
	vector<bool> players;  // The players which could have this card.
};

#endif
