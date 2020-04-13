#include <iostream>
#include <vector>

#include "debug.h"
#include "round.h"
#include "settings.h"
#include "state.h"

using namespace std;

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
