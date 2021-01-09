#pragma once
#include <iostream>
#include <string>
#include <set>
#include "Date.h"

//A class that holds the information about the song

class Song
{
private:
	std::string name;
	std::string singer;
	std::string genre;
	std::string album;
	int year;
	float rating;	
	std::set<std::string> usersWhoVoted;

public:
	Song(std::string _name, std::string _singer, std::string _genre, std::string _album, 
		 int _year, float _rating);

	std::string getName();
	void setName(std::string _name);
	std::string getSinger();
	void setSinger(std::string _singer);
	std::string getGenre();
	void setGenre(std::string _genre);
	std::string getAlbum();
	void setAlbum(std::string _album);
	int getYear();
	void setYear(int _year);
	float getRating();
	void setRating(float _rating);

	//void addToRating(float value);
	float getAverageRating(int numberOfUsers);

	bool operator < (const Song& s) const;
	friend std::ostream& operator << (std::ostream& output, const Song& song);
};

/*
���������� �� �������� � ��������� ���������� ������ �� ������ ��������. 
���� �������� �� ����� �� �� ���������� � ��������� �������� � � ��� � �� �� ��������� �� ���������. 
��������� �� � �������� ������ ���������� � ���� ���� �� ������� ��� �� �������. 

��������:
�������, ��-����� �� ���������� ��������
��������� ��� ���������� �� ������ ��������� �������
�� �� ���� �� �������� �� ����������� �������
�� �� ���� ��/����/����� ���������� ������

��������� �� ������� �������� ��� ������ ���
��������� �� ����� �������� �� ���
��������� �� ���������� �� ������ ����� ������� ��������
�������� �� ������� �� ���������� �����. ������ ������� �� ����� �� �������� ���� ������ �������� �� 
������ ���������� �� �����������. �� ������ �� ����������� �� ���������� �� ������� ������ �� ���� ��� 
�� ������ �����.

���� �������� �� ����� �� �� ���������� � ��������� �������� � � ��� � �� �� ��������� �� ���������.
	��������� �� � �������� ������ ���������� � ���� ���� �� ������� ��� �� �������.
	Playlist playlist;
	bool ? && ||
	1   rating > 4.5 => song.getRating() > rating => u.playlistsCollection.insert(Playlist(Song()))

	2   yes    if song.getGenre() is not contained in u.favouriteGenres => do not add
	    no     else													  => add

	3   add     addedGenresCollection    if song.getGenre() is in addedGenresCollection => add
		  remove  removedGenresCollection  if song.getGenre() is in removedGenresCollection => do not add

	4   if < year => if song.getYear() < year => u.playlistsCollection.insert(Playlist(Song()))
	       = year => if song.getYear() == year => u.playlistsCollection.insert(Playlist(Song()))
	       > year => if song.getYear() > year => u.playlistsCollection.insert(Playlist(Song()))

	playlist.addSongInPlaylist(song);

	1 && 2 || 3 && 4
 */