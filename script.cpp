// Standard Library
#include <string>
#include <iostream>
#include <fstream>
#include <locale>

// Header
#include "function.h"

// using
using namespace std;

bool myshell::script(const wstring& filename)
{
	wifstream ifs;
	ifs.imbue(locale(""));
	ifs.open(filename);
	if(ifs.fail())
		return false;

	wstring line;
	for(unsigned int i = 1 ; getline(ifs, line) ; i++)
	{
		if(command_process(line))
			wcout << L"succeeded(line " << i << L")\n";
		else
			wcerr << L"failed(line " << i << L")\n";
	}

	return true;
}
