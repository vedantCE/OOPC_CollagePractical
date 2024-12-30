#include<stdio.h>
int main()
{
char string[100];
int length=0;
printf("Enter your string here:");
gets(string);
//fflush(stdin);
//Logic of finding length
for(int i=0;string[i]!='\0';i++)
{
length++;
}
//Printing string length
printf("The String length is:%d",length);

printf("\n\nVEDANT BHATT_24CE013\n");
return 0;
}
