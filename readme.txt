|-----------------------------------------------------------|
|             A Student Grades Management Program           |
|-----------------------------------------------------------|
By: -Parvish Mohan  (s11230414)
    -Tanzeel Hussain (s11230375)

Overview

This program is designed to manage student records by reading data from a file, calculating grades based on coursework and final exam marks, and providing functionalities to update student records and print details of all students. The structure of the program is modular due to the use of function and is open for the user to make changes easily. The program is written in C++ and adheres to basic C++ features, utilizing arrays of structs for proper encapsulation.

Files:
	main.cpp: The main source code file.
	studentData.txt: A text file containing the student data (ID, coursework marks, final 	exam marks).

Features:
 	Reading Data: Reads student records from a text file.
 	Grade Calculation: Calculates grades based on the total marks (coursework + final 	exam) from the University of the South Pacific's Handbook 2024.
 	Update Functionality: Allows the user to update a student's marks by their ID.
 	Printing Details: Displays all student records, average marks, pass rate, and the top 	scorer's details.

HOW TO RUN:
Prerequisites:

    A C++ compiler (such as g++, clang, or MSVC).
    The program was tested using Dev-C++ 4.9.9

Compiling the Program:
	To compile the program, use the following command in your terminal or command prompt:
	g++ -o gradeStudents main.cpp

Running the Program
	After compiling, run the program using:
	./gradeStudents

For windows run after compilation from an IDE:
	gradeStudents.exe


Ensure that the first line of the file contains headers and the actual data starts from the second line which would ensure the program is reading data correctly.

Upon running, the program will offer the following menu options:
	Update Marks: Allows you to update the marks of a student by entering their ID, new coursework marks, and final exam marks.
	Print Details: Details, Pass rate, Average Mark and details of the top scorer.
	Exit: Exits the program.

Have a wonderful day to the person reading this! Hope you love our program, do give us a feedback for us to improve on our program for the best user experience, thank you. 