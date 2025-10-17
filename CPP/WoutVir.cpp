#include<iostream>
using namespace std;

class employee{
    int id;
    public:
    employee();
    employee(int);
   virtual void display();
    virtual int findsal(){
        return 0;
    }
};
   
employee::employee(){
    cout<<"this is def const\n"; 
    id=0;
}
employee::employee(int i){
    cout<<"this is arg const\n";
    id=i;
}
 void employee:: display(){

    cout<<"this is the function\n"<<id;
}   

class wageEmp: public employee{
    int hrs,amt;
    public:
    wageEmp();
    wageEmp(int,int,int);
    void display();
    int findsal();
    };
    wageEmp::wageEmp(){
        cout<<"this is the def const of inherited class \n";
        hrs=0;
        amt=0;
    }
    wageEmp::wageEmp(int h,int a,int i):employee(i)
    {
        hrs=h;
        amt=a;
        cout<<"this is the para const \n";

    }
    int wageEmp:: findsal(){
        return hrs*amt;
    }
    void wageEmp ::display(){

        employee::display();
         cout<<amt;
        cout<<hrs;
       
    }


int main(){
   
   
   employee *ptr;
    wageEmp w1(100,10000,10);
   ptr=&w1;
   cout<<"salary is \n"<<ptr->findsal(); 

   ptr->display();
}