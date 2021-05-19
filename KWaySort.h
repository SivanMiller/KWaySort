#pragma once
#include "Heap.h"

namespace kway
{
	class KWaySort
	{
	public:
		static int* KSortAlgo(int* A, int n, int k);
		static void QuickSort(int* A, int left, int right);
		static int Parition(int* A, int left, int right);
		static void Swap(int* a, int* b);
		static int* Merge(int* A, int n, int k);
	};
}

