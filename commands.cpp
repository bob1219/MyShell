// Standard Library
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iomanip>

// Boost
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

// Header
#include "constant.h"
#include "function.h"

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

	std::ofstream ofs(filename);
	return !ofs.fail();
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
		cout << (is_directory(p) ? "dir" : "file") << ":\t" << p.string() << '\n';

	return true;
}

bool myshell::command::tview(const string& filename)
{
	std::ifstream ifs(filename);
	if(ifs.fail())
		return false;

	string line;
	for(unsigned int i = 1 ; getline(ifs, line) ; i++)
		cout << i << ":\t" << line << '\n';

	return true;
}

bool myshell::command::bview(const string& filename)
{
	std::ifstream ifs(filename);
	if(ifs.fail())
		return false;

	char buffer[FILE_SIZE_MAX];
	size_t buf_count = ifs.read(buffer, (sizeof(buffer) / sizeof(char))).gcount();

	cout << "\t+0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F 0123456789ABCDEF\n";
	for(unsigned int i = 0 ; i < buf_count ; i += 0x10)
	{
		cout << hex << i << dec << ":\t";

		for(unsigned int j = 0 ; j <= 0xf ; j++)
			printf("%02X ", static_cast<unsigned char>(buffer[i + j]));

		for(unsigned int k = 0 ; k <= 0xf ; k++)
			cout << (isprint(static_cast<int>(buffer[i + k])) ? buffer[i + k] : '.');

		cout << '\n';
	}

	return true;
}

bool myshell::command::app(const string& app_name)
{
	if(!system(nullptr))
		return false;

	int ret = system(app_name.c_str());
	cout << "return value: " << ret << '\n';

	return true;
}
