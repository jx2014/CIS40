#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <initializer_list>

using namespace std;





struct TextBook
{
	string title;
	string author;
	int year;

}; // end of struct Grades::TextBook



struct College
{
	string name;
	string city;

}; // end of struct Grades::College



struct Course
{
	string semester;
	string time;
	TextBook textbook;
	College college;

}; // end of struct Grades::Course



class Grades
{
	private:
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
		

	public:		
		Grades(); // default constructor
		void SelectClass();
		void DisplayClassInfo();
		bool CheckContinue();

}; // end of class Grades