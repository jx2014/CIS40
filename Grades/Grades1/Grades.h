#include <string>
using namespace std;

class Grades
{
	private:
		// static private variables
		// static int gradeCounter = {};
		// static const int gradeCounter = { 5 };		
		static int gradeCounter;
		
		// normal private variables
		// int gradeCounter = {};
		string fullClassName;
		
	public:
		// static public variables
		static char className;
		
		// normal public variables:
		int classNumber;

		// default constructor
		Grades();

		// all other public functions
		static int GetGradeCounter(); // static function accessing static private variable
		static void DisplayClassName(Grades); // static function accessing non-static private variable
		static string InputClassName();


}; // end of class Grades