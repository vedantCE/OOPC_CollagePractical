#include <iostream>
#include <string>

using namespace std;

// Function to calculate the sum of digits of a number
int SumOfDigits(long long Num) {
    int Sum = 0;
    while (Num > 0) {
        Sum += Num % 10;
        Num /= 10;
    }
    return Sum;
}

// Recursive function
int SuperDigit(long long Num) {
    if (Num < 10) {
        return Num;
    }
    int Sum = SumOfDigits(Num);
    return SuperDigit(Sum);
}

int main() {
    string N;
    int K;
    cout<<"Enter number and value of k:";
    cin >> N >> K;

    // Calculate the initial sum of digits of N
    long long InitialSum = 0;
    for (char Digit : N) {
        InitialSum += Digit - '0';
    }

    // Multiply the initial sum by K to account for the concatenation
    long long TotalSum = InitialSum * K;

    cout << SuperDigit(TotalSum) << endl;

    return 0;
}
