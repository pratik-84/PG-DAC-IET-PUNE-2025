#include<iostream>
using namespace std;

class A{
    int* a;
    public:
    A(){    
        a=new int;
        *a=0;
    }
    A(int p){
        a=new int;
        *a=p;
    }
    void dis(){
        cout<<*a<<endl;
    }
    ~A (){
        cout<<"destructor \n";
    }

};
int main(){
    A obj;
    obj.dis(); // default constructor would be called
 A obj1=A(5); // // parameterized constructor would be called
    obj1.dis();
}