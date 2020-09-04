#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

enum class Platform {PC, Xbox, PS};

class Game {
	string name;		// Название игры
	string genre;		// Жанр
	int year;			// Год выпуска
	Platform platform;	// Платформа
	string sys_req;		// Системные требования
	string developer;	// Разработчик
	int count;			// Количество

public:
	Game();
	Game(string name, string genre, int year, Platform platform, string sys_req, string developer, int count);
	Game(string name, string genre, int year, Platform platform);

	void SetGame();
	void ShowGame();

	friend ofstream& operator<<(ofstream& fout, Game& obj);
	friend ifstream& operator>>(ifstream& fin, Game& obj);

	bool operator==(Game& other);
};