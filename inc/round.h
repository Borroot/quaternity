#ifndef ROUND_H
# define ROUND_H

#include <vector>

using namespace std;

struct Question {
	int player;
	int set;
	int card;
};

typedef bool Answer;

struct Quartet {
	int player;
	int set;
};

#endif
