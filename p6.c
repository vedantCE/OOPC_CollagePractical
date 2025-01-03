// Write a Program for Binary to Octal Conversion. 
#include<stdio.h>

int main()
{
    // Talking input from user
    int binary;
    printf("Enter number between 0-1:");
    scanf("%d",&binary);
    int ans=0;
    int power=1;

while(binary>0)
{
int lastDigit=binary%10;
//ans=ans+lastDigit*2*power// aavu karia to last digit 2 thi gunay
ans+=lastDigit*power;
power*=2;
binary/=10;
}
// Converting decimal to octal

int octal=0;
power=1;
while(ans>0)
{
int lastDigit=ans%8;
octal+=lastDigit*power;
power*=10;
ans/=8;
}
printf("the octal number is:%d",octal);

     return 0;
}
     
