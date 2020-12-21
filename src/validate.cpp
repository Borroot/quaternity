/**
 * @file
 *
 * @brief This file defines functions which can check if a question or state is
 * valid.
 */

#include <iostream>
#include <vector>
#include <numeric>

#include "debug.h"
#include "match.h"
#include "round.h"
#include "settings.h"
#include "state.h"
#include "update.h"
#include "validate.h"

using namespace std;

/**
 * @brief Check if the question asked and the answer given are valid.
 *
 * In other words, there is at least one valid assignment of all cards to the
 * players, after the question is asked and the answer is given.
 */
bool valid_answer(const Settings &settings, const State &state, const Question &question, const Answer &answer)
{
	// make a deep copy of the state which can be changed
	State state_copy = copy_state(state);
	update_state(settings, state_copy, question, answer);

	// check that no player has more set constraints than cards
	for (Player player: state_copy.players)
		if (player.num_cards < accumulate(player.sets.begin(), player.sets.end(), 0))
			return false;

	// create the graph array and initialize all values to false
	const int NUM_CARDS = settings.NUM_SETS * settings.SET_SIZE;
	Graph graph(NUM_CARDS, vector<bool>(NUM_CARDS, false));

	// set all the correct variables in the graph array
	int hand_offset = 0;
	for (int player_index = 0; player_index < settings.NUM_PLAYERS; player_index++) {
		Player player = state_copy.players[player_index];
		int hand_entry = 0;

		for (int set_index = 0; set_index < settings.NUM_SETS; set_index++) {
			int set = player.sets[set_index];

			while (set-- > 0) {
				for (int set_card = 0; set_card < settings.SET_SIZE; set_card++) {
					int card = set_index * settings.SET_SIZE + set_card;

					if (state_copy.cards[card].players[player_index] && !(player_index == state_copy.onturn && card == question.card))
						graph[hand_offset + hand_entry][card] = true;
				}
				hand_entry++;
			}
		}

		while (hand_entry < player.num_cards) {
			for (int card = 0; card < NUM_CARDS; card++)
				if (state_copy.cards[card].players[player_index] && !(player_index == state_copy.onturn && card == question.card))
					graph[hand_offset + hand_entry][card] = true;
			hand_entry++;
		}

		hand_offset += player.num_cards;
	}

	// TODO Do not allow someone to ask for a card they always have themselves.
	cout << state_copy;
	return match_exists(graph);
}

/**
 * @brief Check if the question asked is valid.
 *
 * Check if the values (player, set, card) are all within the bounds they can
 * be. Additionally check if the player whom a question is asked has at least
 * one card and check that the question is not pointed towards oneself. We also
 * make sure that there is at least one valid answer possible.
 *
 * @return array with two boolean values, the first one indicates if 0/false is
 * a valid answer to the question, the second one indicates if 1/true is valid,
 * if there is no valid answer possible NULL is returned
 */
bool *valid_question(const Settings &settings, const State &state, const Question &question)
{
	if (question.player < 0 || question.player >= settings.NUM_PLAYERS) {
		cerr << "Player is out of bounds." << endl;
		return NULL;
	}

	if (question.set < 0 || question.set >= settings.NUM_SETS) {
		cerr << "Set is out of bounds." << endl;
		return NULL;
	}

	if (question.card < 0 || question.card >= settings.SET_SIZE) {
		cerr << "Card is out of bounds." << endl;
		return NULL;
	}

	if (state.onturn == question.player) {
		cerr << "You cannot ask yourself a question." << endl;
		return NULL;
	}

	if (state.players[question.player].num_cards < 1) {
		cerr << "Player " << question.player << " does not have any cards." << endl;
		return NULL;
	}

	bool *valid_answers = new bool[2];

	valid_answers[0] = valid_answer(settings, state, question, false);
	valid_answers[1] = valid_answer(settings, state, question, true);

	return !valid_answers[0] && !valid_answers[1] ? NULL : valid_answers;
}
