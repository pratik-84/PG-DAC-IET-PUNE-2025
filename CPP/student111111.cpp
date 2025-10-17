#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

// ----------------- Student Class -----------------
class Student {
    int rollNo;
    string name;
    float marks[3];

public:
    // Constructors
    Student() {}
    Student(int r, string n, float m1, float m2, float m3) {
        if (m1 < 0 || m2 < 0 || m3 < 0 || m1 > 100 || m2 > 100 || m3 > 100)
            throw invalid_argument("Invalid marks! Marks should be between 0 and 100.");

        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // Getters
    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    float getAverage() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    // Display
    void display() const {
        cout << setw(5) << rollNo << setw(15) << name 
             << setw(10) << marks[0] << setw(10) << marks[1] << setw(10) << marks[2]
             << setw(10) << fixed << setprecision(2) << getAverage() << endl;
    }

    // Operator Overload: ++ to add bonus marks (+1 to each subject)
    Student& operator++() {
        for (int i = 0; i < 3; ++i) {
            if (marks[i] + 1 <= 100)
                marks[i] += 1;
        }
        return *this;
    }

    // Operator Overload: > to compare average marks
    bool operator>(const Student& s) const {
        return this->getAverage() > s.getAverage();
    }

    // Update marks
    void updateMarks(float m1, float m2, float m3) {
        if (m1 < 0 || m2 < 0 || m3 < 0 || m1 > 100 || m2 > 100 || m3 > 100)
            throw invalid_argument("Invalid marks! Marks should be between 0 and 100.");
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // Save to file
    void saveToFile(ofstream& fout) const {
        fout << rollNo << "," << name << "," 
             << marks[0] << "," << marks[1] << "," << marks[2] << "\n";
    }

    // Load from string line
    static Student fromString(const string& line) {
        int r;
        string n;
        float m1, m2, m3;
        size_t pos = 0, prev = 0;
        vector<string> tokens;

        while ((pos = line.find(',', prev)) != string::npos) {
            tokens.push_back(line.substr(prev, pos - prev));
            prev = pos + 1;
        }
        tokens.push_back(line.substr(prev));

        if (tokens.size() != 5) throw runtime_error("Corrupted data line");

        r = stoi(tokens[0]);
        n = tokens[1];
        m1 = stof(tokens[2]);
        m2 = stof(tokens[3]);
        m3 = stof(tokens[4]);

        return Student(r, n, m1, m2, m3);
    }
};

// ----------------- Gradebook Class -----------------
class Gradebook {
    vector<Student> students;

public:
    // Add a student
    void addStudent(const Student& s) {
        for (auto& stu : students) {
            if (stu.getRollNo() == s.getRollNo())
                throw runtime_error("Duplicate roll number found!");
        }
        students.push_back(s);
    }

    // Display all
    void displayAll() const {
        if (students.empty()) throw runtime_error("Gradebook is empty!");
        cout << "\nStudent Records:\n";
        cout << setw(5) << "Roll" << setw(15) << "Name"
             << setw(10) << "Marks1" << setw(10) << "Marks2" << setw(10) << "Marks3"
             << setw(10) << "Average\n";

        for (const auto& s : students)
            s.display();
    }

    // Save to file
    void saveToFile(const string& filename) {
        ofstream fout(filename);
        for (const auto& s : students)
            s.saveToFile(fout);
        fout.close();
    }

    // Load from file
    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        string line;
        while (getline(fin, line)) {
            try {
                Student s = Student::fromString(line);
                addStudent(s);
            } catch (...) {
                cerr << "Skipping corrupted line: " << line << endl;
            }
        }
        fin.close();
    }

    // Search and update
    void updateStudentMarks(int roll, float m1, float m2, float m3) {
        for (auto& s : students) {
            if (s.getRollNo() == roll) {
                s.updateMarks(m1, m2, m3);
                return;
            }
        }
        throw runtime_error("Student not found!");
    }

    // Find top student
    Student getTopper() const {
        if (students.empty()) throw runtime_error("Gradebook is empty!");
        Student top = students[0];
        for (const auto& s : students) {
            if (s > top)
                top = s;
        }
        return top;
    }

    // Increment all student marks
    void applyBonusMarks() {
        for (auto& s : students)
            ++s;
    }
};

// ----------------- Main Function -----------------
int main() {
    Gradebook gb;
    string filename = "gradebook.txt";

    try {
        gb.loadFromFile(filename);
        cout << "Loaded existing student data.\n";
    } catch (...) {
        cout << "No previous data found or error loading file.\n";
    }

    int choice;
    do {
        cout << "\n====== Gradebook Menu ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Marks\n";
        cout << "4. Show Topper\n";
        cout << "5. Apply Bonus Marks\n";
        cout << "6. Save and Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                int roll;
                string name;
                float m1, m2, m3;
                cout << "Enter Roll No, Name, Marks in 3 subjects: ";
                cin >> roll >> name >> m1 >> m2 >> m3;
                Student s(roll, name, m1, m2, m3);
                gb.addStudent(s);
                cout << "Student added.\n";
            } else if (choice == 2) {
                gb.displayAll();
            } else if (choice == 3) {
                int roll;
                float m1, m2, m3;
                cout << "Enter Roll No to update: ";
                cin >> roll;
                cout << "Enter new marks in 3 subjects: ";
                cin >> m1 >> m2 >> m3;
                gb.updateStudentMarks(roll, m1, m2, m3);
                cout << "Marks updated.\n";
            } else if (choice == 4) {
                Student top = gb.getTopper();
                cout << "Topper:\n";
                top.display();
            } else if (choice == 5) {
                gb.applyBonusMarks();
                cout << "Bonus marks applied.\n";
            } else if (choice == 6) {
                gb.saveToFile(filename);
                cout << "Data saved. Exiting...\n";
            } else {
                cout << "Invalid choice.\n";
            }
        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 6);

    return 0;
}
