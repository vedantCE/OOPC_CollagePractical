/*
====================================================================================
    PROGRAM: Employee Salary Management System
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON: April 7, 2025
    LAST UPDATE: April 8, 2025

    Updates:
    - [08-04-2025] Added comments for clarity and understanding.
    - [08-04-2025] Improved output formatting with tabular display using <iomanip>.
=======================================================================================
*/

#include <iostream>
#include <iomanip> // for setw
using namespace std;

// Employee class to store employee details
class Employee
{
    string Name;
    int BasicSalary;
    int BonusAmount;

public:
    Employee *NextEmployee; // Pointer to next employee

    // Constructor to initialize employee details
    Employee(string Name, int BasicSalary, int BonusAmount = 0)
    {
        this->Name = Name;
        this->BasicSalary = BasicSalary;
        this->BonusAmount = BonusAmount;
        NextEmployee = NULL;
    }

    // Function to calculate total salary
    int TotalSalary(int BasicSalary, int BonusAmount)
    {
        return BasicSalary + BonusAmount;
    }

    // Function to display employee data in tabular format
    void Display()
    {
        cout << left << setw(20) << Name
             << setw(15) << BasicSalary
             << setw(15) << BonusAmount
             << setw(15) << TotalSalary(BasicSalary, BonusAmount)
             << endl;
    }
};

int main()
{
    Employee *FirstEmployee = NULL;
    Employee *CurrentEmployee, *LastEmployee;
    int Choice, BasicSalary, BonusAmount;
    string Name;
    char Choice2;

N: // Main menu label
    cout << endl
         << "Press" << endl
         << "1. Add Employee" << endl
         << "2. Display Employees" << endl
         << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> Choice;

    switch (Choice)
    {
    case 0: // Exit
        cout << "VEDANT BHATT || 24CE013 " << endl;
        goto E;

    case 1: // Add new employee
        cout << "Enter Name, Basic Salary: ";
        cin >> Name >> BasicSalary;

        if (FirstEmployee == NULL)
        {
            // First employee creation
            cout << "Is employee eligbile for bomus(y/n)?";
            cin >> Choice2;
            if (Choice2 == 'y')
            {
                cout << "Enter bonus amount:";
                cin >> BonusAmount;
                FirstEmployee = new Employee(Name, BasicSalary, BonusAmount);
            }
            else
            {
                FirstEmployee = new Employee(Name, BasicSalary);
            }
        }
        else
        {
            // Add new employee to the end of the list
            CurrentEmployee = FirstEmployee;
            while (CurrentEmployee->NextEmployee != NULL)
            {
                CurrentEmployee = CurrentEmployee->NextEmployee;
            }
            cout << "Is employee eligbile for bomus(y/n)?";
            cin >> Choice2;
            if (Choice2 == 'y')
            {
                cout << "Enter bonus amount:";
                cin >> BonusAmount;
                LastEmployee = new Employee(Name, BasicSalary, BonusAmount);
            }
            else
            {
                LastEmployee = new Employee(Name, BasicSalary);
            }
            CurrentEmployee->NextEmployee = LastEmployee;
        }
        goto N;

    case 2: // Display all employees
        if (FirstEmployee == NULL)
        {
            cout << "No employee records to display.\n";
        }
        else
        {
            CurrentEmployee = FirstEmployee;

            cout << endl
                 << left
                 << setw(20) << "Name"
                 << setw(15) << "Basic Salary"
                 << setw(15) << "Bonus"
                 << setw(15) << "Total Salary"
                 << endl;
            cout << string(65, '-') << endl;

            // Print employee data
            while (CurrentEmployee != NULL)
            {
                CurrentEmployee->Display();
                CurrentEmployee = CurrentEmployee->NextEmployee;
            }
        }
        goto N;

    default:
        cout << "Enter a valid choice (0, 1, or 2)." << endl;
        goto N;
    }

E: // Exit label
    return 0;
}
