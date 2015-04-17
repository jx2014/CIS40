#include "Bicycle2LibIncludes.h"
#include "Bicycle2Declarations.h"
#include "Bicycle2Prototypes.h"

size_t GetSpeed()
{
	return speed;

} // end of GetSpeed()


size_t GetMinSpeed()
{
	return MINspeed;

} // end of GetMinSpeed()


size_t GetMaxSpeed()
{
	return MAXspeed;

} // end of GetMaxSpeed()


#if OLDSETSPEED //comment out the old SetSpeed() from lab 3 and 4
void SetSpeed()
{
	int sp{ 0 }; // initalize the speed

	bool legalSpeed = (MINspeed <= sp && sp <= MAXspeed ? true : false); // it is going to be false, but I'd like to try out this ternary operator.

	while (legalSpeed == false) // while until sp is set within MINspeed and MAXspeed range.
	{
		cout << "\nSet a speed between " << MINspeed << " and " << MAXspeed << ": ";

		if (!(cin >> sp)) // determine if the user input is valid. i.e. any character, or number that is out of bound will be deemed as invalid input
		{
			cin.clear();			// clear the error flag set by invalid input
			cin.ignore(100, '\n');	// clear input buffer
			cout << "\nInvalid input." << endl;
		}
		else
		{
			if (MINspeed <= sp && sp <= MAXspeed) // if input is valid, check new speed is within range
			{
				legalSpeed = true;  // if within range, set legalSpeed to true to get out of the loop
				speed = sp; // set new speed
				cout << "\nNew speed set to " << speed << " km/h" << endl;
			}
			else // if input is valid but the new speed is out of range, keep the while loop going
			{
				cout << "\nNew speed entered: " << sp; //for checking input, debug only.
				cout << "\nNew speed is out of range." << endl;
				cout << "Current Speed:" << setw(3) << right << speed << " km/h\n";
			} // end of speed range check
		} // end of input validation check
	} // end of while loop
} // end of SetSpeed()


void SetSpeed(size_t s) // function for setting speed, with direct variable input.
{
	if (MINspeed <= s && s <= MAXspeed)
	{
		speed = s;
		cout << "\nSet new speed to: " << speed << " km/h." << endl;
	}
	else
	{
		cout << "\nNew speed is out of range. Good bye." << endl;
	}
}// end of SetSpeed(size_t s)
#endif


void SetSpeed() // new SetSpeed for lab 5
{
	size_t sp; // local variable for user input speed

	while (true)
	{
		static int counter = { 5 }; // SetSpeed() function will exit after 5 tries. 

		if (--counter < 0) // After a number of retries, it will exit the function.
		{
			cout << "\nRetried too many times. Speed not set, good bye." << endl;
			return;
		}
		else
		{		
			cout << "Please set a speed between "
				<< MINspeed << " and " << MAXspeed << " mph: ";

			cin >> sp;
		}	
				
		try
		{
			if (!cin.good()) // if user entered an invalid input. i.e. a character, a string, a digit outside the range of size_t
			{
				cin.clear();
				throw 'e';
			}
			else if (sp < MINspeed || MAXspeed < sp) // Speed outside the range, throw an exception
			{
				throw 0;
			}
			else if (MINspeed <= sp && sp <= MAXspeed) // Speed within range, break the while loop.
			{
				speed = sp;
				cin.ignore(INT_MAX, '\n'); // clear cin buffer when input is good
				break;
			}
		} // end of try
		catch (char error) // catch a char type of error
		{
			error; // so that warning C4101:unreferenced local variable will not show 						
			cout << "Invalid input detected, please try agian.\n" << endl;		
		} // end of catch (char error)
		catch (int error) // catch an int type of error, speed that is out of range
		{
			error; // so that warning C4101:unreferenced local variable will not show
			cout << "The speed you entered is outside of legal range. "
				<< "Please try agian\n" << endl;
		} // end of catch (int error)

		cin.ignore(INT_MAX, '\n'); // clear cin buffer after error occured. 

	} // end of while loop
} // end of SetSpeed(size_t sp)


void GetSelectedSpeed()
{
	char selection = 'a' ; // to store user input M or K

	while (selection != 'K' && selection != 'M') // while until user input a 'k' or a 'm'.
	{
		static int n = { 5 }; // function will exit after retries for n times.

		if (--n < 0) // if retries reach n times, function will exit.
		{
			cout << "Retry limit reached, good bye!" << endl;
			return;

		} // end of if

		cout << "\nPlease select the unit for bicycle speed:\n"
			<< "    press M or m for mph\n"
			<< "    press K or k for km/h\n";
		
		cout << "> ";
		cin.get(selection);		
		selection = toupper(selection); // convert user input letter to upper case.
		cout << selection << endl;
	
		//cout << "selection != M " << (selection != 'M' ? "true" : "false") << endl;
		//cout << "selection != K " << (selection != 'K' ? "true" : "false") << endl;
		//cout << "selection != 'K' || selection != 'M' " << (selection != 'K' || selection != 'M' ? "true" : "false") << endl;
		//cout << "selection != 'K' && selection != 'M' " << (selection != 'K' && selection != 'M' ? "true" : "false") << endl;

		cin.ignore(INT_MAX, '\n'); // clear input buffer
		
	} // end of while loop for checking M or K input

	double speedInKmPerHour;

	if (selection == 'K') // select K for km/h
	{
		speedInKmPerHour = speed * toKmPerHour;
		cout << setfill(' ') << "\nNew speed is:\n"
			<< setw(17) << left << "\nOutput style 1:" << setw(25) << left << "(No manipultator at cout)" << ": " << speedInKmPerHour << " km/h.\n" // no manipulator
			<< setw(17) << left << "\nOutput style 2:" << setw(25) << left << "(3 digits precision)" << ": " << setprecision(3) << speedInKmPerHour << " km/h.\n" // 3 digit precision
			<< setw(17) << left << "\nOutput style 3:" << setw(25) << left << "(int cast)" << ": " << setprecision(3) << static_cast <int> (speedInKmPerHour) << " km/h.\n" // int cast
			<< setw(17) << left << "\nOutput style 4:" << setw(25) << left << "(int cast by adding .5)" << ": " << setprecision(3) << static_cast <int> (speedInKmPerHour + 0.5) << " km/h.\n" // 
			<< setw(17) << left << "\nOutput style 5:" << setw(25) << left << "(ceil())" << ": " << setprecision(3) << ceil(speedInKmPerHour) << " km/h.\n" // 
			<< setw(17) << left << "\nOutput style 6:" << setw(25) << left << "(floor())" << ": " << setprecision(3) << floor(speedInKmPerHour) << " km/h.\n"; // 

	}
	else // selected m for mph
		cout << "\nNew speed is " << speed << " mph.\n";


} // end of GetSelectedSpeed()


void DisplayMenu()
{
	cout << "Selection Menu\n"
		<< "______________\n"
		<< "\n"
		<< "1. Set Speed\n"
		<< "2. Get speed\n"
		<< "3. Get MAX speed\n"
		<< "4. Get MIN speed\n"
		<< "5. Exit" << endl;
		
} // end of DisplayMenu


void DisplayModelMenu()
{
	cout << "\nSelect Bicycle Model\n"
		<< "____________________\n"
		<< "\n"
		<< "1. Road\n"
		<< "2. Mountain\n"
		<< "3. Racing\n"
		<< "4. Folding\n"
		<< "5. Electric\n" 
		<< "6. Exit" << endl;
} // end of DisplayModelMenu()


#if VOIDMenuSelection // old void MenuSelection() not needed.
void MenuSelection()
{

	DisplayMenu();

	GetSelection();

	if (selection != 5) // selectoin 5 means exit the program.
	{
		ImplementSelection();

	} // end if (selection != 5) 

} // end of MenuSelection()
#endif


int MenuSelection()
{
	DisplayMenu();

	selection = { 0 }; //initilaze the selection parameter.

	GetSelection();

	if (1 <= selection && selection <= 5) // selected anything between 1 and 5
	{
		return selection;
	}
	else
	{
		return 0; //for all invalid selection,

	} // end if (1 <= selection && selection <= 5)

} // end of MenuSelection()


void GetSelection()
{
	int localSelection{ 0 };

	for (int counter = { 5 }; counter >= 0;) // continue to get user input until reaches counter limit or user enters correct input
	{		
		
		if (counter <= 0) // exit function when counter reaches 0
		{
			cout << "\nRetired too many times, good bye." << endl;			
			return;
		}

		counter--;

		cout << "\nYour selection:> ";
		cin >> localSelection; // ask user to input a selection.		

		try
		{

			if (!cin.good())
			{
				cin.clear();
				throw 'e';
			}
			else if (localSelection < 1 || localSelection > 5)
			{
				throw 0;
			}
			else if (1 <= localSelection && localSelection <= 5)
			{
				selection = localSelection;
				cin.ignore(INT_MAX, '\n'); // if cin is good, the other buffer clear function won't be executed.
				// break;
				return;
			}
		} // end of try
		catch (char error)
		{
			error;
			cout << "\nInvalid input.\n";			
		} // end of catch char error
		catch (int error)
		{
			error;
			cout << "\nSelection not recongized.\n";
		} // end of catch int error
		catch (...)
		{
			cout << "\nUnkonwn error.\n";
		} // end of catch all other errors
		
		cin.ignore(INT_MAX, '\n'); // before retrying, clear input buffer.
	
	} // end of for loop

#if SWITCH 
	switch (selection)
	{
		case 1:
			cout << "\nSet speed selected." << endl;
			break;

		case 2:
			cout << "\nGet speed selected." << endl;
			break;

		case 3:
			cout << "\nGet MAX speed selected." << endl;
			break;

		case 4:
			cout << "\nGet MIN speed selected." << endl;
			break;

		default:
			cout << "\nExit program." << endl;
			return;
	} // end of switch
#endif

} // end of GetSelection()


void ImplementSelection()
{
	cout << "\nImplementSelection()" << endl;

} // end of ImplementSelection()


bool CheckContinue()
{
	char checkContinue;

	while (true)
	{
		cout << "\nDo you want to contine (Y/n):> ";

		cin.get(checkContinue);
		cin.ignore(INT_MAX, '\n');

		checkContinue = toupper(checkContinue);

		switch (checkContinue)
		{
		case 'Y':
				return true;
		case 'N':
				return false;
		default:		
			cout << "\nYou must enter Y or N\n";
			continue;

		}// end of switch

	} // end of while(true)

} // end of CheckContinue()


void SelectModel()
{
	DisplayModelMenu();

	modelSelection = { 0 };

	GetModelSelection();

	if (1 <= modelSelection && modelSelection <= 5)
	{
		BicycleModels bm = BicycleModels(modelSelection);

		//BicycleModels{Road=1, Mountain, Racing, Folding, Electric};

		switch (bm)
		{
			case Road:
				cout << "\nYou have selected type " << "Road" << endl;
				break;
			case Mountain:
				cout << "\nYou have selected type " << "Mountain" << endl;
				break;
			case Racing:
				cout << "\nYou have selected type " << "Racing" << endl;
				break;
			case Folding:
				cout << "\nYou have selected type " << "Folding" << endl;
				break;
			default:
				cout << "\nYou have selected type " << "Electric" << endl;
				break;
		}// end of switch(bm)
	}
	else if (modelSelection == 6)
	{
		cout << "\nGood bye!\n" << endl;
	}

} // end of SelectModel()

void GetModelSelection()
{
	int localModelSelected = { 0 };

	while (true)
	{
		cout << "\nYour selection:> ";
		cin >> localModelSelected;

		try
		{
			if (!cin.good())
			{
				cin.clear();
				throw 'e';
			}
			else if (localModelSelected < 1 || localModelSelected > 6)
			{
				throw 0;
			}
			else if (1 <= localModelSelected && localModelSelected <= 6)
			{
				cin.ignore(INT_MAX, '\n'); // if cin is good, the other buffer clear function won't be executed.
				modelSelection = localModelSelected;
				return;
			}
		} // end of try
		catch (char error)
		{
			error;
			cout << "\nInvalid input.\n";
		} // end of catch char error
		catch (int error)
		{
			error;
			cout << "\nSelection not recongized.\n";
		} // end of catch int error
		catch (...)
		{
			cout << "\nUnkonwn error.\n";
		} // end of catch all other errors

		cin.ignore(INT_MAX, '\n'); // before retrying, clear input buffer.
	}

} // end of GetModelSelection()


// below functions are from lab 4
void DefaultSetSpeed(size_t s) // functin for setting default speed, with a default value defined in Bicycle2Prototypes
{
	speed = s;

}// end of DefaultSetSpeed(size_t s = 20)


void Swap(size_t &a, size_t &b) // function for swapping two variables
{
	size_t temp;
	temp = a; //save value from address a to temp
	a = b; // assign value from address b to address a;
	b = temp; // assign value saved from address a to address b.

}// end of Swap(size_t &, size_t &)


void DistanceTravelled(size_t x)
{
	static int s; // default distance

	cout << setw(27) << left << setfill('.')  << "Default distance is "
		<< setfill(' ') << setw(3) << right << s << " unit(s)" << endl;

	s = s + x; // increase default distance with distance travelled variable x
	
	cout << setw(27) << left << setfill('.') << "After travelling "
		<< setfill(' ') << setw(3) << right << x << " unit(s)" << endl;

	cout << setw(27) << left << setfill('.') << "Total distance travelled is"
		<< setfill(' ') << setw(3) << right << s << " unit(s)" << endl;

} // end of DistanceTravelled(size_t x)