#ifndef _CONSTANT_H_
#define _CONSTANT_H_

// Standard Library
#include <string>
#include <cstddef>

namespace myshell
{
	namespace
	{
		const std::wstring VERSION	= L"1.0";
		const std::size_t FILE_SIZE_MAX	= 102400;
	}

	namespace exit_code
	{
		namespace
		{
			const int SUCCESS		= 0;
			const int SCRIPT_FAILURE	= 1;
			const int MANY_ARGS		= 2;
			const int STD_EXCEPTION		= -1;
			const int BOOST_EXCEPTION	= -2;
			const int EXCEPTION		= -3;
		}
	}
}

#endif
