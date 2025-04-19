/*
==============================================
    PROGRAM: VMart Billing System
    AIM: To manage a simple product billing system
    DEVELOPER: Vedant Bhatt
    CREATED ON: February 21,2025
    LAST UPDATED: April 19, 2025
==============================================
*/

#include <iostream>
#include <iomanip>  // For use of setw
#include <conio.h>  // For using clear screen
using namespace std;

// Product class to store product details
class Product
{
    int ProductId;
    string ProductName;
    int ProductPrice;
    int TotalPrice;
    int Quantity;

public:
    // Function to display product details in bill format
    void DisplayDetail()
    {
        cout << left << setw(15) << ProductName 
             << right << setw(10) << ProductPrice 
             << setw(10) << Quantity 
             << setw(15) << TotalPrice << endl;
    }

    // Function to check if product ID matches
    int SearchProduct(int Id)
    {
        if (Id == ProductId)
            return 1;
        return 0;
    }

    // Function to add quantity to an existing product
    void AddQuantity()
    {
        Quantity++;
        TotalPrice = ProductPrice * Quantity;
        cout << "Product ID " << ProductId << " found! Added to your basket. New quantity: " 
             << Quantity << "  Total Price: " << TotalPrice << endl;
    }

    // Function to add a new product
    void AddProduct(int Id)
    {
        cout << "New Product Found!!" << endl
             << "Enter product name: ";
        cin >> ProductName;
        cout << "Enter product price: ";
        cin >> ProductPrice;
        ProductId = Id;
        Quantity = 1;
        TotalPrice = ProductPrice;
    }

    // Function to get the total price of a product
    int GetTotalPrice()
    {
        return TotalPrice;
    }
};

// Main Function
int main()
{
    Product ProductList[50];
    int NumProducts = 0, ProductId, GrandTotal = 0;
    char Choice;

Menu:
    cout << "Enter product ID: ";
    cin >> ProductId;

    // Searching for existing product
    for (int i = 0; i < NumProducts; i++)
    {
        if (ProductList[i].SearchProduct(ProductId) == 1)
        {
            ProductList[i].AddQuantity();
            goto ContinueShopping;
        }
    }

    // Adding a new product if not found
    ProductList[NumProducts].AddProduct(ProductId);
    NumProducts++;

ContinueShopping:
    cout << "If you want to add another item press y else n: ";
    cin >> Choice;
    if (Choice == 'y')
    {
        goto Menu;
    }
    else
    {
        system("CLS"); // For clearing screen
        cout << "|--------------------- VMart ---------------------------------|" << endl;
        cout << endl << "Final Bill:" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << left << setw(15) << "Name" 
             << right << setw(10) << "Price" 
             << setw(10) << "Quantity" 
             << setw(15) << "Total Price" << endl;
        cout << "---------------------------------------------------" << endl;

        for (int i = 0; i < NumProducts; i++)
        {
            ProductList[i].DisplayDetail();
            GrandTotal += ProductList[i].GetTotalPrice();
        }

        cout << "---------------------------------------------------" << endl;
        cout << left << setw(35) << "Grand Total:" << GrandTotal << endl;
        cout << endl << "          --x-- Thanks For Visiting --x--         " << endl;
        cout << endl << "Vedant Bhatt" << " " << "ID No: 24CE013" << endl;
    }
    return 0;
}
