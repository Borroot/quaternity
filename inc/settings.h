/**
 * @file
 *
 * @brief This file defines the settings struct.
 */

#ifndef SETTINGS_H
# define SETTINGS_H

/**
 * @brief The default value for SET_SIZE.
 */
#define DEFAULT_SET_SIZE 4

/**
 * @brief The default value for NUM_SETS.
 */
#define DEFAULT_NUM_SETS 3

/**
 * @brief The default value for NUM_PLAYERS.
 */
#define DEFAULT_NUM_PLAYERS 3

/**
 * @brief The settings which characterize a game.
 */
struct Settings {

	/**
	 * @brief The size of one set/category, aka the number of cards in one size/category.
	 */
	const int SET_SIZE;

	/**
	 * @brief The number of sets/categories.
	 */
	const int NUM_SETS;

	/**
	 * @brief The number of players playing the game.
	 */
	const int NUM_PLAYERS;
};

#endif
