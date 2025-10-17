#include<iostream>
using namespace std;
#include<string.h>

int main(){
	char a[10]="hello";
	char a1[10];
	int x;
	x=strlen(a)-1;
	int y=0;
	
	while(x>=0){
		a1[y]=a[x];
		x--;
		y++;
		
	}
	a1[y]='\0';
	cout<<a1;
	return 0;
}