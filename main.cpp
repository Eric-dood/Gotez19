//COMSC-210 | Lab 23 | Eric-Giulio Hedes
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

int main() {
    srand(time(0));
    bool again;

    //Create a list of Goats
    list<Goat> goatList;

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

    //Set up a GM3K1 engine
    int choice = 0;
    while (true)
    {
        choice = main_menu();
        switch (choice)
        {
            case 1:
                add_goat(goatList, names, colors);
                break;
            case 2:
                //delete_goat(goatList);
                break;
            case 3:
                //display_trip(goatList);
                break;
            case 4:
                cout << "Quitting... Thanks for trying!" << endl;
                break;
        }
        if (choice == 4) break;
    }
}

int main_menu()
{
    int temp;
    cout << "*** GOAT MANAGER 3001 ***" << endl; //Print title
    //Print the list of functions
    cout << "[1] Add a goat" << endl << "[2] Delete a goat" << endl << "[3] List goats" << endl << "[4] Quit" << endl;
    while (true)
    {
        cout << "Choice --> ";
        cin >> temp;
        cin.ignore(1000, 10);
        if (temp >= 1 && temp <= 4) break;
        else cout << "ERROR: Please enter between 1 and 4." << endl;
    }
    return temp;
}

void add_goat(list<Goat> &trip, string name[], string col[])
{

}