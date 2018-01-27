// Standard Library
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstddef>

// Boost
#include <boost/filesystem.hpp>

// Header
#include "constant.h"

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

bool myshell::command::copy(const string& from_filename, const string& to_filename)
{
	path from_file(from_filename);
	path to_file(to_filename);

	try
	{
		copy_file(from_file, to_file, copy_option::overwrite_if_exists);
	}
	catch(filesystem_error& e)
	{
		cerr << "error: " << e.what() << '\n';
		return false;
	}

	return true;
}
