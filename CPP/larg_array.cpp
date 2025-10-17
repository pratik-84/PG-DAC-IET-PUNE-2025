#include<iostream>
using namespace std;
 int main(){
 	
 	int a[]={7,4,15,8,9,3};
 	
 	int max=a[0],i,sec_max;
 	
 	for( i=1;i<=5;i++){
 		if(max<a[i]){
 			sec_max=max;
 			max=a[i];
		 }
		 
		 
 	
	 }
	 cout<<max<< endl;
	 
 }