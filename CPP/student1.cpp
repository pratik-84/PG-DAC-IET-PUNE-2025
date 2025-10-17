#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int marks[3];

public:
    Student(int r, string n, int m1, int m2, int m3) {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
  
    int getRollNo() {
        return rollNo;
    }

    string getName() {
        return name;
    }

    int* getMarks() {
        return marks;
    }

    float getAverage() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    

    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name << "\nMarks: ";
        for (int i = 0; i < 3; i++) cout << marks[i] << " ";
        cout << "\nAverage: " << getAverage() << "\n\n";
    }
};

class Gradebook {
private:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    void displayAll() {
        cout << "All Students:\n";
        for (auto& s : students) {
            s.display();
        }
    }

    void displayTopper() {
        if (students.empty()) {
            cout << "No students in gradebook.\n";
            return;
        }

        Student* topper = &students[0];
        for (auto& s : students) {
            if (s.getAverage() > topper->getAverage()) {
                topper = &s;
            }
        }

        cout << "Topper:\n";
        topper->display();
    }
};

int main() {
    Gradebook gb;
    // Add some students
    gb.addStudent(Student(101, "Alice", 85, 92, 78));
    gb.addStudent(Student(102, "Bob", 75, 80, 72));
    gb.addStudent(Student(103, "Charlie", 65, 60, 70));

    gb.displayAll();
    gb.displayTopper();

    return 0;
}
