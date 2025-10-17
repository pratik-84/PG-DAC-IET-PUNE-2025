//selection sort
// #include<iostream>
// using namespace std;

// int main(){
//     int a[]={6,4,3,8,6};
//     int temp;
//     for(int i=0;i<5;i++){
//         for(int j=i+1;j<5;j++){
//             if(a[i]<a[j]){
//              temp=a[i];
//             a[i]=a[j];
//             a[j]=temp;
//             }
//         }
//     }
//     for(int i=0;i<5;i++){
//         cout<<a[i]<<" ";
//     }
// }

//bubble sort
#include<iostream>
using namespace std;

int main(){
    int a[]={6,4,3,8,2};
    int temp;
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            if(a[j]>a[j+1]){
             temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}
