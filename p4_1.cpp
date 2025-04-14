/*
==============================================================================
    PROGRAM: Circle Area Management System
    DEVELOPER: VEDANT BHATT
    ID No: 24CE013
    CREATED ON: April 13, 2025
==============================================================================
*/

#include <iostream>
using namespace std;

class Shape
{
protected:
    double radius;

public:
    // Constructor to initialize radius
    Shape(double r = 0)
    {
        radius = r;
    }

    // Function to set radius
    void setRadius(double r)
    {
        radius = r;
    }

    // Function to get radius
    double getRadius() const
    {
        return radius;
    }
};

class Circle : public Shape
{
public:
    // Constructor to initialize radius
    Circle(double r = 0) : Shape(r) {}

    // Function to calculate area of the circle
    double calculateArea() const
    {
        return (22 / 7) * radius * radius; // Area = πr²
    }

    // Function to display radius and area
    void display() const
    {
        cout << "Radius: " << radius << ", Area: " << calculateArea() << endl;
    }
};

int main()
{
    // Demonstrate using a fixed (static) array of circles
    cout << "==================== Static Circle Array ==============" << endl;

    // Creating 3 predefined circles with fixed radius
    Circle circlesStatic[3] = {Circle(2.22), Circle(3.5), Circle(13.0)};

    // Displaying area of each static circle
    for (int i = 0; i < 3; ++i)
    {
        cout << "Circle " << i + 1 << ": ";
        circlesStatic[i].display();
    }

    // Dynamic circle input using static array
    cout << endl
         << "============= Dynamic Number of Circles Using Array =================" << endl;

    int n;
    cout << "Enter number of circles: ";
    cin >> n;

    Circle circlesDynamic[n];

    // Input radius  for each circle
    for (int i = 0; i < n; ++i)
    {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        circlesDynamic[i].setRadius(r); // set radius
    }

    // Display details for each circle
    for (int i = 0; i < n; ++i)
    {
        cout << "Circle " << i + 1 << ": ";
        circlesDynamic[i].display();
    }

    cout << endl
         << "VEDANT BHATT || 24CE013" << endl;

    return 0;
}
