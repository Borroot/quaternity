#include <iostream>
#include <vector>
#include <string>

#include "debug.h"
#include "card.h"
#include "player.h"
#include "tui.h"

using namespace std;

vector<Card> init_cards(const int &SET_SIZE, const int &NUM_SETS, const int &NUM_PLAYERS)
{
	vector<Card> cards;
	for (int i = 0; i < SET_SIZE * NUM_SETS; i++) {
		Card card = {i / NUM_SETS, vector<bool>(NUM_PLAYERS, true)};
		cards.push_back(card);
	}
	return cards;
}

vector<Player> init_players(const int &SET_SIZE, const int &NUM_SETS, const int &NUM_PLAYERS) {
	vector<Player> players;
	for (int i = 0; i < NUM_PLAYERS; i++) {
		Player player = {(NUM_SETS * SET_SIZE) / NUM_PLAYERS, vector<bool>(NUM_SETS, false)};
		players.push_back(player);
	}
	return players;
}

int main(int argc, const char **argv)
{
	int SET_SIZE = 5;
	int NUM_SETS = 3;
	int NUM_PLAYERS = 3;

	// TODO check if (NUM_SETS * SET_SIZE) % NUM_PLAYERS == 0

	vector<Card> cards = init_cards(SET_SIZE, NUM_SETS, NUM_PLAYERS);
	vector<Player> players = init_players(SET_SIZE, NUM_SETS, NUM_PLAYERS);

	cout << cards << endl;
	cout << players << endl;

	string answer = ask<string>("hello?");
	cout << answer << endl;

	return 0;
}
