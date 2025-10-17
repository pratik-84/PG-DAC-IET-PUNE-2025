#include <iostream>
#include <climits> // Include this for INT_MIN

using namespace std;

int main() {
    int a[] = {7, 9, 15, 8, 9, 3};
    int n = 6; // It's good practice to use a variable for array size

    // Initialize the largest and second-largest variables
    int largest = a[0];
    int secondLargest = INT_MIN; // Use a very small number for initialization

    for (int i = 1; i < n; i++) {
        if (a[i] > largest) {
            secondLargest = largest; // The old largest is now the second largest
            largest = a[i];          // The new element is the largest
        } else if (a[i] > secondLargest && a[i] < largest) {
            secondLargest = a[i];    // Found a new second largest
        }
    }

    cout << "The largest element is: " << largest << endl;
    
    // Handle the case where all elements are the same or there is no second largest
//    if (secondLargest == INT_MIN) {
//        cout << "There is no second largest element." << endl;
//    } else {
//        cout << "The second largest element is: " << secondLargest << endl;
//    }
        cout << "The second largest element is: " << secondLargest << endl;


    return 0;
}
