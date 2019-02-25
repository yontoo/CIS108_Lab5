#include <string>
#include <iostream>
#include "MusicDB.h"



int main()
{
	std::string choice;
	std::cout << "Commands in this program:\n";
	std::cout << "1. add - Add a new song to the database.\n";
	std::cout << "2. list - List the songs in the database.\n";
	std::cout << "3. save - Save the songs to the database.\n";
	std::cout << "4. help - Display this menu again.\n";
	std::cout << "5. exit - Close program.\n";
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
	} while (choice != "exit");


	return 0;
}