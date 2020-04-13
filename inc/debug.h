#ifndef DEBUG_H
# define DEBUG_H

#include <iostream>
#include <vector>

#include "round.h"
#include "settings.h"
#include "state.h"

using namespace std;

template <class T>
ostream &operator<<(ostream &out, const vector<T> &vector)
{
	out << "[";
	for (int i = 0; i < (int)vector.size(); i++) {
		out << vector[i];
		if (i < (int)vector.size() - 1) {
			out << ",";
		}
	}
	out << "]";
	return out;
}

ostream &operator<<(ostream &out, const Card &card)
{
	out << card.players;
	return out;
}

ostream &operator<<(ostream &out, const Player &player)
{
	out << "(" << player.num_cards << "," << player.sets << ")";
	return out;
}

ostream &operator<<(ostream &out, const Settings &settings)
{
	out << "Settings: "
	    << "set size = "    << settings.SET_SIZE    << ", "
	    << "num sets = "    << settings.NUM_SETS    << ", "
	    << "num players = " << settings.NUM_PLAYERS << "." << endl;
	return out;
}

ostream &operator<<(ostream &out, const State &state)
{
	out << "Onturn: "  << state.onturn  << endl
	    << "Cards: "   << state.cards   << endl
	    << "Players: " << state.players << endl;
	return out;
}

ostream &operator<<(ostream &out, const Question &question)
{
	out << "Question: "
	    << "player = " << question.player << ", "
	    << "set = "    << question.set    << ", "
	    << "card = "   << question.card   << "." << endl;
	return out;
}

#endif
