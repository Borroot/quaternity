/**
 * @file
 *
 * @brief This file defines the structs for a question and typedef of an
 * answer.
 */

#ifndef ROUND_H_
#define ROUND_H_

#include <vector>

using namespace std;

/**
 * @brief A question asked by a player. The player asks another player for a
 * specific card from a certain set.
 */
struct Question {

	/**
	 * @brief The player the question is asked to.
	 */
	int player;

	/**
	 * @brief The set the card which is asked belongs to.
	 */
	int set;

	/**
	 * @brief The card in the set which is asked for.
	 */
	int card;
};

/**
 * @brief An answer returned by a player. The answer is either true or false
 * denoting he/she has or does not has the card which was asked for.
 */
typedef bool Answer;

#endif
