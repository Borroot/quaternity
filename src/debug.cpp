#include <iostream>
#include <vector>

#include "debug.h"
#include "card.h"
#include "player.h"

using namespace std;

ostream &operator<<(ostream &out, const Card &card)
{
	out << "[" << card.category << "," << card.players << "]";
	return out;
}

ostream &operator<<(ostream &out, const Player &player)
{
	out << "[" << player.num_cards << "," << player.categories << "]";
	return out;
}
