///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Main Class File:  P2.cpp
// File:             Student.cpp
// Semester:         CS368 Spring 2016
//
// Author:           Michael Simon
// CS Login:         msimon
// Lecturer's Name:  Deb Deppeler
//
//////////////////////////// 80 columns wide //////////////////////////////////

/**
 *
 * This class is for the type Student. There's a function to create the
 * student, a function to get the student's gpa, a function to get the
 * number of courses for that student, a function to add the student's
 * course info, a function to see if the student took a course,
 * and a function to get that student's id number.
 *
 *
 * @author Michael Simon
 */
#include <vector>
#include <string>
#include "Student.h"

/**
 * This constructor creates an object for the student to be
 * entered into the database given the student's ID number
 * and number of courses
 *
 * @param int ID - the student's ID number
 * @param int numCoureses - the student's number of courses
 */
Student::Student(int ID, int numCourses) {
    //currentStudent.Courses(numCourses);
    this->studentID = ID;
    this->nCourses = numCourses;
};

/**
 * This function gets the student's gpa by going through
 * all the courses that the student is in, and converting
 * the letter grade into a point value. The total amount of
 * points and credits are caluclated, and then the total
 * amount of pooints is divided by the total amount of credits
 * to get the student's gpa.
 *
 * @return this->gpa - the gpa for a given student
 */
float Student::getGPA() {
    int totalCreds = 0;
    float points = 0;
    for (int i = 0; i < nCourses; i++) {
        float creds = this->Courses[i].credits;
        float gpaPoints = 0;
        string grades = this->Courses[i].grade;

        //checks to see what the letter grade is,
        //and then converts it to it's respective value
        if (grades[0] == 'A' || grades[0] == 'a') {
            if (grades[1] == 'B' || grades[1] == 'b') {
                gpaPoints = 3.5;
            }
            else {
                gpaPoints = 4;
            }
        } else if (grades[0] == 'B' || grades[0] == 'b') {
            if (grades[1] == 'C' || grades[1] == 'c') {
                gpaPoints = 2.5;
            }
            else {
                gpaPoints = 3;
            }
        } else if (grades[0] == 'C' || grades[0] == 'c') {
            gpaPoints = 2;
        } else if (grades[0] == 'D' || grades[0] == 'd') {
            gpaPoints = 1;
        } else {
            gpaPoints = 0;
        }
        points += gpaPoints * creds;
        totalCreds += creds;
    }

    this->gpa = points / totalCreds;
    return this->gpa;
};

/**
 * This function gets the number of courses for a given
 * student.
 *
 * @return this->nCourses - the number of courses for a
 * given student
 */
int Student::getNumCourses() {
    return this->nCourses;
};

/**
 * This function adds course info for a given student's course.
 * a course is created, and then the course number, credits,
 * and grade are added for this course. The course is then added
 * to the courses list for that given student.
 *
 * @param int courseNumber - course number of the course to be entered.
 * @param int numCredits - number of credits for course to be entered
 * @param char* letterGrade - letter grade for course to be entered.
 *
 */
void Student::addStudentCourseInfo(int courseNumber, int numCredits, char* letterGrade) {
    Coursetype course;
    course.courseNum = courseNumber;
    course.credits = numCredits;
    course.grade = std::string(letterGrade);
    this->Courses.push_back(course);
};

/**
 * This function checks to see if a given student
 * took a given course by going through each course
 * that the student took.
 *
 * @param int courseNumber - course number of the
 * course that we want to know if the student took.
 *
 * @return true - returns true if the student took
 * the course
 * @return false - returns false if the student
 * didn't take the course
 */
bool Student::tookCourse(int courseNumber) {
    for (int i = 0; i < this->nCourses; i++) {
        if (this->Courses[i].courseNum == courseNumber) {
            return true;
        }
    }
    return false;
};

/**
 * This function gets the student's ID number.
 *
 * @return this->studentID - the student ID
 * number of a given student
 */
int Student::getId() {
    return this->studentID;
};