// Problem Statement 1: "Smart Billing System for a Tech Store"
// ?? Objective:
// Design a C++ program to manage customer purchases in a tech store, including item management, billing, and persistent record-keeping.

// ?? Requirements:
// 1. OOP Design
// Create a class Item with attributes:

// itemID, itemName, price, stockQuantity

// Create a class Bill with:

// billID, customerName, list of purchased items

// 2. Operator Overloading
// Overload + to add an item to the bill

// Overload << to display the bill details

// 3. Exception Handling
// Throw exceptions for:

// Negative price or quantity

// Attempt to purchase more than available stock

// Empty bill generation

// 4. File Handling
// Save all bills to bills.txt

// Load previous bills at startup

// Append new bills without overwriting



// More accurate code after fixing issues

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

class Items
{
    int iid;
    float price;
    string iname;
    int stock;
    int quantity;

public:
    Items()
    {
        iid = 0;
        iname = "";
        price = 0.0;
        stock = 0;
        quantity = 0;
    }

    Items(int iid, string iname, float price, int stock, int quantity)
    {
        this->iid = iid;
        this->iname = iname;
        this->price = price;
        this->stock = stock;
        this->quantity = quantity;
    }

    void getarr(Items arrItems[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int iid;
            string name;
            float price;
            int stock;
            int quantity;

            cout << "Enter Your " << i + 1 << " item " << endl;
            cout << "Enter Item Id : ";
            cin >> iid;
            cout << "Enter Item Name : ";
            cin >> name;
            cout << "Enter Item Price : ";
            cin >> price;
            cout << "Enter Items InStock : ";
            cin >> stock;
            cout << "Enter Items Quantity : ";
            cin >> quantity;
            arrItems[i] = Items(iid, name, price, stock, quantity);
        }
    }

    void display()
    {
        cout << "Item ID : " << iid << endl;
        cout << "Item Name : " << iname << endl;
        cout << "Price : " << price << endl;
        cout << "Stock : " << stock << endl;
        cout << "Quantity : " << quantity << endl;
        cout << "---------------------" << endl;

        ofstream my_file("bill2.txt", ios::app);
        my_file << "-------------------------" << endl;
        my_file << "Item Id : " << iid << endl;
        my_file << "Item Name : " << iname << endl;
        my_file << "Item Price : " << price << endl;
        my_file << "Items in Stock : " << stock << endl;
        my_file << "Items Quantity : " << quantity << endl;
        my_file << "-------------------------" << endl;
        my_file.close();
    }

    void errorhandler(Items *t)
    {
        if (t->quantity <= 0)
        {
            throw runtime_error("Quantity must not 0 or less.");
        }
        if (t->quantity > t->stock)
        {
            throw runtime_error("Quantity exceeds stock.");
        }
        if (t->price < 0)
        {
            cout << t->price;
            throw runtime_error("Price is less than 0.");
        }
    }

    Items operator+(Items &p)
    {

        Items temp;

        p.price = p.price * p.quantity;
        temp.price = this->price + p.price;
        errorhandler(&p);

        return temp;
    }

    void displaySum()
    {

        ofstream my_file("bill2.txt", ios::app);
        my_file << "Total Sum : " << price << endl;
        my_file << "-------------------------" << endl;
        my_file << endl;
        my_file.close();
        cout << "Total Sum : " << price << endl;
    }
};

class Bill : public Items
{
    int bId;
    string cname;
    int n;
    Items *array[];

public:
    Bill()
    {
        bId = 0;
        cname = "";
        n = 0;
        *array = new Items[n];
        for (int i = 0; i < n; i++)
        {
            *array[i] = Items();
        }
    }

    Bill(int bId, string cname, int n, Items *obj)
    {
        this->bId = bId;
        this->cname = cname;
        this->n = n;
        *array = new Items[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = new Items();
            array[i] = obj;
        }
    }

    void printItems(Items arrItems[], int n)
    {

        ofstream my_file("bill2.txt", ios::app);
        my_file << "Purchased Items" << endl;
        my_file.close();

        cout << "Your Items are " << endl;
        for (int i = 0; i < n; i++)
        {
            arrItems[i].display();
            cout << endl;
        }
    }

    void displayBill()
    {
        cout << "---------------------" << endl;
        cout << "Billing Details" << endl;
        cout << "Bill Id: " << bId << endl;
        cout << "Customer Name: " << cname << endl;

        ofstream my_file("bill2.txt", ios::app);
        my_file << "Bill Id : " << bId << endl;
        my_file << "Customer Name : " << cname << endl;
        my_file << "---------------------" << endl;
        my_file.close();
    }

    void sumPrice(Items arrItems[], int n, Items sum)
    {
        for (int i = 0; i < n; i++)
        {
            sum = sum + arrItems[i];        // sum = sum + arrItems[i];  // sum.operator+(arrItems[i]);
        }

        sum.displaySum();
    }
};

void openBill()
{
    ifstream my_file("bill2.txt");
    if (!my_file.is_open())
    {
        cout << "File can't be opened" << endl;
    }
    else
    {
        string line;
        cout << "File is opened successfully" << endl;
        while (!my_file.eof())
        {
            getline(my_file, line);
            cout << line << endl;
        }
        my_file.close();
        cout<<"Previous Bills"<<endl;
    }
}

int main()
{
    int n;
    cout << "Enter the no. of elements: ";

    cin >> n;

    if (n == 0)
    {
        throw runtime_error("Can't generate bill due to invalid entries");
    }

    openBill();

    Items sum;
    Items arrItems[n];

    Items *obj;
    obj = new Items();
    obj->getarr(arrItems, n);

    Bill b1(8, "Aman", n, obj);

    b1.displayBill();

    b1.printItems(arrItems, n);
    b1.sumPrice(arrItems, n, sum);

    return 0;
}