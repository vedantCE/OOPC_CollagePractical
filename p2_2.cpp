/*
==============================================================================
    PROGRAM: Student Record Management System
    DEVELOPER: VEDANT BHATT
    ID No: 24CE013
    CREATED ON: April 11, 2025

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
    int rollNumber;
    string name;
    int marks[3];
    float average;

public:
    // Initializes student with default or given values
    void initialize(string studentName = "Unknown", int roll = 0, int m1 = 0, int m2 = 0, int m3 = 0) {
        name = studentName;
        rollNumber = roll;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculateAverage();
    }

    // Calculates the average marks
    void calculateAverage() {
        int total = marks[0] + marks[1] + marks[2];
        average = static_cast<float>(total) / 3.0;
    }

    // Displays student details
    void display(int index) const {
        cout << endl;
        cout << "Student Details for Student " << index + 1 << ":" << endl;
        cout << left << setw(20) << "Name:" << name << endl;
        cout << left << setw(20) << "Roll Number:" << rollNumber << endl;
        cout << left << setw(20) << "Marks (Subject 1):" << marks[0] << endl;
        cout << left << setw(20) << "Marks (Subject 2):" << marks[1] << endl;
        cout << left << setw(20) << "Marks (Subject 3):" << marks[2] << endl;
        cout << left << setw(20) << fixed << setprecision(2) << "Average:" << average << endl;
    }
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore(); // Clear the newline character from input buffer

    Student students[numStudents];

    // Input phase
    for (int i = 0; i < numStudents; ++i) {
        string name;
        int roll, m1, m2, m3;

        cout << endl << "Enter details for student " << i + 1 << ":" << endl;

        cout << "Name: ";
        getline(cin, name); // Allows full name with spaces

        cout << "Roll Number: ";
        cin >> roll;

        cout << "Marks in Subject 1: ";
        cin >> m1;

        cout << "Marks in Subject 2: ";
        cin >> m2;

        cout << "Marks in Subject 3: ";
        cin >> m3;
        cin.ignore(); 

        students[i].initialize(name, roll, m1, m2, m3);
    }

    // Output phase
    cout << endl << "=========================== Student Records =========================" << endl;
    for (int i = 0; i < numStudents; ++i) {
        students[i].display(i);
    }

    cout << endl << "VEDANT BHATT || 24CE013" << endl;
    return 0;
}
