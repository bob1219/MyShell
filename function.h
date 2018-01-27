#ifndef _FUNCTION_H_
#define _FUNCTION_H_

// Standard Library
#include <string>
#include <iostream>

// Header
#include "constant.h"

namespace myshell
{
	void command_line();
	bool script(const std::string& filename);
	bool command_process(const std::string& command);

	inline void print_version()
	{
		std::cout << "MyShell version " << VERSION << '\n';
	}

	namespace command
	{
		bool mk(const std::string& filename);
		bool rm(const std::string& filename);
		bool copy(const std::string& from_filename, const std::string& to_filename);
		bool lfile(const std::string& dir_name);
		bool mkdir(const std::string& dir_name);
		bool rmdir(const std::string& dir_name);
		bool pcwd();
		bool chcwd(const std::string& dir_name);
		bool rename(const std::string& from_name, const std::string& to_name);
		bool tview(const std::string& filename);
		bool bview(const std::string& filename);
		bool version();
		bool app(const std::string& app_name);
		bool date();
		bool time();
		bool pause();
	}
}

#endif
