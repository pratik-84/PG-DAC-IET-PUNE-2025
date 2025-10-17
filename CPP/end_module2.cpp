// ?? Problem Statement 2: "Student Gradebook & Analytics System"
// ?? Objective:
// Build a C++ application to manage student records, calculate grades, and store data securely.

// ?? Requirements:
// 1. OOP Design
// Class Student with:

// rollNo, name, marks in 3 subjects

// Class Gradebook to manage multiple students

// 2. Operator Overloading
// Overload ++ to increment marks (e.g., bonus marks)

// Overload > to compare students based on average marks

// 3. Exception Handling
// Throw exceptions for:

// Invalid marks (e.g., >100 or <0)

// Duplicate roll numbers

// Empty gradebook access

// 4. File Handling
// Save student records to gradebook.txt

// Load records at startup

// Allow search by roll number and update marks

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <cstdlib>
#include <exception>

class students
{
    int roll, p, c, m;
    string sname;

public:
    float avg = 0;
    students();
    students(int, string, int, int, int);
    void display(int);
    float average();
    students getStuDetails(int, int[]);
    int getRoll()
    {
        return roll;
    }
};

students ::students()
{
    roll = p = c = m = 0;
    sname = "";
}
students ::students(int roll, string sname, int p, int c, int m)
{
    this->roll = roll;
    this->sname = sname;
    this->p = p;
    this->c = c;
    this->m = m;
}

float students ::average()
{
    return (p + c + m) / 3.0;
}

void students ::display(int n)
{
    cout << "Roll No: " << roll << endl;
    cout << "Name: " << sname << endl;
    cout << "Marks: " << p << " " << c << " " << m << endl;
    cout << "Average out of 300: " << average() << endl;
    cout << "------------------------------------------" << endl;
}

class gradebook
{
    int n;
    students **stu;

public:
    gradebook(int n)
    {
        cout << "parameter constructor" << endl;
        this->n = n;

        stu = new students *[n];

        for (int i = 0; i < n; i++)
        {
            stu[i] = new students();
        }
    }

    // gradebook(int n)
    // {
    //     *stu = new students[n];
    //     cout << "parameter constructor" << endl;
    //     this->n = n;
    //     for (int i = 0; i < n; i++)
    //     {
    //         *stu[i] = students();
    //     }
    // }

    void manageStudents()
    {
        cout << "Manage Students" << endl;
        for (int i = 0; i < n; i++)
        {
            int roll, p, c, m;
            string sname;

            cout << "Enter details for student " << i + 1 << ": \n";
            cout << "Enter Roll No. : ";
            cin >> roll;
            cout << "Enter name: ";
            cin >> sname;
            cout << "Enter No. of marks in 3 subjects: ";
            cin >> p >> c >> m;
            for (int j = 0; j < n; j++)
            {
                if (roll == stu[j]->getRoll())
                {
                    throw runtime_error("Roll No. " + to_string(stu[j]->getRoll()) + " already exists.");
                }
            }
            if (p > 100 || c > 100 || m > 100 || p < 0 || c < 0 || m < 0)
            {
                throw runtime_error("Invalid marks. Marks should be b/w 0 to 100.");
            }
            ofstream myFile("student.txt", ios::app);
            myFile << "------------------------------------" << endl;
            myFile << "Roll No: " << roll << endl;
            myFile << "Name: " << sname << endl;
            myFile << "Marks: " << p << " " << c << " " << m << endl;
            myFile << "Average out of 300: " << stu[i]->average() << endl;
            myFile << "------------------------------------" << endl;
            myFile.close();
            *stu[i] = students(roll, sname, p, c, m);

        }
        for (int i = 0; i < n; i++)
        {
            cout << "------------------------------------------" << endl;
            cout << "Student " << i + 1 << ": " << endl;
            stu[i]->display(n);
        }
    }
    ~gradebook()
    {

        delete[] stu;
    }
};

void openFile()
{
    ifstream myFile("student.txt");
    if (!myFile.is_open())
    {
        cout << "File can't be opened" << endl;
    }
    else
    {
        string line;
        cout << "File is opened successfully" << endl;
        if (myFile.eof())
            throw runtime_error("GradeBook is Empty");
        while (!myFile.eof())
        {
            getline(myFile, line);
            cout << line << endl;
        }
        myFile.close();
        cout << "Previous Entries" << endl;
        cout << "---------------------------------------" << endl;
        cout << "---------------------------------------" << endl;
        cout << "---------------------------------------" << endl;
        cout<<endl;
    }
}

int main()
{

    cout << "---------------------------------------" << endl;
    static int n;
    cout << "Enter no. of students: ";
    cin >> n;

    if (n <= 0)
    {
        throw runtime_error("Atleast 1 student is required. Please enter a valid no. of students.");
    }

    openFile();

    gradebook g(n);
    g.manageStudents();

    // students stu[n];

    // for (int i = 0; i < n; i++)
    // {
    //     int roll, p, c, m;
    //     string name;

    //     cout << "Enter details for student " << i + 1 << ": \n";
    //     cout << "Enter Roll No. : ";
    //     cin >> roll;
    //     cout << "Enter name: ";
    //     cin >> name;
    //     cout << "Enter No. of marks in 3 subjects: ";
    //     cin >> p >> c >> m;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (roll == stu[j].getRoll())
    //         {
    //             throw runtime_error("Roll No. " + to_string(stu[j].getRoll()) + " already exists.");
    //         }
    //     }
    //     if (p > 100 || c > 100 || m > 100 || p < 0 || c < 0 || m < 0)
    //     {
    //         throw runtime_error("Invalid marks. Marks should be b/w 0 to 100.");
    //     }
    //     stu[i] = students(roll, name, p, c, m);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Student " << i + 1 << ": " << endl;

    //     stu[i].display(n);
    // }

    return 0;
}