#include "Bicycle2LibIncludes.h"
#include "Bicycle2Declarations.h"
//#include "Bicycle2Prototypes.h" // redundant

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
		cout << "Please set a speed between "
			<< MINspeed << " and " << MAXspeed << " km/h: ";

		cin >> sp;

		try
		{
			if (!cin.good()) // if user entered an invalid input. i.e. a character, a string, a digit outside the range of size_t
			{
				throw 'e';
			}
			else if (sp < MINspeed || MAXspeed < sp) // Speed outside the range, throw an exception
			{
				throw 0;
			}
			else if (MINspeed <= sp && sp <= MAXspeed) // Speed within range, break the while loop.
			{
				speed = sp;
				break;
			}
		}
		catch (char error)
		{
			error; // so that warning C4101:unreferenced local variable will not show 
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input detected, please try agian.\n" << endl;			
		}
		catch (int error)
		{
			error; // so that warning C4101:unreferenced local variable will not show
			cin.ignore(INT_MAX, '\n');
			cout << "The speed you entered is outside of legal range. "
				<< "Please try agian\n" << endl;
		}

	} // end of while loop

} // end of new SetSpeed(size_t sp) for lab 5


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