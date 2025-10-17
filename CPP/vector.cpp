//#include<iostream>
//using namespace std;
//#include<vector>
//
//void display(vector<int> &v){
//	
//	for(int i=0;i<v.size();i++){
//		cout<<v[i]<<" ";
//		cout<<v.at(i);
//	}
//}
//int main(){
//	int value,n;
//	cout<<"enter the no of value \n";
//	cin>>n;
//	vector<int>vec;
//	
//	for(int i=0;i<n;i++){
//		cout<<"enter value \n";
//		cin>>value;
//		vec.push_back(value);
//	}
////	display(vec);
//	//vec.pop_back();
//	vector<int>::iterator iter=vec.begin();
//	vec.insert(iter+3,2);
//		display(vec);
//
//}



#include<iostream>
using namespace std;
#include<vector>
void display(vector <int> &v){
	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
int main(){
	int value,n;
	cout<<"enter the no of value \n";
	cin>>n;
	vector<int>vec;
	
	for(int i=0;i<n;i++){
		cout<<"enter no\n";
		cin>>value;
		vec.push_back(value);
	}
	int a=5;
	vec.push_back(a);
	display(vec);
	vec.pop_back();
	display(vec);
// Demonstrating push_back with 'a'
//	int a=5;
//	vec.push_back(a);
//	cout << "Vector after adding 'a': ";
//	display(vec);
//	
//	// Demonstrating pop_back
//	vec.pop_back();
//	cout << "Vector after pop_back: ";
//	display(vec);
}