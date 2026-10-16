// Anthony Huey - 10/16/2026 - COMSC 210 - Lab 23: Goat Manager 3001
// Fork the given repository, then follow the 4 tasks, 
// im not writitng them here, they're on the assignment look there.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20, MIN = 0;

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

    list<Goat> mylist;
    int choice;

    while (choice != 4)
    {
        choice = main_menu();
        switch (choice)
        {
        case 1: add_goat(mylist, names, colors); break;
        case 2: delete_goat(mylist); break;
        case 3: display_trip(mylist); break;
        case 4: cout << "Goodbye."; break;
        }
    }
  
    return 0;
}

int main_menu() // nvm about putting it in the header, saw the function up top.
{               // feel like it would be way easier to just loop this function -
    int choice; // - rather then it just return the user choice, oh well.
    again = 1;
    while (again != 0)
    {
        cout << "\n\t*** GOAT MANAGER 3001 ***";
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

int select_goat(list<Goat> trip) // display the goats, then ask which one.
{
    display_trip(trip);
    
    int choice;
    cout << "\nWhich goat: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

void delete_goat(list<Goat> &trip) // find goat, delete it
{
    again = 1;
    int choice;
    while (again != 0) // validate if choice is < 0 or > size.
    {
        choice = select_goat(trip);
        if (choice < 1 || choice > trip.size())
            cout <<"\nInvalid";
        else
            again = 0;
    }
    auto it = trip.begin();
    advance(it, choice - 1); 
    trip.erase(it);
    cout << endl;
    display_trip(trip);
}

void add_goat(list<Goat> &trip, string n[], string c[]) // add goat
{
    Goat goat = {n[rand()%SZ_NAMES], rand()%MAX_AGE, c[rand()%SZ_COLORS]};
    trip.push_back(goat); // i'll fix the ranges later. i know age is 0-19
}

void display_trip(list<Goat> trip) // display goats
{
    int i = 0;
    for (Goat g : trip)
    {   
        i++;
        cout << "\n[" << i << "] " << g.get_name() << "(" << g.get_age()
             << " " << g.get_color() << ")";  
    }
}

