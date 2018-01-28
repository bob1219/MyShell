// Standard Library
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cwctype>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <locale>

// Boost
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

// Header
#include "constant.h"
#include "function.h"

// using
using namespace std;
using namespace boost::filesystem;

bool myshell::command::mk(const wstring& filename)
{
	const path file(filename);
	if(is_regular_file(file)) // File is found
	{
		wcerr	<< L"Warning: File \"" << filename << L"\" is found.\n"
			<< L"continue?(Y/N)";

		wint_t YorN = getchar();
		YorN = towlower(YorN);
		if(YorN != L'y')
			return false;
	}

	std::wofstream ofs(filename);
	return !ofs.fail();
}

bool myshell::command::copy(const wstring& from_filename, const wstring& to_filename)
{
	path from_file(from_filename);
	path to_file(to_filename);

	try
	{
		copy_file(from_file, to_file, copy_option::overwrite_if_exists);
	}
	catch(filesystem_error& e)
	{
		wchar_t* mess;
		const char* mess_c = e.what();
		mbstowcs(mess, mess_c, strlen(mess_c) + 1);

		wcerr << L"error: " << mess << L'\n';
		return false;
	}

	return true;
}

bool myshell::command::lfile(const wstring& dir_name)
{
	path dir(dir_name);
	BOOST_FOREACH(const path& p, make_pair(directory_iterator(dir), directory_iterator()))
		wcout << (is_directory(p) ? L"dir" : L"file") << L":\t" << p.wstring() << L'\n';

	return true;
}

bool myshell::command::tview(const wstring& filename)
{
	std::wifstream ifs;
	ifs.imbue(locale(""));
	ifs.open(filename);
	if(ifs.fail())
		return false;

	wstring line;
	for(unsigned int i = 1 ; getline(ifs, line) ; i++)
		cout << i << L":\t" << line << L'\n';

	return true;
}

bool myshell::command::bview(const wstring& filename)
{
	std::wifstream ifs;
	ifs.imbue(locale(""));
	ifs.open(filename);
	if(ifs.fail())
		return false;

	char buffer[FILE_SIZE_MAX];
	size_t buf_count = ifs.read(buffer, (sizeof(buffer) / sizeof(char))).gcount();

	wcout << L"\t+0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F 0123456789ABCDEF\n";
	for(unsigned int i = 0 ; i < buf_count ; i += 0x10)
	{
		cout << hex << i << dec << ":\t";

		for(unsigned int j = 0 ; j <= 0xf ; j++)
			wprintf(L"%02X ", static_cast<unsigned char>(buffer[i + j]));

		for(unsigned int k = 0 ; k <= 0xf ; k++)
			wcout << isprint(static_cast<int>(buffer[i + k])) ? buffer[i + k] : L'.';

		cout << '\n';
	}

	return true;
}

bool myshell::command::app(const wstring& app_name)
{
	if(!_wsystem(nullptr))
		return false;

	int ret = _wsystem(app_name.c_str());
	wcout << L"return value: " << ret << L'\n';

	return true;
}

bool myshell::command::rm(const wstring& filename)
{
	path file(filename);
	try
	{
		boost::filesystem::remove(file);
	}
	catch(filesystem_error& e)
	{
		wchar_t* mess;
		const char* mess_c = e.what();
		mbstowcs(mess, mess_c, strlen(mess_c) + 1);

		wcerr << L"error: " << mess << L'\n';
		return false;
	}

	return true;
}

inline bool rename(const std::wstring& from_name, const std::wstring& to_name)
{
	path from(from_name);
	path to(to_name);

	try
	{
		boost::filesystem::rename(from, to);
	}
	catch(filesystem_error& e)
	{
		wchar_t* mess;
		const char* mess_c = e.what();
		mbstowcs(mess, mess_c, strlen(mess_c) + 1);

		wcerr << L"error: " << e.what() << L'\n';
		return false;
	}

	return false;
}
