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
void DisplayCollection(T* Arr, int Size) {
    cout << "Collection Elements: ";
    for (int I = 0; I < Size; ++I)
        cout << Arr[I] << " ";
    cout << endl;
}

// Template to reverse collection
template <typename T>
void ReverseCollection(T* Arr, int Size) {
    for (int I = 0; I < Size / 2; ++I)
        swap(Arr[I], Arr[Size - I - 1]);
}

// Template to find max value
template <typename T>
T FindMax(T* Arr, int Size) {
    T MaxVal = Arr[0];
    for (int I = 1; I < Size; ++I) {
        if (Arr[I] > MaxVal)
            MaxVal = Arr[I];
    }
    return MaxVal;
}

// Main function to test with different data types
int main() {
    int Size, Choice;
    cout << "Choose Data Type:\n1. Integer\n2. Float\n3. Character\nEnter choice: ";
    cin >> Choice;

    cout << "Enter size of collection: ";
    cin >> Size;

    if (Size <= 0) {
        cout << "Invalid size!";
        return 1;
    }

    cout << "Enter elements:\n";

    switch (Choice) {
        case 1: {
            int* IntArr = new int[Size];
            for (int I = 0; I < Size; ++I)
                cin >> IntArr[I];

            DisplayCollection(IntArr, Size);
            cout << "Maximum: " << FindMax(IntArr, Size) << endl;
            ReverseCollection(IntArr, Size);
            cout << "After Reversing: ";
            DisplayCollection(IntArr, Size);

            delete[] IntArr;
            break;
        }

        case 2: {
            float* FloatArr = new float[Size];
            for (int I = 0; I < Size; ++I)
                cin >> FloatArr[I];

            DisplayCollection(FloatArr, Size);
            cout << "Maximum: " << FindMax(FloatArr, Size) << endl;
            ReverseCollection(FloatArr, Size);
            cout << "After Reversing: ";
            DisplayCollection(FloatArr, Size);

            delete[] FloatArr;
            break;
        }

        case 3: {
            char* CharArr = new char[Size];
            for (int I = 0; I < Size; ++I)
                cin >> CharArr[I];

            DisplayCollection(CharArr, Size);
            cout << "Maximum (by ASCII): " << FindMax(CharArr, Size) << endl;
            ReverseCollection(CharArr, Size);
            cout << "After Reversing: ";
            DisplayCollection(CharArr, Size);

            delete[] CharArr;
            break;
        }

        default:
            cout << "Invalid choice!";
    }

    return 0;
}
