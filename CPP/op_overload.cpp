#include<iostream>
using namespace std;

class complex{
	int img,real;
	public:
		
		complex(){
			img=0;
			real=0;
		}
		
		complex(int r,int i){
			img=i;
			real=r;
		}
		void display(){
			cout<<real<<"+"<<img<<"i"<<endl;
		}
		//gives more flexibility of using operators with user define datda types
		complex operator -(complex c){
			complex temp;
			temp.real=real-c.real;
			temp.img=img-c.img;
			return temp;
		}
	};
	int main(){
	
			
	complex c1(8,3);
	complex c2(4,1);
	complex c3;
	
//	c3=c1+c2;
	c3=c1-c2;
	c3.display();
	return 0;
}