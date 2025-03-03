#include <iostream>
using namespace std;

// Declaring BankAccount class
class BankAccount
{
public:
    string HolderName;
    int accountNumber,balance;

    // Deposit money function
    void deposit(int amount)
    {
        if(amount>0)
        {
            balance+=amount;
        }
    }

    // Withdraw money function
    void withdraw(int amount)
    {
        if(amount>0 && amount<balance)
        {
            balance-=amount;
        }
        else if(amount>balance)
        {
            cout<<"Not enough balance!"<<endl;
        }
    }

    // Diplay Current bankbalance
    void display_balance()
    {
        cout<<"Current Balance: "<<balance;
    }
};


// Main Function
int main()
{

    // Declaring First bank accunt
    BankAccount B1;
    B1.balance=10000;
    int amount;
    int choice;

    // Taking bankaccount detail
    cout<<"Enter your name: ";
    cin>>B1.HolderName;
    cout<<"Enter your account number: ";
    cin>>B1.accountNumber;

    cout<<"Enter 1 For DEPOSIT"<<endl<<"Enter 2 For WITHDRAW Enter 2"<<endl<<"Enter 3 For CHECKING CURRENT BALANCE "<<endl<<"Enter 4For EXIT "<<endl;
    do{
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter amount for Deposit: ";
            cin>>amount;
            B1.deposit(amount);
            break;
        case 2:
            cout<<"Enter amount for Withdraw: ";
            cin>>amount;
            B1.withdraw(amount);
            break;
        case 3:
            B1.display_balance();
            break;
        case 4:
            cout<<"\nThank you!"<<endl;
            break;
        default:
            cout<<"Enter valid choice!"<<endl;
        }
    }
    while(choice!=4);

    cout<<"\nName: Vedant Bhatt"<<endl<<"ID: 24CE013";
    return 0;
}