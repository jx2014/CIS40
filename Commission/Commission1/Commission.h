class Commission
{
	private:
		string firstName;
		string lastName;
		string SSN;

		double baseSalary;
		double grossSales;
		double commissionRate;

		// end of private

	public:
		//default constructor
		Commission(string fN = { "FirstName" }, 
					string lN = { "LastName" },
					string SSN = { "123-45-6789" },
					double bS = { 300 },
					double gS = { 5000 },
					double cR = { 0.06 }
		); // end of Commission()

		~Commission(); //destructor


		//Get variables
		string GetFirstName();
		string GetLastName();
		string GetSSN();

		double GetBaseSalary() const;
		double GetGrossSales();
		double GetCommissionRate();

		void Print();

		//Calculation functions
		double Earnings();

		//Set variables
		void SetBaseSalary(const double & bs);
		void SetFirstName(const string & fn);
		void SetLastName(const string & ln);
		void SetSSN(const string & ssn);
		
		// end of public

}; // end of class Commission