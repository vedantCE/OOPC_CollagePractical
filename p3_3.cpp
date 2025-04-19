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
    int AccountNumber;
    string AccountHolderName;
    double AccountBalance;
    BankAccount* NextAccount;

    BankAccount(int AccNo, string Name, double Balance) {
        AccountNumber = AccNo;
        AccountHolderName = Name;
        AccountBalance = Balance;
        NextAccount = NULL;
    }

    void DisplayAccount() {
        cout << left << setw(15) << AccountNumber
             << left << setw(25) << AccountHolderName
             << fixed << setprecision(2) << AccountBalance << endl;
    }
};

class AccountManager {
private:
    BankAccount* FirstAccount;
    int TotalAccounts;

public:
    AccountManager() {
        FirstAccount = NULL;
        TotalAccounts = 0;
    }

    void CreateNewAccount(int AccNo, string Name, double Balance) {
        BankAccount* NewAccount = new BankAccount(AccNo, Name, Balance);
        NewAccount->NextAccount = FirstAccount;
        FirstAccount = NewAccount;
        TotalAccounts++;
        cout << "Account created successfully\n";
    }

    void ShowAllAccounts() {
        if (FirstAccount == NULL) {
            cout << "No accounts found\n";
            return;
        }

        BankAccount* Current = FirstAccount;
        cout << "\nAccount No      Account Holder            Balance\n";
        cout << "------------------------------------------------------\n";

        while (Current != NULL) {
            Current->DisplayAccount();
            Current = Current->NextAccount;
        }
    }

    BankAccount* SearchAccount(int AccNo) {
        BankAccount* Current = FirstAccount;
        while (Current != NULL) {
            if (Current->AccountNumber == AccNo)
                return Current;
            Current = Current->NextAccount;
        }
        return NULL;
    }

    void TransferMoney(int SenderNo, int ReceiverNo, double Amount) {
        BankAccount* Sender = SearchAccount(SenderNo);
        BankAccount* Receiver = SearchAccount(ReceiverNo);

        if (!Sender || !Receiver) {
            cout << "One or both accounts not found\n";
            return;
        }

        if (Sender->AccountBalance < Amount) {
            cout << "Insufficient balance to transfer\n";
            return;
        }

        Sender->AccountBalance -= Amount;
        Receiver->AccountBalance += Amount;

        cout << "Transfer successful\n";
    }

    void DisplayTotalAccounts() {
        cout << "Total accounts created: " << TotalAccounts << endl;
    }

    ~AccountManager() {
        BankAccount* Current = FirstAccount;
        while (Current != nullptr) {
            BankAccount* Next = Current->NextAccount;
            delete Current;
            Current = Next;
        }
    }
};

int main() {
    AccountManager Bank;
    int Choice;

MenuLabel:
    cout << endl << "SAHARA Bank Menu" << endl;
    cout << "===============================" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Display All Accounts" << endl;
    cout << "3. Transfer Funds" << endl;
    cout << "4. Show Total Accounts" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> Choice;

    switch (Choice) {
        case 1: {
            int AccNo;
            string Name;
            double Balance;
            cout << "Enter Account Number: ";
            cin >> AccNo;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, Name);
            cout << "Enter Initial Balance: ";
            cin >> Balance;
            Bank.CreateNewAccount(AccNo, Name, Balance);
            break;
        }
        case 2:
            Bank.ShowAllAccounts();
            break;

        case 3: {
            int SenderAccNo, ReceiverAccNo;
            double Amount;
            cout << "Enter Sender Account Number: ";
            cin >> SenderAccNo;
            cout << "Enter Receiver Account Number: ";
            cin >> ReceiverAccNo;
            cout << "Enter Amount to Transfer: ";
            cin >> Amount;
            Bank.TransferMoney(SenderAccNo, ReceiverAccNo, Amount);
            break;
        }

        case 4:
            Bank.DisplayTotalAccounts();
            break;

        case 0:
            cout << "VEDANT BHATT || 24CE013" << endl << "Exiting program";
            return 0;

        default:
            cout << "Invalid choice\n";
    }

    goto MenuLabel;
}
