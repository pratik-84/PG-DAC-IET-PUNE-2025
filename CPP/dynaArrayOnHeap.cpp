# include<iostream>
using namespace std;

class dynaArrayOnHeap {
int rollNo;
char name[10];
    public:
  void enterDetails(){
    cin>> name ;
    cin>> rollNo;
  }

  void display(){
    cout<<"name is "<< name<<endl;
        cout<<"roll no is"<<rollNo<<endl;
  }

  ~dynaArrayOnHeap(){
    cout<<"distructor is called \n";
  }
};

int main(){
int n,i;
cout<< "enter the value of n  \n";
cin>> n;

  dynaArrayOnHeap* obj= new dynaArrayOnHeap[n];  
  for( i=0; i<n; i++){
    (obj+i)->enterDetails();
  }
  for( i=0; i<n;i++){
   (obj+i)->display();
  }
  delete []obj;
}