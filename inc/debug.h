#ifndef DEBUG_H
# define DEBUG_H

#include <iostream>
#include <vector>

#include "card.h"
#include "player.h"

using namespace std;

template <class T>
ostream &operator<<(ostream &out, const vector<T> &vector);
ostream &operator<<(ostream &out, const Card &card);
ostream &operator<<(ostream &out, const Player &player);

#endif
