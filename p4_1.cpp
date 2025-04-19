/*
==================================================================================== 
    PROGRAM: Circle Area Management System
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON: April 13, 2025

    FEATURES:
    - Demonstrates use of classes and inheritance in C++
    - Supports creation and display of circle objects
    - Calculates area of a circle based on its radius
    - Supports both static and dynamic allocation for circle objects
==================================================================================== 
*/

#include <iostream>
using namespace std;

class Shape
{
protected:
    double Radius; 

public:
    // Constructor to initialize radius
    Shape(double R = 0)
    {
        Radius = R; 
    }

    // Function to set the radius of the shape
    void SetRadius(double R)
    {
        Radius = R; 
    }

    // Function to get the radius of the shape
    double GetRadius() const
    {
        return Radius; 
    }
};



class Circle : public Shape
{
public:
   
    Circle(double R = 0) : Shape(R) {}

    
    double CalculateArea() const
    {
        return (22 / 7) * Radius * Radius; // Calculate and return area
    }

    // Function to display the radius and area of the circle
    void Display() const
    {
        cout << "Radius: " << Radius << ", Area: " << CalculateArea() << endl;
    }
};



int main()
{
    // Demonstrate using a fixed (static) array of circles
    cout << "==================== Static Circle Array ==============" << endl;

    // Creating 3 predefined circles with fixed radius
    Circle CirclesStatic[3] = {Circle(2.22), Circle(3.5), Circle(13.0)};

    // Displaying area of each static circle
    for (int I = 0; I < 3; ++I)
    {
        cout << "Circle " << I + 1 << ": ";
        CirclesStatic[I].Display();
    }

    // Dynamic circle input using static array
    cout << endl
         << "============= Dynamic Number of Circles Using Array =================" << endl;

    int N;
    cout << "Enter number of circles: ";
    cin >> N; 

    Circle CirclesDynamic[N]; 

    // Input radius for each circle
    for (int I = 0; I < N; ++I)
    {
        double R;
        cout << "Enter radius for circle " << I + 1 << ": ";
        cin >> R; 
        CirclesDynamic[I].SetRadius(R); 
    }

    // Display details for each circle
    for (int I = 0; I < N; ++I)
    {
        cout << "Circle " << I + 1 << ": ";
        CirclesDynamic[I].Display(); 
    }

    cout << endl
         << "VEDANT BHATT || 24CE013" << endl; 

    return 0;
}
