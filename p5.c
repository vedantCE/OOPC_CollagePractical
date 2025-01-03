#include <stdio.h>
#include <math.h>
int main()
{
    // program to find roots of a quadratic equation
    float a, b, c;
    float discriminant;
    float root1, root2;
    printf("Enter cofficient of a :");
    scanf("%f", &a);
     printf("Enter cofficient of b :");
    scanf("%f", &b);
     printf("Enter cofficient of c :");
    scanf("%f", &c);
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        printf("roots are real\n");
        root1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
        root2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
        printf("first root is:%f", root1);
        printf("\nsecond root is:%f", root2);
    }
    else
    {
        if (discriminant == 0)
        {
            printf("roots are same\n");
            root1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
            root2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
            printf("first root is:%f", root1);
            printf("\nsecond root is:%f", root2);
        }
        else


    {
        printf("roots are imaginary\n");
    }
}
}