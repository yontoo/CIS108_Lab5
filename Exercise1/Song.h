#include <string>

#pragma once

struct song {
	std::string song;
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