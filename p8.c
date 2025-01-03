
#include<stdio.h>
int main()
{
 int row,sum=0;
 printf("Enter row:");
 scanf("%d",&row);
 int arr[row][3];
 //Taking input
 for(int i=0;i<row;i++)
 {
    for(int j=0;j<3;j++)
    {
        scanf("%d",&arr[i][j]);
    }
 }
 printf("\n");
 //Your input arr
 for(int i=0;i<row;i++)
 {
    for(int j=0;j<3;j++)
    {
        printf("%d ",arr[i][j]);
    }
    printf("\n");
 }
 // checking condition
 for(int j=0;j<3;j++)
 {
    for(int i=0;i<3;i++)
    {
       sum+=arr[i][j];
    }
    
 }
 if(sum==0) printf("YES");
 else printf("NO");
 

}