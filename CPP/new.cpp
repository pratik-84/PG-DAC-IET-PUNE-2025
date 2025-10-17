#include<iostream>
using namespace std; 

int main(){
	
	int n,i;
	cout<<"enter the no of elements";
	cin>>n;
	
	int* ptr=new int[n];
	cout<<"accept the array";
	
	for(i=0;i<n;i++){
		cin>>ptr[i];
	}
	cout<<"display the array";
	
	for(i=0;i<n;i++){
		cout<<ptr[i]<<"\t";
	}
	
	
	
	
//	int *ptr=new int;
//	*ptr=10;
//	cout<<*ptr;
}