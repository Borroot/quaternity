/**
 * @file
 *
 * @brief This file defines state initialization and copy functions.
 */

#include <vector>

#include "settings.h"
#include "state.h"

/**
 * @brief Initialize the cards corresponding to the given settings.
 *
 * The players vector for every card will be initilialized to all true, because
 * at the start every player could have that card. There are a total of
 * `SET_SIZE * NUM_SETS` cards which will be generated.
 */
std::vector<Card> init_cards(const Settings &settings)
{
	std::vector<Card> cards;
	for (int i = 0; i < settings.SET_SIZE * settings.NUM_SETS; i++) {
		Card card = {std::vector<bool>(settings.NUM_PLAYERS, true)};
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
std::vector<Player> init_players(const Settings &settings)
{
	const int NUM_CARDS = (settings.NUM_SETS * settings.SET_SIZE) / settings.NUM_PLAYERS;
	std::vector<Player> players;
	for (int i = 0; i < settings.NUM_PLAYERS; i++) {
		Player player = {NUM_CARDS, std::vector<int>(settings.NUM_SETS, 0)};
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
	return State{0, init_cards(settings), init_players(settings)};
}

/**
 * @brief Copy the old cards vector to a new cards vector.
 */
std::vector<Card> copy_cards(const std::vector<Card> cards)
{
	std::vector<Card> cards_copy;
	for (Card card: cards) {
		Card card_copy = {card.players};
		cards_copy.push_back(card_copy);
	}
	return cards_copy;
}

/**
 * @brief Copy the old player vector to a new player vector.
 */
std::vector<Player> copy_players(const std::vector<Player> players)
{
	std::vector<Player> players_copy;
	for (Player player: players) {
		Player player_copy = {player.num_cards, player.sets};
		players_copy.push_back(player_copy);
	}
	return players;
}

/**
 * @brief Copy the old state to a new state.
 *
 * @see copy_cards
 * @see copy_players
 */
State copy_state(const State &state)
{
	return State{state.onturn, copy_cards(state.cards), copy_players(state.players)};
}
