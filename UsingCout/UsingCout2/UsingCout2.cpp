/************************

UsingCout2

Project: UsingCout
Purpose: Learning the usage of integer, remainder, 
		 logical operators, casting, code collapse option 
		 and math class functions.
Author: Jeremy Xue Zhiming
Date: Feb 15, 2015

Lab: 2

************************/

#include "UsingCout2.h"
#include <math.h>


void Sales()
{
	/*	A company pays its sales people on a commission basis.
	 	The sales people receive a base of $200 per week, plus
	  	0.09 of their gross sales for that week 
	*/

	double base, sale, percentage, wage;

	cout << "Enter your weekly base salary: ";
	cin >> base;	
	
	cout << "Enter your commission percentage (i.e. 0.09 for 9%): ";
	cin >> percentage;
	
	cout << "Enter your gross sales for this week: ";
	cin >> sale;
	
	wage = base + sale * percentage;

	cout << "\nYou will receive a salary of $" << wage << " for this week." << endl;

	cin.ignore(100, '\n'); // flush cin buffer until end of line
	cout << "\nPress Enter key to continue..." << endl; // For pausing the output	
	cin.get();
	system("cls");

} // end of Sales


void Manufacturing()
{
	/*	This program is to be used by General Crates, Inc. to
		calculate the volume, cost, customer charge, and profit
		for manufacturing a crate of any size.
	*/

	double length, width, height; // crate specificitons, user input values
	double volume, cost, charge, profit; // calculated values

	cout << "Enter crate's length in meter: ";
	cin >> length;

	cout << "Enter crate's width in meter: ";
	cin >> width;

	cout << "Enter crate's height in meter: ";
	cin >> height;

	volume = length * width * height;
	cost = volume * 0.23;
	charge = volume * 0.5;
	profit = charge - cost;
		
	cout << setprecision(2) << showpoint
		 << "\nThe cost of making a " << volume << " cubic meter crate is $" << cost << '\n'
		 << "By charging the customer $" << charge << ", you can make a profit of $" << profit << endl;

	cin.ignore(100, '\n'); // flush cin buffer until end of line
	cout << "\nPress Enter key to continue..." << endl; // For pausing the output
	cin.get();
	system("cls");

} // end of Manufacturing


void IntDivision()
{
	/*	This program takes inputs from user a five-digit integer 
		and displays it separated into its individual digits. 

		For example, if the user types in 12321, the program displays:
		1   2   3   2   1
	*/

	int digit1, digit2, digit3, digit4, digit5;
	int userDigit;

	cout << "Enter a five-digit integer: ";
	cin >> userDigit;
		
	digit1 = (userDigit / 10000) % 10;  // By dividing 10000, the five-digit integer becomes four-digit integer, and by module 10 will guaranteed to get the fifth digit.
	digit2 = (userDigit / 1000) % 10;  
	digit3 = (userDigit / 100) % 10;  
	digit4 = (userDigit / 10) % 10;  
	digit5 = (userDigit / 1) % 10;
	
	cout << "\n" << setw(10) << left << "1st digit"
		<< "\t" << setw(10) << left << "2nd digit"
		<< "\t" << setw(10) << left << "3rd digit"
		<< "\t" << setw(10) << left << "4th digit"
		<< "\t" << setw(10) << left << "5th digit";

	cout << "\n" << setw(10) << left << digit1
		<< "\t" << setw(10) << left << digit2 
		<< "\t" << setw(10) << left << digit3 
		<< "\t" << setw(10) << left << digit4 
		<< "\t" << setw(10) << left << digit5 
		<< endl;
	
	cin.ignore(100, '\n'); // flush cin buffer until end of line
	cout << "\nPress Enter key to continue..." << endl; // For pausing the output
	char c;
	cin.get(c);
	system("cls");

} // end of IntDivision()


void Palindrome()
{
	/*	This program determine whether the previous input number is a palindrome.
		
		A palindrome is a number that reads the same backwards as 
		forwards, like 12321 or 45554.	    
	*/
		
	int digit1, digit2, digit3, digit4, digit5;
	int userDigit;
	int overFiveDigits; // For determining if user entered more than 5 digits
	int newDigitLeft, newDigitRight;

	cout << "Enter a five-digit integer: ";
	cin >> userDigit;
	
	overFiveDigits = (userDigit / 100000); //If the integer is largerthan 99999, overDigit will be bigger than 0

	if (overFiveDigits > 0) // program will not perform palindrome determination if user entered more than 5 digits.
	{
		cout << "You must enter 5 digits or less" << endl;		
	}
	else
	{
		//Breaking out single digits:
		digit1 = (userDigit / 10000) % 10;
		digit2 = (userDigit / 1000) % 10;
		digit3 = (userDigit / 100) % 10;
		digit4 = (userDigit / 10) % 10;
		digit5 = (userDigit / 1) % 10;

		//Constructing left and right digits from above single digit.
		newDigitRight = digit1 * 100 + digit2 * 10 + digit3;
		newDigitLeft = digit5 * 100 + digit4 * 10 + digit3;		

		if (newDigitLeft == newDigitRight)
		{
			cout << "\n" << userDigit << " is palindrome." << endl;
		}
		else
		{
			cout << "\n" << userDigit << " is not palindrome." << endl;
		}
	}
	
	cin.ignore(100, '\n'); // flush cin buffer until end of line
	cout << "\nPress Enter key to continue..." << endl; // For pausing the output
	cin.get();
	system("cls");

} // end of Palindrome()


void Swap()
{
	/*	In this program, user will enter a five-digit integer, 
			i.e. 12321
		
		the program then swap first and third digit, thus 12321 becomes:
			3   2   1   2   1

		the program continues to swap second and fifth digits, thus 32121 becomes:
			3   1   1   2   2

		and finally, the program determine the new number is a palindrome.
	*/

	int digit1, digit2, digit3, digit4, digit5;
	int userDigit;
	int overFiveDigits; // For determining if user entered more than 5 digits
	int tempDigit;
	int newDigitLeft, newDigitRight;

	cout << "Enter a five-digit integer: ";
	cin >> userDigit;
	
	overFiveDigits = (userDigit / 100000); //If the integer is largerthan 99999, overDigit will be bigger than 0

	if (overFiveDigits > 0) // program will not perform digit sawp and palindrome determination if user entered more than 5 digits.
	{
		cout << "You must enter 5 digits or less" << endl;
	}
	else
	{
		//Breaking out single digits:
		digit1 = (userDigit / 10000) % 10;
		digit2 = (userDigit / 1000) % 10;
		digit3 = (userDigit / 100) % 10;
		digit4 = (userDigit / 10) % 10;
		digit5 = (userDigit / 1) % 10;

		//Swaping first and 3rd digit.
		tempDigit = digit1;
		digit1 = digit3;
		digit3 = tempDigit;

		//swapping second and fifth digit.
		tempDigit = digit2;
		digit2 = digit5;
		digit5 = tempDigit;
		
		//Constructing left and right digits from above single digit.
		newDigitRight = digit1 * 100 + digit2 * 10 + digit3;
		newDigitLeft = digit5 * 100 + digit4 * 10 + digit3;

		if (newDigitLeft == newDigitRight)
		{
			cout << "\nThe new digit is palindrome:" << endl;
		}
		else
		{
			cout << "\nThe new digit is not palindrome:" << endl;
		}

		//Display the new digit after two swaps.
		cout << digit1 << "\t" << digit2 << "\t" << digit3 << "\t" << digit4 << "\t" << digit5 << endl;
	}

	cin.ignore(100, '\n'); // flush cin buffer until end of line
	cout << "\nPress Enter key to continue..." << endl; // For pausing the output
	cin.get();
	system("cls");

} // end of swap


void Distance()
{
	/*	User enter x, y value of two points, the program will return the distance between this two points
	*/

	double x1, x2, y1, y2;
	double distance;
	
	cout << "Enter x, y value of a point, separated by space: ";
	cin >> x1 >> y1;
	cin.ignore(100, '\n'); // flush cin buffer until end of line

	cout << "\nEnter x, y value of a second point, separated by space: ";
	cin >> x2 >> y2;
	cin.ignore(100, '\n'); // flush cin buffer until end of line

	distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)); // calculate distance between two points

	cout << setprecision(2) << fixed 
		<< "\nDistance between point(" << x1 << ", " << y1 << ") and point(" << x2 << ", " << y2 << ") is\n"
		<< distance << endl;
	
	cout << "\nPress Enter key to continue..." << endl; // For pausing the output
	cin.get();
	system("cls");

} // end of Distance()


void GetChange()
{
	/*	Cash register program
		Gets input from user: Purchase and Payment
		And output the following, total changes, Dollars, Quarters, Dimes, Nickels, and Pennies
		
		i.e.
			Purchase	3.08
			Payment		10.00
			Change		6.92
			Dollars		6
			Quarters	3
			Dimes		1
			Nickels		1
			Pennies		2
	*/

	int payment; // only paper bill accepted
	double purchase, change;
	int dollars, quarters, dimes, nickels;
	int pennies;

	cout << "Enter purchase amount: ";
	cin >> purchase;
	
	cout << "\nEnter payment amount(paper bills only): ";
	cin >> payment;
	
	if (static_cast<double> (payment) < purchase) // Determine if payment is more than the purchase. static cast double to convert i.e. $3 to $3.00
	{
		cout << "\nPayment not enough. Good bye!" << endl;
	}
	else
	{
		payment = static_cast<int> (payment * 100); // get rid of decimals 
		purchase = static_cast<int> (purchase * 100); // get rid of decimals.
		change = payment - purchase;

		dollars = static_cast<int> (change / 100);
		quarters = static_cast<int>((change - dollars * 100) / 25);
		dimes = static_cast<int>((change - dollars * 100 - quarters * 25) / 10);
		nickels = static_cast<int>((change - dollars * 100 - quarters * 25 - dimes * 10) / 5);
		pennies = static_cast<int>(change - dollars * 100 - quarters * 25 - dimes * 10 - nickels * 5);

		cout << "\n" << setprecision(2) << showpoint << fixed
			<< setw(10) << left << "Purchase" << setw(10) << right << purchase / 100 << "\n"
			<< setw(10) << left << "Payment" << setw(10) << right << static_cast<double>(payment) / 100 << "\n" // to display the double zero precision
			<< setw(10) << left << "Change" << setw(10) << right << change / 100 << "\n"
			<< setw(10) << left << "Dollars" << setw(10) << right << dollars << "\n"
			<< setw(10) << left << "Quarters" << setw(10) << right << quarters << "\n"
			<< setw(10) << left << "Dimes" << setw(10) << right << dimes << "\n"
			<< setw(10) << left << "Nickels" << setw(10) << right << nickels << "\n"
			<< setw(10) << left << "Pennies" << setw(10) << right << pennies << endl;
	}
	
	cin.ignore(100, '\n'); // flush cin buffer until end of line
	cout << "\nPress Enter key to continue..." << endl; // For pausing the output
	cin.get();
	system("cls");

} // end of GetChange()


void RollWallpaper()
{
	/*	Roll-wallpaper calculator
		Standard wallpaper roll size(L x W): 33ft x 21in
		
		Ask user input the dimensions of hte room in ft,
		and output the number of wallpaper strips required		
	*/

	const int rollLength{ 396 }; // in inches
	const int rollWidth{ 21 }; // in inches

	int wallWidth, wallLength, wallHeight; // wall dimensions in ft

	cout << "Enter the width length and height of the wall in ft, saperate by space: ";
	cin >> wallWidth >> wallLength >> wallHeight;

	wallWidth = wallWidth * 12; // convert ft to inches
	wallLength = wallLength * 12; // convert ft to inches
	wallHeight = wallHeight * 12; // convert ft to inches

	double wallArea = (wallWidth + wallLength) * wallHeight * 2; // total area of the wall
	double rollArea = rollLength * rollWidth;

	cout << "\nTotal wall area: " << wallLength << " sqrt inchs" << endl;

	double rolls = wallArea / rollArea; // calculate the number of rolls required

	rolls = (static_cast <int> (rolls) < rolls ? rolls + 1 : rolls); // round up the number of rolls, no one would buy 7.7575 rolls.
		
	cout << "\nYou will need a minimum of " << static_cast <int> (rolls) << " rolls." << endl;

	cin.ignore(100, '\n'); // flush cin buffer until end of line
	cout << "\nPress Enter key to continue..." << endl; // For pausing the output
	cin.get();
	system("cls");

} // end of RollWallpaper()


int main()
{
	Sales();
	
	Manufacturing();

	IntDivision();

	Palindrome();

	Swap();

	Distance();

	GetChange();

	RollWallpaper();

} // end of main