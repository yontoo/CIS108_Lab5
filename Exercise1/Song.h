#include <string>

#pragma once

struct song {
	char song[64];
	char artist[32];
	char album[64];
	char genre[10];
	int trk_num;		//Track number
	int year;
	char genre[20];
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