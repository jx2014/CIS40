/************************

Shapes1

Project: Shapes
Purpose: A menu-driven console-application to calculate the area of some shapes Rectangle, Triangle, Trapezoid, Circle
Author: Jeremy Xue Zhiming
Date: March 27th, 2015

Lab: 7

************************/

#include "LibIncludes.h"
#include "Shapes1Prototypes.h"


void main()
{

#if TEST // not needed, for practice only

	cout << R"*("Selection" = )*" << static_cast<int>(GetCurrentSelection()) << endl;

	DisplayMenu();

	GetSelection();
	
	cout << "\nmenuSeleciton is: " << menuSelection << endl;

	if (menuSelection == 'X')
	{
		cout << "\nGood bye!" << endl;
	}
	else
	{
		cout << CheckContinue();
	}
#endif

	while (true)
	{
		char menuSelection = MenuSelection();

		if (menuSelection != 'X' && RetryStatus() == true) // if retry status is false the exit the program; if user selected X or x, then exit the program
		{
			if (CheckContinue() == true) // for successful menu selections, ask user to continue or not. 
			{
				system("cls");
				ResetGlobalVariables(); // if continue the program, then reset global variables before next round.
				continue;
			} // end of if (CheckContinue == true)
			else
			{
				cout << "\nGood bye!\n" << endl;
				break;
			} // end of else
		} // end of if (menuSelection != 'X')
		else
		{
			cout << "\nExit program, good bye!\n" << endl;
			break;
		} // end of else
	} // end of while (true)		

	cout << endl; // line break
	system("pause"); // pause the output

} // end of main()