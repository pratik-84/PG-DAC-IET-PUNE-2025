#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Custom Exception Classes
class NegativeValueException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Negative value not allowed for price or quantity.";
    }
};

class InsufficientStockException : public std::exception {
private:
    std::string message;
public:
    InsufficientStockException(const std::string& itemName)
        : message("Error: Not enough stock for item: " + itemName) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class EmptyBillException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Cannot generate an empty bill.";
    }
};

// 1. OOP Design
class Item {
private:
    int itemID;
    std::string itemName;
    double price;
    int stockQuantity;
public:
    Item(int id = 0, const std::string& name = "", double p = 0.0, int qty = 0)
        : itemID(id), itemName(name), price(p), stockQuantity(qty) {
        if (p < 0 || qty < 0) {
            throw NegativeValueException();
        }
    }

    // Getters and setters
    int getID() const { return itemID; }
    std::string getName() const { return itemName; }
    double getPrice() const { return price; }
    int getStock() const { return stockQuantity; }

    void decreaseStock(int quantity) {
        if (stockQuantity < quantity) {
            throw InsufficientStockException(itemName);
        }
        stockQuantity -= quantity;
    }

    void increaseStock(int quantity) {
        stockQuantity += quantity;
    }

    // Friend function for file I/O
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    friend std::istream& operator>>(std::istream& is, Item& item);
};

// 1. OOP Design (cont.)
class Bill {
private:
    static int nextBillID;
    int billID;
    std::string customerName;
    std::vector<std::pair<Item, int>> purchasedItems; // pair of (Item, quantity)
public:
    Bill(const std::string& name = "") : customerName(name) {
        billID = nextBillID++;
    }

    // 2. Operator Overloading: Overload + to add an item to the bill
    void operator+(const std::pair<Item, int>& purchase) {
        purchasedItems.push_back(purchase);
    }

    // 2. Operator Overloading: Overload << to display the bill details
    friend std::ostream& operator<<(std::ostream& os, const Bill& bill);
    
    int getID() const { return billID; }
    std::string getCustomerName() const { return customerName; }
    const std::vector<std::pair<Item, int>>& getPurchasedItems() const { return purchasedItems; }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& purchase : purchasedItems) {
            total += purchase.first.getPrice() * purchase.second;
        }
        return total;
    }

    void generateBill() const {
        if (purchasedItems.empty()) {
            throw EmptyBillException();
        }
    }
};

int Bill::nextBillID = 1;

// Overloaded << for Item
std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << item.itemID << "," << item.itemName << "," << item.price << "," << item.stockQuantity;
    return os;
}

// Overloaded >> for Item
std::istream& operator>>(std::istream& is, Item& item) {
    std::string line;
    if (std::getline(is, line)) {
        std::stringstream ss(line);
        std::string idStr, name, priceStr, qtyStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');
        std::getline(ss, priceStr, ',');
        std::getline(ss, qtyStr, ',');

        item.itemID = std::stoi(idStr);
        item.itemName = name;
        item.price = std::stod(priceStr);
        item.stockQuantity = std::stoi(qtyStr);
    }
    return is;
}

// Overloaded << for Bill
std::ostream& operator<<(std::ostream& os, const Bill& bill) {
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

// 4. File Handling functions
void saveBillToFile(const Bill& bill) {
    std::ofstream file("bills.txt", std::ios::app); // Append mode
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
        std::cerr << "Error: Unable to open bills.txt for writing.\n";
    }
}

void loadPreviousBills() {
    std::ifstream file("bills.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    } else {
        std::cout << "No previous bills found.\n";
    }
}

int main() {
    // 4. Load previous bills at startup
    std::cout << "Loading previous billing records...\n";
    loadPreviousBills();
    std::cout << "\n";

    // Create some sample items
    std::vector<Item> inventory;
    try {
        inventory.push_back(Item(101, "Laptop", 1200.0, 10));
        inventory.push_back(Item(102, "Mouse", 25.0, 50));
        inventory.push_back(Item(103, "Keyboard", 75.0, 30));
        inventory.push_back(Item(104, "Monitor", 300.0, 15));
        // inventory.push_back(Item(105, "Negative Price Item", -10.0, 5)); // This would throw an exception
    } catch (const NegativeValueException& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "Welcome to the Tech Store!\n\n";

    // Simulate a purchase
    try {
        Bill customerBill("John Doe");

        // Add items using overloaded + operator
        Item& laptop = inventory[0];
        if (laptop.getStock() < 2) {
            throw InsufficientStockException(laptop.getName());
        }
        customerBill + std::make_pair(laptop, 2);
        laptop.decreaseStock(2); // Update stock

        Item& keyboard = inventory[2];
        if (keyboard.getStock() < 1) {
            throw InsufficientStockException(keyboard.getName());
        }
        customerBill + std::make_pair(keyboard, 1);
        keyboard.decreaseStock(1); // Update stock
        
        // This will fail with InsufficientStockException
        // Item& mouse = inventory[1];
        // customerBill + std::make_pair(mouse, 60);
        // mouse.decreaseStock(60); 

        // customerBill.generateBill(); // Test empty bill exception

        // Display the bill using overloaded << operator
        std::cout << "--- Generated Bill ---\n";
        std::cout << customerBill;

        // Save the bill
        saveBillToFile(customerBill);
        std::cout << "Bill saved to bills.txt\n";

    } catch (const NegativeValueException& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    } catch (const InsufficientStockException& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    } catch (const EmptyBillException& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "An unexpected exception occurred: " << e.what() << "\n";
    }

    return 0;
}
