#include <iostream>
#include <vector>
#include <string>

#include "debug.h"
#include "card.h"
#include "init.h"
#include "opts.h"
#include "player.h"
#include "tui.h"

using namespace std;

int main(int argc, char **argv)
{
	Settings settings = options(argc, argv);
	cout << settings << endl;

	// TODO check if (NUM_SETS * SET_SIZE) % NUM_PLAYERS == 0

	vector<Card> cards = init_cards(settings);
	vector<Player> players = init_players(settings);

	//cout << cards << endl;
	//cout << players << endl;

	//int answer = ask<int>("hello?");
	//cout << answer << endl;

	return 0;
}
