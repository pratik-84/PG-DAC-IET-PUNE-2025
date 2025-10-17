#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept> // For standard exceptions

using namespace std;

// 1. OOP Design
class Item {
private:
    int itemID;
    string itemName;
    double price;
    int stockQuantity;
public:
    Item(int id = 0, const string& name = "", double p = 0.0, int qty = 0)
        : itemID(id), itemName(name), price(p), stockQuantity(qty) {
        if (p < 0 || qty < 0) {
            throw invalid_argument("Error: Negative value not allowed for price or quantity.");
        }
    }

    // Getters and setters
    int getID() const { return itemID; }
    string getName() const { return itemName; }
    double getPrice() const { return price; }
    int getStock() const { return stockQuantity; }

    void decreaseStock(int quantity) {
        if (stockQuantity < quantity) {
            throw runtime_error("Error: Not enough stock for item: " + itemName);
        }
        stockQuantity -= quantity;
    }

    void increaseStock(int quantity) {
        stockQuantity += quantity;
    }

    // Friend function for file I/O
    friend ostream& operator<<(ostream& os, const Item& item);
    friend istream& operator>>(istream& is, Item& item);
};

// 1. OOP Design (cont.)
class Bill {
private:
    static int nextBillID;
    int billID;
    string customerName;
    vector<pair<Item, int>> purchasedItems; // pair of (Item, quantity)
public:
    Bill(const string& name = "") : customerName(name) {
        billID = nextBillID++;
    }

    // 2. Operator Overloading: Overload + to add an item to the bill
    void operator+(const pair<Item, int>& purchase) {
        purchasedItems.push_back(purchase);
    }

    // 2. Operator Overloading: Overload << to display the bill details
    friend ostream& operator<<(ostream& os, const Bill& bill);

    int getID() const { return billID; }
    string getCustomerName() const { return customerName; }
    const vector<pair<Item, int>>& getPurchasedItems() const { return purchasedItems; }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& purchase : purchasedItems) {
            total += purchase.first.getPrice() * purchase.second;
        }
        return total;
    }

    void generateBill() const {
        if (purchasedItems.empty()) {
            throw logic_error("Error: Cannot generate an empty bill.");
        }
    }
};

int Bill::nextBillID = 1;

// Overloaded << for Item
ostream& operator<<(ostream& os, const Item& item) {
    os << item.itemID << "," << item.itemName << "," << item.price << "," << item.stockQuantity;
    return os;
}

// Overloaded >> for Item
istream& operator>>(istream& is, Item& item) {
    string line;
    if (getline(is, line)) {
        stringstream ss(line);
        string idStr, name, priceStr, qtyStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        getline(ss, qtyStr, ',');

        item.itemID = stoi(idStr);
        item.itemName = name;
        item.price = stod(priceStr);
        item.stockQuantity = stoi(qtyStr);
    }
    return is;
}

// Overloaded << for Bill
ostream& operator<<(ostream& os, const Bill& bill) {
    os << "------------------------------------------\n";
    os << "Bill ID: " << bill.billID << "\n";
    os << "Customer Name: " << bill.customerName << "\n";
    os << "------------------------------------------\n";
    os << "Item\t\tQty\tPrice\tTotal\n";
    os << "------------------------------------------\n";
    for (const auto& purchase : bill.purchasedItems) {
        os << purchase.first.getName() << "\t\t" << purchase.second << "\t"
           << purchase.first.getPrice() << "\t" << (purchase.first.getPrice() * purchase.second) << "\n";
    }
    os << "------------------------------------------\n";
    os << "Total: " << bill.calculateTotal() << "\n";
    os << "------------------------------------------\n";
    return os;
}

// File Handling functions
void saveBillToFile(const Bill& bill) {
    ofstream file("bills.txt", ios::app); // Append mode
    if (file.is_open()) {
        file << "Bill ID: " << bill.getID() << "\n";
        file << "Customer Name: " << bill.getCustomerName() << "\n";
        file << "Purchased Items:\n";
        for (const auto& purchase : bill.getPurchasedItems()) {
            file << purchase.first.getID() << "," << purchase.first.getName() << ","
                 << purchase.first.getPrice() << "," << purchase.second << "\n";
        }
        file << "Total: " << bill.calculateTotal() << "\n";
        file << "------------------------------------------\n";
        file.close();
    } else {
        cerr << "Error: Unable to open bills.txt for writing.\n";
    }
}

void loadPreviousBills() {
    ifstream file("bills.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    } else {
        cout << "No previous bills found.\n";
    }
}

int main() {
    cout << "Loading previous billing records...\n";
    loadPreviousBills();
    cout << "\n";

    // Create some sample items
    vector<Item> inventory;
    try {
        inventory.push_back(Item(101, "Laptop", 1200.0, 10));
        inventory.push_back(Item(102, "Mouse", 25.0, 50));
        inventory.push_back(Item(103, "Keyboard", 75.0, 30));
        inventory.push_back(Item(104, "Monitor", 300.0, 15));
        // inventory.push_back(Item(105, "Negative Price Item", -10.0, 5)); // This would throw an exception
    } catch (const invalid_argument& e) {
        cerr << e.what() << "\n";
    }

    cout << "Welcome to the Tech Store!\n\n";

    try {
        Bill customerBill("John Doe");

        // Add items using overloaded + operator
        Item& laptop = inventory[0];
        if (laptop.getStock() < 2) {
            throw runtime_error("Error: Not enough stock for item: " + laptop.getName());
        }
        customerBill + make_pair(laptop, 2);
        laptop.decreaseStock(2);

        Item& keyboard = inventory[2];
        if (keyboard.getStock() < 1) {
            throw runtime_error("Error: Not enough stock for item: " + keyboard.getName());
        }
        customerBill + make_pair(keyboard, 1);
        keyboard.decreaseStock(1);

        // customerBill.generateBill(); // Uncomment to test empty bill

        cout << "--- Generated Bill ---\n";
        cout << customerBill;

        saveBillToFile(customerBill);
        cout << "Bill saved to bills.txt\n";

    } catch (const invalid_argument& e) {
        cerr << "Exception: " << e.what() << "\n";
    } catch (const runtime_error& e) {
        cerr << "Exception: " << e.what() << "\n";
    } catch (const logic_error& e) {
        cerr << "Exception: " << e.what() << "\n";
    } catch (const exception& e) {
        cerr << "An unexpected exception occurred: " << e.what() << "\n";
    }

    return 0;
}
