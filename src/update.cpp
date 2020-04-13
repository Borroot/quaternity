#include <vector>

#include "round.h"
#include "settings.h"
#include "state.h"
#include "update.h"

using namespace std;

void update_state(const Settings &settings, State &state, const Question &question) {
	state.players[state.onturn].sets[question.set] = true;
	state.cards[question.set * settings.SET_SIZE + question.card].players[state.onturn] = false;
}

void update_state(const Settings &settings, State &state, const Question &question, const Answer &answer) {
	if (answer) {
		state.players[question.player].sets[question.set] = false;
		state.cards[question.set * settings.SET_SIZE + question.card].players = vector<bool>(settings.NUM_PLAYERS, false);
		state.cards[question.set * settings.SET_SIZE + question.card].players[state.onturn] = true;
	} else {
		state.cards[question.set * settings.SET_SIZE + question.card].players[question.player] = false;
		state.onturn = question.player;
	}
}

void update_state(const Settings &settings, State &state, const vector<Quartet> &quartets);
