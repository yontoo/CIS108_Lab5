#include "MusicDB.h"
#include "Song.h"
#include <fstream>



std::string genre;
song local;
int musicdb::songs = { };

//save some music
void musicdb::save()
{
	std::ofstream database;
	database.open("Database.txt");
	database << "Title:		" << local.song << "\nArtist:		" << local.artist << "\nAlbum:			" << local.album << "\nTrack #:			" << local.trk_num << "\nRelease year:			" << local.year;
	database.close();
}

//load some music
//void musicdb::list(int x)
//{
//	for(x = 0; x < song_count; x++)
//}

//add some music
void musicdb::add()
{
	
	genre = "";

	std::cout << "Enter the song title: ";
	std::cin.getline (local.song, 64);
	std::cout << "\n";

	std::cout << "Enter the artist: ";
	std::getline(std::cin, local.artist);
	std::cout << "\n";

	std::cout << "Enter the album name: ";
	std::getline(std::cin, local.album);
	std::cout << "\n";

	std::cout << "Album track number: ";
	std::cin >> local.trk_num;
	std::cout << "\n";

	std::cout << "Enter release year: ";
	std::cin >> local.year;
	std::cout << "\n";

	//std::cout << "Enter genre: ";
	//std::getline(std::cin, genre);


		
}

//total number of songs
//int total()
//{
//
//}

//Song info