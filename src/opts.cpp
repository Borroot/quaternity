#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "opts.h"

using namespace std;

Settings options(int argc, char **argv)
{
	int SET_SIZE = 4, NUM_SETS = 3, NUM_PLAYERS = 3;
	int opt;

	while ((opt = getopt(argc, argv, "s:n:p:")) != -1) {
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
			default:  // '?'
				cerr << "Usage: " << argv[0] << " [-s setsize] [-n numsets] [-p numplayers]" << endl;
				exit(EXIT_FAILURE);
		}
	}

	//if (optind >= argc) {
		//cerr << "Expected argument after options." << endl;
		//exit(EXIT_FAILURE);
	//}

	Settings settings = {SET_SIZE, NUM_SETS, NUM_PLAYERS};
	return settings;
}
