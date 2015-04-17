#include "LibIncludes.h"
#include "Commission.h"

Commission::Commission(string fN, string lN, string ssn, double bS, double gS, double cR) //initialization default variables. 
{
	cout << "\n...Employee " << fN  + ", " + lN << " initialized...\n" << endl;

	firstName = { fN };
	lastName = { lN };
	SSN = { ssn };
	baseSalary = { bS };
	grossSales = { gS };
	commissionRate = { cR };

}; //end of initialization. 


Commission::~Commission()
{
	cout << "Destructor from object " 
		<< GetFirstName() + ", " + GetLastName() 
		<< " is been called" << endl;
};//end of destructor ~Commission()

//Get variables
string Commission::GetFirstName()
{
	return firstName;
}; // end of GetFirstName()


string Commission::GetLastName()
{
	return lastName;
}; // end of GetlastName()


string Commission::GetSSN()
{
	return SSN;
}; // end of SSN()


double Commission::GetBaseSalary() const
{
	//baseSalary++;
	return baseSalary;
}; // end of GetBaseSalary()


double Commission::GetGrossSales()
{
	return grossSales;
}; // end of GetGrossSales()


double Commission::GetCommissionRate()
{
	return commissionRate;
}; // end of GetCommissionRate()

void Commission::Print()
{
	cout << setw(5) << left << "Name:" << setw(30) << right << GetFirstName() + ", " + GetLastName() << '\n'
		<< setw(36) << setfill('-') << '\n'
		<< setfill(' ')
		<< setw(20) << left << "Social Security #:" << setw(15) << right << GetSSN() << "\n"
		<< setw(20) << left << "Base salary:" << setw(4) << right << "$" << setw(11) << right << GetBaseSalary() << '\n'
		<< setw(20) << left << "Gross Sales:" << setw(4) << right << "$" << setw(11) << right << GetGrossSales() << '\n'
		<< setw(20) << left << "Commission Rate:" << setw(14) << right << GetCommissionRate() << '%' << '\n'
		<< setw(20) << left << "Total Earnings:" << setw(4) << right << "$" << setw(11) << right << Earnings() << endl << endl;

}; // end of Print()



//Calculation functions
double Commission::Earnings()
{
	return baseSalary + commissionRate * grossSales;
};// end of Earnings();



//Set variables
void Commission::SetBaseSalary(const double & bs)
{
	baseSalary = bs;

	if (baseSalary < 0.0)
	{
		throw invalid_argument("Salary must be >= 0.0");
	}

#if A

	cout << "Enter a base salary for " << firstName << ", " << lastName << ": ";
	
	cin >> baseSalary;
	cin.ignore(INT_MAX, '\n');

	if (!cin.good())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Invalid input!" << endl;
	}
	else if (baseSalary < 0.0)
	{
		throw invalid_argument("Salary must be >= 0.0");
	} // end of if
#endif

}; // end of SetBaseSalary()


void Commission::SetFirstName(const string & fn)
{
	firstName = fn;
}; // end of SetFirstName()


void Commission::SetLastName(const string & ln)
{
	lastName = ln;
}; // end of SetFirstName()


void Commission::SetSSN(const string & ssn)
{
	SSN = ssn;
}; // end of SetFirstName()
