/**
 * @file
 *
 * @brief This file defines print operator headers for custom structs and a
 * template for printing a vector. These are useful for debugging purposes.
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <vector>

#include "round.h"
#include "settings.h"
#include "state.h"

/**
 * @brief Print the elements of a vector nicely.
 */
template <class T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vector)
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

std::ostream &operator<<(std::ostream &out, const Card &card);
std::ostream &operator<<(std::ostream &out, const Player &player);
std::ostream &operator<<(std::ostream &out, const Settings &settings);
std::ostream &operator<<(std::ostream &out, const State &state);
std::ostream &operator<<(std::ostream &out, const Question &question);

#endif /* DEBUG_H_ */
