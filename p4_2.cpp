/*
==================================================================================== 
    PROGRAM: Manager Management System
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON: April 13, 2025

    FEATURES:
    - Demonstrates the use of multiple inheritance in C++.
    - Allows adding and displaying Manager records.
    - Uses a linked list structure to maintain Manager records.
    - Displays manager details (Name, Age, ID, Department) in a formatted table.
==================================================================================== 
*/

#include <iostream>
#include <iomanip>
using namespace std;



class Person
{
protected:
    string Name; // Name of the person
    int Age; // Age of the person

public:
    // Constructor to initialize name and age
    Person(string PersonName, int PersonAge)
    {
        Name = PersonName;
        Age = PersonAge;
    }
};



class Employee
{
protected:
    int Id; // Employee ID

public:
    // Constructor to initialize employee ID
    Employee(int EmployeeId)
    {
        Id = EmployeeId;
    }
};



class Manager : public Person, public Employee
{
protected:
    string Department; // Department the manager is assigned to

public:
    Manager *NextManager; // Pointer to next manager in the list
    // Constructor to initialize manager details
    Manager(string PersonName, int PersonAge, int EmployeeId, string ManagerDepartment) : Person(PersonName, PersonAge), Employee(EmployeeId)
    {
        Department = ManagerDepartment;
        NextManager = NULL;
    }

    // Function to display manager details
    void Display()
    {
        cout << left << setw(20) << Name
             << setw(15) << Age
             << setw(15) << Id
             << setw(15) << Department
             << endl;
    }
};



int main()
{
    Manager *FirstManager = NULL; // Pointer to the first manager in the list
    Manager *CurrentManager, *LastManager;
    int Choice, Age, Id;
    string Name, Department;

Menu: // Main menu label
    // Display options to the user
    cout << endl
         << "Press" << endl
         << "1. Add Manager" << endl
         << "2. Display Manager" << endl
         << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> Choice;

    switch (Choice)
    {
    case 0: // Exit
        cout << "VEDANT BHATT || 24CE013 " << endl;
        goto Exit;

    case 1: // Add new manager
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter age: ";
        cin >> Age;
        cout << "Enter Id: ";
        cin >> Id;

        cout << "Enter Department: ";
        cin >> Department;

        // Check if this is the first manager to be added
        if (FirstManager == NULL)
        {
            // Create the first manager
            FirstManager = new Manager(Name, Age, Id, Department);
        }
        else
        {
            // Add new manager to the end of the list
            CurrentManager = FirstManager;
            while (CurrentManager->NextManager != NULL)
            {
                CurrentManager = CurrentManager->NextManager;
            }

            // Create the new manager and add it to the list
            LastManager = new Manager(Name, Age, Id, Department);
            CurrentManager->NextManager = LastManager;
        }
        goto Menu;

    case 2: // Display all managers
        if (FirstManager == NULL)
        {
            cout << "No Manager records to display.\n";
        }
        else
        {
            CurrentManager = FirstManager;

            // Display manager details in tabular format
            cout << endl
                 << left
                 << setw(20) << "Name"
                 << setw(15) << "Age"
                 << setw(15) << "ID"
                 << setw(15) << "Department" << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            while (CurrentManager != NULL)
            {
                CurrentManager->Display(); // Display each manager's details
                CurrentManager = CurrentManager->NextManager;
            }
        }
        goto Menu;

    default:
        cout << "Enter a valid choice (0, 1, or 2)." << endl;
        goto Menu;
    }

Exit: // Exit label
    return 0;
}
