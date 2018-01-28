// Standard Library
#include <string>
#include <iostream>

// Header
#include "function.h"

// using
using namespace std;

void myshell::command_line()
{
	wstring command;
	while(true)
	{
		wcout << L'>';
		getline(cin, command);

		if(command_process(command))
			wcout << L"succeeded.\n";
		else
			wcerr << L"failed.\n";

		cout << L'\n';
	}
}
