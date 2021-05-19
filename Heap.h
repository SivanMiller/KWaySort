#pragma once

using namespace std;

namespace kway
{
	class Heap
	{
	public:
		struct Pair
		{
			int key;
			int data;
		};

		// Ctors & Dtors
	public:
		Heap(int max);
		Heap(Pair* A[], int n);
		~Heap();

		// Class methods
	public:
		static int getLeft(int node);
		static int getRight(int node);
		static int getParent(int node);
		void FixHeap(int node);
		Pair* GetMin() const;
		Pair* DeleteMin();
		void Insert(Pair* item);
		int getSize() const { return _heapSize; };

		// Class members
	private:
		Pair** _data;
		int _maxSize;
		int _heapSize;
		bool _allocated;

	private:
		void Swap(Pair** nodeA, Pair** nodeB);
	};
}
