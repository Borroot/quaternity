/**
 * @file
 *
 * @brief This file defines functions which can check if
 * a question or state is valid.
 */

#include <iostream>
#include <vector>

#include "debug.h"
#include "round.h"
#include "settings.h"
#include "state.h"
#include "validate.h"

using namespace std;

/**
 * @brief Do easy checks on if the question is valid.
 *
 * Check if the values (player, set, card) are all within
 * the bounds they can be. Additionally check if the player
 * whom a question is asked has at least one card and check
 * that the question is not pointed towards oneself.
 */
bool valid_question(const Settings &settings, const State &state, const Question &question)
{
	if (question.player < 0 || question.player >= settings.NUM_PLAYERS) {
		cerr << "Player is out of bounds." << endl;
		return false;
	}

	if (question.set < 0 || question.set >= settings.NUM_SETS) {
		cerr << "Set is out of bounds." << endl;
		return false;
	}

	if (question.card < 0 || question.card >= settings.SET_SIZE) {
		cerr << "Card is out of bounds." << endl;
		return false;
	}

	if (state.onturn == question.player) {
		cerr << "You cannot ask yourself a question." << endl;
		return false;
	}

	if (state.players[question.player].num_cards < 1) {
		cerr << "Player " << question.player << " does not have any cards." << endl;
		return false;
	}

	return true;
}

/**
 * @brief Check if all the cards can be given to at least one player.
 *
 * In other words check if for every card it holds that the players
 * vector does not equal [0, ...,0]. Because then the card can not
 * be distributed and we immediatly know that the state is invalid.
 */
bool valid_cards(const Settings &settings, const State &state)
{
	for (int card = 0; card < (int)state.cards.size(); card++) {
		int count = 0;
		for (int player = 0; player < settings.NUM_PLAYERS; player++) {
			if (!state.cards[card].players[player]) {
				count++;
			}
		}
		if (count >= settings.NUM_PLAYERS) {
			cerr << "Your answer/question is invalid." << endl;
			return false;
		}
	}
	return true;
}

/**
 * @brief Check if there not more set/category restrictions
 * than there are cards in a set/category.
 *
 * Thus if player 0 needs to have 2 cards of set/category 0
 * and player 1 needs to have 3 cards of this same set/category,
 * then if SET_SIZE is smaller then 5 we immediatly know that
 * the state is invalid.
 */
bool valid_players(const Settings &settings, const State &state)
{
	vector<int> sets = vector<int>(settings.NUM_SETS, 0);
	for (int player = 0; player < settings.NUM_PLAYERS; player++) {
		for (int set = 0; set < settings.NUM_SETS; set++) {
			sets[set] += state.players[player].sets[set];
		}
	}
	for (int set = 0; set < settings.NUM_SETS; set++) {
		if (sets[set] > settings.SET_SIZE) {
			return false;
		}
	}
	return true;
}

bool dfs(const Settings &settings, State state, vector<int> unassigned)
{
	// if unassigned is empty
	//   return true

	// if set constraint left
	//   player = set constraint player
	//   for every set constraint relief card
	//     card = set constraint relief card
	//
	//     ----
	//     if player.num_cards > 1
	//       assign card to player (remove from unassigned)
	//       update player num_cards and set constraints
	//       if dfs(new state, new unassigned)
	//         return true
	//     ----
	//   return false
	//
	// else
	//   card = next card (choose from unassigned)
	//   for every player that can have this card
	//     player = player can have this card
	//
	//     ----
	//     if player.num_cards > 1
	//       assign card to player (remove from unassigned)
	//       update player num_cards and set constraints
	//       if dfs(new state, new unassigned)
	//         return true
	//     ----
	//   return false

	return true;
}

bool valid_state_exists(const Settings &settings, const State &state)
{
	// for all cards with only one possible player, e.g. [1,0,0] or [0,1,0]
	//   assign card to player (remove from unassigned)
	//   update player num_cards and set constraints
	return dfs(settings, state);
}

bool valid_state(const Settings &settings, const State &state)
{
	return valid_cards(settings, state) && valid_players(settings, state)
	    && valid_state_exists(settings, state);
}
