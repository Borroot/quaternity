#include <iostream>
#include <string>

#include "debug.h"
#include "init.h"
#include "input.h"
#include "opts.h"
#include "settings.h"
#include "state.h"
#include "update.h"
#include "validate.h"

using namespace std;

int main(int argc, char **argv)
{
	Settings settings = options(argc, (const char**)argv);
	State state = init_state(settings);

	cout << settings;
	cout << state;

	while (true) { // not game over
		// QUESTION
		Question question;
		do {
			do {
				question = ask_question();
				cout << question;
			} while (!valid_question(settings, state, question));
			update_state(settings, state, question);
		} while (!valid_state(settings, state));

		cout << state;

		// ANSWER
		Answer answer;
		do {
			answer = ask_answer();
			cout << "Answer: " << answer << "." << endl;
			update_state(settings, state, question, answer);
		} while (!valid_state(settings, state));

		cout << state;

		// QUARTETS

		// COMMIT STATE
	}

	return 0;
}
