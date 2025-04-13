/*
==============================================================================
    PROGRAM: Community Bank Account Management System
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON: April 9, 2025
    
    Features:
    - Uses singly linked list for dynamic account storage
    - Secure transfer between accounts
    - Tracks total number of accounts
    - Uses goto for menu navigation
    - Displays output in tabular format
==============================================================================
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
public:
    int accountNumber;
    string accountHolderName;
    double accountBalance;
    BankAccount* nextAccount;

    BankAccount(int accNo, string name, double balance) {
        accountNumber = accNo;
        accountHolderName = name;
        accountBalance = balance;
        nextAccount = NULL;
    }

    void displayAccount() {
        cout << left << setw(15) << accountNumber
             << left << setw(25) << accountHolderName
             << fixed << setprecision(2) << accountBalance << endl;
    }
};

class AccountManager {
private:
    BankAccount* firstAccount;
    int totalAccounts;

public:
    AccountManager() {
        firstAccount = NULL;
        totalAccounts = 0;
    }

    void createNewAccount(int accNo, string name, double balance) {
        BankAccount* newAccount = new BankAccount(accNo, name, balance);
        newAccount->nextAccount = firstAccount;
        firstAccount = newAccount;
        totalAccounts++;
        cout << "Account created successfully\n";
    }

    void showAllAccounts() {
        if (firstAccount == NULL) {
            cout << "No accounts found\n";
            return;
        }

        BankAccount* current = firstAccount;
        cout << "\nAccount No      Account Holder            Balance\n";
        cout << "------------------------------------------------------\n";

        while (current != NULL) {
            current->displayAccount();
            current = current->nextAccount;
        }
    }

    BankAccount* searchAccount(int accNo) {
        BankAccount* current = firstAccount;
        while (current != NULL) {
            if (current->accountNumber == accNo)
                return current;
            current = current->nextAccount;
        }
        return NULL;
    }

    void transferMoney(int senderNo, int receiverNo, double amount) {
        BankAccount* sender = searchAccount(senderNo);
        BankAccount* receiver = searchAccount(receiverNo);

        if (!sender || !receiver) {
            cout << "One or both accounts not found\n";
            return;
        }

        if (sender->accountBalance < amount) {
            cout << "Insufficient balance to transfer\n";
            return;
        }

        sender->accountBalance -= amount;
        receiver->accountBalance += amount;

        cout << "Transfer successful\n";
    }

    void displayTotalAccounts() {
        cout << "Total accounts created: " << totalAccounts << endl;
    }

    ~AccountManager() {
        BankAccount* current = firstAccount;
        while (current != nullptr) {
            BankAccount* next = current->nextAccount;
            delete current;
            current = next;
        }
    }
};

int main() {
    AccountManager bank;
    int choice;

menuLabel:
    cout <<endl<< "SAHARA Bank Menu"<<endl;
    cout<<"==============================="<<endl;
    cout << "1. Create Account"<<endl;
    cout << "2. Display All Accounts"<<endl;
    cout << "3. Transfer Funds"<<endl;
    cout << "4. Show Total Accounts"<<endl;
    cout << "0. Exit"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int accNo;
            string name;
            double balance;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Initial Balance: ";
            cin >> balance;
            bank.createNewAccount(accNo, name, balance);
            break;
        }
        case 2:
            bank.showAllAccounts();
            break;

        case 3: {
            int senderAccNo, receiverAccNo;
            double amount;
            cout << "Enter Sender Account Number: ";
            cin >> senderAccNo;
            cout << "Enter Receiver Account Number: ";
            cin >> receiverAccNo;
            cout << "Enter Amount to Transfer: ";
            cin >> amount;
            bank.transferMoney(senderAccNo, receiverAccNo, amount);
            break;
        }

        case 4:
            bank.displayTotalAccounts();
            break;

        case 0:
            cout << "VEDANT BHATT || 24CE013"<<endl<<"Exiting program";
            return 0;

        default:
            cout << "Invalid choice\n";
    }

    goto menuLabel;
}
