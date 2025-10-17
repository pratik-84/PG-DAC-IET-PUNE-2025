#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class item{
    int itemID;
     string itemName;
      double price;
      int stockQuantity;

public:
 item(int id=0, string name="", double p=0.00, int quantity = 0  ){
 itemID = id;
 itemName = name;
 price = p;
 stockQuantity = quantity;
 }
 
 int getId() { return itemID; }
 string getName(){return itemName; }
 double getPrice(){return price; }
 int getQuantity(){ return stockQuantity; }
 
void reduceStock (int qty){
stockQuantity=stockQuantity-qty;
}
};

struct purchase
{
    int itemID;
    string itemName;
    double price;
    int quantity;
};

class bill{
    int billID;
    string customerName;
    vector<purchase> purchaseditems;
double total = 0.0;
public:
bill(int idb=0, string name=""){
 billID= idb;
    customerName = name;
}

bill& operator+(purchase& p){
     purchaseditems.push_back(p);
    total= total+p.price*p.quantity;
    return *this;
}

 friend ostream& operator<<(ostream &out, bill &b){
    if(b.purchaseditems.empty()){
        throw runtime_error("Bill is Empty!!!");
    }

    out<<"\n============Bill #"<<b.billID<<" ======\n";
    out<<"Customer: "<<b.customerName<<"\n";
    out<<"-------------------------------"<<endl;

    for(auto &p: b.purchaseditems){
        out<<p.itemName<<" x "<<p.quantity
            <<" = "<<p.price*p.quantity<<endl;
    }
    out<<"---------------------------------"<<endl;
    out<<"Total: "<<b.total<<"\n";
    return out;
 }

 void saveToFile(){

    if(purchaseditems.empty()){
        throw runtime_error("Cannot Save Empty Bill!!");
    }

    ofstream fout("bill.txt",ios::app);
    fout<<"Bill #"<<billID<<" | "<<customerName<<" | Total: "<<total<<endl;
    fout.close();

 }

};

int main()
{
    vector<item>inventory={
        item(1,"USB Cable",200,10),
        item(2,"Mouse",500,5),
        item(3,"Keyboard",800,3)
    };

     bill b1(101,"John");

    cout<<"Available Items: "<<endl;
    for(auto &it: inventory){
        cout<<it.getId()<<". "<<it.getName()
            <<" (Price: "<<it.getPrice()
            <<", Stock: "<<it.getQuantity()<<")\n";

    };

    int id,qty;
    cout<<"Enter Item ID To Buy: ";
    cin>>id;
    cout<<"Enter Quantity: ";
    cin>>qty;

    for(auto &it:inventory){
        if(it.getId()==id){
            it.reduceStock(qty);
            purchase p{
                it.getId(),it.getName(),it.getPrice(),qty
            };
            b1+p;
        }
    }

    cout<< b1;
    b1.saveToFile();
    cout<<"Bill saved to File."<<endl;
    return 0;
}

