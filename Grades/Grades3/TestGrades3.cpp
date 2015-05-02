/************************

Grades

Project: Grades3
Purpose: ‘class Grades’ to be implemented with a different architecture, 
		to processes a set of grades entered by the user, and stored in
		an array, of C-Standard type or as a C++ class-array. 
		
Author: Jeremy Xue Zhiming
Date: May 1st, 2015

Lab: 12

************************/

#include "Grades3.h"

void main()
{
	Grades myClass = Grades();

	myClass.ProcessGrades();

	cout << endl; // line break
	system("pause");

} // end of main()
