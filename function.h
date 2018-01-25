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

	inline void print_version()
	{
		std::cout << "MyShell version " << VERSION << '\n';
	}
}

#endif
