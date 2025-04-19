/*
==================================================================================== 
    PROGRAM: Car Fuel Management System
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON: April 14, 2025

    FEATURES:
    - Allows adding and displaying cars with fuel type and brand name.
    - Uses linked list to manage car records.
    - Displays car details (Fuel Type, Brand Name) in a formatted table.
==================================================================================== 
*/

#include<iostream>
#include<iomanip>
using namespace std;



class Fuel
{
    protected:
    string TypeOfFuel; 

    public:
    // Constructor to initialize fuel type
    Fuel(string Type)
    {
        TypeOfFuel = Type;
    }
};



class BrandName
{
    protected:
    string brandName; 

    public:
    // Constructor to initialize brand name
    BrandName(string BName)
    {
        brandName = BName;
    }
};


class Car : public Fuel, public BrandName
{
    public:
    Car *NextCar; // Pointer to next car in the list

    // Constructor to initialize car details
    Car(string Type, string BName) : Fuel(Type), BrandName(BName)
    {
        NextCar = NULL;
    }

    // Function to display car details
    void Display()
    {
        cout << endl
             << left
             << setw(20) << TypeOfFuel
             << setw(15) << brandName
             << endl;
    }
};



int main()
{
    Car *FirstCar = NULL; // Pointer to the first car in the list
    Car *CurrentCar, *LastCar;
    int Choice;
    string Type, Brand;

Menu: // Main menu label
    // Display options to the user
    cout << endl
         << "Press" << endl
         << "1. Add Car" << endl
         << "2. Display Car" << endl
         << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> Choice;

    switch (Choice)
    {
    case 0: // Exit
        cout << "VEDANT BHATT || 24CE013 " << endl;
        goto Exit;

    case 1: // Add new car
        cout << "Enter type of fuel: ";
        cin >> Type;
        cout << "Enter brand name: ";
        cin >> Brand;

        // Check if this is the first car to be added
        if (FirstCar == NULL)
        {
            // Create the first car
            FirstCar = new Car(Type, Brand);
        }
        else
        {
            // Add new car to the end of the list
            CurrentCar = FirstCar;
            while (CurrentCar->NextCar != NULL)
            {
                CurrentCar = CurrentCar->NextCar;
            }

            // Create the new car and add it to the list
            LastCar = new Car(Type, Brand);
            CurrentCar->NextCar = LastCar;
        }
        goto Menu;

    case 2: // Display all cars
        if (FirstCar == NULL)
        {
            cout << "No Car records to display.\n";
        }
        else
        {
            CurrentCar = FirstCar;

            // Display car details in tabular format
            cout << endl
                 << left
                 << setw(20) << "Type Of Fuel"
                 << setw(15) << "Brand Name"
                 << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            while (CurrentCar != NULL)
            {
                CurrentCar->Display(); // Display each car's details
                CurrentCar = CurrentCar->NextCar;
            }
        }
        goto Menu;

    default:
        cout << "Enter a valid choice (0, 1, or 2)." << endl;
        goto Menu;
    }

Exit: // Exit label
cout<<"Vedant Bhatt || 24CE013";
    return 0;
}
