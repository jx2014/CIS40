/************************

TestBicycle

Project : Bicycle 2 Third Part
Purpose :  - add the function ‘ImplementSelection()’ and
		   - add an option to continue with another selection.   
		   - Create an ‘enum’ implementation.      
Author  : Jeremy Xue Zhiming
Date    : Mar 14th, 2015

Lab: 5

************************/

#include "Bicycle2LibIncludes.h"
//#include "Bicycle2Declarations.h" // not needed, already declared in BicycleFUnctions.cpp
#include "Bicycle2Prototypes.h"

// quick way to turn on/off each functions in main
#define GetSelectedSpeedFunc 0
#define SetSpeedFunc 0
#define DisplayMenuFunc 0
#define MenuSelectionFunc 1
#define SelectModelFunc 0
#define ExitPrompt 0

template <class Anything> // I want to try a different letter other than T
Anything IntDoubleTemplate(Anything number)
{
	return number;
}


void main()
{
#if SetSpeedFunc == 1 // function to set speed with direct variable input, commented out for cleaner output

	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function SetSpeed with while loop." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;

	SetSpeed(); // calling the SetSpeed function from BicyclePrototypes.h

	cout << "\nCurrent speed is: " << GetSpeed() << " mph.\n" << endl;
#endif


#if GetSelectedSpeedFunc == 1 // function to select speed, commented out for cleaner output

	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function GetSelectedSpeed()." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;

	GetSelectedSpeed();

#endif


#if DisplayMenuFunc == 1

	DisplayMenu();

#endif
	

#if SelectModelFunc == 1

	cout << endl; //line break
	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function SelectModel()." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;

	SelectModel();

#endif


#if MenuSelectionFunc == 1

	cout << endl; //line break
	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function MenuSelection()." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;


	while(true)
	{
		int menuSelection = MenuSelection();
		// cout << "\nmenuSelection: " << menuSelection << endl; // debug purpose

		if (menuSelection == 0) // if it's 0, then it retried too many times, exit program automatically.
		{
			return;
		}
		else if (menuSelection != 5 && CheckContinue() == true) // if it's 5, then exit time.
		{
				system("cls"); // clear screen and start over
				continue;			
		}
    	else
		{
			//cout << "\nGood bye.\n" << endl;
			SelectModel();
			return;

		} // end of (menuSelection == 0)

	}// end of while(true)

#if MENUSELECTION
	int menuSelection = MenuSelection();

	cout << "\nYou have selected: " << menuSelection << endl;

	if (menuSelection != 5)
	{
		bool status = CheckContinue();

	} // end of if(menuSelection != 5)
	else
	{
		cout << "\nGood bye!\n" << endl;
	}
#endif

#endif


#if ExitPrompt == 1

	cout << "\nPress Enter key to continue...";
	cin.get();	
	//system("cls"); // clear the output, commented out for now becaue I want to see the whole output
#endif

} // end of main()
