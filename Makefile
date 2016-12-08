main: P2.cpp Database.h Student.h Database.cpp Student.cpp Input.txt
	/s/gcc-5.1/bin/g++ -std=c++11 P2.cpp
P2.cpp: Database.h Student.h Database.cpp Student.cpp
	/s/gcc-5.1/bin/g++ -std=c++11 P2.cpp
Database.cpp: Database.h Student.h Student.cpp
	/s/gcc-5.1/bin/g++ -std=c++11 Database.cpp
Student.cpp: Database.h Student.h
	/s/gcc-5.1/bin/g++ -std=c++11 Student.cpp
