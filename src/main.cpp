#include <iostream>
#include <vector>
#include <string>

#include "debug.h"
#include "init.h"
#include "input.h"
#include "opts.h"
#include "settings.h"
#include "state.h"

using namespace std;

int main(int argc, char **argv)
{
	Settings settings = options(argc, argv);
	State state = init_state(settings);

	cout << settings << endl;
	cout << state << endl;

	//int answer = ask<int>("hello?");
	//cout << answer << endl;

	return 0;
}
