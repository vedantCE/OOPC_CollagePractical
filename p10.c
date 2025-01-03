#include<stdio.h>
int main()
{
    int number,sum=0;
    printf("Enter number:");
    scanf("%d",&number);
    for(int i=1;i<number;i++)
    {
         if(number%i==0)
         {
            sum=sum+i;
         }
    }
    if(sum==number) printf("Number is perfect number");
    else printf("Given number is not perfect number");
}