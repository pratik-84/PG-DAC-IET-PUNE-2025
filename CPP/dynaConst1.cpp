// #include<iostream>
// using namespace std;
// #include <string.h>
// class string1
// {
// int len;
// char* ptr;

// public:
// string1();
// ~string1()
// {
// cout<<"distructo is called\n";
// }

// void display();
// };

//  string1:: string1(){
//     len=1;
// ptr =new char[len];
// *ptr ='S';
// }
// void string1:: display(){
//     if(len>1)
// 	{
// 			cout<<"length of character is "<<len<<endl;
// 			cout<<"string is "<<ptr<<endl;
// 	}
// 	else
// 	{
// 	cout<<"length of character is "<<len<<endl;
// 	cout<<"character is "<<*ptr<<endl;
// 	}
// }

// int main(){

//     string1 s1;
//     s1.display();
// }











// #include<iostream>
// using namespace std;
// #include <string.h>
// class string1
// {
// int len;
// char* ptr;

// public:
// string1( const char* );
// ~string1()
// {
// cout<<"distructo is called\n";
// }

// void display();
// };

//  string1:: string1( const char* s){
//     len=strlen(s);
// ptr =new char[len+1];
// strcpy(ptr,s);
// }
// void string1:: display(){
//     if(len>1)
// 	{
// 			cout<<"length of character is "<<len<<endl;
// 			cout<<"string is "<<ptr<<endl;
// 	}
// 	else
// 	{
// 	cout<<"length of character is "<<len<<endl;
// 	cout<<"character is "<<*ptr<<endl;
// 	}
// }

// int main(){

//     string1 s1("hii");
//     s1.display();
// }



#include<iostream>
using namespace std;
#include <string.h>
class string1
{
int len;
char* ptr;

public:
string1(char,int);
~string1()
{
cout<<"distructo is called\n";
}

void display();
};

 string1:: string1(char c, int len){
int i;	
	this->len=len;
	ptr=new char[len+1];
	for(i=0;i<len;i++)
	{
		ptr[i]=c;
	}
	ptr[len]='\0'; 
}
void string1:: display(){
    if(len>1)
	{
			cout<<"length of character is "<<len<<endl;
			cout<<"string is "<<ptr<<endl;
	}
	else
	{
	cout<<"length of character is "<<len<<endl;
	cout<<"character is "<<*ptr<<endl;
	}
}

int main(){

    string1 s1('*',80);
	s1.display();
}