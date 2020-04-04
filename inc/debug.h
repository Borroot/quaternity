#ifndef DEBUG_H
# define DEBUG_H

#include <iostream>
#include <vector>

#include "card.h"
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

#endif
