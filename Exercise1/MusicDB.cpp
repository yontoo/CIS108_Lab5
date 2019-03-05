#include "MusicDB.h"
#include "Song.h"
#include <fstream>
#include <string>
#include <iostream>



std::string genre = "";
song local_array[8];
int total_songs = 0;
int curr_song_num = 1;


//save some music
void musicdb::save()
{
	std::ofstream database;
	database.open("Database.txt", std::fstream::app);
	database << "Song #" << curr_song_num << "\n";
	database << "Title:	" << local_array[total_songs - 1].song;
	database << "\nArtists: " << local_array[total_songs - 1].artist;
	database << "\nAlbum: " << local_array[total_songs - 1].album;
	database << "\nTrack #: " << local_array[total_songs - 1].trk_num;
	database << "\nRelease year: " << local_array[total_songs - 1].year;
	database << "\n\n";
	database.close();
	curr_song_num++;
}
//load some music
void musicdb::list()
{
	std::string song_info;
	std::ifstream database("Database.txt");
	if (database.is_open())
	{
		while (std::getline(database, song_info))
		{
			std::cout << song_info << "\n";
		}
		database.close();
	}
}

//add some music
void musicdb::add()
{
	{
		std::cout << "Enter the song title: ";
		std::cin.getline(local_array[total_songs].song, 64);
		std::cout << "\n";

		std::cout << "Enter the artist: ";
		std::cin.getline(local_array[total_songs].artist, 32);
		std::cout << "\n";

		std::cout << "Enter the album name: ";
		std::cin.getline(local_array[total_songs].album, 64);
		std::cout << "\n";

		std::cout << "Album track number: ";
		std::cin >> local_array[total_songs].trk_num;
		std::cout << "\n";

		std::cout << "Enter release year: ";
		std::cin >> local_array[total_songs].year;
		std::cout << "\n";

		std::cout << "Enter genre: ";
		std::getline(std::cin, genre);
		std::cout << "\n";
		total_songs++;
	}
		
}

void musicdb::help()
{
	std::cout << "Commands in this program:\n";
	std::cout << "1. add - Add a new song to the database.\n";
	std::cout << "2. list - List the songs in the database.\n";
	std::cout << "3. save - Save the songs to the database.\n";
	std::cout << "4. clear - Clear the current songs inside of the database.\n";
	std::cout << "5. help - Display this menu again.\n";
	std::cout << "6. exit - Close program.\n";
}

//clear the music
void musicdb::clear()
{
	std::ofstream database;
	database.open("Database.txt", std::ofstream::trunc);
	database.close();
}


//Song info