//  Write a Program to Toggle Each Character in a String (ex: ip=”FoolonCool” ; 
// op=”fOOLONcOOL”). 
#include<stdio.h>
#include<string.h>
int main()
{
    char string1[100];
    char string2[100];
int length=0;
    gets(string1);
    length=strlen(string1);

    for(int i=0;i<length;i++)
    {
        if(string1[i]>='A' && string1[i]<='Z')
        {
            string2[i]=string1[i]+32;
        }
        else
        {
            string2[i]=string1[i]-32;

        }
    }
    printf("Toggled string: %s\n", string2);
    return 0;

}