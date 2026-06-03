 #include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    int choice;

    cout << "===============================================================\n";
    cout << "                  CGPA CALCULATOR SYSTEM\n";
    cout << "===============================================================\n";

    cout << "\n1. Single Semester CGPA Calculator\n";
    cout << "2. Multi Semester CGPA Calculator\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    // ===========================================================
    // CASE 1 : SINGLE SEMESTER
    // ===========================================================

    if (choice == 1) {

        int numCourses;

        cout << "\n===============================================================\n";
        cout << "               SINGLE SEMESTER CALCULATOR\n";
        cout << "===============================================================\n";

        cout << "\nEnter number of courses: ";
        cin >> numCourses;

        string courseNames[100];
        string grades[100];

        double gradeValues[100];
        double creditHours[100];
        double gradePoints[100];

        double totalCredits = 0;
        double totalGradePoints = 0;

        cin.ignore();

        for (int i = 0; i < numCourses; i++) {

            cout << "\n--------------------------------------------------\n";
            cout << "Course " << i + 1 << endl;
            cout << "--------------------------------------------------\n";

            cout << "Course Name : ";
            getline(cin, courseNames[i]);

            cout << "Grade (A+/A/B+/B/C+/C/D/F) : ";
            cin >> grades[i];

            // Grade Conversion

            if (grades[i] == "A+")
                gradeValues[i] = 10;

            else if (grades[i] == "A")
                gradeValues[i] = 9;

            else if (grades[i] == "B+")
                gradeValues[i] = 8.25;

            else if (grades[i] == "B")
                gradeValues[i] = 7.50;

            else if (grades[i] == "C+")
                gradeValues[i] = 6.75;

            else if (grades[i] == "C")
                gradeValues[i] = 6;

            else if (grades[i] == "D")
                gradeValues[i] = 5;

            else if (grades[i] == "F")
                gradeValues[i] = 0;

            else {
                cout << "Invalid Grade! Setting to 0\n";
                gradeValues[i] = 0;
            }

            cout << "Credit Hours : ";
            cin >> creditHours[i];

            gradePoints[i] =
                gradeValues[i] * creditHours[i];

            totalCredits += creditHours[i];
            totalGradePoints += gradePoints[i];

            cin.ignore();
        }

        double cgpa =
            totalGradePoints / totalCredits;

        // ================= REPORT =================

        cout << "\n\n";
        cout << "===============================================================\n";
        cout << "                 SINGLE SEMESTER REPORT\n";
        cout << "===============================================================\n";

        cout << left
             << setw(25) << "Course Name"
             << setw(10) << "Grade"
             << setw(15) << "Credits"
             << setw(15) << "Grade Points"
             << endl;

        cout << "---------------------------------------------------------------\n";

        for (int i = 0; i < numCourses; i++) {

            cout << left
                 << setw(25) << courseNames[i]
                 << setw(10) << grades[i]
                 << setw(15) << creditHours[i]
                 << setw(15) << gradePoints[i]
                 << endl;
        }

        cout << "---------------------------------------------------------------\n";

        cout << left << setw(25)
             << "Total Credits"
             << ": "
             << totalCredits << endl;

        cout << left << setw(25)
             << "Total Grade Points"
             << ": "
             << totalGradePoints << endl;

        cout << left << setw(25)
             << "CGPA"
             << ": "
             << fixed << setprecision(2)
             << cgpa << endl;

        cout << "===============================================================\n";
    }

    // ===========================================================
    // CASE 2 : MULTI SEMESTER
    // ===========================================================

    else if (choice == 2) {


    int numSemesters;

    cout << "\n===============================================================\n";
    cout << "                MULTI SEMESTER CALCULATOR\n";
    cout << "===============================================================\n";

    cout << "\nEnter number of semesters: ";
    cin >> numSemesters;

    double grandTotalCredits = 0;
    double grandTotalGradePoints = 0;

    for (int sem = 1; sem <= numSemesters; sem++) {

        int numCourses;

        cout << "\n===============================================================\n";
        cout << "Semester " << sem << endl;
        cout << "===============================================================\n";

        cout << "Enter number of courses: ";
        cin >> numCourses;

        double semesterCredits = 0;
        double semesterGradePoints = 0;

        cin.ignore();

        for (int i = 0; i < numCourses; i++) {

            string courseName;
            string grade;

            double gradeValue;
            double credit;

            cout << "\n--------------------------------------------------\n";
            cout << "Course " << i + 1 << endl;
            cout << "--------------------------------------------------\n";

            cout << "Course Name : ";
            getline(cin, courseName);

            cout << "Grade (A+/A/B+/B/C+/C/D/F) : ";
            cin >> grade;

            // Grade Conversion

            if (grade == "A+")
                gradeValue = 10;

            else if (grade == "A")
                gradeValue = 9;

            else if (grade == "B+")
                gradeValue = 8.25;

            else if (grade == "B")
                gradeValue = 7.50;

            else if (grade == "C+")
                gradeValue = 6.75;

            else if (grade == "C")
                gradeValue = 6;

            else if (grade == "D")
                gradeValue = 5;

            else if (grade == "F")
                gradeValue = 0;

            else {
                cout << "Invalid Grade! Setting to 0\n";
                gradeValue = 0;
            }

            cout << "Credit Hours : ";
            cin >> credit;

            double gp = gradeValue * credit;

            semesterCredits += credit;
            semesterGradePoints += gp;

            cin.ignore();
        }

        double semesterGPA =
            semesterGradePoints / semesterCredits;

        cout << "\n--------------------------------------------------\n";
        cout << "Semester " << sem << " Summary\n";
        cout << "--------------------------------------------------\n";

        cout << left << setw(25)
             << "Semester Credits"
             << ": "
             << semesterCredits << endl;

        cout << left << setw(25)
             << "Semester Grade Points"
             << ": "
             << semesterGradePoints << endl;

        cout << left << setw(25)
             << "Semester GPA"
             << ": "
             << fixed << setprecision(2)
             << semesterGPA << endl;

        cout << "--------------------------------------------------\n";

        grandTotalCredits += semesterCredits;
        grandTotalGradePoints += semesterGradePoints;
    }

    double finalCGPA =
        grandTotalGradePoints / grandTotalCredits;

    cout << "\n\n";
    cout << "===============================================================\n";
    cout << "                    FINAL CGPA REPORT\n";
    cout << "===============================================================\n";

    cout << left << setw(30)
         << "Total Credits"
         << ": "
         << grandTotalCredits << endl;

    cout << left << setw(30)
         << "Total Grade Points"
         << ": "
         << grandTotalGradePoints << endl;

    cout << left << setw(30)
         << "Final CGPA"
         << ": "
         << fixed << setprecision(2)
         << finalCGPA << endl;

    cout << "===============================================================\n";
}
            
       

        
    else {

        cout << "\nInvalid Choice!\n";
    }

    return 0;
}