#include "LibIncludes.h"
#include "Shapes1Declarations.h"
#include "Shapes1Prototypes.h"



char GetCurrentSelection()
{
	return selection;

}; // end of GetCurrentSelection()



void DisplayMenu()
{
	cout << R"(
Area Calculation Program
------------------------

     <R>ectangle
     <T>riangle
     Trape<Z>oid
     <C>ircle
     e<X>it program

Select Shape: )";

}; // end of DisplayMenu()



bool RetryStatus()
{
	return retryStatus; 

} // end of RetryEnds()



void GetSelection() // to get user input and valide it. 
{
	char c;

	int m = { 5 }; //  maximum number of times an user can enter selection.

	for (int n = 0; n < m; n++) // loop till user input legal characters. 
	{
		// cout << "n is " << n << endl; // testing n

		cin.get(c); // Get user char input then convert to upper case
		c = toupper(c);

		cin.ignore(INT_MAX, '\n');

		switch (c) // validating user input, if it is outside menu selection options, then retry n times
		{
		case 'R':
		case 'T':
		case 'Z':
		case 'C':
		case 'X':
			selection = c;
			return; // selection is good, return function
		default:
			n == (m - 1) ? (cout << "\nYou have tried too many times.\n", retryStatus = false) : (cout << "Wrong selection, please try again: ", retryStatus = true);
			continue; // repeat but only if n < m
		} // end of switch(c)
	} // end of while(true)

}; // end of GetSelection()



char MenuSelection()
{
	DisplayMenu();

	GetSelection();

	if (selection == 'R' || selection == 'T' || selection == 'Z' || selection == 'C')
	{
		ImplementSelection();
	
	} // end of if (selection == 'R' || selection == 'T' || selection == 'Z' || selection == 'C')

	return selection;
}; // end of MenuSelection()



void Rectangle()
{
	cout << "Inside Rectangle()" << endl;

}; // end of Rectangle()



void Triangle()
{
	cout << "Inside Triangle()" << endl;

}; // end of Triangle()



void Trapezoid()
{
	cout << "Inside Trapezoid()" << endl;

}; // end of Trapezoid()



void Circle()
{
	cout << "Inside Circle()" << endl;

}; // end of Circle()



void ImplementSelection()
{
	switch (selection)
	{
		case 'R':
			Rectangle();
			break;
		case 'T':
			Triangle();
			break;
		case 'Z':
			Trapezoid();
			break;
		case 'C':
			Circle();
			break;
	} // end of switch(selection)

}; // end of ImplementSelection()



bool CheckContinue()
{
	char c;

	bool status;

	cout << endl; // line break

	while (true)
	{
		cout << "Do you wish to continue (Y/N)? ";

		try
		{
			cin.get(c);

			cin.clear();
			cin.ignore(INT_MAX, '\n');

			c = toupper(c);

			if (c == 'Y' || c == 'N') // if user entered anything other than y or n, repeat.
			{
				c == 'Y' ? status = true : status = false;
				break;
			} // end of if (c == 'Y' || c == 'N')
			else
			{
				throw 'e';
			}
		} // end of try
		catch (char error)
		{
			error;
			cout << "\nInvalid input detected, please try agian.\n" << endl;
		} // end of catch (char error)
		catch (...)
		{
			cout << "\nSome unknown error occured.\n" << endl;
		}// end of catch (...)

	} // end of while (true)

	return status;

}; // end of CheckContinue()



void ResetGlobalVariables() // If CheckContinue() returns true, program must reset the selection and retryStatus
{
	selection = {};
	retryStatus = { true };

} // end of ResetGlobalVariables()