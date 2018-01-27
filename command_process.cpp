// Standard Library
#include <string>
#include <regex>
#include <sstream>
#include <cstdlib>

// Header
#include "function.h"
#include "constant.h"

// using
using namespace std;

bool myshell::command_process(const string& command)
{
	if(regex_match(command, regex("mk \\S+"))) // Make a file
	{
		istringstream iss(command);
		iss.ignore(3);

		string filename;
		iss >> filename;

		return command::mk(filename);
	}
	else if(regex_match(command, regex("rm \\S+"))) // Remove a file
	{
		istringstream iss(command);
		iss.ignore(3);

		string filename;
		iss >> filename;

		return command::rm(filename);
	}
	else if(regex_match(command, regex("copy \\S+ \\S+"))) // Copy file
	{
		istringstream iss(command);
		iss.ignore(5);

		string from_filename;
		string to_filename;
		iss >> from_filename >> to_filename;

		return command::copy(from_filename, to_filename);
	}
	else if(regex_match(command, regex("lfile \\S+"))) // Print list of files
	{
		istringstream iss(command);
		iss.ignore(6);

		string dir_name;
		iss >> dir_name;

		return command::lfile(dir_name);
	}
	else if(regex_match(command, regex("mkdir \\S+"))) // Make a directory
	{
		istringstream iss(command);
		iss.ignore(6);

		string dir_name;
		iss >> dir_name;

		return command::mkdir(dir_name);
	}
	else if(regex_match(command, regex("rmdir \\S+"))) // Remove a directory
	{
		istringstream iss(command);
		iss.ignore(6);

		string dir_name;
		iss >> dir_name;

		return command::rmdir(dir_name);
	}
	else if(command == "pcwd") // Print current working directory
		return command::pcwd();
	else if(regex_match(command, regex("chcwd \\S+"))) // Change current working directory
	{
		istringstream iss(command);
		iss.ignore(6);

		string dir_name;
		iss >> dir_name;

		return command::chcwd(dir_name);
	}
	else if(regex_match(command, regex("rename \\S+ \\S+"))) // Rename a directory or a file
	{
		istringstream iss(command);
		iss.ignore(7);

		string from_name;
		string to_name;
		iss >> from_name >> to_name;

		return command::rename(name);
	}
	else if(regex_match(command, regex("tview \\S+"))) // View text contents of a file
	{
		istringstream iss(command);
		iss.ignore(6);

		string filename;
		iss >> filename;

		return command::tview(filename);
	}
	else if(regex_match(command, regex("bview \\S+"))) // View binary contents of a file
	{
		istringstream iss(command);
		iss.ignore(6);

		string filename;
		iss >> filename;

		return command::bview(filename);
	}
	else if(command == "version") // Print current version
		return command::version();
	else if(regex_match(command, regex("app .+"))) // Execution a application
	{
		string app_name = command.substr(4);
		return command::app(app_name);
	}
	else if(command == "date") // Print current date
		return command::date();
	else if(command == "time") // Print current time
		return command::time();
	else if(command == "pause") // Pause
		return command::pause();
	else if(regex_match(command, regex("script \\S+"))) // Execution a script
	{
		istringstream iss(command);
		iss.ignore(7);

		string filename;
		iss >> filename;

		return script(filename);
	}
	else if(command == "exit")
		exit(ExitCode::SUCCESS);
	else return false;
}
