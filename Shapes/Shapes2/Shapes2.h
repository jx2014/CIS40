class Shapes2
{
	private:
		char selection; 
		bool retryStatus;
		static double rArea, tArea, zArea, cArea;

		double GetLength();
		void DisplayMenu();
		void GetSelection();

		//shapes related functions
		void Rectangle();
		void Triangle();
		void Trapezoid();
		void Circle();

		// end of private

	public:
		//default constructor
		Shapes2();

		//menu related functions
		char GetCurrentSelection();		
		char MenuSelection();
		void ImplementSelection();

		//For testing private function GetSelection()
		void PublicGetLengh();

		//flow control related functions
		bool CheckContinue();
		bool RetryStatus();
		void ResetGlobalVariables();

		// end of public

}; // end of class Shapes2