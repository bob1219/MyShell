// Standard Library
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cctype>

// Boost
#include <boost/filesystem.hpp>

// using
using namespace std;
using namespace boost::filesystem;

bool myshell::command::mk(const string& filename)
{
	const path file(filename);
	if(is_regular_file(file)) // File is found
	{
		cerr	<< "Warning: File \"" << filename << "\" is found.\n"
			<< "continue?(Y/N)";

		int YorN = getchar();
		YorN = tolower(YorN);
		if(YorN != 'y')
			return false;
	}

	ofstream ofs(filename);
	if(ofs.fail())
		return false;
	else
		return true;
}

bool myshell::command::rm(const string& filename)
{
	if(remove(filename.c_str()) == 0)
		return true;
	else
		return false;
}
