/* 
===========================================================================
    PROGRAM: Bank Management System - SAHARA BANK
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON:  February 21,2025
    LAST UPDATE: March 13, 2025

    Updates:
    - [13-03-2025] Implemented do-while loop instead of goto for better flow.
    - [13-03-2025] Implemented const insted of #define for type saftey
=============================================================================
*/

#include <iostream>
#include <iomanip> // for setw
#include <conio.h> // for clear screen

using namespace std;

const int MAX_ACCOUNT = 50; // Maximum number of accounts

// Class to store Bank Account details
class BankAccount {
    string AccountHolder;     
    int UniqueAccountNumber;  
    float CurrentBalance;     
    int AccountType;          // 1 = Savings, 2 = Business

public:
    // Function to display account details in tabular format
    void DisplayDetail() {
        cout << "| " << left << setw(20) << AccountHolder 
             << "| " << right << setw(15) << UniqueAccountNumber
             << "| " << setw(15) << CurrentBalance << " |" << endl;
    }

    // Function to create a new bank account
    void AddNewAccount() {
        system("CLS"); // Clear screen
        cout << "||-------------- Welcome New User --------------||" << endl;
        cout << "Enter account holder name: ";
        cin >> AccountHolder;
        cout << "Enter your unique account number: ";
        cin >> UniqueAccountNumber;

        // Selecting account type
        cout << "Types of Bank Accounts Available:\n"
             << "1. Savings Account (no initial deposit required)\n"
             << "2. Business Account (minimum Rs. 5000 balance required)\n"
             << "Enter your choice: ";
        cin >> AccountType;

        if (AccountType == 1) {
            cout << "Congratulations " << AccountHolder << "! You opened a Savings Account." << endl;
            CurrentBalance = 0;
        } else {
            cout << "Congratulations " << AccountHolder << "! You opened a Business Account." << endl;
            CurrentBalance = 5000;
        }
    }

    // Function to search an account by ID
    bool SearchAccount(int Id) {
        return (Id == UniqueAccountNumber);
    }

    // Function to withdraw money
    void WithdrawMoney() {
        system("CLS"); // Clear screen
        int Money;
        cout << "||------- Withdraw Money -------||" << endl;
        cout << "Enter the amount to withdraw: ";
        cin >> Money;

        if (AccountType == 1) { // Savings Account
            if (Money <= CurrentBalance) {
                CurrentBalance -= Money;
                cout << "Withdrawal successful. Your current balance is: " << CurrentBalance << endl;
            } else {
                cout << "Insufficient balance! Your current balance is: " << CurrentBalance << endl;
            }
        } else { // Business Account
            if (CurrentBalance - Money >= 5000) {
                CurrentBalance -= Money;
                cout << "Withdrawal successful. Your current balance is: " << CurrentBalance << endl;
            } else {
                cout << "Business accounts must maintain at least Rs. 5000. Transaction failed!" << endl;
            }
        }
    }

    // Function to deposit money
    void DepositMoney() {
        system("CLS"); // Clear screen
        int Money;
        cout << "||------- Deposit Money -------||" << endl;
        cout << "Enter the amount to deposit: ";
        cin >> Money;
        CurrentBalance += Money;
        cout << "Your current balance is: " << CurrentBalance << endl;
    }
};

int main() {
    int NoOfAccount = 0; // Total number of accounts created
    BankAccount account[MAX_ACCOUNT]; // Array to store multiple accounts
    int BankAccountNumber;
    int choice;

    do {
        // Display menu options
        cout << "\n||------------- Welcome to SAHARA Bank -----------||" << endl;
        cout << "1. New account" << endl;
        cout << "2. Withdraw money" << endl;
        cout << "3. Deposit money" << endl;
        cout << "4. Display all account details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (NoOfAccount < MAX_ACCOUNT) {
                    account[NoOfAccount].AddNewAccount();
                    NoOfAccount++;
                } else {
                    cout << "Maximum account limit reached!" << endl;
                }
                break;

            case 2:
                cout << "Enter your Bank Account number: ";
                cin >> BankAccountNumber;
                for (int i = 0; i < NoOfAccount; i++) {
                    if (account[i].SearchAccount(BankAccountNumber)) {
                        account[i].WithdrawMoney();
                        break;
                    }
                }
                break;

            case 3:
                cout << "Enter your Bank Account number: ";
                cin >> BankAccountNumber;
                for (int i = 0; i < NoOfAccount; i++) {
                    if (account[i].SearchAccount(BankAccountNumber)) {
                        account[i].DepositMoney();
                        break;
                    }
                }
                break;

            case 4:
                system("CLS"); // Clear screen
                cout << "\n||----------- SAHARA BANK Account Details -----------||" << endl;
                cout << "==========================================================" << endl;
                cout << "| Account Holder Name  | Account Number  | Current Balance  |" << endl;
                cout << "==========================================================" << endl;
            
                for (int i = 0; i < NoOfAccount; i++) {
                    account[i].DisplayDetail();
                }
                cout << "--------------------------------------------------------" << endl;
                break;

            case 5:
                cout << "Thank you for using SAHARA Bank system. Have a great day!" << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 5); // Loop until the user selects Exit (5)

    return 0;
}
