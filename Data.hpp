#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

using namespace std;

class Date {
// Modul type: date
// Type description: it representate a date maked by three
// integers for store the day, month and year of a date.

private:
	int day;
	int month;
	int year;

public:
	//*********************************************************
	// Builders
	//*********************************************************

	// Pre: true.
	// Post: it creates a empty date.
	Date ();

	// Pre: true.
	// Post: it creates a date with a day, month and year received by parameter.
	Date(int day, int month, int year);

	//*********************************************************
	// Destroyer
	//*********************************************************

	// Default destroyer
	~Date();

	//*********************************************************
	// Getters
	//*********************************************************

	// Pre: true
	// Post: it returns day atribute of implicit parameter.
	int getDay() const;

	// Pre: true
	// Post: it returns month atribute of implicit parameter.
	int getMonth() const;

	//pre: true
	//post: it returns year atribute of implicit parameter
	int getYear() const;

	//pre: true
	//post: returns a boolean, true if the implicit parameter date is
	// previous than the date received, false in other case.
	bool operator>(const Date &d) const;

	//pre: true
	//post: returns a boolean, true if the implicit parameter date is
	// posterior than the date received, false in other case.
	bool operator<(const Date &d) const;

	//pre: true
	//post: return a boolean true if d is equal to the implicit parameter, false in other case.
	bool operator==(const Date &d) const;

	//pre: true
	//post: return a boolean, true if the implicit parameter and d are different, false in other case.
	bool operator!=(const Date &d) const;


	//*********************************************************
	// reading and writting
	//*********************************************************

	//pre: three integers are prepared in the standart input chanel.
	//post: d date is fil up with the integers readed in the standart input chanel.
	//like day, month and year in order.
	friend istream& operator>>(istream &is, Date &d);

	//pre: true
	//post: day, month and year atributes of d date are written
	//in the standart output channel.
	friend ostream& operator<<(ostream &os, const Date &d);
};
#endif
