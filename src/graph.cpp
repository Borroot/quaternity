/**
 * @file
 *
 * @brief This file defines the graph creation functions.
 */

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

#include "graph.h"
#include "settings.h"
#include "state.h"

/**
 * @brief Create a copy of the given graph.
 */
Graph graph_copy(const Graph graph)
{
	Graph graph_clone(graph.size(), std::vector<bool>(graph.size()));
	for (size_t i = 0; i < graph.size(); i++)
		for (size_t j = 0; j < graph[i].size(); j++)
			graph_clone[i][j] = graph[i][j];
	return graph_clone;
}

/**
 * @brief Check if it is possible to create a graph.
 *
 * More specifically, check that no player's total number of set constraints is
 * bigger than the number of cards that player has.
 *
 * @return true if possible
 */
bool graph_possible(const Settings &settings, const State &state)
{
	for (Player player: state.players)
		if (player.num_cards < accumulate(player.sets.begin(), player.sets.end(), 0))
			return false;
	return true;
}

/**
 * @brief Add all the edges representing the set constraints for a player.
 *
 * For every set constraint corresponding to the given set and player, add
 * edges to the current player card (`hand_offset + hand_entry`) to all cards
 * the player can have from the given set.
 */
void graph_set(const Settings &settings, const State &state, Graph &graph, int player, int set, int hand_offset, int hand_entry)
{
	int minimum = state.players[player].sets[set];
	while (minimum-- > 0) {
		int card_start = set * settings.SET_SIZE;
		for (int card = card_start; card < card_start + settings.SET_SIZE; card++)
			if (state.cards[card].players[player])
				graph[hand_offset + hand_entry][card] = true;
		hand_entry++;
	}
}

/**
 * @brief Add all the edges representing the given player.
 *
 * First we add all the edges for our set constraints.
 *
 * After this we assign edges to the leftover cards the player has going to all
 * possible cards the player could have.
 *
 * @see graph_set
 */
void graph_player(const Settings &settings, const State &state, Graph &graph, int player, int hand_offset)
{
	// go through all set constraints and make edges for them
	int hand_entry = 0;
	for (int set = 0; set < settings.NUM_SETS; set++) {
		graph_set(settings, state, graph, player, set, hand_offset, hand_entry);
		hand_entry += state.players[player].sets[set];
	}

	// after all set constraints are set we can have any card
	while (hand_entry < state.players[player].num_cards) {
		for (int card = 0; card < settings.NUM_SETS * settings.SET_SIZE; card++)
			if (state.cards[card].players[player])
				graph[hand_offset + hand_entry][card] = true;
		hand_entry++;
	}
}

/**
 * @brief Create a biparite graph which has a matching if the state is valid.
 *
 * The graph is represented as a 2d array where every cell is an edge between
 * the left node (row number) and the right node (column number). We go
 * through all the players and add the constraints corresponding to that
 * player's possible hands.
 *
 * @see graph_player
 */
Graph graph_create(const Settings &settings, const State &state)
{
	assert(graph_possible(settings, state));  // make sure we can create a graph

	// create the graph array and initialize all values to false
	const int NUM_CARDS = settings.NUM_SETS * settings.SET_SIZE;
	Graph graph(NUM_CARDS, std::vector<bool>(NUM_CARDS, false));

	// set the corresponding edges for all players
	int hand_offset = 0;
	for (int player = 0; player < settings.NUM_PLAYERS; player++) {
		graph_player(settings, state, graph, player, hand_offset);
		hand_offset += state.players[player].num_cards;
	}

	return graph;
}
