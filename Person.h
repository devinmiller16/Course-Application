#pragma once
#include"Date.h"


class Person {
	friend std::ostream& operator<<(std::ostream&, Person); //Overload function that outputs a persons ID, name, and birthdate in a neat format.
	friend bool operator<(const Person p1, const Person p2); //Overload function that sorts the vector based on the students ID.
public:
	//Default constructor
	Person() {}

	//Constructor with parameters
	Person(std::string id, std::string fName, std::string lName, Date bDay) {
		ID = id;
		firstName = fName;
		lastName = lName;
		birthDate = bDay;
	}

	//Getter for ID
	std::string getID() {
		return ID;
	}

	//Getter for first name
	std::string getFirstName() {
		return firstName;
	}

	//Getter for last name
	std::string getLastName() {
		return lastName;
	}

	//Getter for birth date
	Date getBirthDate() {
		return birthDate;
	}

	//Destructor
	~Person() {}

private:
	std::string ID;
	std::string firstName;
	std::string lastName;
	Date birthDate;
};

std::ostream& operator<<(std::ostream& output, Person p) { //Overload function that outputs a persons ID, name, and birthdate in a neat format.
	output << "ID: " << p.ID << std::endl;
	output << "First Name: " << p.firstName << std::endl;
	output << "Last Name: " << p.lastName << std::endl;
	output << "Birth Date: " << p.birthDate << std::endl;

	return output;
}

bool operator<(const Person p1, const Person p2) { //Overload function that sorts the vector based on the students ID.
	return p1.ID < p2.ID;
}