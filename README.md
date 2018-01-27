MyShell
=======
MyShell is a command-line-shell project.

Development Environment
-----------------------
* Operating System: Microsoft Windows 10
* Programing Language: C++
* Compiler: g++(MinGW)

Files
-----
* Source file
	* commands.cpp  
	functions of commands (namespace "myshell::command")

	* main.cpp  
	main function

	* script.cpp  
	script function

	* command\_process.cpp  
	myshell::command\_process function

	* command\_line.cpp  
	myshell::command\_line function

* Header
	* function.h  
	declarations of functions

	* constant.h  
	constants

* Other
	* .gitignore  
	Ignore files in working tree of git

	* LICENSE  
	License file of GPL v3.0

	* myshell.exe  
	Executable file of Microsoft Windows 10

	* README.md  
	Readme file (this file)

Commands
--------
* mk  
Make a file

* rm  
Remove a file

* copy  
Copy file

* lfile  
Print list of files

* mkdir  
Make a directory

* rmdir  
Remove a directory

* pcwd  
Print current working directory

* chcwd  
Change current working directory

* rename  
Rename a directory or a file

* tview  
View a file (text)

* bview  
View a file (binary)

* version  
Print current version

* app  
Execution a application

* now  
Print current date and time

* pause  
Pause

* script  
Execution a script

* exit  
Exit MyShell

History
-------
* 1.0 (January 27th, 2018)
	* First version
