
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

	while (!infile.eof() && infile.good())
	{
		getline(infile, currStr);
		if (counter == n)
		{
			cout << "wrong input" << endl;
			return -1;
		}
		
		if ((currStr.at(0) < '0' || currStr.at(0) > '9') && currStr.at(0) != '-')
		{
			cout << "wrong input" << endl;
			return -1;
		}
		else {
			for (int i = 1; i < currStr.length(); i++) {
				if (currStr.at(i) < '0' || currStr.at(i) > '9')
				{
					cout << "wrong input" << endl;
						return -1;
				}
			}

			int len = stoi(currStr);
			arr[counter] = len;
			counter++;
		}
	}
	infile.close();
	if (counter != n)
	{
		cout << "wrong input" << endl;
		return -1;
	}

	KWaySort::KSortAlgo(arr, n, k);

	ofstream outFile;
	string outFileName;
	cin >> outFileName;
	outFile.open(outFileName);
	if (!outFile.good())
	{
		cout << "wrong input" << endl;
		return -1;
	}

	for (int i = 0; i < n; i++)
	{
		outFile << arr[i] << endl;
	}

	outFile.close();

}