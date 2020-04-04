#include <vector>

#include "card.h"
#include "init.h"
#include "opts.h"
#include "player.h"

vector<Card> init_cards(const Settings &settings)
{
	vector<Card> cards;
	for (int i = 0; i < settings.SET_SIZE * settings.NUM_SETS; i++) {
		Card card = {i / settings.NUM_SETS, vector<bool>(settings.NUM_PLAYERS, true)};
		cards.push_back(card);
	}
	return cards;
}

vector<Player> init_players(const Settings &settings)
{
	vector<Player> players;
	for (int i = 0; i < settings.NUM_PLAYERS; i++) {
		Player player = {(settings.NUM_SETS * settings.SET_SIZE) / settings.NUM_PLAYERS,
		                  vector<bool>(settings.NUM_SETS, false)};
		players.push_back(player);
	}
	return players;
}
