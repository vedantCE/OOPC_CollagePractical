/*
==============================================
    PROGRAM: Simple Reactangle  Management System
    AIM: To perform basic Rectangle operations like Updat Dimenssion,Calculat Area,Calculate Perimeter,
         Display Detail.
    DEVELOPER: Vedant Bhatt
    LAST UPDATED: April 19, 2025
==============================================
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle
{
    int Length;
    int Breadth;

public:
    void DisplayDetail(int I)
    {
        cout << left << setw(15) << I + 1
             << right << setw(10) << Length
             << setw(10) << Breadth
             << setw(15) << (Length * Breadth)
             << setw(10) << (2 * (Length + Breadth)) << endl;
    }

    void Perimeter(int I)
    {
        cout << "Perimeter of Rectangle " << I + 1 << " is: " << 2 * (Length + Breadth) << endl;
    }

    void Area(int I)
    {
        cout << "Area of Rectangle " << I + 1 << " is: " << Length * Breadth << endl;
    }

    void SetDimension()
    {
        cout << "Enter length and breadth: ";
        cin >> Length >> Breadth;
    }

    void UpdateDimension(int RLength, int RBreadth)
    {
        Length = RLength;
        Breadth = RBreadth;
    }
};

int main()
{
    int N, Choice1, Id, RLength, RBreadth;
    char Choice2;
    cout << "Enter number of rectangles: ";
    cin >> N;
    Rectangle Dimension[N];
    int Count = 0;

Menu:
    cout << endl;
    cout << "1. Add Rectangle" << endl;
    cout << "2. Update Rectangle Dimensions" << endl;
    cout << "3. Display Area of All Rectangles" << endl;
    cout << "4. Display Perimeter of All Rectangles" << endl;
    cout << "5. Display All Rectangle Details" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> Choice1;
    cout << endl;

    switch (Choice1)
    {
    case 1:
        if (Count < N)
        {
        AddRectangle:
            cout << "Enter dimensions for Rectangle " << Count + 1 << ": ";
            Dimension[Count].SetDimension();
            Count++;

            if (Count < N) 
            {
                cout << "Do you want to add another Rectangle? (y/n): ";
                cin >> Choice2;
                if (Choice2 == 'y')
                {
                    goto AddRectangle;
                }
            }
        }
        else
        {
            cout << "Maximum number of Rectangles added!" << endl;
        }
        goto Menu;
        break;

    case 2:
        if (Count > 0)
        {
            cout << "Enter ID of the Rectangle to update (1 to " << Count << "): ";
            cin >> Id;
            if (Id >= 1 && Id <= Count)
            {
                cout << "Enter new dimensions (length breadth): ";
                cin >> RLength >> RBreadth;
                Dimension[Id - 1].UpdateDimension(RLength, RBreadth);
            }
            else
            {
                cout << "Invalid ID!" << endl;
            }
        }
        else
        {
            cout << "No Rectangles available to update!" << endl;
        }
        goto Menu;
        break;

    case 3:
        if (Count > 0)
        {
            for (int I = 0; I < Count; I++)
            {
                Dimension[I].Area(I);
            }
        }
        else
        {
            cout << "No Rectangles available to display area!" << endl;
        }
        goto Menu;
        break;

    case 4:
        if (Count > 0)
        {
            for (int I = 0; I < Count; I++)
            {
                Dimension[I].Perimeter(I);
            }
        }
        else
        {
            cout << "No Rectangles available to display perimeter!" << endl;
        }
        goto Menu;
        break;

    case 5:
        if (Count > 0)
        {
            cout << "|--------------------- Rectangle Details ---------------------|" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << left << setw(15) << "ID"
                 << right << setw(10) << "Length"
                 << setw(10) << "Breadth"
                 << setw(15) << "Area"
                 << setw(10) << "Perimeter" << endl;
            cout << "-------------------------------------------------------------" << endl;

            for (int I = 0; I < Count; I++)
            {
                Dimension[I].DisplayDetail(I);
            }

            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
            cout << "Vedant_Bhatt | ID No: 24CE013" << endl;
        }
        else
        {
            cout << "No Rectangles available to display details!" << endl;
        }
        goto Menu;
        break;

    case 6:
        cout << "Exiting program..." << endl;
        cout << "Vedant_Bhatt | ID No: 24CE013" << endl;
        return 0;

    default:
        cout << "Invalid choice! Please enter a valid option." << endl;
        goto Menu;
    }
}
