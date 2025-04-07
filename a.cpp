#include <iostream>
using namespace std;

class Employee
{
    string name;
    int basicSalary;
    int bonusAmount;

public:
    Employee *nextEmployee;

    Employee(string name, int basicSalary, int bonusAmount = 0)
    {
        this->name = name;
        this->basicSalary = basicSalary;
        this->bonusAmount = bonusAmount;
        nextEmployee = NULL;
    }

    int totalSalary(int basicSalary, int bonusAmount)
    {
        int totalSalary = basicSalary + bonusAmount;
        return totalSalary;
    }

    void display()
    {
        cout << "Employee Name:" << name << "Employee Basic Salary:" << basicSalary << "Employee Bouns" << bonusAmount
             << "Total Salary is:" << totalSalary(basicSalary, bonusAmount) << endl;
    }
};

int main()
{
    Employee *firstEmployee = NULL;
    Employee *currentEmployee, *lastEmployee;
    int choice, basicSalary, bonusAmount;
    string name;

    
    n:    cout << "Press" << endl
             << "1.Add Employee" << endl
             << "2.Display Employee" << endl
             << "0.exit" << endl;
        cout << "Enter your Choice here:";
        cin >> choice;

        switch (choice)
        {
        case 0:
            goto e;
        case 1:
            if (firstEmployee == NULL)
            {
                cout << "Enter name,basic salary,bonus:";
                cin >> name >> basicSalary >> bonusAmount;
                firstEmployee = new Employee(name, basicSalary, bonusAmount);
            }
            else
            {
                currentEmployee = firstEmployee;

                while (currentEmployee->nextEmployee != NULL)
                {
                    currentEmployee = currentEmployee->nextEmployee;
                }
                cout << "Enter name,basic salary,bonus:";
                cin >> name >> basicSalary >> bonusAmount;
                lastEmployee = new Employee(name, basicSalary, bonusAmount);
                currentEmployee->nextEmployee = lastEmployee;
            }
            goto n;
        case 2:
            currentEmployee = firstEmployee;
            while (currentEmployee->nextEmployee != NULL)
            {
                currentEmployee->display();
                currentEmployee=currentEmployee->nextEmployee;
            }
            currentEmployee->display();
            goto n;

        default:
            cout << "Enter valid choice:(1 or 2 or 0)" << endl;
            goto n;
        }
        
    e: return 0;
}