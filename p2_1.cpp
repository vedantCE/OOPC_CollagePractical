#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle
{
    int length;
    int breadth;

public:
    void displayDetail(int i)
    {
        cout << left << setw(15) << i + 1
             << right << setw(10) << length
             << setw(10) << breadth
             << setw(15) << (length * breadth)
             << setw(10) << (2 * (length + breadth)) << endl;
    }

    void perimeter(int i)
    {
        cout << "Perimeter of Rectangle " << i + 1 << " is: " << 2 * (length + breadth) << endl;
    }

    void area(int i)
    {
        cout << "Area of Rectangle " << i + 1 << " is: " << length * breadth << endl;
    }

    void setdimension()
    {
        cout << "Enter length and breadth: ";
        cin >> length >> breadth;
    }

    void updatDimension(int rlength, int rbreadth)
    {
        length = rlength;
        breadth = rbreadth;
    }
};

int main()
{
    int n, choice1, ID, rlength, rbreadth;
    char choice2;
    cout << "Enter number of rectangles: ";
    cin >> n;
    Rectangle dimension[n];
    int count = 0;

menu:
    cout << endl;
    cout << "1. Add Rectangle" << endl;
    cout << "2. Update Rectangle Dimensions" << endl;
    cout << "3. Display Area of All Rectangles" << endl;
    cout << "4. Display Perimeter of All Rectangles" << endl;
    cout << "5. Display All Rectangle Details" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice1;
    cout << endl;

    switch (choice1)
    {
    case 1:
        if (count < n)
        {
        add_rectangle:
            cout << "Enter dimensions for Rectangle " << count + 1 << ": ";
            dimension[count].setdimension();
            count++;

            if (count < n) 
            {
                cout << "Do you want to add another Rectangle? (y/n): ";
                cin >> choice2;
                if (choice2 == 'y')
                {
                    goto add_rectangle;
                }
            }
        }
        else
        {
            cout << "Maximum number of Rectangles added!" << endl;
        }
        goto menu;
        break;

    case 2:
        if (count > 0)
        {
            cout << "Enter ID of the Rectangle to update (1 to " << count << "): ";
            cin >> ID;
            if (ID >= 1 && ID <= count)
            {
                cout << "Enter new dimensions (length breadth): ";
                cin >> rlength >> rbreadth;
                dimension[ID - 1].updatDimension(rlength, rbreadth);
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
        goto menu;
        break;

    case 3:
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                dimension[i].area(i);
            }
        }
        else
        {
            cout << "No Rectangles available to display area!" << endl;
        }
        goto menu;
        break;

    case 4:
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                dimension[i].perimeter(i);
            }
        }
        else
        {
            cout << "No Rectangles available to display perimeter!" << endl;
        }
        goto menu;
        break;

    case 5:
        if (count > 0)
        {
            cout << "|--------------------- Rectangle Details ---------------------|" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << left << setw(15) << "ID"
                 << right << setw(10) << "Length"
                 << setw(10) << "Breadth"
                 << setw(15) << "Area"
                 << setw(10) << "Perimeter" << endl;
            cout << "-------------------------------------------------------------" << endl;

            for (int i = 0; i < count; i++)
            {
                dimension[i].displayDetail(i);
            }

            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
            cout << "Vedant_Bhatt | ID No: 24CE013" << endl;
        }
        else
        {
            cout << "No Rectangles available to display details!" << endl;
        }
        goto menu;
        break;

    case 6:
        cout << "Exiting program..." << endl;
        cout << "Vedant_Bhatt | ID No: 24CE013" << endl;
        return 0;

    default:
        cout << "Invalid choice! Please enter a valid option." << endl;
        goto menu;
    }
}
