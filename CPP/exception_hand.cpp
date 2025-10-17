#include<iostream>
using namespace std;

int main(){
	int num,den,res;
	int n=0;
	
	cout<<"enterr the number\n";
	cin>>num>>den;
	try{
		if(den==0){
			throw den;
		}
	}
	catch(int ex){
		cout<<"den is inappropite"<<ex;
	}
	res=num/den;
	cout<<"result is :"<<res;

if (n <= 0)
   {
     throw runtime_error("Atleast 1 student is required. Please enter a valid no. of students.");
   }
}