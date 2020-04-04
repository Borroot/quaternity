#ifndef DEBUG_H
# define DEBUG_H

#include <iostream>
#include <vector>

#include "card.h"
#include "player.h"

using namespace std;

ostream &operator<<(ostream &out, const Card &card);
ostream &operator<<(ostream &out, const Player &player);

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

#endif
