#include <iostream>
#include <limits>

#include "settings.h"
#include "input.h"

using namespace std;

void flush()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

Question ask_question()
{
	cout << "Please provide a question (player, set, card)." << endl << "> ";
	Question question;
	cin >> question.player >> question.set >> question.card;
	flush();
	return question;
}

Answer ask_answer()
{
	cout << "Please provide your answer (0/1)." << endl << "> ";
	Answer answer;
	cin >> answer;
	flush();
	return answer;
}
