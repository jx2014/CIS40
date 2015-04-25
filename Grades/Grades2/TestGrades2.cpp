/************************

Grades

Project: Grades2
Purpose: - implementing non-static-functions, and using ‘struct’ as members.

Author: Jeremy Xue Zhiming
Date: Apr 25th, 2015

Lab: 11

************************/

#include "Grades2.h"

#define MAINPROGRAM 1
#define TEST 0


#if TEST
string ToUpper(string &s);
#endif

void main()
{

#if MAINPROGRAM

		Grades myClass = Grades();

		while (true)
		{

			myClass.SelectClass();

			myClass.DisplayClassInfo();

			if (myClass.CheckContinue() == false)
			{
				cout << "Good Bye!" << endl;
				break;
			}
		}// end of while (true)

#endif

#if TEST
	int number = 2010;

	cout << "int: " << number << endl;
	cout << to_string(number) << endl;
	cout << typeid(number).name() << endl;

	string someString;

	cout << "Enter a string: ";
	getline(cin, someString);

	cout << ToUpper(someString) << endl;
	cout << someString << endl;



#endif

	cout << endl; // line break
	system("pause");
};



#if TEST
string ToUpper(string &s) // s is string, l is length of string
{
	for (char &c : s)
	{
		c = char(toupper(c));
	}

	return s;

}; // end of string Grades::ToUpper(string s)
#endif
