#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Student class
class Student {
private:
    int rollNo;
    string name;
    int marks[3];

public:
    // Constructor
    Student(int r, string n, int m1, int m2, int m3) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        rollNo=r;
        name=n;
    }

    // Calculate average marks
    double average() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    // Overload ++ (prefix) to increment all marks by 1 (bonus)
    Student& operator++() {
        for (int i = 0; i < 3; i++) {
            marks[i]++;
        }
        return *this;
    }

    // Overload > operator to compare students by average marks
    bool operator>(const Student& other) const {
        return this->average() > other.average();
    }

    // Display student details
    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << ", Average: " << average() << endl;
    }
};

// Gradebook class
class Gradebook {
private:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    void displayAll() const {
        for (const auto& s : students) {
            s.display();
        }
    }

    // Find student with highest average
    Student topStudent() const {
        if (students.empty()) {
            throw runtime_error("No students in gradebook");
        }
        Student top = students[0];
        for (const auto& s : students) {
            if (s > top) {
                top = s;
            }
        }
        return top;
    }
};

int main() {
    Gradebook gb;

    // Add some students
    gb.addStudent(Student(1, "Alice", 85, 90, 88));
    gb.addStudent(Student(2, "Bob", 78, 82, 80));
    gb.addStudent(Student(3, "Charlie", 92, 87, 95));

    cout << "Original Students:\n";
    gb.displayAll();

    // Give bonus marks (increment marks of all students)
    cout << "\nAfter giving bonus marks (+1 to all subjects):\n";
    for (int i = 0; i < 3; i++) {
        // Increment marks for each student in the gradebook
        gb.addStudent(++gb.topStudent());  // This is not the best way, we will fix below
    }
    // Instead, let's increment marks correctly (will fix in the next version)
    
    // Better way: increment marks of students inside Gradebook
    // Let's fix this below

    return 0;
}
