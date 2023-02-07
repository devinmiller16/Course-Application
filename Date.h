#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>

class Date { //Class that takes the tokenized date and sets it equal to the day, month, and year.
	friend std::ostream& operator<<(std::ostream&, Date);
public:
	Date(int d = 0, int m = 0, int yyyy = 0) {
		setDate(d, m, yyyy);
	}
	~Date() {}
	void setDate(int  d, int m, int yyyy) {
		day = d;
		month = m;
		year = yyyy;
	}
private:
	int day;
	int month;
	int year;
};
std::ostream& operator<<(std::ostream& output, Date d) { //Overload function to output the date in a certain format.
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}
