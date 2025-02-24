#include <iostream>
#include <iomanip> // For setw()
#include <conio.h> // For clearing screen
using namespace std;
#define MAX_PRODUCT 50

// Product Class
class ProductDetail {
    int ProductId;
    string ProductName;
    int ProductQuantity;
    int ProductPrice;
    int UserProductQuantity = 0;
    int TotalPrice = 0;

public:
    void NewProduct() {
        system("CLS"); // Clear screen
        cout << " ||--------- New Product Add Portal ---------||" << endl
             << endl;
        cout << "Enter ID of the Product: ";
        cin >> ProductId;
        cin.ignore(); // Fix for multi-word product name
        cout << "Enter name of the Product: ";
        getline(cin, ProductName);
        cout << "Enter Quantity of the Product: ";
        cin >> ProductQuantity;
        cout << "Enter Price of the Product: ";
        cin >> ProductPrice;
    }

    int SearchId(int id) {
        return (id == ProductId);
    }

    void UpdateStock() {
        system("CLS");
        cout << " ||--------- Update Product Stock Portal ---------||" << endl
             << endl;
        int NewQuantity;
        cout << "Enter new stock quantity: ";
        cin >> NewQuantity;
        ProductQuantity += NewQuantity;
    }

    void DisplayStockDetail() {
        cout << left << setw(15) << ProductId
             << setw(15) << ProductName
             << setw(15) << ProductQuantity
             << setw(15) << ProductPrice << endl;
    }

    void AddQuantity() {
        if (ProductQuantity > 0) {
            UserProductQuantity++;
            ProductQuantity--;
            TotalPrice = ProductPrice * UserProductQuantity;
        } else {
            cout << "Product is not available at present. Sorry for the inconvenience." << endl;
        }
    }

    int GetTotalPrice() {
        return TotalPrice;
    }

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
    int Choice1, Choice2, Choice3, NoOfProduct = 0, Id, GrandTotal = 0, BillId = 1001;
    char Choice4, Choice5;
    ProductDetail Product[MAX_PRODUCT];

MainMenu:
    system("CLS");
    cout << " ||--------- Welcome to VMart ---------||" << endl;
    cout << "Press 1. Managing Stock" << endl;
    cout << "Press 2. Purchase item" << endl;
    cout << "Press 0. Exit" << endl;
    cout << "Enter your choice here: ";
    cin >> Choice1;

    if (Choice1 == 1) {
    StockMenu:
        cout << endl
             << endl
             << " ||--------- Stock Management Portal ---------||" << endl;
        cout << "Press 1. Add new product" << endl;
        cout << "Press 2. Update Stock Quantity" << endl;
        cout << "Press 3. Display stock details" << endl;
        cout << "Press 0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> Choice2;

        switch (Choice2) {
        case 1:
        ManagerMenu:
            Product[NoOfProduct].NewProduct();
            NoOfProduct++;
            cout << "If you want to add another item press y else n: ";
            cin >> Choice5;
            if (Choice5 == 'y') {
                goto ManagerMenu;
            } else {
                goto StockMenu;
            }
        case 2:
        StockUpdate:
            cout << "Enter ID of the product: ";
            cin >> Id;
            for (int i = 0; i < NoOfProduct; i++) {
                if (Product[i].SearchId(Id)) {
                    Product[i].UpdateStock();
                    goto StockMenu;
                }
            }
            cout << "Invalid ID! Try again." << endl;
            goto StockUpdate;
        case 3:
            system("CLS");
            cout << " ||---------------- Stock Details ----------------||" << endl;
            cout << left << setw(15) << "Product ID"
                 << setw(15) << "Name"
                 << setw(15) << "Quantity"
                 << setw(15) << "Price" << endl;
            cout << "--------------------------------------------------------" << endl;
            for (int i = 0; i < NoOfProduct; i++) {
                Product[i].DisplayStockDetail();
            }
            cout << "--------------------------------------------------------" << endl;
            system("PAUSE");
            goto StockMenu;
        case 0:
            goto MainMenu;
        default:
            cout << "Invalid choice! Try again." << endl;
            goto StockMenu;
        }
    } else if (Choice1 == 2) {
    PurchaseMenu:
        cout << endl
             << endl
             << " ||--------- Welcome to Bill Portal ---------||" << endl
             << endl;
        cout << "Press 1. Buy product" << endl;
        cout << "Press 2. Display Bill details" << endl;
        cout << "Press 0. Back to Main Menu" << endl;
        cout << "Enter your choice here: ";
        cin >> Choice3;

        switch (Choice3) {
        case 1:
            if (NoOfProduct == 0) {
                cout << "No stock available at the moment!" << endl;
                system("PAUSE");
                goto PurchaseMenu;
            }

        User:
            cout << "Enter Product ID: ";
            cin >> Id;
            for (int i = 0; i < NoOfProduct; i++) {
                if (Product[i].SearchId(Id)) {
                    Product[i].AddQuantity();
                    cout << "If you want to add another item press y else n: ";
                    cin >> Choice4;
                    if (Choice4 == 'y') {
                        goto User;
                    } else {
                        goto PurchaseMenu;
                    }
                }
            }
            cout << "Invalid ID! Try again." << endl;
            goto User;

        case 2:
            system("CLS");
            cout << " ||---------------------- VMart ----------------------||" << endl;
            cout << "Bill ID: " << BillId << endl;
            cout << "------------------------------------------------------" << endl;
            cout << left << setw(15) << "Product ID"
                 << setw(15) << "Name"
                 << setw(15) << "Quantity"
                 << setw(15) << "Total Price" << endl;
            cout << "------------------------------------------------------" << endl;

            for (int i = 0; i < NoOfProduct; i++) {
                Product[i].DisplayBill();
                GrandTotal += Product[i].GetTotalPrice();
            }

            cout << "------------------------------------------------------" << endl;
            cout << left << setw(45) << "Grand Total: " << GrandTotal << endl;
            cout << "------------------------------------------------------" << endl;
            cout << "   --x-- Thanks For Visiting --x--" << endl;
            cout << endl
                 << "Vedant_Bhatt | ID No: 24CE013" << endl;
            system("PAUSE");
            goto PurchaseMenu;

        case 0:
            goto MainMenu;

        default:
            cout << "Invalid choice! Try again." << endl;
            goto PurchaseMenu;
        }
    } else if (Choice1 == 0) {
        system("CLS");
        cout << "Exiting the program..." << endl;
        return 0;
    } else {
        cout << "Invalid choice! Try again." << endl;
        goto MainMenu;
    }
}
