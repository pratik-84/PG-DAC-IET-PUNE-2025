// /*Write a Student class and use it in your program.
//  Store the data of 10 students and display the sorted data
//   according to their roll numbers, dates of birth, and total marks.
//   Implement all C++ operators
//  */

  #include <iostream>
 #include <string.h>
 using namespace std;

 class student
 {
   

 public:
  int roll_no[5];
     string dob;
     int marks,i,j;
  //  int roll_no[7];

    
     void entry(int i)
     {
         cout << "Enter Roll no: ";
         cin >> roll_no[i];
         cout << "Enter Date of Birth: ";
         cin >> dob[i];
         // cout << "Enter Marks: ";
         // cin >> marks[i];
     }


     void show(int i)
     {
         cout << "Roll no: " << roll_no[i] << endl;
         cout << "Date of Birth: " << dob[i] << endl;
         ///cout << "Marks: " << marks[i] << endl;
     }
 


 void sort(int n) 
     {
         for( i=0;i<n;i++)	
         {
             for (j=i+1;j<n;j++)
             {
                 if(roll_no[j] >roll_no[i])
                 {
                 int temp=roll_no[i];
                 roll_no[i]=roll_no[j];
                 roll_no[j]=temp;
                 }
             }
         }
         for(int i=0;i<n;i++)
         {
             cout<<roll_no[i]<<" ";
         }
     }};


 int main()
 {

     int no;
     cout << "Enter Size: ";
     cin >> no;

   
     student d;
     for (int i = 0; i < no; i++)
     {
         cout << "Enter details " <<endl;
       
         d.entry(i);
     }
    

   

     cout << "Student Details" << endl;
     for (int i = 0; i < no; i++)
     {
         d.show(i);
        
     }
    d.sort(no);
 }

