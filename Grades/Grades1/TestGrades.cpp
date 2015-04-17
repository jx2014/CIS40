/************************

Grades

Project: Grades1
Purpose: - Declare and use the 'static' members of a class, 
		   and also some restrictions in implementing them;
		 - how to get 'string' input from user.

Author: Jeremy Xue Zhiming
Date: Apr 16th, 2015

Lab: 10

************************/

#include "Grades.h"
#include "LibIncludes.h"

void main()
{

	Grades myClass = Grades();
	int count = {};
	
	count = myClass.GetGradeCounter();

	Grades::className = 'C';
	cout << "*** Setting Grades::className = 'C' ***\n";
	cout << "Grades::className: " << Grades::className << endl;

	cout << endl; // line break

	myClass.className = 'D'; // bad practice
	cout << "*** Setting myClass.className = 'D' ***\n";
	cout << "myClass.className: " << myClass.className << endl;
	cout << "Grades::className: " << Grades::className << endl; // set to D because of myClass.className

	cout << endl; // line break

	cout << "myClass.classNumber: " << myClass.classNumber << endl;
	cout << "Count is: " << count << endl;
	//myClass.DisplayClassName(myClass); // not recommended

	cout << endl; // line break

	string className;
	className = Grades::InputClassName();
	cout << "Class name is: " << className << endl;
	Grades::DisplayClassName(myClass);

	cout << endl; // line break
	system("pause");

} // end of void main()