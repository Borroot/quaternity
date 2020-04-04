#ifndef OPTS_H
# define OPTS_H

#define DEFAULT_SET_SIZE 4
#define DEFAULT_NUM_SETS 3
#define DEFAULT_NUM_PLAYERS 2

using namespace std;

struct Settings {
	const int SET_SIZE;
	const int NUM_SETS;
	const int NUM_PLAYERS;
};

Settings options(int argc, char **argv);
void usage(char **argv);

#endif
