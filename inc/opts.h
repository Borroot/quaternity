#ifndef OPTS_H
# define OPTS_H

using namespace std;

struct Settings {
	const int SET_SIZE;
	const int NUM_SETS;
	const int NUM_PLAYERS;
};

Settings options(int argc, char **argv);

#endif
