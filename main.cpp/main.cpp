// ? ASSIGNMENT 2

// SECJ1013 Programming Technique I

// Section: 1
// Member 1's Name: NISHAT TABASSUM111_____________ 
// Member 2's Name: __DHARANIE A/P ARMUGAM___________ 

// Log the time(s) your pair programming sessions
//  Date                    Time (From)   To             Duration (in minutes)
//  11.06.2025_________    10:40 PM___________                  11:25 am______
//  12.06.2025   ___________   12:03 PM    _                    1:08pm_______

// Video link: https://youtu.be/isiBJGLeMBA
//   _________
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ====================== STRUCT ======================
struct Student {
    string matricNo;
    double courseworkMarks;
    double examMarks;
    double totalMarks;
    string grade;
};

// ====================== GRADE FUNCTION ======================
string grade(double totalMarks) {
    if (totalMarks >= 90) return "A+";
    else if (totalMarks >= 80) return "A";
    else if (totalMarks >= 75) return "A-";
    else if (totalMarks >= 70) return "B+";
    else if (totalMarks >= 65) return "B";
    else if (totalMarks >= 60) return "B-";
    else if (totalMarks >= 55) return "C+";
    else if (totalMarks >= 50) return "C";
    else if (totalMarks >= 45) return "C-";
    else if (totalMarks >= 40) return "D+";
    else if (totalMarks >= 35) return "D";
    else if (totalMarks >= 30) return "D-";
    else return "E";
}


void getInputFile(ifstream &file, string &filename) {
    while (true) {
        cout << "Please enter the file name: ";
        cin >> filename;
        file.open(filename);
        if (file.is_open()) break;
        else {
            cout << "Sorry! Unable to open the file. Please try again." << endl;
            file.clear();
        }
    }
}


double calculateTotal(double coursework, double exam) {
    return coursework + exam;
}

// ====================== GENERATE REPORT ======================
void generateReport(ifstream &file) {
    string courseNameLine;
    getline(file >> ws, courseNameLine); // skip leading whitespace
    int numStudents;
    file >> numStudents;
    file.ignore(); // skip the newline after number
    file.ignore(); // skip the blank line

    vector<Student> students(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        file >> students[i].matricNo >> students[i].courseworkMarks >> students[i].examMarks;
        students[i].totalMarks = calculateTotal(students[i].courseworkMarks, students[i].examMarks);
        students[i].grade = grade(students[i].totalMarks);
    }

    // Calculate Averages
    double totalCoursework = 0, totalExam = 0, totalOverall = 0;
    for (const auto &s : students) {
        totalCoursework += s.courseworkMarks;
        totalExam += s.examMarks;
        totalOverall += s.totalMarks;
    }
    double avgCoursework = totalCoursework / numStudents;
    double avgExam = totalExam / numStudents;
    double avgTotal = totalOverall / numStudents;

    // Print Report
    cout << fixed << setprecision(2);
    cout << "Performance Report for " << courseNameLine << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << left << setw(4) << "No"
         << setw(20) << "Student Matric No."
         << setw(18) << "Coursework Mark"
         << setw(12) << "Exam Mark"
         << setw(13) << "Total Mark"
         << "Grade" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    for (int i = 0; i < numStudents; ++i) {
        cout << left << setw(4) << i + 1
             << setw(20) << students[i].matricNo
             << setw(18) << students[i].courseworkMarks
             << setw(12) << students[i].examMarks
             << setw(13) << students[i].totalMarks
             << students[i].grade << endl;
    }

    cout << "-----------------------------------------------------------------------" << endl;
    cout << left << setw(24) << "Class Average:"
         << setw(18) << avgCoursework
         << setw(12) << avgExam
         << setw(13) << avgTotal
         << grade(avgTotal) << endl;
}
int main() 
{
ifstream file;
string filename;
getInputFile(file,filename);
generateReport(file);
file.close();
system("pause");
    return 0;

}
