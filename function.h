#ifndef _FUNCTION_H_
#define _FUNCTION_H_

// Standard Library
#include <string>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Boost
#include <boost/filesystem.hpp>

// Header
#include "constant.h"

namespace myshell
{
	void command_line();
	bool script(const std::wstring& filename);
	bool command_process(const wstd::string& command);

	inline void print_version()
	{
		std::wcout << L"MyShell version " << VERSION << L'\n';
	}

	namespace command
	{
		bool mk(const std::wstring& filename);
		bool copy(const std::wstring& from_filename, const std::wstring& to_filename);
		bool lfile(const std::wstring& dir_name);
		bool tview(const std::wstring& filename);
		bool bview(const std::wstring& filename);
		bool app(const std::wstring& app_name);
		bool rm(const std::string& filename);

		inline bool mkdir(const std::wstring& dir_name)
		{
			boost::filesystem::path dir(dir_name);
			return boost::filesystem::create_directory(dir);
		}

		inline bool rmdir(const std::wstring& dir_name)
		{
			boost::filesystem::path dir(dir_name);
			if(!boost::filesystem::is_directory(dir))
				return false;
			return boost::filesystem::remove(dir_name.c_str());
		}

		inline bool pcwd()
		{
			boost::filesystem::path cwd = boost::filesystem::current_path();
			std::wcout << cwd.wstring() << L'\n';
			return true;
		}

		inline bool chcwd(const std::wstring& dir_name)
		{
			boost::filesystem::path dir(dir_name);
			boost::filesystem::current_path(dir);
			return true;
		}

		inline bool version()
		{
			std::wcerr << L"MyShell version " << VERSION << L'\n';
			return true;
		}

		inline bool now()
		{
			std::time_t timer = std::time(nullptr);
			std::wcout << std::_wctime(&timer) << L'\n';
			return true;
		}

		inline bool pause()
		{
			std::wcout << L"Press ENTER key to continue...";
			std::getwchar();
			return true;
		}
	}
}

#endif
