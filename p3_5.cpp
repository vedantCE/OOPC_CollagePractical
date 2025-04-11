#include <iostream>
#include <string>

using namespace std;

// Function to calculate the sum of digits of a number
int sumOfDigits(long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Recursive function
int superDigit(long long num) {
    if (num < 10) {
        return num;
    }
    int sum = sumOfDigits(num);
    return superDigit(sum);
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    // Calculate the initial sum of digits of n
    long long initialSum = 0;
    for (char digit : n) {
        initialSum += digit - '0';
    }

    // Multiply the initial sum by k to account for the concatenation
    long long totalSum = initialSum * k;

    cout << superDigit(totalSum) << endl;

    return 0;
}
