#include <iostream>
#include <iomanip>
#include<conio.h>
using namespace std;
#define MAX_ACCOUNT 50

class BankAccount {
    string AccountHolder;
    int UniqueAccountNumber;
    float CurrentBalance;
    int AccountType; // 1 = Saving, 2 = Business

public:
void displayDetail() {
    cout << "| " << left << setw(20) << AccountHolder 
         << "| " << right << setw(15) << UniqueAccountNumber
         << "| " << setw(15) << CurrentBalance << " |" << endl;
}

    int AddNewAccount() {
        system("CLS"); // For clearing screen
        cout << "Hello New User" << endl;
        cout << "Enter account holder name: ";
        cin >> AccountHolder;
        cout << endl << "Enter your unique account number: ";
        cin >> UniqueAccountNumber;
        cout << "There are two (2) types of Bank Accounts available in our bank." << endl
             << "Which type of Bank Account do you want to open?" << endl
             << "1. Saving Account (no initial deposit required)" << endl
             << "2. Business Account (initial Rs. 5000 deposit required)" << endl;
        cout << "Enter your choice here: ";
        cin >> AccountType;

        if (AccountType == 1) {
            cout << "Congratulations " << AccountHolder << "! You opened a Saving Account." << endl;
            CurrentBalance = 0;
        } else {
            cout << "Congratulations " << AccountHolder << "! You opened a Business Account." << endl;
            CurrentBalance = 5000;
        }
        return AccountType;
    }

    int SearchAccount(int Id) {
        return (Id == UniqueAccountNumber);
    }

    void WithdrawMoney() {
        system("CLS"); // Clear screen
        int Money;
        cout << "|------- Withdraw Money System -------|" << endl;
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

    void DepositMoney() {
        system("CLS"); // Clear screen
        int Money2;
        cout << "|------- Deposit Money System -------|" << endl;
        cout << "Enter the amount to deposit: ";
        cin >> Money2;
        CurrentBalance += Money2;
        cout << "Your current balance is: " << CurrentBalance << endl;
    }
};

int main() {
    int NoOfAccount = 0;
    BankAccount account[MAX_ACCOUNT];
    int BankAccountNumber;


menu:

    cout << "||------------- Welcome to SAHARA Bank -----------||" << endl;
    cout << "Press: " << endl
         << "1. New account" << endl
         << "2. Withdraw money" << endl
         << "3. Deposit money" << endl
         << "4. Display Full Details" << endl
         << "5. Exit" << endl;
    int choice;
    cout << endl << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        if (NoOfAccount < MAX_ACCOUNT) {
            account[NoOfAccount].AddNewAccount();
            NoOfAccount++;
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
        system("CLS"); // For clearing screen
        cout << "|-------------------- SAHARA BANK --------------------|" << endl;
        cout << "|-------- BHAVNAGAR, SARDARNAGAR BRANCH, 364002 --------|" << endl;
        cout << "|------------- Bank Account Holder Details ------------|" << endl;
        cout <<endl<< "==============================================================="<<endl;
            cout << "| Account Holder Name  | Account Number  | Current Balance  |"<<endl;
            cout << "==============================================================="<<endl;
      
        for (int i = 0; i < NoOfAccount; i++) {
            account[i].displayDetail();
        }
        cout << "--------------------------------------------------------" << endl;
        cout<<endl<<"Vedant_Bhatt"<<" "<<"ID No:24CE013"<<endl;
        system("pause");
        break;

    case 5:
        exit(0);

    default:
        cout << "Enter a valid choice" << endl;
        break;
    }

    goto menu;
    return 0;
}
