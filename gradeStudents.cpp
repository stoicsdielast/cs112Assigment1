/*  CS112: Data Structures & Algorithms,
	Assignment 1 – Semester II, 2024,
	A Student Grade Calculator Program. 
	
	
	Group Partner Names & Id:
	Parvish Mohan - s11230414
	Tanzeel Hussain - s11230375
	
	Campus: Laucala, Suva, Fiji.
	Mode: F.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 20;  // Maximum number of students

class Student { 
public:
    string ID;
    double courseWork;
    double finalExam;
};

//prototype for functions, more details at the actual function body
void readData(Student students[], int& total_records); 
string calculateGrade(double totalMarks);  //Calculates grades from the USP Handbook 2024
void updateMarks(Student students[], int total_records, string id, double courseWork, double finalExam); //Replaces marks stored in txt through user input 
void printDetails(Student students[], int total_records); //Presents General Information
void printAverageMarks(Student students[], int total_records); 
void printPassRate(Student students[], int total_records);   
void discard_line(ifstream& in);//discards first line of txt file 

int main() {
    Student students[MAX_SIZE];
    int total_records = 0;  
    int choice;
    string id;
    double courseWork, finalExam;

    readData(students, total_records); 
   
    do {
        cout <<"\n"
			 << "|-----------------------------------------------------------|\n"
        	 << "|             A Student Grade Management Program            |\n"
        	 << "|-----------------------------------------------------------|\n"
        	 << "|Program Menu Tab:                                          |\n"  
             << "|(1) Update Student Mark.                                   |\n" 
             << "|(2) Print Enter Student Details.                           |\n" 
             << "|(3) Show the average marks.                                |\n"
			 << "|(4) Show Pass Rate.                                        |\n" 
			 << "|(5) Exit the program.                                      |\n"
             << "|-----------------------------------------------------------|\n";

        cout << "Enter the number of your choice: ";
        cin >> choice;
        cout <<"\n";
        if (choice == 1) {
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter new coursework marks: ";
            cin >> courseWork;
            cout << "Enter new final exam marks: ";
            cin >> finalExam;
            updateMarks(students, total_records, id, courseWork, finalExam); // replaces the original marks with user input 
        }
        else if (choice == 2) {
            printDetails(students, total_records);
        }
        else if (choice == 3) {
            printAverageMarks(students, total_records);
        }
        else if (choice == 4) {
            printPassRate(students, total_records);
        }
    } while (choice != 5); // exits the loops once user presses option 3
    
	system("PAUSE");
    return 0;
}

void readData(Student students[], int& total_records) { // this functions reads the txt file named studentData.txt
    ifstream input("studentData.txt");
    if (!input) {
        cerr << "File could not be opened" << endl;
        exit(1);
    }

    discard_line(input);

    while (input >> students[total_records].ID >> students[total_records].courseWork >> students[total_records].finalExam) {
        total_records++;
        if (total_records > MAX_SIZE) {
            cout << "Maximum student records reached!" << endl;
            break;
        }
    }

    input.close();
}

void discard_line(ifstream &in) { //discards the first line of txt file to read 
    char c;
    do {
        in.get(c);
    } while (c != '\n');
}

string calculateGrade(double totalMarks) {  //this function calculates the grades from the USP handbook 2024, string is used to proved more than char
    if (totalMarks >= 85) return "A+";
    else if (totalMarks >= 78) 
	return "A";
    else if (totalMarks >= 71) 
	return "B+";
    else if (totalMarks >= 64) 
	return "B";
    else if (totalMarks >= 57) 
	return "C+";
    else if (totalMarks >= 50) 
	return "C";
    else 
	return "F";
}

void updateMarks(Student students[], int total_records, string id, double courseWork, double finalExam) { // Updates student marks
    for (int i = 0; i < total_records; i++) {
        if (students[i].ID == id) {
            students[i].courseWork = courseWork;
            students[i].finalExam = finalExam;
            cout << "Marks updated successfully." << endl;
            return;
        }
    }
    cout << "Student ID not found." << endl;
}

void printDetails(Student students[], int total_records) { // prints general details 
    double totalMarks = 0.0;
    int passCount = 0;
    Student topStudent = students[0];

    cout <<"    "<< "ID" <<"          "<< "Coursework" <<"    "<< "Final Exam" <<"     "<< "Total" << "      "<< "Grade" << endl;
    for (int i = 0; i < total_records; i++) {
        double total = students[i].courseWork + students[i].finalExam;
        string grade = calculateGrade(total);  
        totalMarks += total;
        if (grade != "F") passCount++;
        if (total > (topStudent.courseWork + topStudent.finalExam)) {
            topStudent = students[i];
        }
        cout << setw(10) << students[i].ID << setw(15) << students[i].courseWork << setw(15) << students[i].finalExam << setw(10) << total << setw(10) << grade << endl;
    }
    double avgMarks = totalMarks / total_records;
    double passRate = (double)passCount / total_records * 100;

    cout << "\nAverage Marks: " << fixed << setprecision(2) << avgMarks << endl;
    cout << "Pass Rate: " << fixed << setprecision(2) << passRate << "%" << endl;
    cout << "Top Scorer: " << topStudent.ID << " with " << topStudent.courseWork + topStudent.finalExam << " marks." << endl;
}


void printAverageMarks(Student students[], int total_records) {
    double totalMarks = 0.0;
    for (int i = 0; i < total_records; i++) {
        totalMarks += students[i].courseWork + students[i].finalExam;
    }
    double avgMarks = totalMarks / total_records;
    cout << "\nAverage Marks: " << fixed << setprecision(2) << avgMarks << endl;
}


void printPassRate(Student students[], int total_records) {
    int passCount = 0;
    for (int i = 0; i < total_records; i++) {
        double total = students[i].courseWork + students[i].finalExam;
        string grade = calculateGrade(total);
        if (grade != "F") passCount++;
    }
    double passRate = (double)passCount / total_records * 100;
    cout << "Pass Rate: " << setprecision(2) << passRate << "%" << endl;
}

