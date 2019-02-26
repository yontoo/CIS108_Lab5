#include <string>

#pragma once

struct song {
	char song[64];
	std::string artist;
	std::string album;
	int trk_num;		//Track number
	int year;
	enum genres {
		Blues = 0,
		Country,
		Electronic,
		Folk,
		Hip_Hop,
		Jazz,
		Latin,
		Pop,
		Rock

	};
};