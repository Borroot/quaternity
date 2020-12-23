/**
 * @file
 *
 * @brief This file defines functions which can check if a question,
 * optionally plus answer, or state is valid.
 */

#include <algorithm>
#include <iostream>
#include <vector>

#include "debug.h"
#include "graph.h"
#include "match.h"
#include "round.h"
#include "settings.h"
#include "state.h"
#include "update.h"
#include "validate.h"

/**
 * @brief Check if there exists a matching for the given state.
 *
 * @see graph_possible
 * @see graph_create
 * @see match_exists
 */
bool valid_state(const Settings &settings, const State &state)
{
	if (!graph_possible(state)) return false;
	Graph graph = graph_create(settings, state);

	return match_exists(graph);
}

/**
 * @brief Check if the question asked and the answer given are valid.
 *
 * - If answer is yes we need to check the player does not already have the
 *   card which is being asked for.
 *   - If the asked player cannot have the card, return false.
 *   - Update the state according to question.
 *     - The player onturn has at least one card from asked set.
 *     - Only the asked player could have the asked card.
 *   - If there exists no matching, return false.
 *
 * - Update state according to question and answer.
 * - Return if matching exists.
 */
bool valid_answer(const Settings &settings, const State &state, const Question &question, const Answer &answer)
{
	if (answer) { // = yes
		// make sure the asked player can have the card being asked
		const int card = question.set * settings.SET_SIZE + question.card;
		if (!state.cards[card].players[question.player]) return false;

		State state_copy = copy_state(state);

		// the player onturn has at least one card from the asked set
		int *set = &state_copy.players[state_copy.onturn].sets[question.set];
		if (*set == 0) *set = 1;

		// the asked player has the card being asked
		state_copy.cards[card].players = std::vector<bool>(settings.NUM_PLAYERS, false);
		state_copy.cards[card].players[question.player] = true;

		if (!valid_state(settings, state_copy)) return false;
	}

	State state_copy = copy_state(state);
	update_state(settings, state_copy, question, answer);

	return valid_state(settings, state_copy);
}

/**
 * @brief Check if the question asked is valid.
 *
 * Check if the values (player, set, card) are all within the bounds they can
 * be. Additionally check if the player whom a question is asked has at least
 * one card, check that the question is not pointed towards oneself and check
 * that we do not ask for a card from a quartet. We also make sure that there
 * is at least one valid answer possible.
 *
 * @return array with two boolean values, the first one indicates if 0/false is
 * a valid answer to the question, the second one indicates if 1/true is valid,
 * if there is no valid answer possible NULL is returned
 */
bool *valid_question(const Settings &settings, const State &state, const Question &question)
{
	if (question.player < 0 || question.player >= settings.NUM_PLAYERS) {
		std::cerr << "Player is out of bounds." << std::endl;
		return NULL;
	}

	if (question.set < 0 || question.set >= settings.NUM_SETS) {
		std::cerr << "Set is out of bounds." << std::endl;
		return NULL;
	}

	if (question.card < 0 || question.card >= settings.SET_SIZE) {
		std::cerr << "Card is out of bounds." << std::endl;
		return NULL;
	}

	if (state.onturn == question.player) {
		std::cerr << "You cannot ask yourself a question." << std::endl;
		return NULL;
	}

	if (state.quartets[question.set] != -1) {
		std::cerr << "You cannot ask a card from a quartet." << std::endl;
		return NULL;
	}

	int num_quartets = std::count(state.quartets.begin(), state.quartets.end(), question.player);
	if (state.players[question.player].num_cards - num_quartets < 1) {
		std::cerr << "Player " << question.player << " does not have any cards." << std::endl;
		return NULL;
	}

	bool *valid_answers = new bool[2];

	valid_answers[0] = valid_answer(settings, state, question, false);
	valid_answers[1] = valid_answer(settings, state, question, true);

	return !valid_answers[0] && !valid_answers[1] ? NULL : valid_answers;
}
