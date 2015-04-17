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

#define BBC 1
#define SIZELIMIT 0

/*using std::cout;
using std::cin;
using std::endl;
using std::hex;
using std::dec;
using std::setw;
using std::left;
using std::right;*/
using namespace std;



template < class T >
T maximum(T value1, T value2, T value3)
{
	T maximumValue = value1; // assume value1 is maximum

	if (value2 > maximumValue)
		maximumValue = value2;

	if (value3 > maximumValue)
		maximumValue = value3;

	return maximumValue;
}

int Inc(int &a)
{
	a = a + 1;
	return a;
}

int Dec(int &a)
{
	a = a - 1;
	return a;
}

int main()
{
	
	int ival = { 1234 };

	int *pi = { &ival };

	int **ppi = { &pi };

	cout << "ival: " << ival << '\n'
		<< "*pi: " << *pi << '\n'
		<< "**ppi: " << **ppi << '\n';

	ival++;
	cout << endl;

	cout << "ival: " << ival << '\n'
		<< "pi: " << pi << '\n'
		<< "ppi: " << ppi << '\n';

	cout << endl;

	cout << "type of (pi): " << typeid(pi).name() << endl;
	cout << "type of (pi): " << typeid(ppi).name() << endl;

	int * piAddr;

	piAddr = pi;

	cout << piAddr;

	cout << endl;
	system("pause");


} 



#if adsf

int test()
{
	size_t n{ 1 };

#if SIZELIMIT == 1

	cout << setw(20) << left << "size_t" << ": " << numeric_limits<size_t>::max() << endl;
	cout << setw(20) << left << "sizeof size_t" << ": " << sizeof(size_t) << endl;
	cout << setw(20) << left << "streamsize" << ": " << numeric_limits<streamsize>::max() << endl;
	cout << setw(20) << left << "bool" << ": " << numeric_limits<bool>::max() << endl;
	cout << setw(20) << left << "char" << ": " << numeric_limits<char>::max() << endl;
	cout << setw(20) << left << "signed char" << ": " << numeric_limits<signed char>::max() << endl;
	cout << setw(20) << left << "unsiged char" << ": " << numeric_limits<unsigned char>::max() << endl;
	cout << setw(20) << left << "wchar_t" << ": " << numeric_limits<wchar_t>::max() << endl;
	cout << setw(20) << left << "char16_t" << ": " << numeric_limits<char16_t>::max() << endl;   // C++11 feature
	cout << setw(20) << left << "char32_t" << ": " << numeric_limits<char32_t>::max() << endl;   // C++11 feature
	cout << setw(20) << left << "short" << ": " << numeric_limits<short>::max() << endl;
	cout << setw(20) << left << "unsigned_short" << ": " << numeric_limits<unsigned short>::max() << endl;
	cout << setw(20) << left << "int" << ": " << numeric_limits<int>::max() << endl;
	cout << setw(20) << left << "unsigned_int" << ": " << numeric_limits<unsigned int>::max() << endl;
	cout << setw(20) << left << "long" << ": " << numeric_limits<long>::max() << endl;
	cout << setw(20) << left << "unsiged long" << ": " << numeric_limits<unsigned long>::max() << endl;
	cout << setw(20) << left << "long long" << ": " << numeric_limits<long long>::max() << endl;
	cout << setw(20) << left << "unsigned long long " << ": " << numeric_limits<unsigned long long>::max() << endl;
	cout << setw(20) << left << "float" << ": " << numeric_limits<float>::max() << endl;
	cout << setw(20) << left << "size of float" << ": " << sizeof(float) << endl;
	cout << setw(20) << left << "double" << ": " << numeric_limits<double>::max() << endl;
	cout << setw(20) << left << "long double" << ": " << numeric_limits<long double>::max() << endl;
	cout << setw(20) << left << "INT_MAX" << ": " << INT_MAX << endl;

	cout << ((numeric_limits<unsigned long long>::max() - numeric_limits<streamsize>::max()) < 1 ? "unsigned long long" : "streamsize") << endl;
#endif

	int numCount;
	int total{ 0 };
	double average;

	cout << "How many numbers do you want to average ? ";
	cin >> numCount;

	for (int count = 0; count < numCount; count++)
	{
		int num;
		cout << "Enter a number: ";
		cin >> num;
		total += num;
		count++;
	}
	average = total / numCount;
	cout << "The average is " << average << endl;
	return 0;







	cout << '\n';

#if TEST

	int m = { 2 };

	while (m > 0)
	{
		m--;

		if (m <= 1)
		{
			cout << "\nabout to hit continue, and m is:" << m << '\n';
			continue;
		}

		cout << "\ncout is : " << m << '\n' << endl;
	}

	while (true)
	{
		cout << "\nEnter a number: ";
		cin >> n;
		cout << n << endl;

		cin.clear();
		cin.ignore(numeric_limits<long long>::max(), '\n');



		/*cout << showpoint << 0.8 * 2 << " : " << 0.16 << endl;
		cout << ((0.8 * 2 < 0.16) < 0.0001 ? true : false) << endl;
		*/

		system("pause");

	}
#endif

}

#endif