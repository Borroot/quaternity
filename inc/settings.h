/**
 * @file
 *
 * @brief This file defines the settings struct.
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

/** @brief The default value for SET_SIZE.  */
constexpr int DEFAULT_SET_SIZE = 4;

/** @brief The default value for NUM_SETS.  */
constexpr int DEFAULT_NUM_SETS = 3;

/** @brief The default value for NUM_PLAYERS.  */
constexpr int DEFAULT_NUM_PLAYERS = 3;

/**
 * @brief The settings which characterize a game.
 */
struct Settings {

	/**
	 * @brief The size of one set, aka the number of cards in one set.
	 */
	const int SET_SIZE;

	/**
	 * @brief The number of sets.
	 */
	const int NUM_SETS;

	/**
	 * @brief The number of players playing the game.
	 */
	const int NUM_PLAYERS;
};

#endif /* SETTINGS_H_ */
