#include "LibIncludes.h"
#include "Grades.h"

//initalize static variable 
int Grades::gradeCounter = { 1 };
char Grades::className = {};

// default constructor for Grades
Grades::Grades()
{
	//fullClassName = {};
	classNumber = { 1 };
	fullClassName = {"CIS"};

	cout << "Automatically initialized fullClassName is: " << fullClassName << '\n' << endl;
}; // end of Grades::Grades()


//static int Grades::GetGradeCounter() // static is only required inside class declaration, in the .h file.
int Grades::GetGradeCounter() // static function accessing static private variable
{
	//classNumber = 50;

	return Grades::gradeCounter;

}; // end of Grades::GetGradeCounter()


void Grades::DisplayClassName(Grades obj) // static function accessing non-static private variable
{
	cout << "\nFull class name is: " << obj.fullClassName << '\n' << endl;

}; // end of static void DisplayClassName()


string Grades::InputClassName()
{
	string name;

	while (true)
	{
		cout << "Enter Class name (C++ or C#): ";
		getline(cin, name);
		
		if ((name == "C++") || (name == "C#") || (name == "c++") || (name == "c#"))
		{
			break; // if user enter either c++ or c#, quit loop and return name;
		}
		else
		{
			cout << "\nClass name must be either C++ or C#, try again!\n" << endl;
			continue;
		} // end of if

	} // end of while(true)

	return name;
}; // end of Grades::InputClassName()