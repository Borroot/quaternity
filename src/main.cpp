#include <algorithm>
#include <iostream>
#include <string>

#include "debug.h"
#include "input.h"
#include "opts.h"
#include "settings.h"
#include "state.h"
#include "update.h"
#include "validate.h"

int main(int argc, char **argv)
{
	Settings settings = options(argc, (const char**)argv);
	State state = init_state(settings);

	std::cout << settings;
	std::cout << state;

	while (std::find(state.quartets.begin(), state.quartets.end(), -1) != state.quartets.end()) {
		bool *valid_answers;

		// QUESTION
		Question question;
		do {
			question = ask_question();
			std::cout << question;
			valid_answers = valid_question(settings, state, question);
		} while (valid_answers == NULL);

		// ANSWER
		Answer answer;
		do {
			answer = ask_answer();
			std::cout << "Answer: " << answer << "." << std::endl;
		} while (!valid_answers[answer]);

		// STATE
		update_state(settings, state, question, answer);
		std::cout << state;

		// QUARTETS
		update_quartets(settings, state);
		std::cout << state;
	}

	return 0;
}
