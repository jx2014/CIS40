/************************

TestBicycle

Project : Bicycle 2 Second Part
Purpose : Exception and switch demo
Author  : Jeremy Xue Zhiming
Date    : Mar 6th, 2015

Lab: 5

************************/

#include "Bicycle2LibIncludes.h"
//#include "Bicycle2Declarations.h" // not needed, already declared in BicycleFUnctions.cpp
#include "Bicycle2Prototypes.h"

// quick way to turn on/off each functions in main
#define GetSelectedSpeedFunc 1
#define SetSpeedFunc 0
#define DisplayMenuFunc 0
#define MenuSelectionFunc 0

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

	cout << endl; //line break

#if MenuSelectionFunc == 1

	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function MenuSelection()." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;

	MenuSelection();

#endif

	cout << "\nPress Enter key to continue...";
	cin.get();	
	//system("cls"); // clear the output, commented out for now becaue I want to see the whole output

} // end of main()
