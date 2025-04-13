/*
====================================================================================
    PROGRAM: Flexible Collection Manager Using Templates
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON: April 10, 2025

    FEATURES:
    - Uses function templates to handle int, float, char collections
    - Supports operations: Max Value, Reverse, Display
    - Uses dynamic memory allocation (new/delete)
====================================================================================
*/

#include <iostream>
using namespace std;

// Template to display collection
template <typename T>
void displayCollection(T* arr, int size) {
    cout << "Collection Elements: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Template to reverse collection
template <typename T>
void reverseCollection(T* arr, int size) {
    for (int i = 0; i < size / 2; ++i)
        swap(arr[i], arr[size - i - 1]);
}

// Template to find max value
template <typename T>
T findMax(T* arr, int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

// Main function to test with different data types
int main() {
    int size, choice;
    cout << "Choose Data Type:\n1. Integer\n2. Float\n3. Character\nEnter choice: ";
    cin >> choice;

    cout << "Enter size of collection: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size!";
        return 1;
    }

    cout << "Enter elements:\n";

    switch (choice) {
        case 1: {
            int* intArr = new int[size];
            for (int i = 0; i < size; ++i)
                cin >> intArr[i];

            displayCollection(intArr, size);
            cout << "Maximum: " << findMax(intArr, size) << endl;
            reverseCollection(intArr, size);
            cout << "After Reversing: ";
            displayCollection(intArr, size);

            delete[] intArr;
            break;
        }

        case 2: {
            float* floatArr = new float[size];
            for (int i = 0; i < size; ++i)
                cin >> floatArr[i];

            displayCollection(floatArr, size);
            cout << "Maximum: " << findMax(floatArr, size) << endl;
            reverseCollection(floatArr, size);
            cout << "After Reversing: ";
            displayCollection(floatArr, size);

            delete[] floatArr;
            break;
        }

        case 3: {
            char* charArr = new char[size];
            for (int i = 0; i < size; ++i)
                cin >> charArr[i];

            displayCollection(charArr, size);
            cout << "Maximum (by ASCII): " << findMax(charArr, size) << endl;
            reverseCollection(charArr, size);
            cout << "After Reversing: ";
            displayCollection(charArr, size);

            delete[] charArr;
            break;
        }

        default:
            cout << "Invalid choice!";
    }

    return 0;
}
