
#include<iostream>
using namespace std;

class Account
{
    protected:

    int AccountNumber;
    float AccountBalance;

    public:

    Account(int AccNo,float Balance)
    {
          AccountNumber=AccNo;
          AccountBalance=Balance;
    }
};

class SavingAccount:public Account
{
     float InteresRate;

     public:
       
       SavingAccount(int AccNo,float Balance,float Ir):Account(AccNo,Balance)
       {
            InteresRate=Ir;
       }
};

class CurrentAccount:public Account
{
  int OverDraftLimit=1850;

  public:

    CurrentAccount(int AccNo,float Balance):Account(AccNo,Balance){}


};

int main()
{
      


}