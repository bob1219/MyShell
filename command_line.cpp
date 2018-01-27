// Standard Library
#include <string>
#include <iostream>

// Header
#include "function.h"

// using
using namespace std;

void myshell::command_line()
{
	string command;
	while(true)
	{
		cout << ">";
		getline(cin, command);

		if(command_process(command))
			cout << "succeeded.\n";
		else
			cerr << "failed.\n";

		cout << "\n";
	}
}
