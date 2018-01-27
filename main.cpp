// Standard Library
#include <iostream>
#include <vector>
#include <string>
#include <exception>

// Boost
#include <boost/system/system_error.hpp>
#include <boost/system/error_code.hpp>

// Header
#include "function.h"
#include "constant.h"

// using
using namespace myshell;
using namespace std;

int main(int argc, char** argv)
{
	try
	{
		vector<string> args;
		for(unsigned int i = 0 ; i < argc ; i++)
			args[i] = argv[i];

		if(argc == 1)
		{
			print_version();
			cout << '\n';
			command_line();
		}
		else if(argc == 2)
		{
			if(script(args[1]))
			{
				cout << "succeeded run script.\n";
				return exit_code::SUCCESS;
			}
			else
			{
				cerr << "failed run script.\n";
				return exit_code::SCRIPT_FAILURE;
			}
		}
		else
		{
			cerr	<< "usage:\n"
				<< '"' << args[0] << '"' << '\n'
				<< "or\n"
				<< '"' << args[0] << " [script-filename]\n";
			return exit_code::MANY_ARGS;
		}
	}
	catch(boost::system::system_error& e)
	{
		cerr << "boost exception was occured.\n";
		cerr << "error code:\t" << e.code().value() << '\n';
		cerr << "error message:\t" << e.what() << '\n';
		return exit_code::BOOST_EXCEPTION;
	}
	catch(std::exception& e)
	{
		cerr << "standard c++ library exception was occured.\n";
		cerr << "error message: " << e.what() << '\n';
		return exit_code::STD_EXCEPTION;
	}
	catch(...)
	{
		cerr << "error.\n";
		return exit_code::EXCEPTION;
	}
}
