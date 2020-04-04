#ifndef DEBUG_H
# define DEBUG_H

#include <iostream>
#include <vector>

#include "card.h"
#include "opts.h"
#include "player.h"

using namespace std;

template <class T>
ostream &operator<<(ostream &out, const vector<T> &vector)
{
	out << "[";
	for (int i = 0; i < (int)vector.size(); i++) {
		out << vector[i];
		if (i < (int)vector.size() - 1) {
			out << ",";
		}
	}
	out << "]";
	return out;
}

ostream &operator<<(ostream &out, const Card &card)
{
	out << "C(" << card.category << "," << card.players << ")";
	return out;
}

ostream &operator<<(ostream &out, const Player &player)
{
	out << "P(" << player.num_cards << "," << player.categories << ")";
	return out;
}

ostream &operator<<(ostream &out, const Settings &settings)
{
	out << "Settings: "
		<< "set size = " << settings.SET_SIZE << ", "
		<< "num sets = " << settings.NUM_SETS << ", "
		<< "num players = " << settings.NUM_PLAYERS << ".";
	return out;
}

#endif
