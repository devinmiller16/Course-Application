#pragma once
#include"Student.h"
#include"Faculty.h"
#include<vector>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>

class Course { //Class that stores the information of the course.
public:
	//Constructor
	Course() {}

	//Constructor with paramaters
	Course(std::string courseName, int classCapacity) {
		capacity = classCapacity;
		name = courseName;
	}

	//Function to print the date of the class
	void printData(int studentsInClass) {
		std::cout << "Information for Course " << name << std::endl;
		if (instructor.empty()) //If there is no instructor assigned to the course yet.
		{
			std::cout << "No instructor has been assigned to the course." << std::endl;
		}
		else { //If there is an instructor assigned.
			std::cout << instructor[0];
		}

		std::sort(students.begin(), students.end()); //Sorts the vector of students.
		if (students.empty()) { //If there are no students currently enrolled.
			std::cout << "No students are enrolled in the course." << std::endl << std::endl;
		}
		else { //If there are students enrolled the function outputs the vector students.
			std::cout << "These are the Students enrolled in the " << name << " course:" << std::endl;
			for (int i = 0; i < students.size(); i++) {
				std::cout << students.at(i) << std::endl;
			}
		}
	}


	//Function to enroll a student in the course
	void enroll() { 

		int m, d, y;
		Date bDay, enrollDate;  //date object; holds date after tokenization
		std::string ID, firstName, lastName, major, level;
		char birthDate[20], dateOfEnrollment[20]; //holds the date the user entered in char array
		double GPA;

		if (students.size() > capacity) { //If the vector is greater than the capacity no more students can be enrolled.
			std::cout << "The Class is full. No more students can be added." << std::endl << std::endl;
		}
		else { //If there is still room in the course enroll a student.
			std::cout << "Create a Student" << std::endl << std::endl << std::endl;

			std::cout << "ID: ";
			std::cin >> ID;
			while (std::cin.fail() || std::string::npos != ID.find_first_not_of("0123456789") || ID.size() == 0) { //Error checking loop for student ID.
				if (ID.size() == 0) {
					std::cout << "ERROR! You must enter in a student ID. Please try again: ";
				}
				else if (std::string::npos != ID.find_first_not_of("0123456789")) {
					std::cout << "ERROR! Student ID must only contain numbers. Please try again: ";
				}
				std::cin.clear();
				std::cin >> ID;
			}
			std::cout << std::endl << std::endl;

			std::cout << "First Name: ";
			std::cin >> firstName;
			std::cin.ignore(); //Ignores the next blank character.
			firstName = errorCheck(firstName); //Invokes the error check function and sets the return value equal to the first name.
			std::cout << std::endl << std::endl;

			std::cout << "Last Name: ";
			std::cin >> lastName;
			std::cin.ignore(); //Ignores the next blank character.
			lastName = errorCheck(lastName); //Invokes the error check function and sets the return value equal to the last name.
			std::cout << std::endl << std::endl;

			std::cout << "Birthdate (mm/dd/yyyy): ";
			std::cin >> birthDate;
			std::cin.ignore(); //Ignores the next blank character.
			tokenizeDate(birthDate, m, d, y); //separates char array into month, day, and year
			bDay.setDate(d, m, y); //sets the date of the object using the parsed values
			std::cout << std::endl << std::endl;

			std::cout << "Major: ";
			getline(std::cin, major);
			major = errorCheck(major); //Invokes the error check function and sets the return value equal to the students major.
			std::cout << std::endl << std::endl;

			std::cout << "Level (Freshman, Sophomore, Junior, Senior): ";
			std::cin >> level;
			level = errorCheck(level); //Invokes the error check function and sets the return value equal to the students level.
			std::cout << std::endl << std::endl;

			std::cout << "GPA: ";
			std::cin >> GPA;
			while (GPA < 0 || GPA > 4) //Error checking function for the students GPA.
			{
				if (GPA < 0) {
					std::cout << "GPA cannot be a negative number. Please try again: ";
				}
				else if (GPA > 4) {
					std::cout << "GPA cannot be greater than 4. Please try again: ";
				}
				std::cin.clear();
				std::cin >> GPA;
			}
			std::cout << std::endl << std::endl;

			std::cout << "Date of Enrollment: ";
			std::cin >> dateOfEnrollment;
			tokenizeDate(dateOfEnrollment, m, d, y); //separates char array into month, day, and year
			enrollDate.setDate(d, m, y); //sets the date of the object using the parsed values
			std::cout << std::endl << std::endl << std::endl;

			students.push_back(Student(enrollDate, major, level, GPA, ID, firstName, lastName, bDay)); //Adds the student to the vector.
		}
	}

	//Function to add an instructor to the course
	void addInstructor() {
		int m, d, y;
		std::string ID, firstName, lastName, title, rank;
		Date birthDate, dateOfHire;
		char bDay[20], dateHire[20];
		double salary;

		std::cout << "Create Faculty Member" << std::endl << std::endl << std::endl;

		std::cout << "ID: ";
		std::cin >> ID;
		while (std::cin.fail() || std::string::npos != ID.find_first_not_of("0123456789") || ID.size() == 0) { //Error checking function for the Faculty ID.
			if (ID.size() == 0) {
				std::cout << "ERROR! You must enter in a student ID. Please try again: ";
			}
			else if (std::string::npos != ID.find_first_not_of("0123456789")) {
				std::cout << "ERROR! Student ID must only contain numbers. Please try again: ";
			}
			std::cin.clear();
			std::cin >> ID;
		}
		std::cout << std::endl << std::endl;

		std::cout << "First Name: ";
		std::cin >> firstName;
		std::cin.ignore(); //Ignores the next blank character.
		firstName = errorCheck(firstName); //Invokes the error check function and sets the return value equal to the Instructors first name.
		std::cout << std::endl << std::endl;

		std::cout << "Last Name: ";
		std::cin >> lastName;
		std::cin.ignore(); //Ignores the next blank character.
		lastName = errorCheck(lastName); //Invokes the error check function and sets the return value equal to the Instructors last name.
		std::cout << std::endl << std::endl;

		std::cout << "Birthdate (mm/dd/yyyy): ";
		std::cin >> bDay;
		std::cin.ignore(); //Ignores the next blank character.
		tokenizeDate(bDay, m, d, y); //separates char array into month, day, and year
		birthDate.setDate(d, m, y); //sets the date of the object using the parsed values
		std::cout << std::endl << std::endl;

		std::cout << "Title: ";
		getline(std::cin, title);
		title = errorCheck(title); //Invokes the error check function and sets the return value equal to the Instructors title.
		std::cout << std::endl << std::endl;

		std::cout << "Rank: ";
		getline(std::cin, rank);
		rank = errorCheck(rank); //Invokes the error check function and sets the return value equal to the Instructors rank.
		std::cout << std::endl << std::endl;

		std::cout << "Salary: ";
		std::cin >> salary;
		while (std::cin.fail() || salary < 0) { //Salary error checking function.
			std::cout << "Salary cannot be a negative number. Please try again: ";
			std::cin.clear();
			std::cin >> salary;
		}
		std::cout << std::endl << std::endl;

		std::cout << "Date of Hire: ";
		std::cin >> dateHire;
		tokenizeDate(dateHire, m, d, y); //separates char array into month, day, and year
		dateOfHire.setDate(d, m, y); //sets the date of the object using the parsed values
		std::cout << std::endl << std::endl << std::endl;

		instructor.push_back(Faculty(title, rank, salary, dateOfHire, ID, firstName, lastName, birthDate)); //Adds the Instructor to the instructor vector.
	}

	std::string errorCheck(std::string s) { //Function that does basic error checking for strings. 
		while (std::cin.fail() || s.size() == 0 || s.size() < 2 || std::string::npos != s.find_first_of("0123456789")) {
			if (s.size() == 0) {
				std::cout << "ERROR! You must enter in something. Please try again: ";
			}
			else if (s.size() < 2) {
				std::cout << "ERROR! You must enter in more than 1 character. Please try again: ";
			}
			else if (std::string::npos != s.find_first_of("0123456789")) {
				std::cout << "ERROR! You cannot enter in numbers. Please try again: ";
			}
			std::cin.clear();
			getline(std::cin, s);
		}
		return s;
	}
	void tokenizeDate(char* cDate, int& month, int& day, int& year) //Function that tokenizes the date.
	{
		char seps[] = "/";
		char* token = NULL;
		char* next_token = NULL;

		token = NULL;
		next_token = NULL;
		// Establish string and get the tokens:  
		token = strtok_s(cDate, seps, &next_token);
		month = atoi(token);
		token = strtok_s(NULL, seps, &next_token);
		day = atoi(token);
		token = strtok_s(NULL, seps, &next_token);
		year = atoi(token);
	}

	//Destructor
	~Course() {}
private:
	std::vector<Faculty> instructor; //Vector to store the Instructor.
	std::string name; //Stores the name of the course.
	std::vector<Student> students; //Vector to store the students in the class.
	int capacity;
};
