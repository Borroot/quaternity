/**
 * @file
 *
 * @brief This file defines the command line argument parsing
 * function and some helper functions.
 */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "opts.h"
#include "settings.h"

using namespace std;

/**
 * @brief Print the usage information for this program
 * on the screen.
 *
 * @param argv Command line arguments.
 */
void usage(const char **argv)
{
	cerr
		<< "Usage: " << argv[0] << " [OPTIONS]"             << endl
		                                                    << endl
		<< "  A flexible engine for imaginary quartet!"     << endl
		                                                    << endl
		<< "Note:"                                          << endl
		<< "  To ensure an equal distribution of the cards" << endl
		<< "  we enforce: (n * s) mod p == 0."              << endl
		                                                    << endl
		<< "Options:"                                       << endl
		<< "  -s [int]    Size of one set.   [default: "    << DEFAULT_SET_SIZE    << "]" << endl
		<< "  -n [int]    Number of sets.    [default: "    << DEFAULT_NUM_SETS    << "]" << endl
		<< "  -p [int]    Number of players. [default: "    << DEFAULT_NUM_PLAYERS << "]" << endl
		<< "  -h          Show this help and exit."         << endl;

}

/**
 * @brief Validate the settings given.
 *
 * This function checks if all of the settings have
 * their minimum value: 1 for SET_SIZE (s), 1 for NUM_SETS (n)
 * and 2 for NUM_PLAYERS (p). It also checks if the condition
 * `(n * s) mod p == 0` holds. This condition is necessary to
 * allow an equal distribution of the cards.
 *
 * @param argv Command line arguments.
 */
bool valid(const Settings &settings, const char **argv)
{
	if (settings.SET_SIZE < 1) {
		cerr << argv[0] << ": the size of one set has to be at least one" << endl;
		return false;
	}

	if (settings.NUM_SETS < 1) {
		cerr << argv[0] << ": the number of sets has to be at least one" << endl;
		return false;
	}

	if (settings.NUM_PLAYERS < 2) {
		cerr << argv[0] << ": the number of players has to be at least two" << endl;
		return false;
	}

	if ((settings.NUM_SETS * settings.SET_SIZE) % settings.NUM_PLAYERS != 0) {
		cerr << argv[0] << ": enforces (n * s) mod p == 0" << endl;
		return false;
	}

	return true;
}

/**
 * @brief Parse the command line arguments and generate
 * the settings from these.
 *
 * This function parses the command line arguments and
 * generates the corresponding settings. If no argument
 * is given for a specific value then the default value
 * will be used.
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
				usage(argv);
				exit(EXIT_SUCCESS);
			default:  // '?'
				usage(argv);
				exit(EXIT_FAILURE);
		}
	}

	Settings settings = {SET_SIZE, NUM_SETS, NUM_PLAYERS};
	if (!valid(settings, argv)) {
		usage(argv);
		exit(EXIT_FAILURE);
	}
	return settings;
}
