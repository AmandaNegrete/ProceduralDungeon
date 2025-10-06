#include "dungeon.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string answer = "yes";

    while (answer == "yes") {
        // create dungeon
        //random values i found online
        Dungeon d(50, 40, 12, 5, 10);
        d.generateDungeon();
        d.printDungeon();

        //
        cout << "\nPlay again? (yes or no): ";
        cin >> answer;

        if (answer != "yes") {
            cout << "Gbyeee!\n";
        }
    }

    return 0;
}
