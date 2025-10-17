#include<iostream>
using namespace std;    
    class A{
        int p;
        public:

        void setData(int p){
            //cin>>p;
            
			this -> p=p;
        }
        void getData(){
            cout<<"value is "<<p;
        }


    };    
    int main(){ 
        A a;
        a.setData(4);
        a.getData();

}