/**
 * @file
 *
 * @brief This file defines user input functions.
 */

#include <iostream>
#include <limits>

#include "settings.h"
#include "input.h"

using namespace std;

/**
 * @brief Flush the input stream so it is empty for the next user input.
 */
void flush()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Ask the user to provide a question.
 */
Question ask_question()
{
	cout << "Please provide a question (player, set, card)." << endl << "> ";
	Question question;
	cin >> question.player >> question.set >> question.card;
	flush();
	return question;
}

/**
 * @brief Ask the user to provide an answer.
 */
Answer ask_answer()
{
	cout << "Please provide your answer (0/1)." << endl << "> ";
	Answer answer;
	cin >> answer;
	flush();
	return answer;
}
