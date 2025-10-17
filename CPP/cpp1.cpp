#include<iostream>
using namespace std;

class Item{
	int itemID=0,price=0,stockQua=0;
	char itemname[10];
	public:
	void enter(){
		cout<<"enter itemID \n";
		cin>>itemID;	
		cout<<"enter price \n";
		cin>>price;
		cout<<"enter stock quantity \n";
		cin>>stockQua;
		cout<<"enter item name \n";
		cin>>itemname;
	}

	void display(){
	/*	cout<<"item id is "<<itemID<<endl ;
		cout<<"price is "<<price<<endl ;
		cout<<"stock quantity are  "<<stockQua<<endl ;
		cout<<"enter item name "<<itemname<<endl; */
		
		cout<<"details of items  are  :-"<<"the item ID is:-  "<<itemID<<" name of the item is:-  "<< itemname<<" price of the item:-  "<<price<<" quantity of the stock:-  "<<stockQua<<endl;
	}

};

int main(){
	int num,i;
	cout<<"enter num \n";
	cin>>num;
	Item * obj =new Item[num];
	cout<<"enter elements \n";
	for(i=0;i<num;i++){
		(obj+i)->enter();
	}
	cout<<"display elements \n";
	for(i=0;i<num;i++){
	
	(obj+i)->display();
    }
}