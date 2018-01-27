#ifndef _CONSTANT_H_
#define _CONSTANT_H_

// Standard Library
#include <string>
#include <cstddef>

namespace myshell
{
	namespace
	{
		const std::string VERSION	= "1.0";
		const std::size_t FILE_SIZE_MAX	= 102400;
	}

	namespace ExitCode
	{
		namespace
		{
			const int SUCCESS = 0;
		}
	}
}

#endif
