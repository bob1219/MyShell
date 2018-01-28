// Standard Library
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <locale>
#include <cstdlib>
#include <cstring>

// Boost
#include <boost/system/system_error.hpp>
#include <boost/system/error_code.hpp>

// Header
#include "function.h"
#include "constant.h"

// using
using namespace myshell;
using namespace std;

int wmain(int argc, wchar_t** argv)
{
	try
	{
		wcout.imbue(locale(""));
		wcerr.imbue(locale(""));
		wcin.imbue(locale(""));

		vector<wstring> args;
		for(unsigned int i = 0 ; i < argc ; i++)
			args.push_back(argv[i]);

		if(argc == 1)
		{
			print_version();
			wcout << L'\n';
			command_line();
		}
		else if(argc == 2)
		{
			if(script(args[1]))
			{
				wcout << L"succeeded run script.\n";
				return exit_code::SUCCESS;
			}
			else
			{
				wcerr << L"failed run script.\n";
				return exit_code::SCRIPT_FAILURE;
			}
		}
		else
		{
			wcerr	<< L"usage:\n"
				<< L'"' << args[0] << L'"' << L'\n'
				<< L"or\n"
				<< L'"' << args[0] << L" [script-filename]\n";
			return exit_code::MANY_ARGS;
		}
	}
	catch(boost::system::system_error& e)
	{
		wchar_t* mess;
		const char* mess_c = e.what();
		mbstowcs(mess, mess_c, strlen(mess_c) + 1);

		wcerr << L"boost exception was occured.\n";
		wcerr << L"error code:\t" << e.code().value() << L'\n';
		wcerr << L"error message:\t" << mess << L'\n';
		return exit_code::BOOST_EXCEPTION;
	}
	catch(std::exception& e)
	{
		wchar_t* mess;
		const char* mess_c = e.what();
		mbstowcs(mess, mess_c, strlen(mess_c) + 1);

		wcerr << L"standard c++ library exception was occured.\n";
		wcerr << L"error message: " << mess << L'\n';
		return exit_code::STD_EXCEPTION;
	}
	catch(...)
	{
		wcerr << L"error.\n";
		return exit_code::EXCEPTION;
	}
}
