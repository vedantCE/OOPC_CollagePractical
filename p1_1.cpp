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
    string HolderName;
    int AccountNumber, Balance;

    // Deposit money function
    void Deposit(int Amount)
    {
        if (Amount > 0)
        {
            Balance += Amount;
        }
    }

    // Withdraw money function
    void Withdraw(int Amount)
    {
        if (Amount > 0 && Amount < Balance)
        {
            Balance -= Amount;
        }
        else if (Amount > Balance)
        {
            cout << "Not enough balance!" << endl;
        }
    }

    // Display current bank balance
    void DisplayBalance()
    {
        cout << "Current Balance: " << Balance;
    }
};

// Main Function
int main()
{
    // Declaring first bank account
    BankAccount B1;
    B1.Balance = 10000;
    int Amount;
    int Choice;

    // Taking bank account details
    cout << "Enter your name: ";
    cin >> B1.HolderName;
    cout << "Enter your account number: ";
    cin >> B1.AccountNumber;

    cout << "Enter 1 For DEPOSIT" << endl
         << "Enter 2 For WITHDRAW" << endl
         << "Enter 3 For CHECKING CURRENT BALANCE" << endl
         << "Enter 4 For EXIT" << endl;

    do
    {
        cout << endl;
        cout << "Enter your choice: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            cout << "Enter amount for Deposit: ";
            cin >> Amount;
            B1.Deposit(Amount);
            break;
        case 2:
            cout << "Enter amount for Withdraw: ";
            cin >> Amount;
            B1.Withdraw(Amount);
            break;
        case 3:
            B1.DisplayBalance();
            break;
        case 4:
            cout << "\nThank you!" << endl;
            break;
        default:
            cout << "Enter valid choice!" << endl;
        }
    } while (Choice != 4);

    cout << "\nName: Vedant Bhatt" << endl
         << "ID: 24CE013";
    return 0;
}
