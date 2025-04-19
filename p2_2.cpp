/*
==============================================================================
    PROGRAM: Student Record Management System
    DEVELOPER: VEDANT BHATT
    ID No: 24CE013
    CREATED ON: April 11, 2025
    LAST UPDATE ON: April 19,2025

    DESCRIPTION:
    A system to manage student academic records including roll number, name, 
    and marks in 3 subjects. Calculates and displays average marks with options 
    to input custom or default values.
==============================================================================
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    int RollNumber;
    string Name;
    int Marks[3];
    float Average;

public:
    // Initializes student with default or given values
    void Initialize(string StudentName = "Unknown", int Roll = 0, int M1 = 0, int M2 = 0, int M3 = 0) {
        Name = StudentName;
        RollNumber = Roll;
        Marks[0] = M1;
        Marks[1] = M2;
        Marks[2] = M3;
        CalculateAverage();
    }

    // Calculates the average marks
    void CalculateAverage() {
        int Total = Marks[0] + Marks[1] + Marks[2];
        Average = static_cast<float>(Total) / 3.0;
    }

    // Displays student details
    void Display(int Index) const {
        cout << endl;
        cout << "Student Details for Student " << Index + 1 << ":" << endl;
        cout << left << setw(20) << "Name:" << Name << endl;
        cout << left << setw(20) << "Roll Number:" << RollNumber << endl;
        cout << left << setw(20) << "Marks (Subject 1):" << Marks[0] << endl;
        cout << left << setw(20) << "Marks (Subject 2):" << Marks[1] << endl;
        cout << left << setw(20) << "Marks (Subject 3):" << Marks[2] << endl;
        cout << left << setw(20) << fixed << setprecision(2) << "Average:" << Average << endl;
    }
};

int main() {
    int NumStudents;
    cout << "Enter the number of students: ";
    cin >> NumStudents;
    cin.ignore(); // Clear the newline character from input buffer

    Student Students[NumStudents];

    // Input phase
    for (int I = 0; I < NumStudents; ++I) {
        string Name;
        int Roll, M1, M2, M3;

        cout << endl << "Enter details for student " << I + 1 << ":" << endl;

        cout << "Name: ";
        getline(cin, Name); // Allows full name with spaces

        cout << "Roll Number: ";
        cin >> Roll;

        cout << "Marks in Subject 1: ";
        cin >> M1;

        cout << "Marks in Subject 2: ";
        cin >> M2;

        cout << "Marks in Subject 3: ";
        cin >> M3;
        cin.ignore(); 

        Students[I].Initialize(Name, Roll, M1, M2, M3);
    }

    // Output phase
    cout << endl << "=========================== Student Records =========================" << endl;
    for (int I = 0; I < NumStudents; ++I) {
        Students[I].Display(I);
    }

    cout << endl << "VEDANT BHATT || 24CE013" << endl;
    return 0;
}
