#include "Website.h"
#include <Windows.h>

void Website::PuchGame() {
	Game newgame;
	game.push_back(newgame);
	system("cls");
	cout << "Game added successfully" << endl << endl;
}

void Website::DeleteGame() {


void Website::ShowGame() {
	try {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (game.size() == 0)
			throw exception("Game list on the website is empty");

		for (int i = 0; i < game.size(); ++i) {
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
			cout << i + 1 << " game:" << endl;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			game[i].ShowGame();
			cout << endl << endl;
		}
	}
	catch (exception & ex) {
		cout << ex.what() << endl;
	}
}

void Website::EditGame() {
	try {
		system("cls");
		if (game.size() == 0)
			throw exception("Game list on the website is empty");

		ShowGame();
		int number;

		while (true) {
			cout << endl << "Enter number game: ";
			cin >> number;
			if (cin.fail() || number < 1 || number > game.size()) {
				cout << "The number of game is incorrect! Please re-enter!" << endl;
				number = 0;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else
				break;
		}

		game[number - 1].SetGame();

		system("cls");
		cout << "Data changed successfully" << endl << endl;
	}
	catch (exception & ex) {
		cout << ex.what() << endl << endl;
	}
}

void Website::WriteInFile() {
	try {
		ofstream fout("Website.txt", ios::out);

		if (!fout.is_open())
			throw exception("Error opening file Website.txt");

			fout << game.size() << endl;

			for (int i = 0; i < game.size(); ++i) {
				fout << game[i];
			}

			cout << "Writing to the file was successful" << endl << endl;
	}
	catch (exception & ex) {
		cout << ex.what() << endl << endl;
	}
}

void Website::ReadFile() {
	try {
		ifstream fin("Website.txt", ios::in);
		Game empty_object("", "", 0, Platform::PC, "", "", 0);

		if (!fin.is_open())
			throw exception("Error opening file Website.txt");

			int size;
			game.clear();
			fin >> size;

			for (int i = 0; i < size; ++i) {
				fin >> empty_object;
				game.push_back(empty_object);
			}

			cout << "Reading from the file was successful" << endl << endl;
	}
	catch (exception & ex) {
		cout << ex.what() << endl << endl;
	}
}

Game Website::Handle(Game request) {
	for (int i = 0; i < game.size(); ++i) {
		if (game[i] == request) {
			cout << "The game was found on the website on the " << i + 1 << " place" << endl;
			return request;
		}
	}

	return AbstractHandler::Handle(request);
}