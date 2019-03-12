#include "MusicDB.h"
#include "Song.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>


std::string genre = "";
std::string checked_genre = "";
int genre_enum;
song local_array[8];
int total_songs = 0;

//save some music
void musicdb::save()
{
	std::ofstream database;
	database.open("Database.txt", std::fstream::app);
	database << local_array[total_songs - 1].song << '&' << local_array[total_songs - 1].artist << '&' << local_array[total_songs - 1].album << '&' << local_array[total_songs - 1].trk_num << '&' << local_array[total_songs - 1].year << '&' << local_array[total_songs - 1].genre << "&\n";
	database.close();
}
//load some music
void musicdb::list()
{
	int curr_song_num = 1;
	if (total_songs == 1)
	{
		std::cout << "There is " << total_songs << " song in the database\n";
	}
	else
	{
		std::cout << "There are " << total_songs << " songs in the database\n";
	}
	for (int z = 0; z < total_songs; z++)
	{
		std::cout << "Song #" << curr_song_num << "\n";
		std::cout << "Song title: " << local_array[z].song;
		std::cout << "\nArtist: " << local_array[z].artist;
		std::cout << "\nAlbum: " << local_array[z].album;
		std::cout << "\nTrack #: " << local_array[z].trk_num;
		std::cout << "\nRelease year: " << local_array[z].year;
		std::cout << "\nGenre: " << local_array[z].genre << "\n\n";
		curr_song_num++;
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
		std::cin.ignore();
		std::cout << "\n";

		std::cout << "Enter genre: ";
		std::getline(std::cin, genre);
		musicdb::checking();
		std::istringstream sschecked_genre(checked_genre);
		checked_genre.copy(local_array[total_songs].genre, 20);
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
	total_songs = 0;
}

//function to load any songs from the file into array at start up

void musicdb::init_load()
{
	std::string read_line;
	std::string temp;
	std::ifstream database;
	database.open("Database.txt");
	while(std::getline(database, read_line))
	{
		std::istringstream ssread_line(read_line);
		std::getline(ssread_line, temp, '&');
		temp.copy(local_array[total_songs].song, 64);
		std::getline(ssread_line, temp, '&');
		temp.copy(local_array[total_songs].artist, 32);
		std::getline(ssread_line, temp, '&');
		temp.copy(local_array[total_songs].album, 64);
		std::getline(ssread_line, temp, '&');
		local_array[total_songs].trk_num = std::stoi(temp);
		std::getline(ssread_line, temp, '&');
		local_array[total_songs].year = std::stoi(temp);
		std::getline(ssread_line, temp, '&');
		temp.copy(local_array[total_songs].genre, 20);
		total_songs++;

	}


	database.close();
}

void musicdb::checking()
{
	//https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
	std::transform(genre.begin(), genre.end(), genre.begin(), ::tolower);
	if (genre == "blues")
	{
		genre_enum = song::genres::Blues;
	}
	else if (genre == "country")
	{
		genre_enum = song::genres::Country;
	}
	else if (genre == "electronic")
	{
		genre_enum = song::genres::Electronic;
	}
	else if (genre == "folk")
	{
		genre_enum = song::genres::Folk;
	}
	else if (genre == "hip hop" || genre == "hiphop" || genre == "hip-hop")
	{
		genre_enum = song::genres::Hip_Hop;
	}
	else if (genre == "jazz")
	{
		genre_enum = song::genres::Jazz;
	}
	else if (genre == "latin")
	{
		genre_enum = song::genres::Latin;
	}
	else if (genre == "pop")
	{
		genre_enum = song::genres::Pop;
	}
	else if (genre == "rock")
	{
		genre_enum = song::genres::Rock;
	}
	else
	{
		std::cout << "Error: Invalid Genre";
	}
	switch (genre_enum)
	{
	case 0:
		checked_genre = "Blues";
		break;
	case 1:
		checked_genre = "Country";
		break;
	case 2:
		checked_genre = "Electronic";
		break;
	case 3:
		checked_genre = "Folk";
		break;
	case 4:
		checked_genre = "Hip Hop";
		break;
	case 5:
		checked_genre = "Jazz";
		break;
	case 6:
		checked_genre = "Latin";
		break;
	case 7:
		checked_genre = "Pop";
		break;
	case 8:
		checked_genre = "Rock";
	}
}