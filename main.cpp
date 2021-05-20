#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "KWaySort.h"

using namespace std;
using namespace kway;

int main()
{
	int n, k;
	cin >> n;
	cin >> k;

	//Checking n, k are natural numbers
	if (n <= 0 || k <= 0)
	{
		cout << "wrong input" << endl;
		return -1;
	}

	string fileName;
	int* arr = new int[n];
	cin >> fileName;
	// Create new infile stream
	ifstream infile;
	infile.open(fileName);
	// Error reading file
	if (!infile || !infile.good())
	{
		cout << "wrong input" << endl;
		exit(1);
	}

	string currStr;
	int counter = 0;

	//Reading numbers from file
	while (!infile.eof() && infile.good())
	{
		getline(infile, currStr);
		//If there are more than n numbers in the file --> wrong input
		if (counter == n)
		{
			cout << "wrong input" << endl;
			return -1;
		}
		
		//Checking first char in number is a digit or '-' (negative number)
		if ((currStr.at(0) < '0' || currStr.at(0) > '9') && currStr.at(0) != '-')
		{
			cout << "wrong input" << endl;
			return -1;
		}
		else {
			// Reading all digits of number, and checking that they are indeed digits
			for (int i = 1; i < currStr.length(); i++) {
				if (currStr.at(i) < '0' || currStr.at(i) > '9')
				{
					cout << "wrong input" << endl;
						return -1;
				}
			}

			// Convert the string to number
			int len = stoi(currStr);

			// adding number to array
			arr[counter] = len;
			counter++;
		}
	}

	infile.close();

	//Checking if there are enough numbers in file
	if (counter != n)
	{
		cout << "wrong input" << endl;
		return -1;
	}

	// Running K Way Sort
	KWaySort::KSortAlgo(arr, n, k);

	//Creating output File
	ofstream outFile;
	string outFileName;
	cin >> outFileName;
	
	outFile.open(outFileName);

	//In case of error in out file
	if (!outFile.good())
	{
		cout << "wrong input" << endl;
		return -1;
	}

	//Writing sorted array yo out file
	for (int i = 0; i < n; i++)
	{
		outFile << arr[i] << endl;
	}

	outFile.close();

	delete[] arr;
}