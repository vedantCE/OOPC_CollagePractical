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
    string name;
    int basicSalary;
    int bonusAmount;

public:
    Employee *nextEmployee; // Pointer to next employee

    // Constructor to initialize employee details
    Employee(string name, int basicSalary, int bonusAmount = 0)
    {
        this->name = name;
        this->basicSalary = basicSalary;
        this->bonusAmount = bonusAmount;
        nextEmployee = NULL;
    }

    // Function to calculate total salary
    int totalSalary(int basicSalary, int bonusAmount)
    {
        return basicSalary + bonusAmount;
    }

    // Function to display employee data in tabular format
    void display()
    {
        cout << left << setw(20) << name
             << setw(15) << basicSalary
             << setw(15) << bonusAmount
             << setw(15) << totalSalary(basicSalary, bonusAmount)
             << endl;
    }
};

int main()
{
    Employee *firstEmployee = NULL;
    Employee *currentEmployee, *lastEmployee;
    int choice, basicSalary, bonusAmount;
    string name;
    char choice2;

n: // Main menu label
    cout << endl
         << "Press" << endl
         << "1. Add Employee" << endl
         << "2. Display Employees" << endl
         << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 0: // Exit
        cout << "VEDANT BHATT || 24CE013 " << endl;
        goto e;

    case 1: // Add new employee
        cout << "Enter Name, Basic Salary: ";
        cin >> name >> basicSalary;

        if (firstEmployee == NULL)
        {
            // First employee creation
            cout << "Is employee eligbile for bomus(y/n)?";
            cin >> choice2;
            if (choice2 == 'y')
            {
                cout << "Enter bonus amount:";
                cin >> bonusAmount;
                firstEmployee = new Employee(name, basicSalary, bonusAmount);
            }
            else
            {
                firstEmployee = new Employee(name, basicSalary);
            }
        }
        else
        {
            // Add new employee to the end of the list
            currentEmployee = firstEmployee;
            while (currentEmployee->nextEmployee != NULL)
            {
                currentEmployee = currentEmployee->nextEmployee;
            }
            cout << "Is employee eligbile for bomus(y/n)?";
            cin >> choice2;
            if (choice2 == 'y')
            {
                cout << "Enter bonus amount:";
                cin >> bonusAmount;
                lastEmployee = new Employee(name, basicSalary, bonusAmount);
            }
            else
            {
                lastEmployee = new Employee(name, basicSalary);
            }
            currentEmployee->nextEmployee = lastEmployee;
        }
        goto n;

    case 2: // Display all employees
        if (firstEmployee == NULL)
        {
            cout << "No employee records to display.\n";
        }
        else
        {
            currentEmployee = firstEmployee;

            // Print header
            cout << "\n"
                 << left
                 << setw(20) << "Name"
                 << setw(15) << "Basic Salary"
                 << setw(15) << "Bonus"
                 << setw(15) << "Total Salary"
                 << endl;
            cout << string(65, '-') << endl;

            // Print employee data
            while (currentEmployee != NULL)
            {
                currentEmployee->display();
                currentEmployee = currentEmployee->nextEmployee;
            }
        }
        goto n;

    default:
        cout << "Enter a valid choice (0, 1, or 2)." << endl;
        goto n;
    }

e: // Exit label
    return 0;
}
