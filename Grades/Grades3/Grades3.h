#include <iostream>
#include <iomanip>
#include <string>
#include <array>
//#include <initializer_list>

using namespace std;


class Grades
{
	private:
		static const size_t gradeCounter = { 5 };
		int grades[gradeCounter];
		
		void GetGrades(array<int, gradeCounter> &a); // c++ style array
		void GetGrades(); // c style array
		double GetAverage(array<int, gradeCounter> &a); // c++ style array
		double GetAverage(); // c style array
		int GetMaximum();
		int GetMinimum();
		void ShowLetterGrade();
		void DisplayGrades(array<int, gradeCounter> &a); // c++ style array
		void DisplayGrades(); // c style array
		/*
		string courseName;
		void InputClassName();
		void SetClassInfo();
		bool CheckIfLegalName(string s);

		Course program;
		TextBook textbook;
		College college;

		string ToUpper(string &s); // convert string to upper case
		bool ClassInfoQualifer(string userInput, string qualifier[], int size);
		string GetUserInput(string &userInput);
		int GetUserInput(int &userInput);
		*/


	public:
		//Grades(); // default constructor
		void ProcessGrades();
		/*
		void SelectClass();
		void DisplayClassInfo();
		bool CheckContinue();
		*/

}; // end of class Grades