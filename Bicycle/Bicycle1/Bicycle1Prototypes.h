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