#ifndef STATE_H
# define STATE_H

#include <vector>

using namespace std;

struct Card {
	int category;             // The category (id) this card belongs to.
	vector<bool> players;     // The players which could have this card.
};

struct Player {
	int num_cards;            // The number of cards this player has.
	vector<bool> categories;  // The categories of which this player has at least one card.
};

struct State {
	vector<Card> cards;
	vector<Player> players;
};

#endif
