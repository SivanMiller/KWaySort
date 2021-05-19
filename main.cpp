
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
	    int i = 0;
	    while (getline(infile, currStr) && infile.good())
	    {
		   if (i == n)
		   {
			  cout << "wrong input" << endl;
			  return -1;
		   }

		   for (int i = 0; i < currStr.length(); i++) {
			  if (currStr.at(i) < '0' || currStr.at(i) > '9')
			  {
				 cout << "wrong input" << endl;
				 return -1;
			  }
		   }
		   int len = stoi(currStr);
		   arr[i] = len;
		   i++;
	    }
	    infile.close();
	    if (i != n)
	    {
		   cout << "wrong input" << endl;
		   return -1;
	    }
	    
	    int *res =KWaySort::KSortAlgo(arr, n, k);
	
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
		   outFile << res[i] << endl;
	    }

	    outFile.close();

}