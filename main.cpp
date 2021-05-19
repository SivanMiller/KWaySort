
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n;
	cin >> k;

	string fileName;

	cin >> fileName;
	// Create new infile stream
	ifstream infile(fileName);

	// Error reading file
	if (!infile || !infile.good())
	{
		cout << "Invalid input" << endl;
		exit(1);
	}
	else
	{

	}
}