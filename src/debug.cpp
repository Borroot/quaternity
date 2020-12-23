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

/**
 * @brief Print the information of a card struct.
 */
std::ostream &operator<<(std::ostream &out, const Card &card)
{
	out << card.players;
	return out;
}

/**
 * @brief Print the information of a player struct.
 */
std::ostream &operator<<(std::ostream &out, const Player &player)
{
	out << "(" << player.num_cards << "," << player.sets << ")";
	return out;
}

/**
 * @brief Print the information of a settings struct.
 */
std::ostream &operator<<(std::ostream &out, const Settings &settings)
{
	out << "Settings: "
		<< "set size = "    << settings.SET_SIZE    << ", "
		<< "num sets = "    << settings.NUM_SETS    << ", "
		<< "num players = " << settings.NUM_PLAYERS << "." << std::endl;
	return out;
}

/**
 * @brief Print the information of a state struct.
 */
std::ostream &operator<<(std::ostream &out, const State &state)
{
	out << "Onturn: "   << state.onturn   << std::endl
	    << "Cards: "    << state.cards    << std::endl
	    << "Players: "  << state.players  << std::endl
	    << "Quartets: " << state.quartets << std::endl;
	return out;
}

/**
 * @brief Print the information of a question struct.
 */
std::ostream &operator<<(std::ostream &out, const Question &question)
{
	out << "Question: "
	    << "player = " << question.player << ", "
	    << "set = "    << question.set    << ", "
	    << "card = "   << question.card   << "." << std::endl;
	return out;
}
