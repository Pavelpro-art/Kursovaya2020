#include "Functions.h"
#include <Windows.h>

void SubMenu(AbstractHandler* ptr, string name){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    int button;
    bool flag = true;
    int button1;
    bool flag1 = true;
    int button2;
    bool flag2 = true;
   

    while (flag) {
        system("cls");
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 3));

        cout << name << endl << endl;
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        cout << "1) Add game" << endl;
        cout << "2) Delete game" << endl;
        cout << "3) Show games" << endl;
        cout << "4) Edit game" << endl;
        cout << "5) Write to file" << endl;
        cout << "6) Reading from a file" << endl;
        cout << "0) Exit to main menu" << endl;
        cout << endl << "Your choice: ";
        cin >> button;

        if (cin.fail()) {
            button = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (button) {
        case 1: system("cls"); ptr->PuchGame(); system("pause"); break;
        case 2: system("cls"); ptr->DeleteGame(); system("pause"); break;
        case 3: system("cls"); ptr->ShowGame(); system("pause");  break;
        case 4: system("cls"); ptr->EditGame(); system("pause"); break;
        case 5: 
            flag1 = true;
            while (flag1) {
                system("cls");
                cout << "Are you sure you want to write data to a file?" << endl;
                cout << "1) Yes" << endl;
                cout << "2) No" << endl;
                cout << endl << "Your choice: ";
                cin >> button1;
                system("cls");
                if (cin.fail()) {
                    button1 = 0;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                switch (button1) {
                case 1:
                    ptr->WriteInFile();
                    flag1 = false;
                    break;
                case 2:
                    cout << "File write canceled" << endl << endl;
                    flag1 = false;
                    break;

                default:cout << "Invalid input!" << endl << endl; system("pause");
                }
            } 
            system("pause"); 
            break;
        case 6: 
            system("cls"); 
            flag2 = true;
            while (flag2) {
                system("cls");
                cout << "Are you sure you want to read the data from the file? " << endl;
                cout << "1) Yes" << endl;
                cout << "2) No" << endl;
                cout << endl << "Your choice: ";
                cin >> button2;
                system("cls");
                if (cin.fail()) {
                    button2 = 0;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                switch (button2) {
                case 1:
                    ptr->ReadFile();
                    flag2 = false;
                    break;

                case 2:
                    cout << "Reading from file canceled" << endl << endl;
                    flag2 = false;
                    break;

                default:cout << "Invalid input!" << endl << endl; system("pause");
                }
            }
            system("pause"); 
            break;
        case 0: flag = false; break;
        default: cout << "Invalid input!" << endl << endl; system("pause");
        }
    }
}

void GameSearch(AbstractHandler* ptr){
    system("cls");
    Game empty_object("", "", 0, Platform::PC, "", "", 0);
    
    string name;
    string genre;
    Platform platform;
    int year;

    system("cls");
    cout << "Enter the name of the game: ";
    cin >> name;

    cout << "Enter game genre: ";
    cin >> genre;

    while (true) {
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

    Game ser(name, genre, year, platform);

    Game res = ptr->Handle(ser);
    if (res == empty_object)
        cout << "Game not found" << endl << endl;

    system("pause");
}

