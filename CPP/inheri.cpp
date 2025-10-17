#include<iostream>
using namespace std;


class Base{
	public:
	void display1(){
		cout<<"this is base class";
	}
};

class Derived1:public Base{
	public:
	void display2(){
		
	
		cout<<"this is thee classs which derive base class";
	}
};
class Derived2:public Derived1{
	public:
	void display3(){
		cout<<"this is the function which derived the base and derive1 class";
	}
};

int main(){
	
	Derived2 dev;
	dev.display1();
	dev.display2();
}