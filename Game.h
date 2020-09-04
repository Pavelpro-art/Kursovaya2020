#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

enum class Platform {PC, Xbox, PS};

class Game {
	string name;		// �������� ����
	string genre;		// ����
	int year;			// ��� �������
	Platform platform;	// ���������
	string sys_req;		// ��������� ����������
	string developer;	// �����������
	int count;			// ����������

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