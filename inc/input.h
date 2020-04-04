#ifndef INPUT_H
# define INPUT_H

#include <iostream>
#include <string>

template <typename T>
T ask(string question)
{
	cout << question << endl << "> ";
	T answer;
	cin >> answer;
	return answer;
}

#endif
