/*
==============================================
    PROGRAM: Simple Bank Account Management System
    AIM: To perform basic banking operations like deposit, withdraw, and check balance.
    DEVELOPER: Vedant Bhatt
    LAST UPDATED: March 12, 2025
==============================================
*/

#include <iostream>
using namespace std;

// Declaring BankAccount class
class BankAccount
{
public:
    string holder_name;
    int account_number, balance;

    // Deposit money function
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    // Withdraw money function
    void withdraw(int amount)
    {
        if (amount > 0 && amount < balance)
        {
            balance -= amount;
        }
        else if (amount > balance)
        {
            cout << "Not enough balance!" << endl;
        }
    }

    // Display current bank balance
    void display_balance()
    {
        cout << "Current Balance: " << balance;
    }
};

// Main Function
int main()
{
    // Declaring first bank account
    BankAccount b1;
    b1.balance = 10000;
    int amount;
    int choice;

    // Taking bank account details
    cout << "Enter your name: ";
    cin >> b1.holder_name;
    cout << "Enter your account number: ";
    cin >> b1.account_number;

    cout << "Enter 1 For DEPOSIT" << endl
         << "Enter 2 For WITHDRAW" << endl
         << "Enter 3 For CHECKING CURRENT BALANCE" << endl
         << "Enter 4 For EXIT" << endl;

    do
    {
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount for Deposit: ";
            cin >> amount;
            b1.deposit(amount);
            break;
        case 2:
            cout << "Enter amount for Withdraw: ";
            cin >> amount;
            b1.withdraw(amount);
            break;
        case 3:
            b1.display_balance();
            break;
        case 4:
            cout << "\nThank you!" << endl;
            break;
        default:
            cout << "Enter valid choice!" << endl;
        }
    } while (choice != 4);

    cout << "\nName: Vedant Bhatt" << endl
         << "ID: 24CE013";
    return 0;
}
