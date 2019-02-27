#include "MusicDB.h"
#include "Song.h"
#include <fstream>



std::string genre;
song local;
int total_songs = 0;


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
	std::cin.getline (local.artist, 32);
	std::cout << "\n";

	std::cout << "Enter the album name: ";
	std::cin.getline (local.album, 64);
	std::cout << "\n";

	std::cout << "Album track number: ";
	std::cin >> local.trk_num;
	std::cout << "\n";

	std::cout << "Enter release year: ";
	std::cin >> local.year;
	std::cout << "\n";

	std::cout << "Enter genre: ";
	std::getline(std::cin, genre);

	//for(int x = 0, x > musicdb::song_array)


		
}

void musicdb::help()
{
	std::cout << "Commands in this program:\n";
	std::cout << "1. add - Add a new song to the database.\n";
	std::cout << "2. list - List the songs in the database.\n";
	std::cout << "3. save - Save the songs to the database.\n";
	std::cout << "4. help - Display this menu again.\n";
	std::cout << "5. exit - Close program.\n";
}

//total number of songs
//int total()
//{
//
//}

//Song info