// Standard Library
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstddef>

// Boost
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

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
	return !ofs.fail();
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

bool myshell::command::lfile(const string& dir_name)
{
	path dir(dir_name);
	BOOST_FOREACH(const path& p, make_pair(directory_iterator(dir), directory_iterator()))
	{
		if(is_directory(p))
			cout << "dir:\t" << p.string() << '\n';
		else
			cout << "file:\t" << p.string() << '\n';
	}

	return true;
}

bool myshell::command::mkdir(const string& dir_name)
{
	path dir(dir_name);
	return create_directory(dir);
}

bool myshell::command::rmdir(const string& dir_name)
{
	path dir(dir_name);
	if(!is_directory(dir))
		return false;
	return remove(dir);
}

bool myshell::command::pcwd()
{
	path cwd = current_path();
	cout << cwd.string() << '\n';
	return true;
}

bool myshell::command::chcwd(const string& dir_name)
{
	path dir(dir_name);
	current_path(dir);
	return true;
}
