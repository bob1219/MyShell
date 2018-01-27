// Standard Library
#include <string>
#include <iostream>
#include <fstream>

// Header
#include "function.h"

// using
using namespace std;

bool myshell::script(const string& filename)
{
	ifstream ifs(filename);
	if(ifs.fail())
		return false;

	string line;
	for(unsigned int i = 1 ; getline(ifs, line) ; i++)
	{
		if(command_process(line))
			cout << "succeeded(line " << i << ")\n";
		else
			cerr << "failed(line " << i << ")\n";
	}

	return true;
}
