#include "ProcessArray.h"



bool GreaterThanFifty(int a)
{
	return (a > 50);
};



void ProcessArray::UsingCTypeAlgorithms() // c type array
{
	//greeting message
	cout << R"(

********************************************************************************
**                                                                            **
**                 This is ProcessArray with C style array                    **
**                                                                            **
********************************************************************************

)";

	//display the size of c type array
	cout << setw(WIDTH) << fixed << left << setfill('.')
		<< "sizeof(cArray)" << ": " << sizeof(cArray) << endl;
	cout << setw(WIDTH) << fixed << left << setfill('.')
		<< "sizeof(size_t)" << ": " << sizeof(size_t) << endl;
	cout << setw(WIDTH) << fixed << left << setfill('.')
		<< "size of cArray" << ": " << sizeof(cArray) / sizeof(size_t) << endl;
		

	//initialize c type array with 0s
	cout << "\nInitialize c type array with 0s." << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cArray[i] = 0;

	}; // end of for (int i = 0; i < SIZE; i++)


	/* // use overloaded functoin instead
	//display content of c type array
	cout << "\nDisplay content of c type array: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << cArray[i] << ' ';

	}; // end of for (int i = 0; i < SIZE; i++)
	*/


	//display content of c type array
	DisplayArray("Display content of c type array", cArray);


	//initialize c type array with random number from range 0 to 100
	cout << "\nInitialize c type array with random number from range 0 to 100." << endl;
	for (auto i = begin(cArray); i != end(cArray); i++ )
	{
		*i = rand() % 100 + 1; // in the range 1 to 100

	}; // end of for (int i = 0; i < SIZE; i++)


	//display content of c type array
	DisplayArray("Display content of c type array", cArray);


	//display content of c type array in reverse order
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Display content of c type array in reverse order"
		<< ": ";
	for (auto i = rbegin(cArray); i != rend(cArray); i++)
	{
		cout << *i << ' ';

	}; // end of for (auto i = rbegin(cArray); i != rend(cArray); i++)


	cout << endl; // line break


	//display the sum of c type array
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Display the sum of c type array"
		<< ": ";
	cout << accumulate(begin(cArray), end(cArray), 0) << endl;


	//display the min and max of c type array
	auto minElement = *min_element(begin(cArray), end(cArray));
	auto maxElement = *max_element(begin(cArray), end(cArray));
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Display the min_element() of c type array"
		<< ": "
		<< minElement << endl;
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Display the max_element() of c type array"
		<< ": "
		<< maxElement << endl;


	//find the first element of a specified value
	size_t targetElement = 25;
	auto ptr = find(begin(cArray), end(cArray), targetElement);
	cout << '\n'
		<< "Target element " << targetElement
		<< setw(33) << fixed << left << setfill('.')
		<< " found in cArray at index "
		<< ": ";
	if (ptr != end(cArray))
	{
		cout << ptr - begin(cArray) << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (ptr != end(cArray))
	targetElement = 99;
	ptr = find(begin(cArray), end(cArray), targetElement);
	cout << '\n'
		<< "Target element " << targetElement
		<< setw(33) << fixed << left << setfill('.')
		<< " found in cArray at index "
		<< ": ";
	if (ptr != end(cArray))
	{

		cout << ptr - begin(cArray) << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (ptr != end(cArray))

	
	// count # of elements in the array of a specified value
	targetElement = 25;
	int targetCount = count(begin(cArray), end(cArray), targetElement);
	cout << '\n'
		<< "Number of " << targetElement 
		<< setw(38) << fixed << left << setfill('.') 
		<< " found in c type array is"		
		<< ": "
		<< targetCount << endl;
	cout << '\n'
		<< "cArray[0] = targetElement" << endl;
	cArray[0] = targetElement;
	targetCount = count(begin(cArray), end(cArray), targetElement);
	cout << '\n'
		<< "Number of " << targetElement
		<< setw(38) << fixed << left << setfill('.')
		<< " found in c type array is"
		<< ": "
		<< targetCount << endl;
	

	// count # of elements in the array greater than a specified value
	//int greaterTarget = count_if(begin(cArray), end(cArray), [](size_t i){return i > 50; });
	int greaterTarget = count_if(begin(cArray), end(cArray), GreaterThanFifty);
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Number of values greater than 50 in cArray is"
		<< ": "
		<< greaterTarget << endl;


	//display content of c type array
	DisplayArray("Display content of c type array", cArray);


	//is array sorted?
	string answer;
	is_sorted(begin(cArray), end(cArray)) ? answer = "Yes" : answer = "No";
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Is array sorted?"
		<< ": "
		<< answer << endl;


	//sort the darn thing
	sort(begin(cArray), end(cArray));
	cout << '\n' << "sort(begin(cArray), end(cArray))" << endl;


	//display content of c type array
	DisplayArray("Display content of c type array", cArray);


	//is array sorted?
	is_sorted(begin(cArray), end(cArray)) ? answer = "Yes" : answer = "No";
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< "Is array sorted?"
		<< ": "
		<< answer << endl;


	//reverse sort the darn thing
	sort(begin(cArray), end(cArray), greater<size_t>());
	cout << '\n' << "sort with greater<size_t>()" << endl;


	//display content of c type array
	DisplayArray("Display content of c type array", cArray);


	//reverse array
	reverse(begin(cArray), end(cArray));
	cout << '\n' << "Reverse cArray." << endl;


	//display content of c type array
	DisplayArray("Display content of c type array", cArray);


	//binary_search for a value within the array
	targetElement = 28;
	binary_search(begin(cArray), end(cArray), targetElement) ? answer = "Found" : answer = "Not found";
	cout << '\n'
		<< "\"binary_search\" for " << targetElement
		<< setw(28) << fixed << left << setfill('.')
		<< " in cArray"
		<< ": "
		<< answer << endl;


	//binary_search for a value outside of the array
	targetElement = 68;
	binary_search(begin(cArray), end(cArray), targetElement) ? answer = "Found" : answer = "Not found";
	cout << '\n'
		<< "\"binary_search\" for " << targetElement
		<< setw(28) << fixed << left << setfill('.')
		<< " in cArray"
		<< ": "
		<< answer << endl;
	

	//initialize c type array with 0s
	cout << "\nInitialize c type array manually." << endl;
	cArray[0] = 0;
	cArray[1] = 2;
	cArray[2] = 2;
	cArray[3] = 3;
	cArray[4] = 4;
	cArray[5] = 5;
	cArray[6] = 6;
	cArray[7] = 7;
	cArray[8] = 8;
	cArray[9] = 10;

	
	//display content of c type array
	DisplayArray("Display content of c type array", cArray);
	

	//BinarySearch() for a value outside of the array
	targetElement = 0;
	int index = {};
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
		if (index > -1)
		{
			cout << index << endl;
		}
		else
		{
			cout << "Not found" << endl;
		} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 1;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
		if (index > -1)
		{
			cout << index << endl;
		}
		else
		{
			cout << "Not found" << endl;
		} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 2;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
		if (index > -1)
		{
			cout << index << endl;
		}
		else
		{
			cout << "Not found" << endl;
		} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 3;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
		if (index > -1)
		{
			cout << index << endl;
		}
		else
		{
			cout << "Not found" << endl;
		} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 4;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
		if (index > -1)
		{
			cout << index << endl;
		}
		else
		{
			cout << "Not found" << endl;
		} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 5;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
		if (index > -1)
		{
			cout << index << endl;
		}
		else
		{
			cout << "Not found" << endl;
		} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 6;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
		if (index > -1)
		{
			cout << index << endl;
		}
		else
		{
			cout << "Not found" << endl;
		} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 7;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
	if (index > -1)
	{
		cout << index << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 8;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
	if (index > -1)
	{
		cout << index << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 9;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
	if (index > -1)
	{
		cout << index << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (index > -1)

	//BinarySearch() for a value outside of the array
	targetElement = 10;
	index = BinarySearch(cArray, SIZE, targetElement);
	cout << '\n'
		<< setw(20) << fixed << left << setfill(' ')
		<< "\"BinarySearch()\" for " << setw(3) << targetElement
		<< setw(26) << left << setfill('.')
		<< "in cArray index"
		<< ": ";
	if (index > -1)
	{
		cout << index << endl;
	}
	else
	{
		cout << "Not found" << endl;
	} // end of if (index > -1)


	//BinarySearch2() for a value outside of the array
	targetElement = 99;
	index = BinarySearch2(cArray, SIZE, targetElement);
		cout << '\n'
			<< setw(20) << fixed << left << setfill(' ')
			<< "\"BinarySearch2()\" for " << setw(3) << targetElement
			<< setw(25) << left << setfill('.')
			<< "in cArray index"
			<< ": ";
		if (index > -1)
		{
			cout << index << endl;
		}
		else
		{
			cout << "Not found" << endl;
		} // end of if (index > -1)


	//initialize c type array with random number from range 0 to 100
	cout << "\nInitialize c type array with random number from range 0 to 100." << endl;
	for (auto i = begin(cArray); i != end(cArray); i++)
	{
		*i = rand() % 100 + 1; // in the range 1 to 100

	}; // end of for (int i = 0; i < SIZE; i++)


	//display content of c type array
	DisplayArray("Display content of c type array", cArray);
		

	//shuffle array
	cout << "\nshuffle array." << endl;
	random_shuffle(begin(cArray), end(cArray));


	//display content of c type array
	DisplayArray("Display content of c type array", cArray);


	//search by LinearSearchCArray()
	targetElement = 92;
	index = LinearSerachCArray(cArray, SIZE, targetElement);
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


	//search by LinearSearchCArray()
	targetElement = 25;
	index = LinearSerachCArray(cArray, SIZE, targetElement);
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


	//BubbleSortCArrayDescending
	cout << "\nAfter BubbleSortCArrayDescending treatment." << endl;
	BubbleSortCArrayDescending(cArray, SIZE);

	//display content of c type array
	DisplayArray("Display content of c type array", cArray);


	cout << endl; // line break

}; // end of void ProcessArray::UsingCTypeAlgorithms()



void ProcessArray::DisplayArray(string message, size_t someArray[SIZE])
{
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< message
		<< ": ";

	for (int i = 0; i < SIZE; i++)
	{
		cout << setfill(' ') << setw(3) << left << fixed << someArray[i];

	}; // end of for (int i = 0; i < SIZE; i++)

	setfill(' ');

	cout << endl; // line break

}; // end of void ProcessArray::DisplayArray(string message, size_t array[])



void ProcessArray::DisplayArrayIndex(string message, size_t someArray[SIZE])
{
	cout << '\n'
		<< setw(WIDTH) << fixed << left << setfill('.')
		<< message
		<< ": ";

	for (int i = 0; i < SIZE; i++)
	{
		cout << setfill(' ') << setw(3) << left << fixed << i;

	}; // end of for (int i = 0; i < SIZE; i++)

	setfill(' ');

	cout << endl; // line break

}; // end of void ProcessArray::DisplayArray(string message, size_t array[])



int ProcessArray::BinarySearch(size_t *someArray, size_t indexEnd, const size_t & targetElement)
{
	indexEnd -= 1;
	size_t indexStart = 0;
	size_t indexMiddle = indexEnd / 2; // get mid point

	while (indexStart < indexMiddle && indexMiddle < indexEnd)
	{
		//cout << "head..." << endl;
		//cout << "someArray[indexStart]: " << someArray[indexStart] << endl;
		//cout << "someArray[indexMiddle]: " << someArray[indexMiddle] << endl;
		//cout << "someArray[indexEnd]: " << someArray[indexEnd] << endl;

#if NOTWORKING
		if (someArray[indexStart] < targetElement && targetElement < someArray[indexMiddle])
		{
			indexEnd = indexMiddle;
			//indexMiddle = (indexEnd + indexStart) / 2; // indexMiddle is the new indexEnd
		}
		else // (someArray[indexMiddle] < targetElement && targetElement < someArray[indexEnd])
		{
			indexStart = indexMiddle;			
		}

		indexMiddle = (indexEnd + indexStart) / 2;

		if (someArray[indexMiddle] == targetElement)
		{
			return indexMiddle;
		}
		else if (someArray[indexStart] == targetElement)
		{
			return indexStart;
		}
		else if (someArray[indexEnd] == targetElement)
		{
			return indexEnd;
		}
		else
		{
			return -1;
		}
#endif		

		if (someArray[indexStart] < targetElement && targetElement < someArray[indexMiddle])
		{
			indexEnd = indexMiddle;
			indexMiddle = (indexEnd + indexStart) / 2; // indexMiddle is the new indexEnd
		}
		else if (someArray[indexMiddle] < targetElement && targetElement < someArray[indexEnd])
		{
			indexStart = indexMiddle;
			indexMiddle = (indexEnd + indexStart) / 2;
		}
		else if (someArray[indexMiddle] == targetElement)
		{
			return indexMiddle;
		}
		else if (someArray[indexStart] == targetElement)
		{
			return indexStart;
		}
		else if (someArray[indexEnd] == targetElement)
		{
			return indexEnd;
		}
		else
		{
			return -1;
		}

		//cout << "...tail" << endl;
		//cout << "someArray[indexStart]: " << someArray[indexStart] << endl;
		//cout << "someArray[indexMiddle]: " << someArray[indexMiddle] << endl;
		//cout << "someArray[indexEnd]: " << someArray[indexEnd] << endl;
	}
	return -1;

}; // end of int ProcessArray::BinarySearch(size_t *someArray, size_t indexStart, size_t indexEnd, const size_t & targetElement)


// from handout
int ProcessArray::BinarySearch2(size_t array[], int numElems, size_t value)
{
	int first = 0;  // First array element
	int last = numElems - 1;  // Last array element
	int middle;  // Midpoint of search
	int position = -1;   // Position of search value
	bool found = false;  // Flag
	while (!found && first <= last)
	{
		middle = (first + last) / 2;  // Calculate midpoint
		if (array[middle] == value)  // If value is found
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // value is in lower half
			last = middle - 1;
		else
			first = middle + 1;  // value is in upper half
	}
	return position;
}


int ProcessArray::LinearSerachCArray(size_t *someArray, const size_t size, const size_t & targetElement)
{
	for (size_t i = 0; i < size; i++)
	{
		if (someArray[i] == targetElement)
		{
			return i;
		}
		else
		{
			continue;
		}
	}
	return -1;
}; // end of int ProcessArray::LinearSerachCArray(size_t * someArray, const size_t size, const size_t & targetElement)



void ProcessArray::BubbleSortCArrayDescending(size_t *someArray, const size_t size)
{
	bool needSwap = true;
	size_t temp = {};

	while (needSwap == true)
	{
		needSwap = false;

		for (size_t i = 0; i < (size - 1); i++)
		{
			if (someArray[i] < someArray[i + 1])
			{
				needSwap = true;
				temp = someArray[i];
				someArray[i] = someArray[i + 1];
				someArray[i + 1] = temp;
			}
		}
	}
}; // end of void ProcessArray::BubbleSortCArrayDescending(size_t *someArray, const size_t size)