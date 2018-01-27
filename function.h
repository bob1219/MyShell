#ifndef _FUNCTION_H_
#define _FUNCTION_H_

// Standard Library
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio>

// Boost
#include <boost/filesystem.hpp>

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
		bool copy(const std::string& from_filename, const std::string& to_filename);
		bool lfile(const std::string& dir_name);
		bool tview(const std::string& filename);
		bool bview(const std::string& filename);
		bool app(const std::string& app_name);

		inline bool rm(const std::string& filename)
		{
			return std::remove(filename.c_str()) == 0;
		}


		inline bool mkdir(const std::string& dir_name)
		{
			boost::filesystem::path dir(dir_name);
			return boost::filesystem::create_directory(dir);
		}


		inline bool rmdir(const std::string& dir_name)
		{
			boost::filesystem::path dir(dir_name);
			if(!boost::filesystem::is_directory(dir))
				return false;
			return std::remove(dir_name.c_str());
		}


		inline bool pcwd()
		{
			boost::filesystem::path cwd = boost::filesystem::current_path();
			std::cout << cwd.string() << '\n';
			return true;
		}


		inline bool chcwd(const std::string& dir_name)
		{
			boost::filesystem::path dir(dir_name);
			boost::filesystem::current_path(dir);
			return true;
		}


		inline bool rename(const std::string& from_name, const std::string& to_name)
		{
			return std::rename(from_name.c_str(), to_name.c_str()) == 0;
		}


		inline bool version()
		{
			std::cerr << "MyShell version " << VERSION << '\n';
			return true;
		}

		inline bool now()
		{
			std::time_t timer = std::time(nullptr);
			std::cout << std::ctime(&timer) << '\n';
			return true;
		}

		inline bool pause()
		{
			std::cout << "Press ENTER key to continue...";
			std::getchar();
			return true;
		}
	}
}

#endif
