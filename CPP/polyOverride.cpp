#include <iostream>
 #include <string.h>
 using namespace std;


 class A{

    public:
    virtual void fun(){
        cout<<"this is the def fun \n";
    }
 };
 class B: public A{
    public:
    void fun() override{
        cout<<"this is derived class \n";
    }
 };
 class C :public A{
    public:
    void fun() override{
        cout<<"this class is C \n";
    }

 };
 int main(){

    A* a1=new B();
    A* a2=new C();
    a1->fun();
    a2->fun();
delete a1;
delete a2;
     return 0;
 }