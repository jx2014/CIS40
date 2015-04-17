/************************

TestBicycle2

Project: Bicycle
Purpose: Learning ways of implanting functions, variables via
         header files.
Author: Jeremy Xue Zhiming
Date: Feb 28th, 2015

Lab: 4

************************/

#include "Bicycle2LibIncludes.h"
//#include "Bicycle2Declarations.h" // not needed, already declared in BicycleFUnctions.cpp
#include "Bicycle2Prototypes.h"

// quick way to turn on/off each functions in main
#define SetSpeedFunc 1
#define IntDoubleTemplateFunc 0
#define DefaultSetSpeedFunc 0
#define SwapFunc 0
#define DistanceTravelledFunc 0

template <class Anything> // I want to try a different letter other than T
Anything IntDoubleTemplate(Anything number)
{
	return number;
}


void main()
{

#if SetSpeedFunc == 1 // function to set speed with direct variable input, commented out for cleaner output

	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function SetSpeed with direct variable input." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;

	//cout << "SetSpeed(-12)" << endl;

	SetSpeed(); // calling the SetSpeed function from BicyclePrototypes.h

	cout << "\nCurrent speed is: " << GetSpeed() << " km/h." << endl;
#endif

	

#if IntDoubleTemplateFunc == 1 // function template demostration, commented out for clearner output
	cout << "\n\n"; //line break between each functions

	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function template demo." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;

	size_t intValue = { 15 };
	double doubleValue = { 13.5 };

	intValue = IntDoubleTemplate(intValue);
	cout << "Current value from int is: " << intValue << endl;

	doubleValue = IntDoubleTemplate(doubleValue);
	cout << "Current value from double is: " << doubleValue << endl;
#endif
	
	

#if DefaultSetSpeedFunc == 1 // show functions with default value, commented out for cleaner output
	cout << "\n\n"; //line break between each functions

	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function SetSpeed with default value." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;

	cout << "DefaultSetSpeed()" << endl;
	DefaultSetSpeed();
	cout << GetSpeed() << endl;

	cout << "DefaultSetSpeed(11)" << endl;
	DefaultSetSpeed(11);
	cout << GetSpeed() << endl;

	cout << "DefaultSetSpeed(22)" << endl;
	DefaultSetSpeed(22);
	cout << GetSpeed() << endl;

	cout << "DefaultSetSpeed(6)" << endl;
	DefaultSetSpeed(6);
	cout << GetSpeed() << endl;

	cout << "DefaultSetSpeed()" << endl;
	DefaultSetSpeed();
	cout << GetSpeed() << endl;
#endif
	


#if SwapFunc == 1 // swap function, commented out for cleaner output
	cout << "\n\n"; //line break between each functions

	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function SwapFunc output." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;

	size_t firstSpeed = { 12 };
	size_t secondSpeed = { 18 };

	cout << "Original variables are:\n"
		<< "size_t firstSpeed = { 12 }\n"
		<< "size_t secondSpeed = { 18 }" << "\n" << endl;

	cout << "firstSpeed was: " << firstSpeed << endl;
	cout << "secondSpeed was: " << secondSpeed << endl;

	swap(firstSpeed, secondSpeed);
	cout << "\nSwap firstSpeed and secondSpeed\n" << endl;

	cout << "firstSpeed is: " << firstSpeed << endl;
	cout << "secondSpeed is: " << secondSpeed << endl;

#endif



#if DistanceTravelledFunc == 1
	cout << "\n\n"; //line break between each functions

	cout << setw(50) << setfill('*') << "*" << endl;
	cout << "Function DistanceTraelledFunc output." << endl;
	cout << setw(50) << setfill('*') << "*" << "\n" << endl;
	
	DistanceTravelled(5); // total travelled: 5
	cout << endl;

	DistanceTravelled(10); // total travelled: 15
	cout << endl;

	DistanceTravelled(15); // total travelled: 30
	cout << endl;

#endif

		
	cin.ignore(INT_MAX, '\n'); // flush cin buffer
	cout << "\nPress Enter key to continue...";
	cin.get();	
	//system("cls"); // clear the output, commented out for now becaue I want to see the whole output

} // end of main()
