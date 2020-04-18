/**
 * @file
 *
 * @brief This file defines initialization functions.
 */

#include <vector>

#include "init.h"
#include "settings.h"
#include "state.h"

/**
 * @brief Initialize the cards corresponding to the given settings.
 *
 * The players vector for every card will be initilialized to all true, because
 * at the start every player could have that card. There are a total of
 * `SET_SIZE * NUM_SETS` cards which will be generated.
 */
vector<Card> init_cards(const Settings &settings)
{
	vector<Card> cards;
	for (int i = 0; i < settings.SET_SIZE * settings.NUM_SETS; i++) {
		Card card = {vector<bool>(settings.NUM_PLAYERS, true)};
		cards.push_back(card);
	}
	return cards;
}

/**
 * @brief Initialize the players corresponding to the given settings.
 *
 * The cards are equally distributed among the players which means that every
 * player will start with `(NUM_SETS * SET_SIZE) / NUM_PLAYERS` amount of
 * cards. They further have the sets vector initialized to all zeros because
 * they do not need to have any specific set at the start.
 */
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

/**
 * @brief Initialize the starting state corresponding to the given settings.
 *
 * The cards and players are defined by their respective functions. The zero'th
 * player starts the game (has the first turn).
 *
 * @see init_cards
 * @see init_players
 */
State init_state(const Settings &settings)
{
	vector<Card> cards = init_cards(settings);
	vector<Player> players = init_players(settings);
	State state = {0, cards, players};
	return state;
}
