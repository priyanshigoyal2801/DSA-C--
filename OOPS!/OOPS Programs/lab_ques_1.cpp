#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Student {
public:
    class Subject {  
    public:
        string name;
        float maxMarks;
        float obtainedMarks;

        void inputSubject() {
            cout << "Enter subject name: ";
            cin >> name;
            cout << "Enter maximum marks: ";
            cin >> maxMarks;
            cout << "Enter obtained marks: ";
            cin >> obtainedMarks;
        }
    };

    string studentName;
    Subject subjects[3];
    float averageMarks;

    void inputStudent() {
        cout << "Enter student name: ";
        cin >> studentName;
        float totalMarks = 0, totalObtained = 0;
        for (int i = 0; i < 3; ++i) {
            cout << "Enter details for subject " << i + 1 << ":" << endl;
            subjects[i].inputSubject();
            totalMarks += subjects[i].maxMarks;
            totalObtained += subjects[i].obtainedMarks;
        }
        averageMarks = (totalObtained / totalMarks) * 100;  // Calculate percentage
    }

    void displayStudent() const {
        cout << "Student Name: " << studentName << endl;
        cout << "Average Percentage: " << averageMarks << "%" << endl;
    }
};

bool compareStudents(const Student &s1, const Student &s2) {
    return s1.averageMarks > s2.averageMarks;  // Sorting in descending order of percentage
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];  // Dynamically allocate array of students

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        students[i].inputStudent();
    }

    // Sort students by percentage
    sort(students, students + n, compareStudents);

    // Display sorted students
    cout << "\nStudents sorted by percentage:\n";
    for (int i = 0; i < n; ++i) {
        students[i].displayStudent();
        cout << endl;
    }

    delete[] students;  // Free dynamically allocated memory
    return 0;
}
