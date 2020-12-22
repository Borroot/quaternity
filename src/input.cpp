/**
 * @file
 *
 * @brief This file defines user input functions.
 */

#include <iostream>
#include <limits>

#include "settings.h"
#include "input.h"

/**
 * @brief Flush the input stream so it is empty for the next user input.
 */
void flush()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Ask the user to provide a question.
 */
Question ask_question()
{
	std::cout << "Please provide a question (player, set, card)." << std::endl << "> ";
	Question question;
	std::cin >> question.player >> question.set >> question.card;
	flush();
	return question;
}

/**
 * @brief Ask the user to provide an answer.
 */
Answer ask_answer()
{
	std::cout << "Please provide your answer (0/1)." << std::endl << "> ";
	Answer answer;
	std::cin >> answer;
	flush();
	return answer;
}
