//<Programming Assignment 7> -- Allows users to create a course, set its capacity, then add an instructor and students to the course.
//CSIS 112-<D01>
//<Citations if necessary> -- Example code used from "C++ Programming Assignment Instructions" by Terri Sipantzi.
//Sorting help from -- https://stackoverflow.com/questions/10308686/c-operator-overload-stl-sort-on-vector-of-my-custom-class

#include<iostream>
#include<string>
#include"Course.h"

using namespace std;

char printMenu(); //Function to print the menu

int main() {

	cout << "Devin Miller -- Programming Assignment 7" << endl << endl;

	int classCapacity;
	string courseName;
	char selection;
	bool go = true;
	Faculty instructor;
	int studentsInClass = 0, instructorInClass = 0;

	cout << "Enter a name for your Course: ";
	getline(cin, courseName); //Gets the name of the course as input.
	cout << endl;
	while (cin.fail() || courseName.size() == 0 || courseName.size() < 8) { //Error checking function for the course name.
		if (courseName.size() == 0) {
			cout << "ERROR! You must enter the name of the course. Please try again: ";
		}
		else if (courseName.size() < 8) {
			cout << "ERROR! The course name must be 8 characters long. Ex: CSIS 112. Please try again: ";
		}
		cin.clear();
		getline(cin, courseName);
		cout << endl << endl;
	}

	cout << "What is the maximum capacity for your Course? ";
	cin >> classCapacity;
	while (cin.fail() || classCapacity < 0) { //Error checking function for the class capacity.
		if (cin.fail()) {
			cout << "You must enter a number. Please try again: ";
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cout << "The number you entered was negative. Please try again: ";
		}
		cin >> classCapacity;
	}
	cin.ignore();
	cout << endl << endl;

	Course course1(courseName, classCapacity); //Passes the course name and class capacity to the constuctor of class Course.

	while (go) { //While go equals true this loop will continue.
		selection = printMenu(); //Sets the selection equal to the print menu function which returns the selection.

		switch (selection) { //Switch statements for the users selection.
		case 'i':
		case 'I': //If the user selects 'i'.
			if (instructorInClass < 1) {
				course1.addInstructor(); //Invokes the add instructor function.
				instructorInClass++; //Changes the instructors assigned to the class to one.
			}
			else
				cout << "An instructor has already been assigned to the course." << endl << endl; //If the user attempts to add more than one instructor this ouput statement occurs.
			break;
		case 's':
		case 'S': //If the user selects 's'.
			if (studentsInClass < classCapacity) { //Occurs only if the students in the class is less than the class capacity.
				course1.enroll(); //Invokes the enroll function to enroll a student in the course.
				studentsInClass++; //Adds one to the students in the class.
			}
			else {
				cout << "The class is full. No more students can be added." << endl << endl; //If the class is full this output statment occurs.
			}
			break;
		case 'l':
		case 'L': //If the user selects 'l'.
			course1.printData(studentsInClass); //Invokes the print data function which also passes the amount of students in the class.
			break;
		case 'q':
		case 'Q': //If the user selects 'q'.
			go = false; //Go is set to false.
			system("pause"); //Program ends.
			return 0;
			break;
		default:
			cout << "Invalid input! Please try again." << endl << endl; //If something other than 'i', 's', 'l' or 'q' is input into the program this output statment occurs.
		}

	}

	system("pause");
	return 0;
}

char printMenu() { //Function that prints out a menu 
	char selection;
	cout << "Main Menu" << endl << endl;
	cout << "I -- Add Instructor" << endl << endl;
	cout << "S -- Add Student" << endl << endl;
	cout << "L -- List Course Information" << endl << endl;
	cout << "Q -- Quit" << endl << endl;
	cout << "Selection: "; //Asks for the users selection
	cin >> selection;
	cout << endl << endl;

	return selection; //Returns the selection of the user.
}