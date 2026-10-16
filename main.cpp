// Anthony Huey - 10/16/2026 - COMSC 210 - Lab 23: Goat Manager 3001
// Fork the given repository, then follow the 4 tasks, 
// im not writitng them here, they're on the assignment look there.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() 
{
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // building the main menu here to test but ill move it to the header later.
    
    int choice;
    while (choice != 4)
    {
        cout << "\t*** GOAT MANAGER 3001 ***";
        cout << "\n[1] Add a goat \n[2] Delete a goat";
        cout << "\n[3] List goats \n[4] Quit \nChoice --> ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            
        case 2:

        case 3:

        case 4:

        default:
            cout << "Invalid\n";
        }
    }

    return 0;
}

