#ifndef STATE_H
# define STATE_H

#include <vector>

using namespace std;

struct Card {
	vector<bool> players;  // The players which could have this card.
};

struct Player {
	int num_cards;         // The number of cards the player has.
	vector<int> sets;      // The number of cards the player has from a certain set.
};

struct State {
	int onturn;
	vector<Card> cards;
	vector<Player> players;
};

#endif
