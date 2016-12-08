///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Title:            P2.cpp
// Files:            Student.cpp, Database.cpp
// Semester:         (course) Spring 2016
//
// Author:           Michael Simon
// Email:            masimon2@wisc.edu
// CS Login:         msimon
// Lecturer's Name:  Deb Deppeler
//
//
//////////////////////////// 80 columns wide //////////////////////////////////

#include <iostream>
#include "Student.cpp"
#include "Database.cpp"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstddef>
#include <string>
#include <vector>

using namespace std;

/**
 * The main function reads in a file which is entered in the command line, and
 * and then reads the file line by line adding the information to the student,
 * and then entering that student into the database. It then asks for a command
 * and value from the user, which the program uses to process data that is in
 * the database, or end the program.
 *
 * @param int argc - number of arguments entered
 * @param char* argv[] - a pointer to the lits of arguments
 *
 * @return - 0 if the program ends
 * @return - a statement to be printed out to the user based
 * on a command.
 */
int main(int argc, char* argv[]) {

    //list of variables to be used
    char command;
    int value = 0;
    Database inputDatabase(0);
    ifstream myfile;
    vector<string> input;
    int filesize = 0;
    int i = 0;
    Student newStudent = Student(0,0);
    int tmp1 = 0;
    int tmp2 = 0;
    int tmp3 = 0;
    int tmp4 = 0;
    string tmp5;
    char* tmp6;
    int inputNumStudents;
    string getInput;

    //checks to see if the amount of commands entered is valid
    //and opens the file if there is the correct amount
    if (argc < 2) {
        cout << "Invalid File \n";
        exit(0);
    }
    else {
        myfile.open(argv[1]);
    }

    if (!myfile.is_open()) {
        cout << "Invalid File \n";
        exit(0);
    }

    //reads the first line of the file and creates the database
    //the size of the given amount. Goes through the rest of
    //the lines in the file, converts them from a string
    //to integers or a char* (if its a grade), stores the info
    //for the student, and then adds that student to the
    //database when that student's info is done being read.
    for (std::string line; getline(myfile, line); i++) {
        if (i == 0) {
            input.push_back(line);
            filesize++;
            inputNumStudents = std::stoi(input[0], 0);
            inputDatabase = Database(inputNumStudents);
        }
        else {
            if (i % 2 == 1) {
                input.push_back(line);
                filesize++;
               tmp1 = std::stoi(line.substr(0, line.find(' ')), 0);
               tmp2 = std::stoi(line.substr(line.find(' '),
                                             line.find(' ')), 
					     0);
                newStudent = Student(tmp1, tmp2);
            } else if (i % 2 == 0) {
                input.push_back(line);
                filesize++;
                for (int j = 0; j < tmp2; j++) {
                    tmp3 = stoi(line.substr(0, line.find(' ')), 0);
                    line.erase(0, line.find(' ') + 1);
                    tmp4 = std::stoi(line.substr(0, line.find(' ')), 
						 0);
                    line.erase(0, line.find(' ') + 1);
                    tmp5 = line.substr(0, line.find(' '));
                    //line.erase(0, line.find(' ') + 1);
                    //tmp6 = (char *) std::stoi(line.substr(0,line.find(' ')), 0);
                    tmp6 = (char *) tmp5.c_str();
                    line.erase(0, line.find(' ') + 1);
		    newStudent.addStudentCourseInfo(tmp3, tmp4, tmp6);
                }
                inputDatabase.addStudent(newStudent);
            }
        }
    }

    cout << "Welcome! \n";

    bool valid = false;

    //the main while loop that reads in a command and a value (if needed)
    //from the user, checks to see if the command and value are valid,
    //and then processes data based on the given command.
    //runs until the user enters 'q' or 'Q' for quit.
    while (command != 'q' || command != 'Q') {
        command  = 0;
        cout << ">";
        cin >> command;
        if (command == 'h' || command == 'H' || command == 'n' ||
                command == 'N' || command == 'q' || command == 'Q') {

            inputDatabase.dataProcess(command, value);
            valid = true;
        } else if (command == 'g' || command == 'G' || command == 'c' ||
                    command == 'C' || command == 'p' || command == 'P') {
            cin >> value;
            valid = true;

            if ((command == 'g' && (value <= 10000 || value >= 99999)) ||
                (command == 'G' && (value <= 10000 || value >= 99999)) ||
                (command == 'c' && (value <= 0 || value >= 1000)) ||
                (command == 'C' && (value <= 0 || value >= 1000)) ||
                (command == 'p' && value >= 4) ||
                (command == 'P' && value >= 4)) {
                cout << "Invalid Input\n";
            } else {
                inputDatabase.dataProcess(command, value);
            }
        }

        if (!valid) {
            cout << "Invalid Command. Need help?\n";
            inputDatabase.dataProcess('h', value);
        }
    }
    return 0;
}
