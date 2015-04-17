void test()
{
	size_t n{ 0 };

	cout << setw(15) << left << "size_t" << ": " << numeric_limits<size_t>::max() << endl;
	cout << setw(15) << left << "streamsize" << ": " << numeric_limits<streamsize>::max() << endl;
	cout << setw(15) << left << "bool" << ": " << numeric_limits<bool>::max() << endl;
	cout << setw(15) << left << "char" << ": " << numeric_limits<char>::max() << endl;
	cout << setw(15) << left << "signed char" << ": " << numeric_limits<signed char>::max() << endl;
	cout << setw(15) << left << "unsiged char" << ": " << numeric_limits<unsigned char>::max() << endl;
	cout << setw(15) << left << "wchar_t" << ": " << numeric_limits<wchar_t>::max() << endl;
	cout << setw(15) << left << "char16_t" << ": " << numeric_limits<char16_t>::max() << endl;   // C++11 feature
	cout << setw(15) << left << "char32_t" << ": " << numeric_limits<char32_t>::max() << endl;   // C++11 feature
	cout << setw(15) << left << "short" << ": " << numeric_limits<short>::max() << endl;
	cout << setw(15) << left << "unsigned_short" << ": " << numeric_limits<unsigned short>::max() << endl;
	cout << setw(15) << left << "int" << ": " << numeric_limits<int>::max() << endl;
	cout << setw(15) << left << "unsigned_int" << ": " << numeric_limits<unsigned int>::max() << endl;
	cout << setw(15) << left << "long" << ": " << numeric_limits<long>::max() << endl;
	cout << setw(15) << left << "unsiged long" << ": " << numeric_limits<unsigned long>::max() << endl;
	cout << setw(15) << left << "long long" << ": " << numeric_limits<long long>::max() << endl;
	cout << setw(15) << left << "unsigned long long " << ": " << numeric_limits<unsigned long long>::max() << endl;
	cout << setw(15) << left << "float" << ": " << numeric_limits<float>::max() << endl;
	cout << setw(15) << left << "double" << ": " << numeric_limits<double>::max() << endl;
	cout << setw(15) << left << "long double" << ": " << numeric_limits<long double>::max() << endl;
	cout << setw(15) << left << "INT_MAX" << ": " << INT_MAX << endl;

	cout << ((numeric_limits<unsigned long long>::max() - numeric_limits<streamsize>::max()) > 0.1 ? "unsigned long long" : "streamsize") << endl;

	while (true)
	{
		cout << "Enter a number: ";
		cin >> n;
		cout << n << endl;

		cin.clear();
		cin.ignore(numeric_limits<long long>::max(), '\n');



		/*cout << showpoint << 0.8 * 2 << " : " << 0.16 << endl;
		cout << ((0.8 * 2 < 0.16) < 0.0001 ? true : false) << endl;
		*/

		system("pause");

	}

}