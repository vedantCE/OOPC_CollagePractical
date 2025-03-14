/*
===========================================================================
    PROGRAM: Bank Loan Management System
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON: March 1, 2025
    LAST UPDATE: March 14, 2025

    Updates:
    - [14-03-2025] Implemented do-while loop instead of goto for better flow.
    - [14-03-2025] Added documentation for better readability.
=============================================================================
*/

#include <iostream>
#include <conio.h> // for system("CLS")
#include <iomanip> // for setw()
#include <cmath>   // for pow() function

const int MAX_ACCOUNT = 50;

using namespace std;

// Class representing bank loan details
class BankLoanDetail
{
    int AccountHolderId;
    string AccountHolder;
    int LoanAmount;
    int LoanTenure; // Loan repayment period in months
    float AnnualInterest;
    float EMI;

    // Function to calculate EMI
    float CalculateEMI(int P, int T, float R)
    {
        float H = pow(1 + R, T);
        return (P * R * H) / (H - 1);
    }

public:
    // Function to add loan details
    void AddDetail()
    {
        cout << "Enter your Account ID:";
        cin >> AccountHolderId;

        cout << "Enter Account holder name:";
        cin >> AccountHolder;

        cout << "Enter your loan amount:";
        cin >> LoanAmount;

        cout << "Enter loan tenure (months):";
        cin >> LoanTenure;

        cout << "Enter your annual interest rate:";
        cin >> AnnualInterest;

        EMI = CalculateEMI(LoanAmount, LoanTenure, AnnualInterest);
    }

    // Function to display loan details
    void DisplayDetail()
    {
        cout << "| " << setw(11) << right << AccountHolderId
             << " | " << setw(15) << right << AccountHolder
             << " | " << setw(12) << right << LoanAmount
             << " | " << setw(15) << right << LoanTenure
             << " | " << setw(8) << right << fixed << setprecision(2) << AnnualInterest
             << " | " << setw(10) << right << fixed << setprecision(2) << EMI
             << " |" << endl;
    }
};

int main()
{
    BankLoanDetail Account[MAX_ACCOUNT];
    int NoOfAccount = 0;
    int Choice1, Choice2;

    do
    {
        cout << "Press" << endl
             << "1. Add loan taker detail." << endl
             << "2. Display all loan taker details" << endl
             << "0. Exit" << endl
             << endl;

        cout << "Enter your choice:";
        cin >> Choice1;

        switch (Choice1)
        {
        case 1:
            system("CLS");
            cout << "|-----Welcome to New Customer Loan Detail Portal----|" << endl;
            do
            {
                if (NoOfAccount >= MAX_ACCOUNT)
                {
                    cout << "Bank Account is full!";
                    break;
                }
                Account[NoOfAccount].AddDetail();
                NoOfAccount++;
                cout << "Press 1. Add another account" << endl
                     << "2. Exit to menu" << endl;
                cin >> Choice2;
            } while (Choice2 == 1);
            break;

        case 2:
            if (NoOfAccount == 0)
            {
                cout << "No account currently available in the bank!";
            }
            else
            {
                cout << "------------------------------------------------------------------------------------------" << endl;
                cout << "| Account ID  |  Account Holder  | Loan Amount  | Tenure (Months) | Interest |    EMI    |" << endl;
                cout << "------------------------------------------------------------------------------------------" << endl;

                for (int i = 0; i < NoOfAccount; i++)
                {
                    Account[i].DisplayDetail();
                }

                cout << "------------------------------------------------------------------------------------------" << endl;
            }
            cout << endl
                 << endl
                 << "Vedant_Bhatt | ID No: 24CE013" << endl;
            system("PAUSE");
            break;

        case 0:
            cout << endl
                 << "Vedant_Bhatt | ID No: 24CE013" << endl;
            return 0;
        }
    } while (Choice1 != 0);

    return 0;
}
