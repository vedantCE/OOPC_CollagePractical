/*
==============================================================================
    PROGRAM: Recursive vs Iterative Sum of Array
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON: April 8, 2025
   

    Objective:
    - Compare performance and complexity of recursive vs iterative algorithms
   
==============================================================================
*/

#include <iostream>
using namespace std;

// Recursive function to calculate sum of array
int RecursiveSum(int Arr[], int N) {
    if (N == 0)
        return 0;
    return Arr[N - 1] + RecursiveSum(Arr, N - 1);
}

// Iterative function to calculate sum of array
int IterativeSum(int Arr[], int N) {
    int Sum = 0;
    for (int I = 0; I < N; I++) {
        Sum += Arr[I];
    }
    return Sum;
}

int main() {
    int N;

    // Input array size
    cout << "Enter number of elements in the array: ";
    cin >> N;

    // Dynamically allocate memory for array
    int* Arr = new int[N];

    // Input array elements
    cout << "Enter " << N << " elements:" << endl;
    for (int I = 0; I < N; I++) {
        cout << "Element " << I + 1 << ": ";
        cin >> Arr[I];
    }

    // Calculate and display sum using recursion
    int SumRecursive = RecursiveSum(Arr, N);
    cout << "\nRecursive Sum: " << SumRecursive << endl;

    // Calculate and display sum using iteration
    int SumIterative = IterativeSum(Arr, N);
    cout << "Iterative Sum: " << SumIterative << endl;

    // Free dynamically allocated memory
    delete[] Arr;

    cout << endl << "VEDANT BHATT || 24CE013" << endl;

    return 0;
}
