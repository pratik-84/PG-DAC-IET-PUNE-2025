#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// -------------------- Item Class --------------------
class Item {
private:
    int itemID;
    string itemName;
    double price;
    int stockQuantity;

public:
    // Constructor
    Item(int id = 0, string name = "", double pr = 0.0, int qty = 0): itemID(id), itemName(name), price(pr), stockQuantity(qty) {}

    // Getters
    int getItemID() 
	const { return itemID; }
	
    string getItemName() 
	const { return itemName; }
	
    double getPrice() 
	const { return price; }
	
    int getStockQuantity() 
	const { return stockQuantity; }

    // Update stock
    bool reduceStock(int qty) {
        if (qty <= stockQuantity) {
            stockQuantity -= qty;
            return true;
        }
        return false;
    }

    // Display Item
    void displayItem() const {
        cout << left << setw(10) << itemID
             << setw(20) << itemName
             << setw(10) << price
             << setw(10) << stockQuantity << endl;
    }
};

// -------------------- Bill Class --------------------
class Bill {
private:
    int billID;
    string customerName;

    struct PurchasedItem {
        Item item;
        int quantity;
    };

    vector<PurchasedItem> purchasedItems;

public:
    Bill(int id, string name) : billID(id), customerName(name) {}

    void addItem(Item &item, int qty) {
        if (item.reduceStock(qty)) {
            purchasedItems.push_back({item, qty});
        } else {
            cout << "?? Not enough stock for " << item.getItemName() << endl;
        }
    }

    void displayBill() {
        cout << "\n========= Bill ID: " << billID << " =========\n";
        cout << "Customer: " << customerName << "\n";
        cout << "---------------------------------------------\n";
        cout << left << setw(20) << "Item"
             << setw(10) << "Price"
             << setw(10) << "Qty"
             << setw(10) << "Total" << endl;

        double grandTotal = 0.0;
        for (auto &p : purchasedItems) {
            double total = p.item.getPrice() * p.quantity;
            grandTotal += total;
            cout << left << setw(20) << p.item.getItemName()
                 << setw(10) << p.item.getPrice()
                 << setw(10) << p.quantity
                 << setw(10) << total << endl;
        }

        cout << "---------------------------------------------\n";
        cout << "Grand Total: " << grandTotal << endl;
        cout << "=============================================\n";
    }
};

// -------------------- Main Function --------------------
int main() {
    // Sample items
    Item i1(1, "Laptop", 55000, 5);
    Item i2(2, "Smartphone", 20000, 10);
    Item i3(3, "Keyboard", 1500, 20);

    // Display available items
    cout << "\nAvailable Items:\n";
    cout << left << setw(10) << "ItemID"
         << setw(20) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Stock" << endl;
    i1.displayItem();
    i2.displayItem();
    i3.displayItem();

    // Create a bill
    Bill b1(101, "Rohan");

    // Customer purchases
    b1.addItem(i1, 1);
    b1.addItem(i2, 2);
    b1.addItem(i3, 5);

    // Show bill
    b1.displayBill();

    return 0;
}
