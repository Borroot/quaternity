/**
 * @file
 *
 * @brief This file defines functions for updating the state.
 */

#include <cassert>
#include <vector>

#include "graph.h"
#include "match.h"
#include "round.h"
#include "settings.h"
#include "state.h"
#include "update.h"

/**
 * @brief Update the player onturn such that he has cards for sure.
 *
 * If the player onturn does not have any cards left after it got a new
 * quartet, the player who the card was asked from will be onturn. If that
 * player also does not have any cards, we choose the first player in the
 * player list with cards, if there is none we set onturn to -1.
 */
void update_onturn(const Settings &settings, State &state, const Question &question)
{
	// player onturn does not have any cards
	if (info_num_cards(settings, state, state.onturn) == 0) {

		// player asked does not have any cards
		if (info_num_cards(settings, state, question.player) > 0)
			state.onturn = question.player;
		else {
			// choose the first player with cards from the player list
			for (int player = 0; player < settings.NUM_PLAYERS; player++)
				if (info_num_cards(settings, state, player) > 0) {
					state.onturn = player;
					return;
				}
			state.onturn = -1;  // no players with cards left
		}
	}
}

/**
 * @brief Update the state such that the given player has the provided set.
 *
 * First we check if it is already known the player has the provided set. Next
 * we make sure that in every possible matching the player has the set. To do
 * this we execute the code shown below. If this succeeds we update the state
 * such that every card from the provided set can only be assigned to the
 * player and we set the quartets array entry to the player.
 *
 * @verbatim
   for card in quartet:
       remove all edges from player's hand to the card
       if match exists for graph:
          return
   @endverbatim
 *
 * @return if the player and set given is a new quartet
 */
bool update_quartet(const Settings &settings, State &state, const Graph &graph, int hand_offset, int player, int set)
{
	// check if we already know the quartet belongs to the player
	if (state.quartets[set] == player)
		return false;

	// make sure that in every possible matching this player has the given set
	for (int card = set * settings.SET_SIZE; card < (set + 1) * settings.SET_SIZE; card++) {
		Graph graph_restricted = graph_copy(graph);
		for (int hand_entry = 0; hand_entry < state.players[player].num_cards; hand_entry++)
			graph_restricted[hand_offset + hand_entry][card] = false;
		if (match_exists(graph_restricted))
			return false;
	}

	// update the state so only this player can have the cards from the set
	for (int card = set * settings.SET_SIZE; card < (set + 1) * settings.SET_SIZE; card++) {
		state.cards[card].players = std::vector<bool>(settings.NUM_PLAYERS, false);
		state.cards[card].players[player] = true;
	}
	state.quartets[set] = player;
	return true;
}

/**
 * @brief Find if there are new quartets and update the state accordingly.
 *
 * First we generate a matching. We check for every player if they have all
 * cards from a set (i.e. a quartet) in the found matching, if so we call
 * `update_quartet` with the found player and set. If a new quartet is found,
 * we use `update_onturn` to make sure that the player onturn has cards.
 *
 * @see update_quartet
 * @see update_onturn
 */
void update_quartets(const Settings &settings, State &state, const Question &question)
{
	assert(graph_possible(settings, state) && match_exists(graph_create(settings, state)));

	// find any matching of the current state graph for checking of quartets
	Graph graph = graph_create(settings, state);
	std::vector<int> match = match_find(graph);

	bool newquartet = false;  // indicates whether any new quartet was found
	int hand_offset = 0;
	for (int player = 0; player < settings.NUM_PLAYERS; player++) {

		// count the number of cards this player has of every set
		std::vector<int> sets(settings.NUM_SETS, 0);
		for (int card = 0; card < state.players[player].num_cards; card++)
			sets[match[hand_offset + card] / settings.SET_SIZE]++;

		// check if there are any new possible quartets, if so update the state
		for (int set = 0; set < settings.NUM_SETS; set++)
			if (sets[set] == settings.SET_SIZE)
				if (update_quartet(settings, state, graph, hand_offset, player, set))
					newquartet = true;

		hand_offset += state.players[player].num_cards;
	}

	// make sure that the player who is onturn has cards left
	if (newquartet)
		update_onturn(settings, state, question);
}

/**
 * @brief Update the state of the game according to the question asked and the
 * answer which is given.
 *
 * - If the player onturn does not have have a set restriction for the asked
 *   set yet, give it a set restriction of one.
 * - If the answer is true.
 *   - Update the set restrictions.
 *     - Increase the player onturn's set restriction by one.
 *     - Decrease the player asked set restriction by one (not lower than 0).
 *   - Update who has the card which is asked.
 *     - Set the card's player status only to true for the onturn player.
 *   - Update the number of cards the players have.
 *     - Increase the player onturn's card count by one.
 *     - Decrease the player asked card count by one.
 *   - Update the quartets.
 *     - Call function `update_quartets`.
 * - If the answer is false.
 *   - Update who has the card which is asked.
 *     - Set the card's player status false for the onturn player.
 *     - Set the card's player status false for the asked player.
 *   - Change onturn.
 *     - Switch onturn to the player asked.
 *
 * @see update_quartets
 */
void update_state(const Settings &settings, State &state, const Question &question, const Answer &answer)
{
	const int card = question.set * settings.SET_SIZE + question.card;

	// update the set restriction of the player onturn
	int *set = &state.players[state.onturn].sets[question.set];
	if (*set == 0) *set = 1;

	if (answer) {
		// update the set restrictions
		state.players[state.onturn].sets[question.set] += 1;
		int *set = &state.players[question.player].sets[question.set];
		if (*set > 0) *set -= 1;

		// update who has the card which is asked
		state.cards[card].players = std::vector<bool>(settings.NUM_PLAYERS, false);
		state.cards[card].players[state.onturn] = true;

		// update the number of cards the players have
		state.players[state.onturn].num_cards += 1;
		state.players[question.player].num_cards -= 1;

		// update the quartets
		update_quartets(settings, state, question);
	} else {
		// update who could have the card which is asked
		state.cards[card].players[state.onturn] = false;
		state.cards[card].players[question.player] = false;

		// update the turn
		state.onturn = question.player;
	}
}
