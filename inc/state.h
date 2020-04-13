#ifndef STATE_H
# define STATE_H

#include <vector>

using namespace std;

struct Card {
	vector<bool> players;  // The players which could have this card.
};

struct Player {
	int num_cards;         // The number of cards this player has.
	vector<bool> sets;     // The sets of which this player has at least one card.
};

struct State {
	int onturn;
	vector<Card> cards;
	vector<Player> players;
};

#endif
