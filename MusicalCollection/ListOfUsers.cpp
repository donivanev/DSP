#include "ListOfUsers.h"

//A function that converts a date in format "dd-mm-yyyy" to date in with integers in order to 
//eventually comparing dates
void ListOfUsers::toDate(std::string& str, int& y, int& m, int& d)
{
	int place = 0;
	std::string token, delimeter = "-";
	std::vector<std::string> v;

	while ((place = str.find(delimeter)) != std::string::npos)
	{
		token = str.substr(0, place);
		v.push_back(token);
		str.erase(0, place + delimeter.length());
	}
	v.push_back(str);

	d = stoi(v.at(0));
	m = stoi(v.at(1));
	y = stoi(v.at(2));
}

void ListOfUsers::strToVector(std::string genres, std::vector<std::string>& genresCollection)
{
	int place = 0;
	std::string token, delimeter = " ";

	while ((place = genres.find(delimeter)) != std::string::npos)
	{
		token = genres.substr(0, place);
		genresCollection.push_back(token);
		genres.erase(0, place + delimeter.length());
	}

	genresCollection.push_back(genres);
}

int ListOfUsers::strToInt(std::string s)
{
	int number = 0, power = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		number += (s[i] - '0') * pow(10, power);
		power++;
	}

	return number;
}

void ListOfUsers::reverseStr(std::string& str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
	{
		int helper = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = helper;
	}
}

void ListOfUsers::removeSpace(std::string& str)
{
	std::string strWithoutSpacesAfter;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] == '\0')
		{
			break;
		}
		else
		{
			strWithoutSpacesAfter += str[i];
		}
	}

	str = strWithoutSpacesAfter;
}

void ListOfUsers::saveSong(std::set<Song> listOfSongs)
{
	f_inout.open("songs.txt", std::ios::out);
	//f_inout.clear();
	for (Song song : listOfSongs)
	{
		f_inout << song << "\n-----";
		f_inout << std::endl;
	}
	f_inout.close();
}

void ListOfUsers::processExpression(std::string expression, std::vector<std::string>& arr)
{
	int place = 0;
	std::string token, delimeter = " ";

	while ((place = expression.find(delimeter)) != std::string::npos)
	{
		token = expression.substr(0, place);
		arr.push_back(token);
		expression.erase(0, place + delimeter.length());
	}

	token = expression.substr(0, place);
	arr.push_back(token);
}

//A function that searches the file for an user
bool ListOfUsers::userExists(std::string username, std::string password)
{
	for (User user : listOfUsers)
	{
		//if (user.getUsername() == username && user.getPassword() == password)
		if (user.getUsername() == username)
		{
			return true;
		}
	}

	return false;

	/*f_inout.open("users.txt");

	std::string line;
	bool usr = false, pas = false;

	while (std::getline(f_inout, line)) 
	{
		if (line.find(username) != std::string::npos) 
		{
			if (username == line)
			{
				usr = true;
			}
		}
 		if (line.find(password) != std::string::npos)
		{
			if (password == line)
			{
				pas = true;
			}
		}
		if (usr && pas)
		{
			break;
		}
		if (line == "___\r")
		{
			usr = false;
			pas = false;
		}
	}
	
	f_inout.close();

	return usr && pas;*/
} 

//A function that adds an user
void ListOfUsers::addUser(std::string _username, std::string _password, std::string _fullName, Date _birthdate,
				          std::vector<std::string> _favouriteGenres, std::set<Playlist> _playlistsCollection)
{
	listOfUsers.push_back(User(_username, _password, _fullName, _birthdate, _favouriteGenres, _playlistsCollection));
}

//A function that prints all the users
void ListOfUsers::printUsers()
{
	for (User u : listOfUsers)
	{
		u.printUser();
	}
}

void ListOfUsers::returnSongsToCollection()
{
	f_inout.open("songs.txt");

	std::string line;
	std::vector<std::string> arrOfData;

	while (std::getline(f_inout, line))
	{
		if (line != "-----\r")
		{
			arrOfData.push_back(line);
		}

		if (line.find("-----") != std::string::npos)
		{
			Song song(arrOfData[0], arrOfData[1], arrOfData[2], arrOfData[3], stoi(arrOfData[4]), 
					  atof(arrOfData[5].c_str()));
			listOfSongs.insert(song);
			arrOfData.clear();
		}
	}

	f_inout.close();
}

void ListOfUsers::changeProfileData(std::string user)
{
	std::cout << "Please choose one of the following: " << std::endl;
	std::cout << "Type U to change your username." << std::endl;
	std::cout << "Type P to change your password." << std::endl;
	std::cout << "Type F to change your fullname." << std::endl;
	std::cout << "Type B to change your birthdate." << std::endl;
	std::cout << "Type G to change your favourite genres." << std::endl;

	char choice = ' ';
	std::cin >> choice;
	std::string strData;
	int y, m, d;
	char aOrR = ' ';
	std::vector<User> listOfUsersHelper;

	for (User u : listOfUsers)
	{
		if (u.getUsername() == user)
		{
			switch (choice)
			{
				case 'U': std::cout << "Please type your new username: "; std::cin.ignore();
					std::getline(std::cin, strData); u.setFullName(strData); break;
						  u.setUsername(strData); break;

				case 'P': std::cout << "Please type your new password: "; std::cin.ignore();
					std::getline(std::cin, strData); u.setFullName(strData); break;
						  u.setPassword(strData); break;

				case 'F': std::cout << "Please type your new fullname: "; std::cin.ignore(); 
					std::getline(std::cin, strData); u.setFullName(strData); break;

				case 'B': std::cout << "Please type your new birthdate: "; std::cin.ignore();
					std::getline(std::cin, strData); u.setFullName(strData); break;

				case 'G': std::cout << "-Type A to add a favourite genre." << std::endl;
						  std::cout << "-Type R to remove a favourite genre." << std::endl;
						  std::cin >> aOrR; break;
				default: break;
			}

			if (choice == 'B')
			{
				toDate(strData, y, m, d);
				Date date(y, m, d);
				u.setBirthdate(date);
			}

			if (aOrR == 'A')
			{
				std::string g;
				std::cin >> g;

				u.addGenre(g);
			}
			else if (aOrR == 'R')
			{
				std::string g;
				std::cin >> g;

				u.removeGenre(g); 
			}
		}
		//std::vector<std::string> favGenres;
		//strToVector(u.getGenres(), favGenres); 

		//listOfUsersHelper.push_back(User(u.getUsername(), u.getPassword(), u.getFullName(), u.getBirthdate(), favGenres, std::set<Playlist>()));
		listOfUsersHelper.push_back(User(u.getUsername(), u.getPassword(), u.getFullName(), u.getBirthdate(), 
			                             u.getGenres(), u.getPlaylists()));
	}

	listOfUsers = listOfUsersHelper;
	//printUsers();
}

void ListOfUsers::addSong()
{
	std::cout << "Please enter on a separate lines the following things: " <<
		"\nname, singer, genre, album, year, rating. Then type Submit." << std::endl;

	std::string info;
	std::vector<std::string> arrOfData; 

	while (info != "Submit")
	{
		std::getline(std::cin, info);
		arrOfData.push_back(info);
	}

	Song song(arrOfData[1], arrOfData[2], arrOfData[3], arrOfData[4], stoi(arrOfData[5]), atof(arrOfData[6].c_str()));

	returnSongsToCollection();
	listOfSongs.insert(song);
	saveSong(listOfSongs);
	std::cout << "Successfully added song!";
}

bool ListOfUsers::doesSongExist(std::string song)
{
	for (Song s : listOfSongs)
	{
		if (s.getName() == song)
		{
			return true;
		}
	}

	return false;
}

void ListOfUsers::generateAndSavePlaylist(std::string user)
{   
	returnSongsToCollection();
	std::cout << "Please choose from those following criteria and type one or more: " << std::endl;
	std::cout << "1. Rating bigger than a certain value (> [value])." << std::endl;
	std::cout << "2. Add or remove genres. (add/remove {genres})" << std::endl;
	std::cout << "3. Only from your favourite genres (y/n)." << std::endl;
	std::cout << "4. From/after/before a certain year (</=/> [year])." << std::endl;
	
	std::cout << "Enter an expression in the form: [criteria &&/|| criteria &&/|| criteria"
			  << "&&/|| criteria]\n";

	std::cin.ignore();
	std::string expression;
	std::getline(std::cin, expression);
	std::vector<std::string> arr;

	processExpression(expression, arr);

	char choice = ' ', criteria = ' ';
	std::string year = "", genres = "";
	float rating = 0.0;
	bool favourites = false, onlyOneElement = false;
	std::string path[6] = { "L", "R", "RL", "RR", "RRL", "RRR" };
	int index = 0, indexArr = 1;

	std::vector<User> listOfUsersHelper;

	/*if (arr.size() == 1)
	{
		onlyOneElement = true;
	}
	else
	{
		t.addNode(arr.at(indexArr).c_str(), "");
		indexArr += 2;
	}*/

	for (User u : listOfUsers)  
	{
		if (u.getUsername() == user)
		{
			Playlist playlist;

			for (int i = 0; i < arr.size(); i += 2)
			{
				if (arr[i] == "1")
				{
					std::cout << "Please enter rating: ";
					std::cin >> rating;
				}
				else if (arr[i] == "2")
				{
					std::cin.ignore();
					std::cout << "Please enter add/remove [genres]: ";
					std::getline(std::cin, genres);
				}
				else if (arr[i] == "3")
				{
					std::cout << "Do you want the songs to be only from your favourite genres? ";
					std::cin >> choice;
				}
				else if (arr[i] == "4")
				{
					std::cin.ignore();
					std::cout << "Please enter <, = or > [year] to select your filtering: ";
					std::getline(std::cin, year);
				}
			}

			for (Song song : listOfSongs)
			{
				bool isInRating = false, isInGenres = false, isInFavourites = false, isInYear = false;

				if (arr.size() == 1)
				{
					onlyOneElement = true;
				}
				else
				{
					t.addNode(arr.at(indexArr).c_str(), "");
					indexArr += 2;
				}

				for (int i = 0; i < arr.size(); i+=2)
				{
					if (rating != -1 && rating != 0.0 && isInRating == false)
					{
						song.getRating() > rating ? t.addNode("T", path[index].c_str())
												  : t.addNode("F", path[index].c_str());
						index++;
						isInRating = true;
					}
					else if (genres != "-" && genres != "" && isInGenres == false)
					{
						std::unordered_set<std::string> s;
						char empty = ' ';

						reverseStr(genres);

						int place = 0;
						std::string token, delimeter = " ";

						while ((place = genres.find(delimeter)) != std::string::npos)
						{
							token = genres.substr(0, place);
							reverseStr(token);
							s.insert(token);
							genres.erase(0, place + delimeter.length());
						}

						token = genres.substr(0, place);
						reverseStr(token);
						s.insert(token);

						if (*(s.begin()) == "add")
						{
							bool flag = true;

							for (auto iter = s.begin(); iter != s.end(); ++iter)
							{
								if (song.getGenre() != *iter)
								{
									flag = false;
									break;
								}
							}

							flag ? t.addNode("F", path[index].c_str()) : t.addNode("F", path[index].c_str());
							index++;
						}
						else if (*(s.begin()) == "remove")
						{
							bool flag = true;

							for (auto iter = s.begin(); iter != s.end(); ++iter)
							{
								if (song.getGenre() == *iter)
								{
									flag = false;
									break;
								}
							}

							flag ? t.addNode("T", path[index].c_str()) : t.addNode("F", path[index].c_str());
							index++;
						}
						else
						{
							std::cout << "Wrong command!";
						}

						isInGenres = true;
					}
					else if (choice != '-' && choice != ' ' && isInFavourites == false)
					{
						if (choice == 'y')
						{
							u.isFromFavourites(song.getGenre()) ? t.addNode("T", path[index].c_str())
															    : t.addNode("F", path[index].c_str());
							index++;
						}

						isInFavourites = true;
					}
					else if (year != "-" && year != "" && isInYear == false)
					{
						int y = strToInt(year.substr(2));

						switch (year[0])
						{
							case '>': song.getYear() > y ? t.addNode("T", path[index].c_str())
														 : t.addNode("F", path[index].c_str()); 
								break;
							case '=': song.getYear() == y ? t.addNode("T", path[index].c_str())
														  : t.addNode("F", path[index].c_str());
								break;
							case '<': song.getYear() < y ? t.addNode("T", path[index].c_str())
													     : t.addNode("F", path[index].c_str());
								break;
							default: break;
						}

						index++;
						isInYear = true;
					}

					if (!onlyOneElement)
					{
						if (indexArr < arr.size())
						{
							t.addNode(arr.at(indexArr), path[index].c_str());
							index++;
							indexArr += 2;
						}
					}
				}
				
				if (t.evaluateExpression()) 
				{
					//playlist.setNumber(++number);
					playlist.addSongToPlaylist(song);
				}

				t.clearTree();
			}

			std::string name;
			std::cout << "Please choose a name for your playlist: ";
			std::cin.ignore();	
			std::getline(std::cin, name);

			playlist.setName(name);
			u.pushInPlaylist(playlist);
		}

		listOfUsersHelper.push_back(u);
	}

	//because listOfUsers.push_back() gives error in rfor, we use helperVector
	listOfUsers = listOfUsersHelper;
}

//��������� �� ����� �������� �� ���
//��������� �� ���������� �� ������ ����� ������� ��������

void ListOfUsers::loadPlaylistByName(std::string user)
{
	std::string name;
	std::cin.ignore();
	std::getline(std::cin, name);

	for (User u : listOfUsers)
	{
		if (u.getUsername() == user)
		{
			u.showSongsByPlaylist(name);
		}
	}
}

void ListOfUsers::returnInformationAboutTheVotes(std::map<std::string, std::vector<std::string>>& m)
{
	f_inout.open("votes.txt");

	std::string line;
	std::string song;
	std::vector<std::string> arrOfUsers;
	int index = 0;

	while (std::getline(f_inout, line))
	{
		if (index == 0)
		{
			song = line;
		}

		index++;

		if (index > 1 && line != "" && line != "_____")
		{
			arrOfUsers.push_back(line);
		}

		if (line.find("_____") != std::string::npos)
		{
			m.insert({ song, arrOfUsers });

			arrOfUsers.clear();
			index = 0;
		}
	}

	f_inout.close();
}

//�������� �� ������� �� ���������� �����
//������ ������� �� ����� �� �������� ���� ������ �������� �� ������ ���������� �� �����������. 
//�� ������ �� ����������� �� ���������� �� ������� ������ �� ���� ��� �� ������ �����.

bool ListOfUsers::haveUserRated(std::string user, std::string song, std::map<std::string, std::vector<std::string>> m)
{
	for (const auto& element : m)
	{
		if (element.first == song)
		{
			for (const auto& u : element.second)
			{
				if (u == user)
				{
					return true;
				}
			}
		}
	}

	return false;
}

void ListOfUsers::saveVotes(std::map<std::string, std::vector<std::string>> m)
{
	f_inout.open("votes.txt");

	for (const auto& element : m)
	{
		f_inout << element.first;
		f_inout << "\n" << "\n";
		for (const auto& arr : element.second)
		{
			f_inout << arr << "\n";
		}
		f_inout << "_____\n";
	}

	f_inout.close();
}

void ListOfUsers::setRating(std::string user)
{
	returnSongsToCollection();
	std::string n;
	float r;
	std::cout << "Please type the name of the song you want to rate.\n";
	std::cin.ignore();
	std::getline(std::cin, n);

	std::map<std::string, std::vector<std::string>> m;
	returnInformationAboutTheVotes(m);

	std::set<Song> modifiedSongs;
	int numberOfVotes = 0;

	for (User u : listOfUsers)
	{
		if (u.getUsername() == user)
		{
			for (Song s : listOfSongs)
			{
				if (!doesSongExist(n))
				{
					std::cout << "Sorry, but there isn't a song with this name." << std::endl;
					return;
				}
				if (s.getName() == n && haveUserRated(u.getUsername(), s.getName(), m) == true)
				{
					std::cout << "Sorry, but you can rate a song only once." << std::endl; 
					return;
				}
				else if (s.getName() == n)
				{
					for (const auto& element : m)
					{
						if (element.first == n)
						{
							for (const auto& user : element.second)
							{
								numberOfVotes++;
							}
						}
					}

					std::cout << "Please type the rating you give to this song.\n";
					std::cin >> r;

					float average = (s.getRating() + r) / (numberOfVotes + 1);
					s.setRating(s.getRating() + r);

					m[s.getName()].push_back(user);
				}

				modifiedSongs.insert(s);
			}
		}
		saveVotes(m); 
	}

	listOfSongs = modifiedSongs;
	saveSong(listOfSongs);
}

std::ostream& operator << (std::ostream& output, const ListOfUsers& list)
{
	for (User user : list.listOfUsers)
	{
		output << user << "\n___\r\n";
	}

    return output;
}
