///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Main Class File:  P2.cpp
// File:             Database.cpp
// Semester:         CS368 Spring 2016
//
// Author:           Michael Simon
// CS Login:         msimon
// Lecturer's Name:  Deb Deppeler
//
//////////////////////////// 80 columns wide //////////////////////////////////

/**
 * This is the Database class, and it contains a function to create the
 * Database with a given amount of students, a function to add a student
 * to the database, a function to get the number of students in the
 * database, and a function to process the data in the database with a
 * user entered command
 *
 * @author Michael Simon
 */

#include <vector>
#include "Student.h"
#include <iostream>
#include "Database.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * This constructor creates the initial database with a given amount
 * of students.
 *
 * @param int nStudents - the number of students in the database
 */
Database::Database(int nStudents) {
    //Database studentDatabase(nStudents);
    this->numStudents = nStudents;
    this->students[nStudents];
};

/**
 * This function adds a student to the database
 *
 * @param Student student - the object of type student to
 * be entereed into the database.
 */
void Database::addStudent(Student student) {
    this->students.push_back(student);
};

/**
 * This function gets the number of students in the database
 *
 * @return this->numStudents - number of students in the given
 * database.
 */
int Database::getNumStudents() {
    return this->numStudents;
};

/**
 * This function processes the command and value entered by the user.
 * It checks to see what command and value the user entered, and
 * then processes data based on that command.
 *
 * @param char command - command entered by the user
 * @param int value - value entetered by the user
 */
void Database::dataProcess(char command, int value) {

    //if user enters h then shows the available options
    if (command == 'h' || command == 'H') {
        cout << "You can enter the following valid commands:\n";
        cout << "n: displays the number of students currently in the "
                        "database\n";
        cout << "c num: displays the number of students and who took course "
                        "'num'. It also prints the student id numbers of "
                        "those students\n";
        cout << "g student_id: displays the GPA of student with student id "
                        "number given\n";
        cout << "p num: displays the number of students with a GPA greater "
                        "than 'num'. It also prints the student id numbers "
                        "of those students\n";
        cout << "q: will exit the program\n";
    }
    //if user enters n, shows the number of students
    else if (command == 'n' || command == 'N') {
        cout << this->numStudents << "\n";
    }
    //if user enters c and a value, shows the number of students who took
    //the course with the entered value
    else if (command == 'c' || command == 'C') {
        int numTaken = 0;
        vector<int> taken;
        for (int i = 0; i < this->numStudents; i++) {
                if (this->students[i].tookCourse(value)) {
                    numTaken++;
                    taken.push_back(this->students[i].getId());
                }
        }
        cout << numTaken << "\n";

        if (numTaken > 0) {
            for (int j = 0; j < numTaken; j++) {
                cout << taken[j] << " ";
            }
            cout << "\n";
        }
    }
    //if user enters g and a value, the gpa of that
    //student is displayed
    else if (command == 'g' || command == 'G') {
        for (int i = 0; i < getNumStudents(); i++) {
            if(this->students[i].getId() == value) {
                float gpa = this->students[i].getGPA();
                printf("%.5f\n", gpa);
            }
        }
    }
    //if user enters p and a value, it shows the number of students
    //with a gpa greater than the entered value
    else if (command == 'p' || command == 'P') {
        vector<int> greaterThan;
        int numGreater = 0;
        for (int i = 0; i < this->numStudents; i++) {
            if (this->students[i].getGPA() > value) {
                numGreater++;
                greaterThan.push_back(this->students[i].getId());
            }
        }
        cout << numGreater << "\n";
        for (int j =0; j < numGreater; j++) {
            printf("%.5d ", greaterThan[j]);
        }
        cout << "\n";
    }
};

