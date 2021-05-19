#pragma once
#include "Heap.h"

namespace kway
{
	class KWaySort
	{
	public:
		int* KSortAlgo(int* A, int n, int k);
		void QuickSort(int* A, int left, int right);
		int Parition(int* A, int left, int right);
		void Swap(int* a, int* b);
		int* Merge(int* A, int n, int k);
	};
}

