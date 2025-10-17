#include <iostream>
#include <fstream>
using namespace std; 
int main() {
    // opening a text file for writing
    fstream my_file("name.txt", ios::app);
    if (!my_file) {

    // print error message
    cout << "Error opening the file." << endl;
    // terminate the main() function
    
}
else{
cout << " opening the file." << endl;
}
my_file <<"pratik "<<endl;
    // close the file
    my_file.close();
    return 0;
}