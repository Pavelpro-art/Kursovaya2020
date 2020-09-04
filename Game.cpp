#include "Game.h"
#include <Windows.h>

Game::Game(){
	SetGame();
}

Game::Game(string name, string genre, int year, Platform platform, string sys_req, string developer, int count) {
	this->name = name;
	this->genre = genre;
	this->year = year;
	this->platform = platform;
	this->sys_req = sys_req;
	this->developer = developer;
	this->count = count;
}

Game::Game(string name, string genre, int year, Platform platform){
	this->name = name;
	this->genre = genre;
	this->year = year;
	this->platform = platform;

	this->sys_req = "";
	this->developer = "";
	this->count = 0;
}

void Game::SetGame(){
	system("cls");
	cout << "Enter the name of the game: ";
	cin >> name;

	system("cls");
	cout << "Enter game genre: ";
	cin >> genre;

	while (true) {
		system("cls");
		cout << "Enter the year the game was released: ";
		cin >> year;

		if (cin.fail() || year < 1950 || year > 2020) {
			cout << "Wrong year! Please re-enter!" << endl;
			year = 0;
			cin.clear();
			cin.ignore(10000, '\n');
			system("pause");
		}
		else
			break;
	}

	bool flag = true;
	while (flag) {
		system("cls");
		int button;
		cout << "Select platform: " << endl;
		cout << "1) PC " << endl;
		cout << "2) Xbox " << endl;
		cout << "3) PS " << endl;
		cout << endl << "Your choice: ";
		cin >> button;

		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (button) {
			case 1: platform = Platform::PC; flag = false; break;
			case 2: platform = Platform::Xbox; flag = false; break;
			case 3: platform = Platform::PS; flag = false; break;
			default: cout << "Incorrect choice! Please re-enter!" << endl; system("pause");
		}
	}

	system("cls");
	cout << "Enter the system requirements of the game : ";
	cin >> sys_req;

	system("cls");
	cout << "Enter game developer: ";
	cin >> developer;

	while (true) {
		system("cls");
		cout << "Enter the number of games: ";
		cin >> count;

		if (cin.fail() || count <= 0) {
			cout << "The number of games is incorrect! Please re-enter!" << endl;
			count = 0;
			cin.clear();
			cin.ignore(10000, '\n');
			system("pause");
		}
		else
			break;
	}
}

void Game::ShowGame(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
	cout << "Name: ";
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	cout << name << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
	cout << "Genre: ";
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	cout << genre << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
	cout << "Release year: ";
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	cout << year << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
	cout << "Platform: ";
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	switch (platform){
		case Platform::PC: cout << "PC" << endl; break;
		case Platform::Xbox: cout << "Xbox" << endl; break;
		case Platform::PS: cout << "PS" << endl; break;
	}
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
	cout << "System requirements: ";
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	cout << sys_req << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
	cout << "Developer: ";
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	cout << developer << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
	cout << "Number of games: ";
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	cout<< count << endl;
}

bool Game::operator==(Game& other){
	if (this->name != other.name) return false;
	if (this->genre != other.genre) return false;
	if (this->year != other.year) return false;
	if (this->platform != other.platform) return false;

	return true;
}

ofstream& operator<<(ofstream& fout, Game& obj){
	fout << obj.name << " " << obj.genre << " " << obj.year << " ";
	switch (obj.platform) {
	case Platform::PC: fout << "PC "; break;
	case Platform::Xbox: fout << "Xbox "; break;
	case Platform::PS: fout << "PS "; break;
	}
	fout << obj.sys_req << " " << obj.developer << " " << obj.count << endl;

	return fout;
}

ifstream& operator>>(ifstream& fin, Game& obj){
	string tmp;
	
	fin >> obj.name >> obj.genre >> obj.year >> tmp >> obj.sys_req >> obj.developer >> obj.count;
	if (tmp == "PC")
		obj.platform = Platform::PC;
	else if (tmp == "Xbox")
		obj.platform = Platform::Xbox;
	else
		obj.platform = Platform::PS;

	return fin;
}
