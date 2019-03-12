#include <string>
#include <iostream>
#include "MusicDB.h"



int main()
{
	std::string choice;
	musicdb::init_load();
	musicdb::help();
	do
	{
		std::cout << ">";
		std::cin >> choice;
		std::cin.ignore();		//Apparently c++ doesn't like the combination of the operator ">>" and "getline." This fixes the problem of the program not waiting for input by flushing the buffer.

		if (choice == "add")
		{
			musicdb::add();
		}

		else if (choice == "save")
		{
			musicdb::save();
		}

		else if (choice == "list")
		{
			musicdb::list();
		}

		else if (choice == "help")
		{
			musicdb::help();
		}
		else if (choice == "clear")
		{
			musicdb::clear();
		}
	} while (choice != "exit");
	return 0;
}