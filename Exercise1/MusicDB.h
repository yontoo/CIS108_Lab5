#pragma once
#include <string>
#include <iostream>



namespace musicdb
{
	void save();
	void add();
	void list(int);
	int total();
	void help();
	int songs[8];
}