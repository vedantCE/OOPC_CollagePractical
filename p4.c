#include <stdio.h>
int main()
{
    int num1, num2, lcf = 0, max = 0;
    printf("Enter num1 and num2:");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2)
        max = num1;
    else
        max = num2;

    while (1)
    {
        if (max % num1 == 0 && max % num2 == 0)
        {
            lcf = max;
            break;
        }
        else
        {
            max++;
        }
    }
    printf("The lcf of %d and %d is:%d", num1, num2, lcf);
    return 0;
}