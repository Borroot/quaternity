/**
 * @file
 *
 * @brief This file defines the structs for a card, player and a game state,
 * plus a state initialize and copy function header.
 */

#ifndef STATE_H_
#define STATE_H_

#include <vector>

using namespace std;

/**
 * @brief The information connected to a card.
 *
 * @note We use a struct instead of a typedef in case it turns out that we need
 * more information later on in the development process.
 */
struct Card {

	/**
	 * @brief The players which could have this card.
	 *
	 * This is denoted by true if the player can have the card and false
	 * otherwise. To give an example, [0,1,0] means that player 0 and 2 cannot
	 * have this card, but player 1 can have this card.
	 */
	vector<bool> players;
};

/**
 * @brief The information connected to a player.
 */
struct Player {

	/**
	 * @brief The number of cards this player has.
	 */
	int num_cards;

	/**
	 * @brief The number of cards the player at least has from a certain set.
	 *
	 * To give an example, [0,3,1] means that this player has at least 0 cards
	 * from set 0, it has at least 3 cards from set 1 and it has at least 1
	 * card from set 2.
	 */
	vector<int> sets;
};

/**
 * @brief The complete game state.
 *
 * This struct contains all the information of the game state at a specific
 * moment in time.
 */
struct State {

	/**
	 * @brief The player who is on turn.
	 */
	int onturn;

	/**
	 * @brief The information on all the cards.
	 *
	 * This vector also contains information on which card is in what set and
	 * which card they are with respect to their set. Consider the following
	 * example [card0, ..., card7] and we have a SET_SIZE of 4 and thus a
	 * NUM_SETS of 2 then the cards [card0, ..., card3] belong to set 0 and
	 * [card4, ..., card7] belong to set 1. So, in these examples card4 will be
	 * card 0 with respect to its own set and card7 will be card 3.
	 */
	vector<Card> cards;

	/**
	 * @brief The information on all the players.
	 *
	 * This is where it is defined who is player 0, 1, etc.
	 */
	vector<Player> players;
};

State init_state(const Settings &settings);
State copy_state(const State &state);

#endif /* STATE_H_ */
