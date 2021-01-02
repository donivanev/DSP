#pragma once
#include <iostream>
#include <string>
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
	double rating;	

public:
	Song(std::string _name, std::string _singer, std::string _genre, std::string _album, 
		int _year, double _rating);

	std::string getName();
	std::string getSinger();
	std::string getGenre();
	std::string getAlbum();
	Date getYear();
	double getRating();
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
*/
 





