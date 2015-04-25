#include "Grades2.h"

/*************************
*                        *
*    PRIVATE FUNCTIONS   *
*                        *
*************************/

bool Grades::CheckIfLegalName(string s) // private member
{
	// c++ style of array
	array<string, 4> str = { "C", "C++", "C#", "Java" };


	for (string x : str)
	{
		if (ToUpper(x) == ToUpper(s))
		{
			return true; // found a matching class name, return true
		}
	}
	return false; // if nothing fits, then return false. 

}; // end of bool Grades::CheckIfLegalName(string)



void Grades::InputClassName() // private member
{
	string goodClassName;

	while (true)
	{
		cout << "\nEnter Class name (C++, C#, C or Java): ";
		getline(cin, goodClassName);

		if (CheckIfLegalName(goodClassName) == true)
		{
			break; // if user enter either c++ or c#, quit loop and return name;
		}
		else
		{
			cout << "\nClass name must be C++, C#, C or Java, try again!" << endl;
			continue;
		} // end of if

	} // end of while(true)

	courseName = goodClassName;

}; // end of void Grades::InputClassName



void Grades::SetClassInfo()
{

	string *validInputs; // declare a array for use later on
	int numberOfItems;

restartSemester:
	cout << "\nEnter semester (Spring or Fall): ";
	numberOfItems = 2;
	validInputs = new string[numberOfItems] { "spring", "fall" };
	if (ClassInfoQualifer(GetUserInput(program.semester), validInputs, numberOfItems) == false)
	{
		goto restartSemester;
	}

restartTime:
	cout << "\nEnter time (Day or Evening or Weekend): ";
	numberOfItems = 3;
	validInputs = new string[numberOfItems] { "day", "evening", "Weekend" };
	if (ClassInfoQualifer(GetUserInput(program.time), validInputs, numberOfItems) == false)
	{
		goto restartTime;
	}

// textbook title has no qualifier
	cout << "\nEnter textbook title: ";
	GetUserInput(program.textbook.title);

// textbook author has no qualifier
	cout << "\nEnter textbook author: ";
	GetUserInput(program.textbook.author);

restartTextbookYear:
	//cout << textbook.year << endl; // for debug
	cout << "\nEnter textbook edition (2010/2012/2013): ";
	numberOfItems = 3;
	validInputs = new string[numberOfItems] { "2010", "2012", "2013" };	
	if (ClassInfoQualifer(to_string(GetUserInput(program.textbook.year)), validInputs, numberOfItems) == false)
	{
		goto restartTextbookYear;
	}

	//cout << typeid(program.textbook.year).name() << endl; // for debug

restartCollege:
	cout << "\nEnter College name (Mission or WestValley): ";
	numberOfItems = 2;
	validInputs = new string[numberOfItems] { "Mission", "WestValley" };
	if (ClassInfoQualifer(GetUserInput(program.college.name), validInputs, numberOfItems) == false)
	{
		goto restartCollege;
	}

restartCity:
	cout << "\nEnter campus location (Santa Clara or Saratoga): ";
	numberOfItems = 2;
	validInputs = new string[numberOfItems] { "Santa Clara", "Saratoga" };
	if (ClassInfoQualifer(GetUserInput(program.college.city), validInputs, numberOfItems) == false)
	{
		goto restartCity;
	}


}; // end of void Grades::SetClassInfo()



string Grades::ToUpper(string &s) // s is string, l is length of string
{
	for (char &c : s)
	{
		c = char(toupper(c));
	}

	return s;

}; // end of string Grades::ToUpper(string s)



bool Grades::ClassInfoQualifer(string userInput, string validInputs[], int size)
{
	//cout << "ClassInfoQualifer" << endl;

	if (userInput == "") // no input? better start over.
	{
		cout << "No input, try again" << endl;
		return false;
	}

	int n = 0;

	while (n < size) // loop through the list of valid inputs, if user input matches any one on the list, return true.
	{
		if (userInput == ToUpper(validInputs[n]))
		{
			//cout << userInput << endl;
			return true;
		}

		n++;
	}

	cout << "Invalid input, try again!" << endl;
	return false; // if nothing found, return false and start over

}; // end of bool Grades::ClassInfoQualifer(string userInput, string validInputs[], int size)



string Grades::GetUserInput(string &userInput) // this funciton can be used as function argument
{
	getline(cin, userInput);
	return ToUpper(userInput);

}; // end of Grades::GetUserInput(string &userInput)



int Grades::GetUserInput(int &userInput) // functoin overload to accept int input
{
	if (!(cin >> userInput))
	{
		cin.clear();
		userInput = 0;
	}

	cin.ignore(INT_MAX, '\n');
	return userInput;
};



/*************************
*                        *
*    PUBLIC FUNCTIONS    *
*                        *
*************************/

Grades::Grades() // default constructor
{

}; // end of Grades::Grades()



void Grades::SelectClass() // public member
{
	InputClassName();
	SetClassInfo();

}; // end of void Grades::SelectClass()



void Grades::DisplayClassInfo()
{
	cout << endl; // line break

	int w = 20; // width

	string edition; // determine text book edition
	switch (program.textbook.year)
	{
		case 2010:
			edition = "Seventh";
		case 2012:
			edition = "Eight";
		case 2013:
			edition = "Ninth";
	};

	cout << setw(w) << left << setfill('.') << "College Name: " << ' ' << program.college.name << endl;
	cout << setw(w) << left << setfill('.') << "College Location: " << ' ' << program.college.city << endl;
	cout << setw(w) << left << setfill('.') << "Program semester: " << ' ' << program.semester << endl;
	cout << setw(w) << left << setfill('.') << "Program time: " << ' ' << program.time << endl;
	cout << setw(w) << left << setfill('.') << "Textbook: " << ' ' << program.textbook.title << endl;
	cout << setw(w) << left << setfill('.') << "Author: " << ' ' << program.textbook.author << endl;
	cout << setw(w) << left << setfill('.') << "Publish: " << ' ' << program.textbook.year << " - " << edition << " edition" << endl;
		
} // end of void Grades::Print()



bool Grades::CheckContinue()
{
	char c;

	bool status;

	cout << endl; // line break

	while (true)
	{
		cout << "Do you wish to continue (Y/N)? ";

		try
		{
			cin.get(c);

			cin.clear();
			cin.ignore(INT_MAX, '\n');

			c = toupper(c);

			if (c == 'Y' || c == 'N') // if user entered anything other than y or n, repeat.
			{
				c == 'Y' ? status = true : status = false;
				break;
			} // end of if (c == 'Y' || c == 'N')
			else
			{
				throw 'e';
			}
		} // end of try
		catch (char error)
		{
			error;
			cout << "\nInvalid input detected, please try agian.\n" << endl;
		} // end of catch (char error)
		catch (...)
		{
			cout << "\nSome unknown error occured.\n" << endl;
		}// end of catch (...)

	} // end of while (true)

	return status;

}; // end of CheckContinue()
