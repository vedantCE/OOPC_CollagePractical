// #include<stdio.h>
// int main()
// {
//     int m,n,a;
//     scanf("%d %d %d",&m,&n,&a);
//     int areaOfTheater=m*n;
//     int areaOfFlagstones=a*a;

//     if((areaOfTheater/areaOfFlagstones)!=0)
//     {
//         printf("%d",((areaOfTheater/areaOfFlagstones)+1));
//     }
// }
#include<stdio.h>

int main()
{
    long long m, n, a;
    
    // Input the dimensions of the Theatre Square (m, n) and the side of a flagstone (a)
    scanf("%lld %lld %lld", &m, &n, &a);

    // Calculate the number of flagstones required for length and width
    // Equivalent to ceil(m / a) and ceil(n / a)
    long long flagstones_along_length = (m + a - 1) / a; // ceil(m / a)
    long long flagstones_along_width = (n + a - 1) / a;  // ceil(n / a)

    // Total flagstones required is the product of flagstones needed for length and width
    long long total_flagstones = flagstones_along_length * flagstones_along_width;

    // Output the result
    printf("%lld\n", total_flagstones);

    return 0;
}
