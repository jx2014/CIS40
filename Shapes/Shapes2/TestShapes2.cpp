/************************

Shapes2

Project: Shapes
Purpose: This project is going to be implemented as a class type, and to isolate 
		 the designer’s code from the client’s code.
Author: Jeremy Xue Zhiming
Date: Apr 7th, 2015

Lab: 8

************************/

#include "LibIncludes.h"
#include "Shapes2.h"

#define DEBUG 0
#define WHILELOOP 1

void main()
{

	Shapes2 Shape = Shapes2();

#if DEBUG == 1
	cout << R"("selection" = )"
		<< static_cast<int>(Shape.GetCurrentSelection()) << "\n\n";

	Shape.PublicGetLengh();
#endif	

#if WHILELOOP == 1
	while (true)
	{
		char menuSelection = Shape.MenuSelection();

		if (menuSelection != 'X' && Shape.RetryStatus() == true) // if retry status is false the exit the program; if user selected X or x, then exit the program
		{
			if (Shape.CheckContinue() == true) // for successful menu selections, ask user to continue or not. 
			{
				system("cls");
				Shape.ResetGlobalVariables(); // if continue the program, then reset global variables before next round.
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
#endif 

	cout << endl; // line break
	system("pause"); // pause the output

} // end of main()