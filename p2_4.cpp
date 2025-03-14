/*
===========================================================================
    PROGRAM: Stock Bill System - VMart
    DEVELOPER: Vedant Bhatt
    ID No: 24CE013
    CREATED ON:  February 24, 2025
    LAST UPDATE: March 13, 2025

    Updates:
    - [13-03-2025] Implemented do-while loop instead of goto for better flow.
    - [13-03-2025] Implemented const instead of #define for type safety.
=============================================================================
*/

#include <iostream>
#include <iomanip> // For setw()
#include <conio.h> // For clearing screen
using namespace std;
const int MAX_PRODUCT=50;

// Product Class
class ProductDetail {
    int ProductId;
    string ProductName;
    int ProductQuantity;
    int ProductPrice;
    int UserProductQuantity = 0;
    int TotalPrice = 0;

public:
// Function for adding new product in stock
    void NewProduct() {
        system("CLS");
        cout << " ||--------- New Product Add Portal ---------||" << endl;
        cout << "Enter ID of the Product: ";
        cin >> ProductId;
        cin.ignore();
        cout << "Enter name of the Product: ";
        getline(cin, ProductName);
        cout << "Enter Quantity of the Product: ";
        cin >> ProductQuantity;
        cout << "Enter Price of the Product: ";
        cin >> ProductPrice;
    }

// for purchasing item search function 
    int SearchId(int id) {
        return (id == ProductId);
    }

// Function for updating product quantity in stock
    void UpdateStock() {
        if (ProductQuantity == 0) {
            cout << "Stock is currently zero. Cannot update!" << endl;
            return;
        }
        system("CLS");
        cout << " ||--------- Update Product Stock Portal ---------||" << endl;
        int NewQuantity;
        cout << "Enter new stock quantity: ";
        cin >> NewQuantity;
        ProductQuantity += NewQuantity;
    }

// Function for displayin stock detail to manager
    void DisplayStockDetail() {
        cout << left << setw(15) << ProductId
             << setw(15) << ProductName
             << setw(15) << ProductQuantity
             << setw(15) << ProductPrice << endl;
    }
// quantity mange in stock 
    void AddQuantity() {
        if (ProductQuantity > 0) {
            UserProductQuantity++;
            ProductQuantity--;
            TotalPrice = ProductPrice * UserProductQuantity;
        } else {
            cout << "Product is not available at present. Sorry for the inconvenience." << endl;
        }
    }

// Function for total price calculation
    int GetTotalPrice() {
        return TotalPrice;
    }

// Function to display bill for customer
    void DisplayBill() {
        if (UserProductQuantity > 0) {
            cout << left << setw(15) << ProductId
                 << setw(15) << ProductName
                 << setw(15) << UserProductQuantity
                 << setw(15) << TotalPrice << endl;
        }
    }
};

int main() {
    int Choice1, Choice2, NoOfProduct = 0, Id, GrandTotal = 0, BillId = 1001;
    char Choice3;
    ProductDetail Product[MAX_PRODUCT];

    do {
        system("CLS");
        cout << " ||--------- Welcome to VMart ---------||" << endl;
        cout << "Press 1. Managing Stock" << endl;
        cout << "Press 2. Purchase item" << endl;
        cout << "Press 0. Exit" << endl;
        cout << "Enter your choice here: ";
        cin >> Choice1;

        switch (Choice1) {
        case 1:
            do {
                cout << "\n ||--------- Stock Management Portal ---------||" << endl;
                cout << "Press 1. Add new product" << endl;
                cout << "Press 2. Update Stock Quantity" << endl;
                cout << "Press 3. Display stock details" << endl;
                cout << "Press 0. Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> Choice2;

                switch (Choice2) {
                case 1:
                    do {
                        Product[NoOfProduct].NewProduct();
                        NoOfProduct++;
                        cout << "If you want to add another item press y else n: ";
                        cin >> Choice3;
                    } while (Choice3 == 'y');
                    break;
                case 2:
                    cout << "Enter ID of the product: ";
                    cin >> Id;
                    for (int i = 0; i < NoOfProduct; i++) {
                        if (Product[i].SearchId(Id)) {
                            Product[i].UpdateStock();
                            break;
                        }
                    }
                    break;
                case 3:
                    system("CLS");
                    cout << " ||---------------- Stock Details ----------------||" << endl;
                    cout << left << setw(15) << "Product ID"
                         << setw(15) << "Name"
                         << setw(15) << "Quantity"
                         << setw(15) << "Price" << endl;
                    for (int i = 0; i < NoOfProduct; i++) {
                        Product[i].DisplayStockDetail();
                    }
                    system("PAUSE");
                    break;
                }
            } while (Choice2 != 0);
            break;

        case 2:
            do {
                cout << "\n ||--------- Welcome to Bill Portal ---------||" << endl;
                cout << "Press 1. Buy product" << endl;
                cout << "Press 2. Display Bill details" << endl;
                cout << "Press 0. Back to Main Menu" << endl;
                cout << "Enter your choice here: ";
                cin >> Choice2;

                switch (Choice2) {
                case 1:
                    do {
                        cout << "Enter Product ID: ";
                        cin >> Id;
                        for (int i = 0; i < NoOfProduct; i++) {
                            if (Product[i].SearchId(Id)) {
                                Product[i].AddQuantity();
                                break;
                            }
                        }
                        cout << "If you want to buy another item press y else n: ";
                        cin >> Choice3;
                    } while (Choice3 == 'y');
                    break;
                case 2:
                    system("CLS");
                    cout << " ||---------------------- VMart ----------------------||" << endl;
                    cout << "Bill ID: " << BillId << endl;
                    cout << left << setw(15) << "Product ID"
                         << setw(15) << "Name"
                         << setw(15) << "Quantity"
                         << setw(15) << "Total Price" << endl;
                    for (int i = 0; i < NoOfProduct; i++) {
                        Product[i].DisplayBill();
                        GrandTotal += Product[i].GetTotalPrice();
                    }
                    cout<<"--------------------------------------------------------------";
                    cout << left << setw(45) << "Grand Total: " << GrandTotal << endl;
                    cout << "   --x-- Thanks For Visiting --x--" << endl;
                    cout << "Vedant_Bhatt | ID No: 24CE013" << endl;
                    system("PAUSE");
                    break;
                }
            } while (Choice2 != 0);
            break;
        }
    } while (Choice1 != 0);
    return 0;
}
