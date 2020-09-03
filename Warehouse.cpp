#include "Warehouse.h"
#include <Windows.h>

void Warehouse::PuchGame() {
	Game newgame;
	game.push_back(newgame);
	system("cls");
	cout << "Game added successfully" << endl << endl;
}

void Warehouse::DeleteGame(){
	try {
		system("cls");
		if(game.size() == 0)
			throw exception("The list of games in warehouse is empty");

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

		game.erase(game.begin() + number - 1);

		cout << "Game successfully deleted" << endl << endl;
	}
	catch (exception & ex) {
		cout << ex.what() << endl << endl;
	}
}

void Warehouse::ShowGame() {
	try {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (game.size() == 0)
			throw exception("The list of games in warehouse is empty");

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

void Warehouse::EditGame(){
	try {
		system("cls");
		if (game.size() == 0)
			throw exception("The list of games in warehouse is empty");

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

void Warehouse::WriteInFile() {
	try {
		ofstream fout("Warehouse.txt", ios::out);

		if (!fout.is_open())
			throw exception("Error opening file Warehouse.txt");

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

void Warehouse::ReadFile() {
	try {
		ifstream fin("Warehouse.txt", ios::in);
		Game empty_object("", "", 0, Platform::PC, "", "", 0);

		if (!fin.is_open())
			throw exception("Error opening file Warehouse.txt");

		game.clear();
		int size;

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

Game Warehouse::Handle(Game request) {
	for (int i = 0; i < game.size(); ++i) {
		if (game[i] == request) {
			cout << "The game was found in warehouse at " << i + 1 << " place" << endl;
			return request;
		}
	}

	return AbstractHandler::Handle(request);
}