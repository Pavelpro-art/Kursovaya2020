#include "Game.h"
#include "Website.h"
#include "Shop.h"
#include "Warehouse.h"
#include "Functions.h"
#include <Windows.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

    Game empty_object("", "", 0, Platform::PC, "", "", 0);
    Game res("", "", 0, Platform::PC, "", "", 0);
    AbstractHandler* website = new Website;
    AbstractHandler* shop = new Shop;
    AbstractHandler* warehouse = new Warehouse;
    website->SetNext(shop)->SetNext(warehouse);


    bool flag = true;
    int button = 0;

    while (flag) {
        system("cls");
        cout << "1) Website games" << endl;
        cout << "2) Shop games" << endl;
        cout << "3) Warehouse games" << endl;
        cout << "4) Game search" << endl;
        cout << "0) Exit" << endl;
        cout << endl << "Your choice: ";
        cin >> button;

        if (cin.fail()) {
            button = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (button) {
            case 1: SubMenu(website, "Website"); break;
            case 2: SubMenu(shop, "Shop"); break;
            case 3: SubMenu(warehouse, "Warehouse"); break;
            case 4: GameSearch(website); break;
            case 0: flag = false; break;
            default: cout << "Invalid input!" << endl << endl; system("pause");
        }
    }

    delete website;
    delete shop;
    delete warehouse;
    return 0;
}