 #include <iostream>
 #include <string.h>
 using namespace std;

 class A{
    public:
    void fun(){
        cout<<"fun without parameter \n";
    }
    void fun(int a){
        cout<<"this passes1 parametre \n"<<a;
    }
    void fun( string a){

        cout<<"this passes parameter string : \n" <<a;
    }

};
int main(){
A a1;
a1.fun();
a1.fun(4);
a1.fun("hello");
}