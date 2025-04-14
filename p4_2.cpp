/*
==============================================================================
    PROGRAM: Organization Hierarchy Management System
    DEVELOPER: VEDANT BHATT
    ID No: 24CE013
    CREATED ON: April 13, 2025
==============================================================================
*/

#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    // Constructor to initialize name and age
    Person(string n = "unknown", int a = 0)
    {
        name = n;
        age = a;
    }

    // Function to display person details
    void displayPerson() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person
{
protected:
    int employeeID;

public:
    // Constructor to initialize name, age, and employeeID
    Employee(string n = "unknown", int a = 0, int id = 0) : Person(n, a)
    {
        employeeID = id;
    }

    // Function to display employee details
    void displayEmployee() const
    {
        displayPerson();
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Manager : public Employee
{
private:
    string department;

public:
    // Constructor to initialize all attributes
    Manager(string n = "uknown", int a = 0, int id = 0, string dept = "") : Employee(n, a, id)
    {
        department = dept;
    }

    // Function to display manager details
    void displayManager() const
    {
        displayEmployee();
        cout << "Department: " << department << endl;
    }

    // Getter for employee ID (for future sorting/search logic)
    int getEmployeeID() const
    {
        return employeeID;
    }
};

int main()
{
    const int MAX_MANAGERS = 100;
    Manager managers[MAX_MANAGERS];
    int n;

    cout << "Enter number of managers (max:100):";
    cin >> n;

    // Input validation
    if (n > MAX_MANAGERS || n <= 0)
    {
        cout << "Invalid number of managers!" << endl;
        return 1;
    }

    // Input manager details
    for (int i = 0; i < n; ++i)
    {
        string name, dept;
        int age, id;

        cout << endl
             << "Enter details for Manager " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore(); // for remove buffer
        getline(cin, name);

        cout << "Age: ";
        cin >> age;

        cout << "Employee ID: ";
        cin >> id;

        cin.ignore();
        cout << "Department: ";
        getline(cin, dept);

        managers[i] = Manager(name, age, id, dept);
    }

    // Display all managers
    cout << endl
         << "=== Organization Managers List ===" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << endl
             << "Manager " << i + 1 << ":" << endl;
        managers[i].displayManager();
    }

    cout << endl
         << "VEDANT BHATT || 24CE013" << endl;

    return 0;
}
