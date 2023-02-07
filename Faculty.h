#pragma once
#include"Person.h"


class Faculty: public Person { //Class that sets the Instructors information.
	friend std::ostream& operator<<(std::ostream&, Faculty); //Overload function to output the Instructors information.
public:
	//Default constructor 
	Faculty() {}

	//Constructor with paramaters
	Faculty (std::string t, std::string r, double s, Date dateOfHire, std::string ID, std::string firstName, std::string lastName, Date birthDate): Person(ID, firstName, lastName, birthDate) {
		title = t;
		rank = r;
		salary = s;
		dateHired = dateOfHire;
	}

	//Getter for title
	std::string getTitle() {
		return title;
	}

	//Getter for rank
	std::string getRank() {
		return rank;
	}

	//Getter for salary
	double getSalary() {
		return salary;
	}

	//Getter for date hired
	Date getDateHired() {
		return dateHired;
	}

	//Destructor
	~Faculty() {}

private:
	std::string title;
	std::string rank;
	double salary;
	Date dateHired;
};

std::ostream& operator<<(std::ostream& output, Faculty f) { //Overload function that outputs the Instructors information in a neat format.
	output << std::fixed << std::showpoint << std::setprecision(2);
	output << "Instructor: " << std::endl;
	output << "Faculty ID: " << "\t\t" << f.getID() << std::endl;
	output << "Faculty Name: " << "\t\t" << f.getTitle() << " " << f.getFirstName() << " " << f.getLastName() << ", " << f.getRank() << std::endl;
	output << "Birth Date: " << "\t\t" << f.getBirthDate() << std::endl;
	output << "Date Hired: " << "\t\t" << f.getDateHired() << std::endl;
	output << "Salary: " << "\t\t" << f.getSalary() << std::endl << std::endl;
	 
	return output;
}