/************************

ProcessArray

Project: ProcessArray
Purpose: - use algorithms from the Standard Template Library to access, 
		   search, and sort standard C-type arrays and C++ arrays;  
		 - use function ‘rand()’ to initialize arrays.
		 - implement some code for searching and sorting arrays.    

Author: Jeremy Xue Zhiming
Date: May 9th, 2015

Lab: 13

************************/

#include "ProcessArray.h"

void main()
{
	ProcessArray TestArray = ProcessArray();

	TestArray.UsingCTypeAlgorithms();

	TestArray.UsingCppTypeAlgorithms();

	cout << endl; // line break
	system("pause");

} // end of void main()


