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
	array <int, 5> alist = { 11, 22, 33, 44, 55 };

	//cout << alist.begin << endl;

	cout << begin(alist);

	cout << endl;
	system("pause");
} // end of main()