#include "Heap.h"

namespace kway
{
	Heap::Heap(int max)
	{
		// Allocate data
		_data = new Pair*[max];

		// Set max heap size
		_maxSize = max;

		// Set actual heap size
		_heapSize = 0;

		// Set allocated flag to be true (memory was allocated)
		_allocated = true;
	}

	Heap::Heap(Pair* A[], int n)
	{
		_heapSize = _maxSize = n;

		// Assign array A to data pointer
		_data = A;

		// Set allocated flag to be false (memory wasnt allocated)
		_allocated = false;

		// Fix heap
		for (int i = n / 2; i >= 0; i--)
		{
			FixHeap(i);
		}
	}

	Heap::~Heap()
	{
		// Free memory if allocated
		if (_allocated)
		{
			delete[] _data;
			_data = nullptr;
		}
	}

	int Heap::getLeft(int node)
	{
		return ((2 * node) + 1);
	}

	int Heap::getRight(int node)
	{
		return ((2 * node) + 2);
	}

	int Heap::getParent(int node)
	{
		return ((node - 1) / 2);
	}

	void Heap::Swap(Pair** nodeA, Pair** nodeB)
	{
		Pair* temp = *nodeA;
		*nodeA = *nodeB;
		*nodeB = temp;
	}

	void Heap::FixHeap(int node)
	{
		int min;
		int left = getLeft(node);
		int right = getRight(node);

		// Find minimum among node, left and right
		if (left < _heapSize && _data[left]->data < _data[node]->data)
		{
			min = left;
		}
		else
		{
			min = node;
		}
		if (right < _heapSize && _data[right]->data < _data[min]->data)
		{
			min = right;
		}

		// Continue fixing the heap
		if (min != node)
		{
			// Swap between data[node], data[max]
			Swap(&_data[node], &_data[min]);

			// Fix heap
			FixHeap(min);
		}
	}
	
	Heap::Pair* Heap::GetMin() const
	{
		if (_allocated)
		{
			return _data[0];
		}
	}

	Heap::Pair* Heap::DeleteMin()
	{
		if (_heapSize >= 1)
		{
			// Set current minimum
			Pair* min = _data[0];

			// Set new heap size
			_heapSize--;

			// Set root as most right leaf
			_data[0] = _data[_heapSize];

			// Fix heap
			FixHeap(0);

			return min;
		}
	}

	void Heap::Insert(Pair* item)
	{
		if (_heapSize == _maxSize)
		{
			return;
		}

		int i = _heapSize;
		_heapSize++;

		// Find right place to insert new item
		while ((i > 0) && (_data[getParent(i)]->data > item->data))
		{
			_data[i] = _data[getParent(i)];
			i = getParent(i);
		}

		// Insert new item
		_data[i] = item;
	}
}