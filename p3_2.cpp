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
int recursiveSum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

// Iterative function to calculate sum of array
int iterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;

    // Input array size
    cout << "Enter number of elements in the array: ";
    cin >> n;

    // Dynamically allocate memory for array
    int* arr = new int[n];

    // Input array elements
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Calculate and display sum using recursion
    int sumRecursive = recursiveSum(arr, n);
    cout << "\nRecursive Sum: " << sumRecursive << endl;

    // Calculate and display sum using iteration
    int sumIterative = iterativeSum(arr, n);
    cout << "Iterative Sum: " << sumIterative << endl;

    // Free dynamically allocated memory
    delete[] arr;

    cout<<endl<<"VEDANT BHATT || 24CE013"<<endl;

    return 0;
}
