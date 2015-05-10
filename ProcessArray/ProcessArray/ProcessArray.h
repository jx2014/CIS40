#include <iomanip>
#include <string>
#include <array>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

class ProcessArray
{
	private:
		const static size_t SIZE = 10;
		const static int WIDTH = 50;
		size_t cArray[SIZE]; // c type array of size 10
		array <size_t, SIZE> cppArray; // c++ type array of size 10
		int BinarySearch(size_t *someArray, size_t indexEnd, const size_t &targetElement);
		int BinarySearch2(size_t array[], int numElems, size_t value);
		int LinearSerachCArray(size_t *someArray, const size_t size, const size_t &targetElement);
		int LinearSerachCppArray(array <size_t, SIZE> &someArray, const size_t &targetElement);
		void BubbleSortCArrayDescending(size_t *someArray, const size_t size);
		void SelectionSortCppArray(array<size_t, SIZE> &);

	public:
		void UsingCTypeAlgorithms();
		void UsingCppTypeAlgorithms();
		void ProcessArray::DisplayArray(string message, size_t someArray[SIZE]);
		void ProcessArray::DisplayArrayIndex(string message, size_t someArray[SIZE]);
		void ProcessArray::DisplayArray(string message, array <size_t, SIZE> someArray);

}; // end of class ProcessArray