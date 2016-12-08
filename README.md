# cs368_p2

This project was done for my cs368 - C++ for Java Programmers course at the University of Wisconsin-Madison.

Description:
For this assignment you will use command-line arguments, read an input file, and implement with two instantiable classes. 

Specifications:
In this assignment, you'll implement these classes: 
1. Student class
2. Database class

The Student Class
The Student class is used to represent individual students. Each Student object will contain the fields specified here. 
The header file containing the interface for the Student class is given in Student.h. 

The Database Class
The Database class contains all the Student objects. The Database class will provide some global information obtained from all students, 
via its own methods. The header file containing the interface for the Database class is given in Database.h.

Main Command Menu Loop
Once you are done reading and parsing the input file to load the database, you will accept commands from the users. 

The main program loop will display a command prompt with '>' character on a new line, process the given command, repeat the prompt.  
The command loop will keep on accepting commands until the user enters 'q' to quit the program. The following commands are valid and 
must be executed as described. Each command is a single character and some commands have an additional argument.

h: displays list of available commands to the user

n: displays the number of students currently in the database

c num:displays the number of students who took course 'num'. It also prints the student id numbers of those students.

g student_id: displays the GPA of student with student id number given

p num: displays the number of students with a GPA greater than 'num'. It also prints the student id numbers of those students.
