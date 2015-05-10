#include "ProcessArray.h"



bool GreaterThanSixty(int a)
{ 
	return (a > 60); 
};



void ProcessArray::UsingCppTypeAlgorithms() // c++ type array
{
	//greeting message
	cout << R"(

********************************************************************************
**                                                                            **
**                This is ProcessArray with C++ style array                   **
**                                                                            **
********************************************************************************

)";

	//display the size of c++ type array
	cout << setw(WIDTH) << fixed << left << setfill('.') 
		<< "cppArray.size()" << ": " << cppArray.size() << endl;


	//initialize c++ type array with 0s
	cout << "\nInitialize c++ type array with 0s." << endl;
	for (auto &i : cppArray)
	{
		i = 0;

	}; // end of for (auto i = cppArray.begin(); i != cppArray.end(); i++)


	/* // use overloaded functoin instead
	//display content of c++ type array
	cout << "\nDisplay content of c++ type array: ";
	for (auto &i : cppArray)
	{
		cout << i << ' ';

	}; // end of for (auto &i : cppArray)
	*/


	//display content of c++ type array
	DisplayArray("Display content of c++ type array", cppArray);


	//initialize c++ type array with random number from range 0 to 100
	cout << "\nInitialize c++ type array with random number from range 0 to 100." << endl;
	for (auto i = cppArray.begin(); i != cppArray.end(); i++)
	{
		*i = rand() % 100 + 1; // in the range 1 to 100

	}; // end of for (int i = 0; i < SIZE; i++)


	//display content of c++ type array
	DisplayArray("Display content of c++ type array", cppArray);


	//display content of c++ type array in reverse order
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Display content of c++ type array in reverse order"
		<< ": ";
	for (auto i = cppArray.rbegin(); i != cppArray.rend(); i++)
	{
		cout << *i << ' ';

	}; // end of for (auto i = cppArray.rbegin(); i != cppArray.rend(); i++)


	cout << endl; // line break


	//display the sum of c++ type array
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Display the sum of c++ type array"
		<< ": ";
	cout << accumulate(cppArray.begin(), cppArray.end(), 0) << endl;


	//display the min and max of c++ type array
	auto minElement = *min_element(cppArray.begin(), cppArray.end());
	auto maxElement = *max_element(cppArray.begin(), cppArray.end());
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Display the min_element() of c++ type array"
		<< ": ";
	cout << minElement << endl;
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Display the max_element() of c++ type array"
		<< ": ";
	cout << maxElement << endl;


	//find the first element of a specified value
	size_t targetElement = 37;
	auto ptr = find(cppArray.begin(), cppArray.end(), targetElement);
	cout << '\n'
		<< "Target element " << targetElement
		<< setw(33) << fixed << left << setfill('.')
		<< " found in cppArra at index "
		<< ": ";
	if (ptr != cppArray.end())
	{
		cout << ptr - cppArray.begin() << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (ptr != cppArray.end())

	targetElement = 99;
	ptr = find(cppArray.begin(), cppArray.end(), targetElement);
	cout << '\n'
		<< "Target element " << targetElement
		<< setw(33) << fixed << left << setfill('.')
		<< " found in cppArra at index "
		<< ": ";
	if (ptr != cppArray.end())
	{
		cout << ptr - cppArray.begin() << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (ptr != cppArray.end())


	// count # of elements in the array of a specified value
	targetElement = 43;
	int targetCount = count(cppArray.begin(), cppArray.end(), targetElement);
	cout << '\n'
		<< "Number of " << targetElement
		<< setw(38) << fixed << left << setfill('.')
		<< " found in c++ type array is"
		<< ": "
		<< targetCount << endl;
	cout << '\n'
		<< "cppArray[0] = targetElement" << endl;
	cppArray[0] = targetElement;
	targetCount = count(cppArray.begin(), cppArray.end(), targetElement);
	cout << '\n'
		<< "Number of " << targetElement
		<< setw(38) << fixed << left << setfill('.')
		<< " found in c++ type array is"
		<< ": "
		<< targetCount << endl;


	// count # of elements in the array greater than a specified value	
	//int greaterTarget = count_if(cppArray.begin(), cppArray.end(), [](size_t i){return i > 60; });
	int greaterTarget = count_if(cppArray.begin(), cppArray.end(), GreaterThanSixty);
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Number of values greater than 60 in cppArray is"
		<< ": "
		<< greaterTarget << endl;


	//display content of c++ type array
	DisplayArray("Display content of c++ type array", cppArray);


	//is array sorted?
	string answer;
	is_sorted(cppArray.begin(), cppArray.end()) ? answer = "Yes" : answer = "No";
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Is array sorted?"
		<< ": "
		<< answer << endl;


	//sort the darn thing
	sort(cppArray.begin(), cppArray.end());
	cout << '\n' << "sort(cppArray.begin(), cppArray.end())" << endl;


	//display content of c++ type array
	DisplayArray("Display content of c++ type array", cppArray);


	//is array sorted?
	is_sorted(cppArray.begin(), cppArray.end()) ? answer = "Yes" : answer = "No";
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Is array sorted?"
		<< ": "
		<< answer << endl;


	//reverse sort the darn thing
	sort(cppArray.begin(), cppArray.end(), greater<size_t>());
	cout << '\n' << "sort with greater<size_t>()" << endl;


	//display content of c++ type array
	DisplayArray("Display content of c++ type array", cppArray);


	//reverse array
	reverse(cppArray.begin(), cppArray.end());
	cout << '\n' << "Reverse cppArray." << endl;


	//display content of c++ type array
	DisplayArray("Display content of c++ type array", cppArray);


	//binary_search for a value within the array
	targetElement = 70;
	binary_search(cppArray.begin(), cppArray.end(), targetElement) ? answer = "Found" : answer = "Not found";
	cout << '\n'
		<< "\"binary_search\" for " << targetElement
		<< setw(28) << fixed << left << setfill('.')
		<< " in cppArray"
		<< ": "
		<< answer << endl;

	//binary_search for a value outside of the array
	targetElement = 22;
	binary_search(cppArray.begin(), cppArray.end(), targetElement) ? answer = "Found" : answer = "Not found";
	cout << '\n'
		<< "\"binary_search\" for " << targetElement
		<< setw(28) << fixed << left << setfill('.')
		<< " in cppArray"
		<< ": "
		<< answer << endl;


	//shuffle array
	cout << "\nshuffle array." << endl;
	random_shuffle(cppArray.begin(), cppArray.end());


	//display content of c++ type array
	DisplayArray("Display content of c++ type array", cppArray);


	//search by LinearSearchCppArray()
	targetElement = 70;
	int index = {};
	index = LinearSerachCppArray(cppArray, targetElement);
	cout << '\n'
		<< "LinearSerach found target " << targetElement
		<< setw(22) << fixed << left << setfill('.')
		<< " at index"
		<< ": ";
	if (index > -1)
	{
		cout << index << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (index > -1)


	//search by LinearSearchCppArray()
	targetElement = 22;
	index = LinearSerachCppArray(cppArray, targetElement);
	cout << '\n'
		<< "LinearSerach found target " << targetElement
		<< setw(22) << fixed << left << setfill('.')
		<< " at index"
		<< ": ";
	if (index > -1)
	{
		cout << index << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (index > -1)


	//SelectionSortCppArray
	cout << "\nAfter SelectionSortCppArray treatment." << endl;
	SelectionSortCppArray(cppArray);


	//display content of c++ type array
	DisplayArray("Display content of c++ type array", cppArray);

		
	cout << endl; // line break

}; // end of void ProcessArray::UsingCppTypeAlgorithms()



void ProcessArray::DisplayArray(string message, array <size_t, SIZE> someArray)
{
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< message
		<< ": ";

	for (auto &i : someArray)
	{
		cout << i << ' ';

	}; // end of for (int i = 0; i < SIZE; i++)

	setfill(' ');

	cout << endl; // line break

}; // end of void ProcessArray::DisplayArray(string message, size_t array[])



int ProcessArray::LinearSerachCppArray(array <size_t, SIZE> & someArray, const size_t & targetElement)
{
	for (auto &i : someArray)
	{
		if (i == targetElement)
		{
			return &i - &someArray[0]; // return index
		}
		else
		{
			continue;
		}
	}
	return -1;
}; // end of int LinearSerachCArray(array <size_t, SIZE> someArray, const size_t & targetElement)



void ProcessArray::SelectionSortCppArray(array<size_t, SIZE> & someArray)
{
	size_t minElement = {};
	int minElementIndex = {};
	int n = {};

	while (n < SIZE)
	{
		minElement = someArray[n];

		//find minimum in the remaining array
		for (auto i = someArray.begin() + n; i != someArray.end(); i++)
		{
			if (minElement > *i) // a new minimum found, need to swap
			{
				minElement = *i;
				minElementIndex = i - someArray.begin();

				someArray[minElementIndex] = someArray[n];
				someArray[n] = minElement;
			}
		}

		n++;
	}
}; // end of void ProcessArray::SelectionSortCppArray(array<size_t, SIZE> &)