#include<iostream>
using namespace std;

class Item{
	int itemID=0,price=0,stockQua=0;
	char itemname[10];
	public:
	void enter(int itemID,int price,int stockQua,char itemNAme[10]){
	/*	cout<<"enter itemID \n";
		cin>>itemID;	
		cout<<"enter price \n";
		cin>>price;
		cout<<"enter stock quantity \n";
		cin>>stockQua;
		cout<<"enter item name \n";
		cin>>itemname;*/
cout<<"details of items  are  :-"<<"the item ID is:-  "<<itemID<<" name of the item is:-  "<< itemname<<" price of the item:-  "<<price<<" quantity of the stock:-  "<<stockQua<<endl;

	}

	void display(){
	/*	cout<<"item id is "<<itemID<<endl ;
		cout<<"price is "<<price<<endl ;
		cout<<"stock quantity are  "<<stockQua<<endl ;
		cout<<"enter item name "<<itemname<<endl; */
		
		cout<<"details of items  are  :-"<<"the item ID is:-  "<<itemID<<" name of the item is:-  "<< itemname<<" price of the item:-  "<<price<<" quantity of the stock:-  "<<stockQua<<endl;
	}

};
class Bill{
	int billID;
	char Custname[10];
	public:	
	void dis(int billID,char Custname[10]){
cout<<"bil ID of items  are  :-"<<billID<<" name of the customer is:-  "<< Custname<<endl;

			
	}
};
		
int main(){
	int num,i;
//	cout<<"enter num \n";
//	cin>>num;
	Item * obj =new Item[num];
	Item * obj1 =new Item[num];
	Item * obj2 =new Item[num];

	cout<<"enter elements \n";
/*	for(i=0;i<num;i++){
		(obj+i)->enter();
	}*/
	obj->enter(4201,10000,5,"mobile");
	obj1->enter(2106,50000,5,"laptop");
	obj2->enter(5124,90000,5,"camera");
//	cout<<"display elements \n";
	/*for(i=0;i<num;i++){
	
	(obj+i)->display();
    }*/
    Bill * A =new Bill[num];
    Bill * A1 =new Bill[num];
    Bill * A2 =new Bill[num];
	
	A->dis(176,"pratik");  
    A1->dis(22,"rohit");
    
}