#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Convert grade to points
int gradeToPoints(string grade) {
    if (grade == "O" || grade == "A+") return 10;
    else if (grade == "A") return 9;
    else if (grade == "B") return 8;
    else if (grade == "C") return 7;
    else if (grade == "D") return 6;
    else if (grade == "F") return 0;
    else return -1;
}

// Function to calculate GPA for one semester
float calculateSemesterGPA() {
    int numCourses;
    cout << "\nEnter number of courses: ";
    cin >> numCourses;

    float totalCredits = 0, totalGradePoints = 0;

    vector<string> grades(numCourses);
    vector<float> credits(numCourses);

    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << ":\n";

        while (true) {
            cout << "Enter grade (O, A+, A, B, C, D, F): ";
            cin >> grades[i];

            int points = gradeToPoints(grades[i]);
            if (points == -1) {
                cout << "Invalid grade! Try again.\n";
                continue;
            }

            cout << "Enter credit hours: ";
            cin >> credits[i];

            totalCredits += credits[i];
            totalGradePoints += points * credits[i];
            break;
        }
    }

    cout << "\n--- Course Details ---\n";
    for (int i = 0; i < numCourses; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credits: " << credits[i] << endl;
    }

    float gpa = totalGradePoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\nSemester GPA: " << gpa << endl;

    return gpa;
}

int main() {
    int choice;

    do {
        cout << "\n===== CGPA CALCULATOR =====\n";
        cout << "1. Calculate CGPA (Multiple Semesters)\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int numSemesters;
            cout << "\nEnter number of semesters: ";
            cin >> numSemesters;

            float totalCGPA = 0;

            for (int i = 0; i < numSemesters; i++) {
                cout << "\n--- Semester " << i + 1 << " ---\n";
                totalCGPA += calculateSemesterGPA();
            }

            float finalCGPA = totalCGPA / numSemesters;

            cout << fixed << setprecision(2);
            cout << "\n🎯 Final CGPA: " << finalCGPA << endl;
        }

    } while (choice != 2);

    cout << "\nThank you for using CGPA Calculator!\n";
    return 0;
}