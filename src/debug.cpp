/**
 * @file
 *
 * @brief This file defines print operators for custom structs.
 * These are useful for debugging purposes.
 */

#include <iostream>
#include <vector>

#include "debug.h"
#include "round.h"
#include "settings.h"
#include "state.h"

using namespace std;

/**
 * @brief Print the information of a card struct.
 */
ostream &operator<<(ostream &out, const Card &card)
{
	out << card.players;
	return out;
}

/**
 * @brief Print the information of a player struct.
 */
ostream &operator<<(ostream &out, const Player &player)
{
	out << "(" << player.num_cards << "," << player.sets << ")";
	return out;
}

/**
 * @brief Print the information of a settings struct.
 */
ostream &operator<<(ostream &out, const Settings &settings)
{
	out << "Settings: "
		<< "set size = "    << settings.SET_SIZE    << ", "
		<< "num sets = "    << settings.NUM_SETS    << ", "
		<< "num players = " << settings.NUM_PLAYERS << "." << endl;
	return out;
}

/**
 * @brief Print the information of a state struct.
 */
ostream &operator<<(ostream &out, const State &state)
{
	out << "Onturn: "  << state.onturn  << endl
	    << "Cards: "   << state.cards   << endl
	    << "Players: " << state.players << endl;
	return out;
}

/**
 * @brief Print the information of a question struct.
 */
ostream &operator<<(ostream &out, const Question &question)
{
	out << "Question: "
	    << "player = " << question.player << ", "
	    << "set = "    << question.set    << ", "
	    << "card = "   << question.card   << "." << endl;
	return out;
}
