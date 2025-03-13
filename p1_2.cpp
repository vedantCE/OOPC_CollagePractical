/*
==============================================
    PROGRAM: VMart Billing System
    AIM: To manage a simple product billing system
    DEVELOPER: Vedant Bhatt
    CREATED ON: February 21,2025
    LAST UPDATED: March 12, 2025
==============================================
*/

#include <iostream>
#include <iomanip>  // For use of setw
#include <conio.h>  // For using clear screen
using namespace std;

// Product class to store product details
class Product
{
    int product_id;
    string product_name;
    int product_price;
    int total_price;
    int quantity;

public:
    // Function to display product details in bill format
    void display_detail()
    {
        cout << left << setw(15) << product_name 
             << right << setw(10) << product_price 
             << setw(10) << quantity 
             << setw(15) << total_price << endl;
    }

    // Function to check if product ID matches
    int search_product(int id)
    {
        if (id == product_id)
            return 1;
        return 0;
    }

    // Function to add quantity to an existing product
    void add_quantity()
    {
        quantity++;
        total_price = product_price * quantity;
        cout << "Product ID " << product_id << " found! Added to your basket. New quantity: " 
             << quantity << "  Total Price: " << total_price << endl;
    }

    // Function to add a new product
    void add_product(int id)
    {
        cout << "New Product Found!!" << endl
             << "Enter product name: ";
        cin >> product_name;
        cout << "Enter product price: ";
        cin >> product_price;
        product_id = id;
        quantity = 1;
        total_price = product_price;
    }

    // Function to get the total price of a product
    int get_total_price()
    {
        return total_price;
    }
};

// Main Function
int main()
{
    Product product_list[50];
    int num_products = 0, product_id, grand_total = 0;
    char choice;

menu:
    cout << "Enter product ID: ";
    cin >> product_id;

    // Searching for existing product
    for (int i = 0; i < num_products; i++)
    {
        if (product_list[i].search_product(product_id) == 1)
        {
            product_list[i].add_quantity();
            goto continue_shopping;
        }
    }

    // Adding a new product if not found
    product_list[num_products].add_product(product_id);
    num_products++;

continue_shopping:
    cout << "If you want to add another item press y else n: ";
    cin >> choice;
    if (choice == 'y')
    {
        goto menu;
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

        for (int i = 0; i < num_products; i++)
        {
            product_list[i].display_detail();
            grand_total += product_list[i].get_total_price();
        }

        cout << "---------------------------------------------------" << endl;
        cout << left << setw(35) << "Grand Total:" << grand_total << endl;
        cout << endl << "          --x-- Thanks For Visiting --x--         " << endl;
        cout << endl << "Vedant Bhatt" << " " << "ID No: 24CE013" << endl;
    }
    return 0;
}
