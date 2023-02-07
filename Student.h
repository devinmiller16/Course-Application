#pragma once
#include"Person.h"
#include<iomanip>

class Student: public Person {
	friend std::ostream& operator<<(std::ostream&, Student); //Overload function that outputs the student data in a neat format.
public:
	//Constructor
	Student() {}

	//Constructor with paramaters
	Student(Date dateOfEnrollment, std::string m, std::string lvl, double G, std::string id, std::string fName, std::string lName, Date bDay): Person(id, fName, lName, bDay) {
		dateEnrolled = dateOfEnrollment;
		major = m;
		level = lvl;
		GPA = G;
	}

	//Getter for date of enrollment
	Date getDateEnrolled() {
		return dateEnrolled;
	}

	//Getter for major
	std::string getMajor() {
		return major;
	}

	//Getter for level
	std::string getLevel() {
		return level;
	}

	//Getter for GPA
	double getGPA() {
		return GPA;
	}

	//Destructor
	~Student() {}

private:
	Date dateEnrolled;
	std::string major;
	std::string level;
	double GPA;
};

std::ostream& operator<<(std::ostream& output, Student s) { //Overload function that outputs the student data in a neat format.
	output << "Student ID: " << "\t\t" << s.getID() << std::endl;
	output << "Student Name: " << "\t\t" << s.getFirstName() << " " << s.getLastName() << std::endl;
	output << "Birth date: " << "\t\t" << s.getBirthDate() << std::endl;
	output << "Date Enrolled: " << "\t\t" << s.dateEnrolled << std::endl;
	output << "Major: " << "\t\t\t" << s.major << std::endl;
	output << "Level: " << "\t\t\t" << s.level << std::endl;
	output << "GPA: " << "\t\t\t" << s.GPA << std::endl << std::endl;

	return output;
}