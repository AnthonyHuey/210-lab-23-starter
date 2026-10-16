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

bool again = 1; // is this for the main menu function?

int main() 
{
    srand(time(0));

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

    Goat test = {names[rand()%SZ_NAMES], rand()%MAX_AGE, colors[rand()%SZ_COLORS]};
    list<Goat> mylist;
    mylist.push_back(test);
    for (Goat g : mylist)
    {
        cout << g.get_age() << " " << g.get_color() << " " << g.get_name();
    }

    list<int> numbers = {5,2,3,1,4};
    for (int nm : numbers)
        cout << nm << " ";
    

    int choice;
    choice = main_menu();

    cout << "\nUSER CHOICE: " << choice;


    return 0;
}

int main_menu() // nvm about putting it in the header, saw the function up top.
{               // feel like it would be way easier to just loop this function -
    int choice; // - rather then it just return the user choice, oh well.
    again = 1;
    while (again != 0)
    {
        cout << "\t*** GOAT MANAGER 3001 ***";
        cout << "\n[1] Add a goat \n[2] Delete a goat";
        cout << "\n[3] List goats \n[4] Quit \nChoice --> ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1: again = 0; break;
        case 2: again = 0; break;
        case 3: again = 0; break; 
        case 4: again = 0; break;
        default: cout << "Invalid\n"; 
        }
    }
    return choice;
}
/*
int select_goat(list<Goat> trip) // display the goats, then ask which one.
{
    int choice;
    for ( auto it = trip.begin(); it != trip.end(); it++)
    {   
        int i = 1;
        cout << "[" << i << "]" << *it ; // something else here. 
        i++;
    }
}

void delete_goat(list<Goat> &trip)
{

}

void add_goat(list<Goat> &trip, string [], string [])
{

}

void display_trip(list<Goat> trip)
{

}
*/
