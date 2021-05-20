#pragma once
#include "Heap.h"

namespace kway
{
	class KWaySort
	{
	public:
		//Sorting and merging K sub-arrays
		static void KSortAlgo(int* A, int n, int k);

		//QuickSort
		static void QuickSort(int* A, int left, int right);
		//Partition for QuickSort
		static int Parition(int* A, int left, int right);
		//Swap for Partition
		static void Swap(int* a, int* b);

		//Merging K sub-arrays
		static void Merge(int* A, int n, int k);
	};
}

