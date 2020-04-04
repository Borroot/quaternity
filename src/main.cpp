#include <iostream>
#include <vector>
#include <string>

#include "debug.h"
#include "card.h"
#include "init.h"
#include "input.h"
#include "opts.h"
#include "player.h"

using namespace std;

int main(int argc, char **argv)
{
	Settings settings = options(argc, argv);
	cout << settings << endl;

	vector<Card> cards = init_cards(settings);
	vector<Player> players = init_players(settings);

	//cout << cards << endl;
	//cout << players << endl;

	//int answer = ask<int>("hello?");
	//cout << answer << endl;

	return 0;
}
