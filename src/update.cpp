/**
 * @file
 *
 * @brief This file defines a function for updating the state given a question
 * and answer.
 */

#include <vector>

#include "round.h"
#include "settings.h"
#include "state.h"
#include "update.h"

using namespace std;

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
 * - If the answer is false.
 *   - Update who has the card which is asked.
 *     - Set the card's player status false for the onturn player.
 *     - Set the card's player status false for the asked player.
 *   - Change onturn.
 *     - Switch onturn to the player asked.
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
		state.cards[card].players = vector<bool>(settings.NUM_PLAYERS, false);
		state.cards[card].players[state.onturn] = true;

		// update the number of cards the players have
		state.players[state.onturn].num_cards += 1;
		state.players[question.player].num_cards -= 1;
	} else {
		// update who could have the card which is asked
		state.cards[card].players[state.onturn] = false;
		state.cards[card].players[question.player] = false;

		// update the turn
		state.onturn = question.player;
	}
}
