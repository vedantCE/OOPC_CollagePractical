#include <iostream>
#include <iomanip>  // For use of setw
#include <conio.h> // For using of clear screen 
using namespace std;

class Product
{
    int pid;
    string pname;
    int pprice;
    int totalPrice;
    int quantity;

public:
    void displayDetail()
    {
        cout << left << setw(15) << pname 
     << right << setw(10) << pprice 
     << setw(10) << quantity 
     << setw(15) << totalPrice << endl;

    }

    int searchProduct(int id)
    {
        return (id == pid);
    }

    void addQuantity()
    {
        quantity++;
        totalPrice = pprice * quantity;
        cout << "Product ID " << pid << " found! Added to your basket. New quantity: " << quantity << "  Total Price: " << totalPrice << endl;
    }

    void addProduct(int id)
    {
        cout << "New Product Found!!" << endl
             << "Enter product name: ";
        cin >> pname;
        cout << "Enter product price: ";
        cin >> pprice;
        pid = id;
        quantity = 1;
        totalPrice = pprice;
    }

    int getTotalPrice()
    {
        return totalPrice;
    }
};

int main()
{
    Product p[50];
    int noOfProduct = 0, id, grandTotal = 0;
    char choice;

menu:
    cout << "Enter product id: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i < noOfProduct; i++)
    {
        if (p[i].searchProduct(id))
        {
            p[i].addQuantity();
            found = true;
            break;
        }
    }

    if (!found)
    {
        p[noOfProduct].addProduct(id);
        noOfProduct++;
    }

    cout << "If you want to add another item press y else n: ";
    cin >> choice;
    if (choice == 'y')
    {
        goto menu;
    }
    else
    {
        system("CLS"); // For clearing screen
        cout<<"|---------------------VMart---------------------------------|"<<endl;
        cout <<endl<< "Final Bill:"<<endl;
        cout << "---------------------------------------------------"<<endl;
        cout << left << setw(15) << "Name" 
        << right << setw(10) << "Price" 
        << setw(10) << "Quantity" 
        << setw(15) << "Total Price" << endl;
   
        cout << "---------------------------------------------------"<<endl;
        for (int i = 0; i < noOfProduct; i++)
        {

            p[i].displayDetail();
            grandTotal += p[i].getTotalPrice();
        }
        cout << "---------------------------------------------------"<<endl;
        cout << left << setw(35) << "Grand Total:" << grandTotal << endl;
        cout<<endl<<"          --x--Thanks For Visiting--x--         "<<endl;
        cout<<endl<<"Vedant_Bhatt"<<" "<<"ID No:24CE013"<<endl;

    }
    return 0;
}