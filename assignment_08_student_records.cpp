// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};


void add_student(vector<Student>& students) {
    Student student;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    int num_scores;
    cout << "How many scores? ";
    cin >> num_scores;

    for (int i = 0; i < num_scores; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;

        student.scores.push_back(score);
    }

    students.push_back(student);

    cout << "Student \"" << student.name
         << "\" added successfully." << endl;
}


double calculate_average(const vector<double>& scores) {
    double total = 0;

    for (double score : scores) {
        total += score;
    }

    return total / scores.size();
}


void display_students(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << "------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name"
         << setw(15) << "ID"
         << setw(20) << "Scores"
         << "Average" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (const Student& student : students) {
        double average = calculate_average(student.scores);

        cout << left << setw(20) << student.name
             << setw(15) << student.id;

        for (int i = 0; i < student.scores.size(); i++) {
            cout << student.scores[i];

            if (i < student.scores.size() - 1) {
                cout << ", ";
            }
        }

        cout << "\t" << fixed << setprecision(2)
             << average << endl;
    }

    cout << "------------------------------------------------------------" << endl;
}


void student_average(const vector<Student>& students) {
    int student_id;

    cout << "Enter student ID: ";
    cin >> student_id;

    for (const Student& student : students) {
        if (student.id == student_id) {
            double average = calculate_average(student.scores);

            cout << student.name
                 << "'s average score: "
                 << fixed << setprecision(2)
                 << average << endl;

            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}


int main() {
    vector<Student> students;

    while (true) {
        cout << "\n================================" << endl;
        cout << "    STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;

        int choice;

        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "Error: Please enter a number from 1 to 4." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            add_student(students);
        }
        else if (choice == 2) {
            display_students(students);
        }
        else if (choice == 3) {
            student_average(students);
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Error: Invalid choice. "
                 << "Please select a number from 1 to 4." << endl;
        }
    }

    return 0;
}