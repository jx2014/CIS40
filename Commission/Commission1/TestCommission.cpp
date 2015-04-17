/************************

Commission

Project: Commission1
Purpose: More on programming with classes and objects
Author: Jeremy Xue Zhiming
Date: Apr 10th, 2015

Lab: 9

************************/

#include "LibIncludes.h"
#include "Commission.h"

#define CLASS 0
#define STRUCT 1
#define STRUCT_DEFAULT 0 // struct initalization with default values

#if STRUCT
struct Salesman
{
	string firstName;
	string lastName;
	string SSN;
	double baseSalary;
	double grossSales;
	double commissionRate;

#if STRUCT_DEFAULT
	Salesman() // initalization with default values
	{ 
		firstName = { "FirstName" };
		lastName = { "LastName" };
		SSN = { "123-45-6789" };
		baseSalary = { 500.0 };
		grossSales = { 300 };
		commissionRate = { 0.06 }; 
	}
#endif // endif STRUCT_DEFAULT

};// end of struct Salesman

void GetInfo(Salesman somebody)
{
	cout << setw(5) << left << "Name:" << setw(30) << right << somebody.firstName + ", " + somebody.lastName << '\n'
		<< setw(36) << setfill('-') << '\n'
		<< setfill(' ')
		<< setw(20) << left << "Social Security #:" << setw(15) << right << somebody.SSN << "\n"
		<< setw(20) << left << "Base salary:" << setw(4) << right << "$" << setw(11) << right << somebody.baseSalary << '\n'
		<< setw(20) << left << "Gross Sales:" << setw(4) << right << "$" << setw(11) << right << somebody.grossSales << '\n'
		<< setw(20) << left << "Commission Rate:" << setw(14) << right << somebody.commissionRate << '%' << '\n' << endl;
		//<< setw(20) << left << "Total Earnings:" << setw(4) << right << "$" << setw(11) << right << Earnings() << endl << endl;
}; // end of GetInfo(Salesman somebody)
#endif // end if STRUCT

#if TEST
//testing only
void test1(string & s)
{
	cout << "String1 is " << s << endl;
}

void test2(const string & s)
{
	cout << "String2 is " << s << endl;
}
#endif

void main()
{
	cout << setprecision(2) << fixed; // setting output format for digits	

#if STRUCT

#if STRUCT_DEFAULT
	Salesman defaultPerson;
	//Salesman person1 = { "king", "kong", "100-11-0001", 350.0, 10000.0, 0.1 }; // Error
	GetInfo(defaultPerson);
#endif // endif STRUCT_DEFAULT

#if STRUCT_DEFAULT == 0 // without the default value at initization 
	Salesman person1 = { "king", "kong", "100-11-0001", 350.0, 10000.0, 0.1};
	GetInfo(person1);
#endif // endif STRUCT_DEFAULT == 0

#endif // endif STRUCT

#if CLASS
	double newBaseSalary = { 0.01 };
	Commission defaultEmployee;	
	defaultEmployee.Print();
	
	cout << "Employee update...\n" << endl;

	defaultEmployee.SetFirstName("King");
	defaultEmployee.SetLastName("Kong");
	defaultEmployee.SetSSN("010-01-0110");
	defaultEmployee.Print();
	
	Commission employee1{ "John", "Doe", "321-98-3765", 250, 6000, 0.5 };
	employee1.SetBaseSalary(newBaseSalary);
	employee1.Print();
#endif

#if TEST
	string a = "abcdefg";

	test1(a);
	test2(a);

	test1("direct input");
	test2("direct input");
#endif

	system("pause"); //pausing the output

} // end of main()