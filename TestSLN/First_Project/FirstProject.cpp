/************************
	Program Name

	Project:
	Purpose:
	Author:
	Date:

	Rev
************************/

#include <iostream>
#include <iomanip>
#include <exception>
#include <ctime>
#include <array>
#include <fstream>
#include <string>

/*using std::cout;
using std::cin;
using std::endl;
using std::hex;
using std::dec;
using std::setw;
using std::left;
using std::right;*/
using namespace std;

void main()
{
	string oFile = "output.txt";
	string oDir = "c:\\temp\\";
	
	string finalOutputFile = oDir + oFile;

	cout << "File to be writen: " << finalOutputFile << endl;
		
	ofstream outputFile(finalOutputFile);

	if (outputFile.is_open())
	{
		cout << "inside \"if (outputFile.is_open())\"" << endl;
		outputFile << "line 1 test 13" << endl;
		outputFile << "line 2 test 2\n";
		outputFile.close();
	}



	cout << endl;
	system("pause");
} // end of main()