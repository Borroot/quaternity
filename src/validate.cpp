#include <iostream>
#include <vector>

//#include "debug.h"
#include "round.h"
#include "settings.h"
#include "state.h"
#include "validate.h"

using namespace std;

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

bool valid_cards_minimum_one(const Settings &settings, const State &state)
{
	// Check if every card can at least be assigned to one player.
	for (int card = 0; card < (int)state.cards.size(); card++) {
		int count = 0;
		for (int player = 0; player < settings.NUM_PLAYERS; player++) {
			if (!state.cards[card].players[player]) {
				count++;
			}
		}
		if (count >= settings.NUM_PLAYERS) {
			cerr << "Your answer is invalid." << endl;
			return false;
		}
	}
	return true;
}

bool valid_state(const Settings &settings, const State &state)
{
	return valid_cards_minimum_one(settings, state);
}
