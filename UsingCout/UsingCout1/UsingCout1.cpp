/************************

UsingCout1

Project: UsingCout1
Purpose: Learning the usage of cout and printf_s, and various io manuplators
		 Total five functions defined.
Author: Jeremy Xue Zhiming
Date: Feb 7, 2015

Lab: 1

************************/

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::setprecision;
using std::fixed;


void DisplayWithCout()
{
	cout << "1 2 3 4" << endl; //one statement with one string to cout
	
	cout << "1 " << "2 " << "3 " << "4 " << endl; // one statement with four cascaded inputs
	
	cout << "1 "; //four statement
	cout << "2 ";
	cout << "3 ";
	cout << "4 " << endl;

} // end of DisplayWithCout()


void DisplayWithPrintf()
{
	printf_s("1 2 3 4\n");	

} // end of DisplayWithPrintf()


void DisplayTable()
{
	int n{ 1 };

	cout << "number\t" << "square\t" << "cube" << endl;

	cout << setw(2) << n << "\t" << setw(2) << n * n << "\t" << setw(2) << n * n * n << endl;
	n++;
	cout << setw(2) << n << "\t" << setw(2) << n * n << "\t" << setw(2) << n * n * n << endl;
	n++;
	cout << setw(2) << n << "\t" << setw(2) << n * n << "\t" << setw(2) << n * n * n << endl;

} // end of DisplayTable()


void ReDisplayTable()
{
	int n{ 1 };

	printf_s("%s\t%2s\t%2s\n", "number", "square", "cube");
	printf_s("%2d\t%2d\t%2d\n", n, n*n, n*n*n);
	n++;
	printf_s("%2d\t%2d\t%2d\n", n, n*n, n*n*n);
	n++;
	printf_s("%2d\t%2d\t%2d\n", n, n*n, n*n*n);

} // end of ReDisplayTable()


void Circle()
{
	double pi{ 3.1415926 };
	double rad{ 1.25 };

	cout << "Radius\t" << "Length\t" << "Area" << endl;
	cout << setprecision(2) << fixed << rad << "\t" << 2 * pi * rad << "\t" << pi * rad * rad << "\t" << endl;

} // end of Circle()


int main()
{
	
	cout << "\nThis is the output from function DisplayWithCout():" << endl;

	DisplayWithCout();

	cout << "\nThis is the output from function DisplayWithPrintf():" << endl;

	DisplayWithPrintf();
	
	cout << "\nThis is the output from function DisplayTable():" << endl;

	DisplayTable();

	cout << "\nThis is the output from function ReDisplayTable():" << endl;

	ReDisplayTable();

	cout << "\nThis is the output from function Circle():" << endl;

	Circle();

	cout << "\n";

	system("pause");

} // end of main()

