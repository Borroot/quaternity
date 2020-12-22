/**
 * @file
 *
 * @brief This file defines the command line argument parsing function and some
 * helper functions.
 */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "opts.h"
#include "settings.h"

/**
 * @brief Print the usage information for this program on the screen.
 *
 * @param argv Command line arguments.
 */
void usage(std::ostream &out, const char **argv)
{
	out
		<< "Usage: " << argv[0] << " [OPTIONS]"             << std::endl
		                                                    << std::endl
		<< "  A flexible engine for imaginary quartet!"     << std::endl
		                                                    << std::endl
		<< "Note:"                                          << std::endl
		<< "  To ensure an equal distribution of the cards" << std::endl
		<< "  we enforce: (n * s) mod p == 0."              << std::endl
		                                                    << std::endl
		<< "Options:"                                       << std::endl
		<< "  -s [int]    Size of one set.   [default: "    << DEFAULT_SET_SIZE    << "]" << std::endl
		<< "  -n [int]    Number of sets.    [default: "    << DEFAULT_NUM_SETS    << "]" << std::endl
		<< "  -p [int]    Number of players. [default: "    << DEFAULT_NUM_PLAYERS << "]" << std::endl
		<< "  -h          Show this help and exit."         << std::endl;

}

/**
 * @brief Validate the settings given.
 *
 * This function checks if all of the settings have their minimum value: 1 for
 * SET_SIZE (s), 1 for NUM_SETS (n) and 2 for NUM_PLAYERS (p). It also checks
 * if the condition `(n * s) mod p == 0` holds. This condition is necessary to
 * allow an equal distribution of the cards.
 *
 * @param argv Command line arguments.
 */
bool valid(const Settings &settings, const char **argv)
{
	if (settings.SET_SIZE < 1) {
		std::cerr << argv[0] << ": the size of one set has to be at least one" << std::endl;
		return false;
	}

	if (settings.NUM_SETS < 1) {
		std::cerr << argv[0] << ": the number of sets has to be at least one" << std::endl;
		return false;
	}

	if (settings.NUM_PLAYERS < 2) {
		std::cerr << argv[0] << ": the number of players has to be at least two" << std::endl;
		return false;
	}

	if ((settings.NUM_SETS * settings.SET_SIZE) % settings.NUM_PLAYERS != 0) {
		std::cerr << argv[0] << ": enforces (n * s) mod p == 0" << std::endl;
		return false;
	}

	return true;
}

/**
 * @brief Parse the command line arguments and generate the settings from
 * these.
 *
 * This function parses the command line arguments and generates the
 * corresponding settings. If no argument is given for a specific value then
 * the default value will be used.
 *
 * @param argc Number of command line arguments.
 * @param argv Command line arguments.
 */
Settings options(const int argc, const char **argv)
{
	int SET_SIZE = DEFAULT_SET_SIZE;
	int NUM_SETS = DEFAULT_NUM_SETS;
	int NUM_PLAYERS = DEFAULT_NUM_PLAYERS;

	int opt;
	while ((opt = getopt(argc, (char* const*)argv, "s:n:p:h")) != -1) {
		switch (opt) {
			case 's':
				SET_SIZE = atoi(optarg);
				break;
			case 'n':
				NUM_SETS = atoi(optarg);
				break;
			case 'p':
				NUM_PLAYERS = atoi(optarg);
				break;
			case 'h':
				usage(std::cout, argv);
				exit(EXIT_SUCCESS);
			default:  // '?'
				usage(std::cerr, argv);
				exit(EXIT_FAILURE);
		}
	}

	Settings settings = {SET_SIZE, NUM_SETS, NUM_PLAYERS};
	if (!valid(settings, argv)) {
		usage(std::cerr, argv);
		exit(EXIT_FAILURE);
	}
	return settings;
}
