#include "Grades3.h"


#define WHILEWTRYCATCH 1
#define DOWHILEWTRYCATCH 0
#define WHILEWOTRYCATCH 0
#define DOWHILEWOTRYCATCH 0



/*************************
*                        *
*    PRIVATE FUNCTIONS   *
*                        *
*************************/
void Grades::GetGrades()
{

	cout << R"(
********************************************
**                                        **
**  This is GetGrades with C style array  **
**                                        **
********************************************

)";

	size_t i = 0;

#if WHILEWTRYCATCH
	while (true)
	{
		cout << "Enter Grades(50-100): ";
		
		cin >> grades[i];

		try
		{
			if (!cin.good())
			{
				throw 'e'; // generate char error
			}
			else if (grades[i] < 50 || 100 < grades[i])
			{
				throw 0; // generate int error
			}
			else
			{
				cin.ignore(INT_MAX, '\n');
				i++;
				if (i < gradeCounter)
					continue; // to the next item in array
				else
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
			cout << "Grades is outside of legal range, please try agian.\n" << endl;
		}
	} // end of while(true) without try catch
#endif


#if DOWHILEWTRYCATCH
	do
	{
		cout << "Enter Grades(50-100): ";

		cin >> grades[i];

		try
		{
			if (!cin.good())
			{
				throw 'e'; // generate char error
			}
			else if (grades[i] < 50 || 100 < grades[i])
			{
				throw 0; // generate int error
			}
			else
			{
				cin.ignore(INT_MAX, '\n');
				i++;
				if (i < grades.size())
					continue; // to the next item in array
				else
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
			cout << "Grades is outside of legal range, please try agian.\n" << endl;
		}
	} while (true); // end of while(true)
#endif


#if WHILEWOTRYCATCH
	while (true)
	{
		cout << "Enter Grades(50-100): ";
		cin >> grades[i];

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input detected, please try agian.\n" << endl;
			continue;
		}
		else if (grades[i] < 50 || 100 < grades[i])
		{
			cin.ignore(INT_MAX, '\n');
			cout << "Grades is outside of legal range, please try agian.\n" << endl;
		}
		else
		{
			cin.ignore(INT_MAX, '\n');
			i++;
			if (i < grades.size())
				continue; // to the next item in array
			else
				break;
		}
	}// end of while(true) without try catch
#endif


#if DOWHILEWOTRYCATCH
	do
	{
		cout << "Enter Grades(50-100): ";
		cin >> grades[i];

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input detected, please try agian.\n" << endl;
			continue;
		}
		else if (grades[i] < 50 || 100 < grades[i])
		{
			cin.ignore(INT_MAX, '\n');
			cout << "Grades is outside of legal range, please try agian.\n" << endl;
		}
		else
		{
			cin.ignore(INT_MAX, '\n');
			i++;
			if (i < grades.size())
				continue; // to the next item in array
			else
				break;
		}		
	} while (true); // end of do while(true) without try catch
#endif
	
}; // end of void Grades::GetGrades()



void Grades::DisplayGrades()
{
	for (auto i = 0; i < gradeCounter; i++)
	{
		cout << grades[i] << " ";
	}
	cout << endl; // line break

} // end of void Grades::DisplayGrades()



double Grades::GetAverage()
{
	int total = {};

	for (auto i = 0; i < gradeCounter; i++)
	{
		total += grades[i];
	}

	return static_cast<double>(total) / gradeCounter;

} // end of double Grades::GetAverage()



int Grades::GetMaximum()
{
	int max = grades[0];

	for (auto i = 0; i < gradeCounter; i++)
	{
		if (grades[i] > max)
		{
			max = grades[i];
		}			
	}
	auto maxVal = max_element(begin(grades), end(grades));
	
	return *maxVal;
	//return max;

} // end of int Grades::GetMaximum()



int Grades::GetMinimum()
{
	int min = grades[0];

	for (auto i = 0; i < gradeCounter; i++)
	{
		if (grades[i] < min)
		{
			min = grades[i];
		}
	}
	auto minVal = min_element(begin(grades), end(grades));
	return *minVal;
	//return min;

} // end of int Grades::GetMinimum()



void Grades::GetGrades(array<int, gradeCounter> &a)
{
	cout << R"(
********************************************
**                                        **
** This is GetGrades with C++ style array **
**                                        **
********************************************

)";

	size_t i = 0;

	do
	{
		cout << "Enter Grades(50-100): ";
		cin >> a[i];

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input detected, please try agian.\n" << endl;
			continue;
		}
		else if (a[i] < 50 || 100 < a[i])
		{
			cin.ignore(INT_MAX, '\n');
			cout << "Grades is outside of legal range, please try agian.\n" << endl;
		}
		else
		{
			cin.ignore(INT_MAX, '\n');
			i++;
			if (i < a.size())
				continue; // to the next item in array
			else
				break;
		}
	} while (true); // end of do while(true) without try catch

}; // end of void Grades::GetGrades(array<int, gradeCounter> &a)



void Grades::DisplayGrades(array<int, gradeCounter> &a) // c++ style array
{
	for (auto i = a.begin(); i != a.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl; // line break
}; // end of void Grades::DisplayGrades()



double Grades::GetAverage(array<int, gradeCounter> &a) // c++ style array
{
	int total = {};

	for (auto i = a.begin(); i != a.end(); i++)
	{
		total += *i;
	}

	return static_cast<double>(total) / gradeCounter;
}




void Grades::ShowLetterGrade()
{
	char letterGrade;

	double average = GetAverage();

	if (average >= 88)
		letterGrade = 'A';
	else if (average >= 75)
		letterGrade = 'B';
	else if (average >= 62)
		letterGrade = 'C';
	else if (average >= 50)
		letterGrade = 'D';
	else if (average >= 1)
		letterGrade = 'F';
	else
		letterGrade = 'I';

	switch (letterGrade)
	{
		case 'A':
			cout << "Letter grade is A : Excellent" << endl;
			break;
		case 'B':
			cout << "Letter grade is B : Good" << endl;
			break;
		case 'C':
			cout << "Letter grade is C : Satisfactory" << endl;
			break;
		case 'D':
			cout << "Letter grade is D : Passing" << endl;
			break;
		case 'F':
			cout << "Letter grade is F : Failing" << endl;
			break;
		case 'I':
			cout << "Letter grade is I : Incomplete" << endl;
			break;
	} // end of switch

} // end of void Grades::ShowLetterGrade()



/*************************
*                        *
*    PUBLIC FUNCTIONS    *
*                        *
*************************/

void Grades::ProcessGrades()
{
	// c style array
	GetGrades(); 
	DisplayGrades();
	cout << "Averge for above grades is: " << setprecision(2) << showpoint << fixed << GetAverage() << '\n';
	cout << "Maximum for above grades is: " << setprecision(2) << showpoint << fixed << GetMaximum() << '\n';
	cout << "Minimum for above grades is: " << setprecision(2) << showpoint << fixed << GetMinimum() << '\n' << endl;
	ShowLetterGrade();

	cout << endl; // line break

	for (size_t j = 0; j < gradeCounter; j++)
	{
		grades[j] = 50 + rand() % 51;
	}

	DisplayGrades();
	cout << "Averge for above grades is: " << setprecision(2) << showpoint << fixed << GetAverage() << '\n';
	cout << "Maximum for above grades is: " << setprecision(2) << showpoint << fixed << GetMaximum() << '\n';
	cout << "Minimum for above grades is: " << setprecision(2) << showpoint << fixed << GetMinimum() << '\n' << endl;
	ShowLetterGrade();

	// c++ style array
	array<int, gradeCounter> arr = {};
	GetGrades(arr);
	DisplayGrades(arr);
	cout << "Averge for above grades is: " << setprecision(2) << showpoint << fixed << GetAverage(arr) << endl;


}; // end of void Grades::ProcessGrades()