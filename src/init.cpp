#include <vector>

#include "init.h"
#include "settings.h"
#include "state.h"

vector<Card> init_cards(const Settings &settings)
{
	vector<Card> cards;
	for (int i = 0; i < settings.SET_SIZE * settings.NUM_SETS; i++) {
		Card card = {vector<bool>(settings.NUM_PLAYERS, true)};
		cards.push_back(card);
	}
	return cards;
}

vector<Player> init_players(const Settings &settings)
{
	vector<Player> players;
	for (int i = 0; i < settings.NUM_PLAYERS; i++) {
		Player player = {(settings.NUM_SETS * settings.SET_SIZE) / settings.NUM_PLAYERS,
		                  vector<int>(settings.NUM_SETS, 0)};
		players.push_back(player);
	}
	return players;
}

State init_state(const Settings &settings)
{
	vector<Card> cards = init_cards(settings);
	vector<Player> players = init_players(settings);
	State state = {0, cards, players};
	return state;
}
