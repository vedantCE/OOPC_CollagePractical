#include<iostream>
using namespace std;

class complexNumber
{
     public:
int real,img;

 complexNumber(int x, int y)
{
    real = x;
    img  = y;
}



complexNumber operator+ (complexNumber &c) // &c object of class complexNumber
{
       complexNumber ans(0,0);
       ans.real=real+c.real;
       ans.img=img+c.img;
       return ans;
}

complexNumber operator- (complexNumber &c) // &c object of class complexNumber
{
       complexNumber ans(0,0);
       ans.real=real-c.real;
       ans.img=img-c.img;
       return ans;
}

};

int main()
{
    complexNumber c1(1,2);
    complexNumber c2(1,3);


complexNumber c3=c1+c2;
complexNumber c4=c1-c2;



 cout<<c3.real<<"+i"<<c3.img<<" ";
 cout<<c4.real<<"+i"<<c4.img<<" ";


}
