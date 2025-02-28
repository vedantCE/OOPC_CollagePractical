#include <iostream>
#include <conio.h> // for  system("CLS")
#include <iomanip> // for setw()
#include <cmath>   //  for pow() function

#define MAX_ACCOUNT 50

using namespace std;

class BankLoanDetail
{
    int AccountHolderId;
    string AccountHolder;
    int LoanAmount;
    int LoanTenure; // Timeperiod of loan
    float AnnualInterest;
    float EMI;

    float CalculateEMI(int P, int T, float R)
    {

        float H = pow(1 + R, T);
        return (P * R * H) / (H - 1);
    }

public:
    void AddDetail()
    {
        cout << "Enter your Account ID:";
        cin >> AccountHolderId;

        cout << "Enter Account holder name:";
        cin >> AccountHolder;

        cout << "Enter your loan ammount:";
        cin >> LoanAmount;

        cout << "Enter after how many months you return money:";
        cin >> LoanTenure;

        cout << "Enter your annual rate:";
        cin >> AnnualInterest;

        EMI = CalculateEMI(LoanAmount, LoanTenure, AnnualInterest);
    }

    void DisplayDetail(int NoOfProduct)
    {
        if (NoOfProduct > 0)
        {
            cout << "| " << setw(11) << right << AccountHolderId
                 << " | " << setw(15) << right << AccountHolder
                 << " | " << setw(12) << right << LoanAmount
                 << " | " << setw(15) << right << LoanTenure
                 << " | " << setw(8) << right << fixed << setprecision(2) << AnnualInterest
                 << " | " << setw(10) << right << fixed << setprecision(2) << EMI
                 << " |" << endl;
        }
    }
};

int main()
{
    BankLoanDetail Account[MAX_ACCOUNT];
    int NoOfAccount = 0;
menu:
    cout << "Press" << endl
         << "1. Add loan taker detail." << endl
         << "2.Display all loan taker detail" << endl
         << "0.Exit" << endl
         << endl;

    int Choice1, Choice2;
    cout << "Enter your choice:";
    cin >> Choice1;

    if (Choice1 == 1)
    {
        system("CLS");
        cout << "|-----Welcome to New customer Loan detail portal----|" << endl;
        if (NoOfAccount == 0)
        {
            Account[NoOfAccount].AddDetail();
            NoOfAccount++;
            cout << "Press" << endl
                 << "1.Add another account" << endl
                 << "2.Exit" << endl;
            cin >> Choice2;
            if (Choice2 == 1)
            {
                goto add;
            }
            else
            {
                system("PAUSE");
                goto menu;
            }
        }
        else if (NoOfAccount > 0 && NoOfAccount < 50)
        {
        add:
            Account[NoOfAccount].AddDetail();
            NoOfAccount++;
            cout << "Press 1.Add another account" << endl
                 << "2.Exit";
            cin >> Choice2;
            if (Choice2 == 1)
            {
                goto add;
            }
            else
            {
                system("PAUSE");
                goto menu;
            }
        }
        else
        {
            cout << "Bank Account is full!";
            exit(0);
        }
    }

    else if (Choice1 == 2)
    {
        if (NoOfAccount == 0)
        {
            cout << "No account currently available in Bank!";
        }
        else
        {
            cout << "------------------------------------------------------------------------------------------" << endl;
            cout << "| Account ID  |  Account Holder  | Loan Amount  | Tenure (Months) | Interest |    EMI    |" << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;

            for (int i = 0; i < NoOfAccount; i++)
            {
                Account[i].DisplayDetail(NoOfAccount);
            }

            cout << "------------------------------------------------------------------------------------------" << endl;
        }
        cout << endl
             << endl
             << "Vedant_Bhatt | ID No: 24CE013" << endl;
        system("PAUSE");
        goto menu;
    }

    else if (Choice1 == 0)
    {
        cout << endl
             << "Vedant_Bhatt | ID No: 24CE013" << endl;
        return 0;
    }

    return 0;
}
