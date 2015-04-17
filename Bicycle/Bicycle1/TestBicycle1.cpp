/************************

TestBicycle1

Project: Bicycle
Purpose: Learning ways of implanting functions, variables via
         header files.
Author: Jeremy Xue Zhiming
Date: Feb 19th, 2015

Lab: 3

************************/

#include "Bicycle1LibIncludes.h"
#include "Bicycle1Declarations.h"
#include "Bicycle1Prototypes.h"

void main()
{

	cout << "Speed limit is within " << MINspeed << " and " << MAXspeed << " km/h." << endl;	// Show the user the speed limit of said bicycle
	cout << "Current Speed:" << speed << " km/h" << endl; // Shows the user current speed, which is 0 km/h

	SetSpeed(); // calling the SetSpeed function from BicyclePrototypes.h

	cin.ignore(100, '\n'); // flush cin buffer
	cout << "\nPress Enter key to continue...";
	cin.get();
	system("cls");

} // end of main()


