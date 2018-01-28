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

bool myshell::command_process(const wstring& command)
{
	if(regex_match(command, regex(L"mk \\S+"))) // Make a file
	{
		wistringstream iss(command);
		iss.ignore(3);

		wstring filename;
		iss >> filename;

		return command::mk(filename);
	}
	else if(regex_match(command, regex(L"rm \\S+"))) // Remove a file
	{
		wistringstream iss(command);
		iss.ignore(3);

		wstring filename;
		iss >> filename;

		return command::rm(filename);
	}
	else if(regex_match(command, regex(L"copy \\S+ \\S+"))) // Copy file
	{
		wistringstream iss(command);
		iss.ignore(5);

		wstring from_filename;
		wstring to_filename;
		iss >> from_filename >> to_filename;

		return command::copy(from_filename, to_filename);
	}
	else if(regex_match(command, regex(L"lfile \\S+"))) // Print list of files
	{
		wistringstream iss(command);
		iss.ignore(6);

		wstring dir_name;
		iss >> dir_name;

		return command::lfile(dir_name);
	}
	else if(regex_match(command, regex(L"mkdir \\S+"))) // Make a directory
	{
		wistringstream iss(command);
		iss.ignore(6);

		wstring dir_name;
		iss >> dir_name;

		return command::mkdir(dir_name);
	}
	else if(regex_match(command, regex(L"rmdir \\S+"))) // Remove a directory
	{
		wistringstream iss(command);
		iss.ignore(6);

		wstring dir_name;
		iss >> dir_name;

		return command::rmdir(dir_name);
	}
	else if(command == L"pcwd") // Print current working directory
		return command::pcwd();
	else if(regex_match(command, regex(L"chcwd \\S+"))) // Change current working directory
	{
		wistringstream iss(command);
		iss.ignore(6);

		wstring dir_name;
		iss >> dir_name;

		return command::chcwd(dir_name);
	}
	else if(regex_match(command, regex(L"rename \\S+ \\S+"))) // Rename a directory or a file
	{
		wistringstream iss(command);
		iss.ignore(7);

		wstring from_name;
		wstring to_name;
		iss >> from_name >> to_name;

		return command::rename(from_name, to_name);
	}
	else if(regex_match(command, regex(L"tview \\S+"))) // View text contents of a file
	{
		wistringstream iss(command);
		iss.ignore(6);

		wstring filename;
		iss >> filename;

		return command::tview(filename);
	}
	else if(regex_match(command, regex(L"bview \\S+"))) // View binary contents of a file
	{
		wistringstream iss(command);
		iss.ignore(6);

		wstring filename;
		iss >> filename;

		return command::bview(filename);
	}
	else if(command == L"version") // Print current version
		return command::version();
	else if(regex_match(command, regex(L"app .+"))) // Execution a application
	{
		wstring app_name = command.substr(4);
		return command::app(app_name);
	}
	else if(command == L"now")
		return command::now();
	else if(command == L"pause") // Pause
		return command::pause();
	else if(regex_match(command, regex(L"script \\S+"))) // Execution a script
	{
		wistringstream iss(command);
		iss.ignore(7);

		wstring filename;
		iss >> filename;

		return script(filename);
	}
	else if(command == L"exit")
		exit(exit_code::SUCCESS);
	else return false;
}
