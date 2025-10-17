#include<iostream>
using namespace std;

class A{
	public:
		int rno[10];
     string dob;
		int i,j;
	void Get(int i){
	cout<<"enter rollno \n";
		cin>>rno[i];
		cout<<"enter the dob \n";
		cin>>dob[i];
		
	}
	void dis(int i){
		
		cout<<"roll no is "<<rno[i];
		cout<<"dob is"<<dob[i];
}

	void sort(int n){
	
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				
				if(rno[j]>rno[i]){
					int temp=rno[i];
					rno[i]=rno[j];
					rno[j]=temp;
					
				}
			}
		}
	for(int i=0;i<n;i++)
         {
             cout<<rno[i]<<" ";
         }	
	}
};

int main(){
	
	
	int no;
	cout<<":enter the  number \n";
	cin>>no;
	A a1;
	for(int i=0;i<no;i++){
			cout<<"enter details \n";

		a1.Get(i);
		
	}                 
	
	for (int i=0;i<no;i++){
			a1.dis(i);
	
	}
	
	a1.sort(no);
}
