//COMSC-210 | Lab 23 | Eric-Giulio Hedes
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

//Define the global constants
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

//Prototype functions
int select_goat(list<Goat> trip, bool);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

//Start of main()
int main() {
    //Use a random seed generator
    srand(time(0));

    //Create a list of Goats
    list<Goat> goatList;

    //Read & populate arrays for names and colors
    //Define fin & read the names file
    ifstream fin("names.txt");
    //Make an array of names
    string names[SZ_NAMES];
    //Loop until the maximum name size to store all the names from the textfile
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    //Define fin1 & read the colors file
    ifstream fin1("colors.txt");
    //Make an array of colors
    string colors[SZ_COLORS];
    //Loop until the maximum color size to store all the color from the textfile
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    //Set up a GM3K1 engine
    int choice = 0; //This'll be used for the choicer
    //Use a while() loop to do a proper validation input
    while (true)
    {
        //Output the main menu
        choice = main_menu();
        //Do a different function depending on the value of the choice
        switch (choice)
        {
            case 1: //Adds a goat
                add_goat(goatList, names, colors);
                break;
            case 2: //Removed a goat
                delete_goat(goatList);
                break;
            case 3: //Displays the goat list
                display_trip(goatList);
                break;
            case 4: //Quits the application
                cout << "Quitting... Thanks for trying!" << endl;
                break;
        }
        //Do another break for number 4 so that it quits the loop properly
        if (choice == 4) break;
    }

    return 0;
}

//Define main_menu()
int main_menu()
{
    //Add a temporary variable for returning
    int temp;
    cout << "*** GOAT MANAGER 3001 ***" << endl; //Print title
    //Print the list of functions
    cout << "[1] Add a goat" << endl << "[2] Delete a goat" << endl << "[3] List goats" << endl << "[4] Quit" << endl;
    //Do a validaiton loop
    while (true)
    {
        cout << "Choice --> ";
        cin >> temp;
        cin.ignore(1000, 10);
        //If the value is between 1 and 4, exit the loop safely
        if (temp >= 1 && temp <= 4) break;
        //Otherwise print an error message
        else cout << "ERROR: Please enter between 1 and 4." << endl;
    }
    //Return the temp variable
    return temp;
}

//Define select_goat()
int select_goat(list<Goat> trip, bool big = false)
{
    //Temporary variable
    int temp;
    //Define min & max values
    int minimum = 1 - (int)big;
    int maximum = trip.size();
    //Check if the list is empty; if it's empty, display a message
    if (trip.empty())
        cout << "List is empty." << endl;
    else //Otherwise perform as usual
    {
        //Do a validation loop
        cout << " (between head [" << minimum << "] and tail [" << maximum << "]): ";
        while (true)
        {
            cin >> temp;
            cin.ignore(1000, 10);
            //If the temp value is between the min and max values, get out of the loop
            if (temp >= minimum && temp <= maximum) break;
            //Otherwise display an error message
            else cout << "ERROR: Enter a number between 1 and " << maximum << ": ";
        }
        //Return the value
        return temp - 1;
    }
    //If nothing works, just return 0
    return 0;
}

//Define add_goat()
void add_goat(list<Goat> &trip, string name[], string col[])
{
    int goatAge = rand() % MAX_AGE + 1;
    Goat temp = Goat(name[rand() % SZ_NAMES], goatAge, col[rand() % SZ_COLORS]);
    if (trip.size() < 1)
        trip.push_back(temp);
    else
    {
        cout << "Select a number to insert the goat before a certain element";
        int sel = select_goat(trip, true) + 1;
        auto it = trip.begin();
        advance(it, sel);
        trip.insert(it, temp);
    }
}

void delete_goat(list<Goat> &trip)
{
    if (!trip.empty())
    {
        if (trip.size() <= 1)
            trip.pop_back();
        else
        {
            cout << "Select a goat by number to delete";
            int sel = select_goat(trip);
            auto it = trip.begin();
            advance(it, sel);
            trip.erase(it);
        }
    }
    else
        cout << "List is already empty." << endl;
}

void display_trip(list<Goat> trip)
{
    int count = 1;
    if (trip.empty())
        cout << "List is empty." << endl;
    else
    {
        for (Goat value : trip)
            cout << "[" << count++ << "] " << value.get_name() << " (" << value.get_age() << ", " << value.get_color() << ")" << endl;
    }
}