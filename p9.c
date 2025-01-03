// l^2+h^2=(l+h)^2
// l^2+h^2=d^2+2dh+h^2
// d^2+2dh-l^2
//applying quadratic solution
//d=sqet((h^2)-(l^2))-h
#include <stdio.h>
#include <math.h>

int main() {
    int H, L;
    // Input H and L
    scanf("%d %d", &H, &L);

    // Calculate depth using the derived formula
    double depth = sqrt((double)H * H + (double)L * L) - H;

    // Print the result with high precision
    printf("%.6lf\n", depth);

    return 0;
}
