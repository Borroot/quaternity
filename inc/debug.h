/**
 * @file
 *
 * \brief This file defines print operators for custom structs.
 * These are useful for debugging purposes.
 */

#ifndef DEBUG_H
# define DEBUG_H

#include <iostream>
#include <vector>

#include "round.h"
#include "settings.h"
#include "state.h"

using namespace std;

/**
 * Print the elements of a vector nicely.
 */
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

ostream &operator<<(ostream &out, const Card &card);
ostream &operator<<(ostream &out, const Player &player);
ostream &operator<<(ostream &out, const Settings &settings);
ostream &operator<<(ostream &out, const State &state);
ostream &operator<<(ostream &out, const Question &question);

#endif
