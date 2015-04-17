#include "LibIncludes.h"
#include "Shapes2.h"

Shapes2::Shapes2() // initialization default variables. 
{
	selection = { '\0' };
	retryStatus = { true };

}; //end of Shapes2()initialization



char Shapes2::GetCurrentSelection()
{
	return selection;

}; // end of GetCurrentSelection()



void Shapes2::DisplayMenu()
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



bool Shapes2::RetryStatus()
{
	return retryStatus;

} // end of RetryEnds()



void Shapes2::GetSelection() // to get user input and valide it. 
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



char Shapes2::MenuSelection()
{
	DisplayMenu();

	GetSelection();

	if (selection == 'R' || selection == 'T' || selection == 'Z' || selection == 'C')
	{
		ImplementSelection();

	} // end of if (selection == 'R' || selection == 'T' || selection == 'Z' || selection == 'C')

	return selection;
}; // end of MenuSelection()



void Shapes2::Rectangle()
{
	// cout << "Inside Rectangle()" << endl; //for debugging purposes. 

	cout << R"(
         ^ ------------------
         | |                |
         a |                |
         | |                |
         v ------------------
           <--------b------->
				)" << endl;

	cout << "Enter length of side a: ";
	double a = GetLength();

	cout << "Enter length of side b: ";
	double b = GetLength();

	rArea = a * b;

	cout << setprecision(2) << fixed << "Area of Rectangle is: " << rArea << endl;

}; // end of Rectangle()



void Shapes2::Triangle()
{
	// cout << "Inside Triangle()" << endl; //for debugging purposes.

	cout << R"(
        ^ |\
        | | \
          |  \
        a |   \
          |    \
        | |     \
        v |      \
          --------
          <---b--->
				)" << endl;

	cout << "Enter length of side a: ";
	double a = GetLength();

	cout << "Enter length of side b: ";
	double b = GetLength();

	tArea = ( a * b ) * 0.5;

	cout << setprecision(2) << fixed << "Area of Triangle is: " << tArea << endl;

}; // end of Triangle()



void Shapes2::Trapezoid()
{
	//cout << "Inside Trapezoid()" << endl; //for debugging purposes.

	cout << R"(
          <- b1 ->
          --------
         /   ^    \
        /    h     \
       /     v      \
       --------------
       <---- b2 ---->      
				)" << endl;

	cout << "Enter length of side b1: ";
	double b1 = GetLength();

	cout << "Enter length of side b2: ";
	double b2 = GetLength();

	cout << "Enter length of side h: ";
	double h = GetLength();

	zArea = ((b1 + b2) / 2) * h;

	cout << setprecision(2) << fixed << "Area of Trapezoid is: " << zArea << endl;

}; // end of Trapezoid()



void Shapes2::Circle()
{
	//cout << "Inside Circle()" << endl; //for debugging purposes.
	cout << R"(
              ** 
          *        *              
        *            * 
       *              * 
       *       ---r---* 
       *              *
        *            * 
          *        *
              **        
				)" << endl;

	cout << "Enter length of radius r: ";
	double r = GetLength();

	cArea = 3.1415926 * r * r;

	cout << setprecision(2) << fixed << "Area of Circle is: " << cArea << endl;

}; // end of Circle()



void Shapes2::ImplementSelection()
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



bool Shapes2::CheckContinue()
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



void Shapes2::ResetGlobalVariables() // If CheckContinue() returns true, program must reset the selection and retryStatus
{
	selection = { '\0' };
	retryStatus = { true };

} // end of ResetGlobalVariables()



double Shapes2::GetLength() // return legal length
{
	double l = { 0 };
	int counter = { 3 };
	
	// cout << "Enter length: "; // For debug, not used when function is called by shapes func.
	
	while (true)
	{

		if (!(cin >> l))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input. Try again: ";
			continue;
		}
		else
		{
			if (0 <= l && l <= 50) // if input is valid, return length if within legal length range.
			{
				cin.ignore(INT_MAX, '\n');
				return l;
			}
			else // if input is valid but the new length is out of range, keep the while loop going
			{
				cout << "Length is out of range. Try again: ";
				cin.ignore(INT_MAX, '\n');
				continue;
			} // end of length range check
		}//end of if(!(cin >> l)) else
	}//end of while loop
}



void Shapes2::PublicGetLengh()
{
	cout << "Length is " << GetLength() << endl;
}



//private variable initialization. 
double Shapes2::rArea = {};
double Shapes2::tArea = {};
double Shapes2::zArea = {};
double Shapes2::cArea = {};