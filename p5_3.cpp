#include<iostream>
#include<stack>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point operator+ (Point &c)
    {
        Point ans(0, 0);
        ans.x = x + c.x;
        ans.y = y + c.y;
        return ans;
    }

    Point operator- (Point &c)
    {
        Point ans(0, 0);
        ans.x = x - c.x;
        ans.y = y - c.y;
        return ans;
    }

    int operator== (Point &c)
    {
        return (x == c.x && y == c.y) ? 1 : 0;
    }

    void print()
    {
        cout << "(" << x << ", " << y << ")\n";
    }
};

int main()
{
    int operation;
    int x1, y1, x2, y2;

    cout << "Enter coordinates for Point 1 (x y): ";
    cin >> x1 >> y1;
    Point c1(x1, y1);

    cout << "Enter coordinates for Point 2 (x y): ";
    cin >> x2 >> y2;
    Point c2(x2, y2);


menu:
    cout << "Select operation to perform:"<<endl;
    cout << "1. Add Points:"<<endl;
    cout << "2. Subtract Points:"<<endl;
    cout << "3. Check if Points are Equal:"<<endl;
    cout << "4. Exit"<<endl;
    cout << "Enter your choice (1/2/3/4/5): ";
    cin >> operation;

    switch (operation)
    {
    case 1:

        Point c3 = c1 + c2;
        cout << "Result of addition: ";
        c3.print();

        goto menu;

    case 2:

        Point c4 = c1 - c2;
        cout << "Result of subtraction: ";
        c4.print();
        goto menu;

    case 3:

        if (c1 == c2)
        {
            cout << "The points are equal.\n";
        }
        else
        {
            cout << "The points are not equal.\n";
        }
        goto menu;

    case 4:
        cout << "Exiting program.\n";
        return 0;
    default:
        cout << "Invalid operation choice. Please select 1, 2, 3, 4, or 5.\n";
        goto menu;
    }


    return 0;
}
