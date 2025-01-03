#include <stdio.h>

int main() {
    int num, originalNum, remainder, result = 0, n = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    originalNum = num;

    // Find the number of digits in the number
    while (originalNum != 0) {
        originalNum /= 10;
        n++;
    }

    originalNum = num;

    // Compute the sum of the nth powers of its digits
    while (originalNum != 0) {
        remainder = originalNum % 10;

        // Calculate remainder^n manually
        int power = 1;
        for (int i = 0; i < n; i++) {
            power *= remainder;
        }

        result += power;
        originalNum /= 10;
    }

    // Check if the number is an Armstrong number
    if (result == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
