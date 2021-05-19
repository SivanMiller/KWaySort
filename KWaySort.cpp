#include "KWaySort.h"

namespace kway
{
    void kway::KWaySort::KSortAlgo(int* A, int n, int k)
    {
        if (n < k)
        {
            QuickSort(A, 0, n - 1);
        }
        else 
        {
            int size;
            int mod_k = (n % k);
            int mod_size;
            if (mod_k == 0)
            {
                size = (n / k);
                mod_size = (n / k);
            }
            else 
            {
                size = (n / k)  + 1;
                mod_size = n % size;
            }
            
            for (int i = 0; i < k; i++)
            {
                if (i != k - 1)
                {
                    KSortAlgo(A + (i * size), size, k);
                }
                else {
                    KSortAlgo(A + (i * size), mod_size, k);
                }
            }
            Merge(A, n, k);
        }
    }

    void KWaySort::QuickSort(int* A, int left, int right)
    {
        int pivot;

        if (left < right)
        {
            pivot = Parition(A, left, right);
            QuickSort(A, left, pivot - 1);
            QuickSort(A, pivot + 1, right);
        }
    }

    int KWaySort::Parition(int* A, int left, int right)
    {
        int pivot = A[left];

        // Going over all the elements in the array
        while (left != right)
        {
            // If we found a smaller element -> swaping places
            if (A[left] > A[right])
            {
                Swap(&A[left], &A[right]);
            }

            //Decreaseing/Increasing the "pointer" to the opposite side of pivot after swap
            if (pivot == A[left])
                right--;
            else // Pivot == arr[right]
                left++;
        }
        return left;
    }

    void KWaySort::Swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void KWaySort::Merge(int* A, int n, int k)
    {
        int size;
        int mod_k = (n % k);
        int mod_size;
        if (mod_k == 0)
        {
            size = (n / k);
            mod_size = (n / k);
        }
        else
        {
            size = (n / k) + 1;
            mod_size = n % size;
            if (mod_size == 0)
            {
                k--;
            }
        }

        int* output = new int[n];
        Heap::Pair** temp = new Heap::Pair*[k];

        for (int j = 0; j < k; j++)
        {
            temp[j] = new Heap::Pair();
            temp[j]->data = A[j * size];
            temp[j]->key = j * size;
        }

        Heap heap(temp, k);
        Heap::Pair* pair;
        for (int i = 0; i < n; i++)
        {
            pair = heap.DeleteMin();
            output[i] = pair->data;
            Heap::Pair* newPair = new Heap::Pair();
            if (pair->key + 1 < n && (pair->key + 1) % size != 0)
            {
                newPair->data = A[pair->key + 1];
                newPair->key = pair->key + 1;
                heap.Insert(newPair);
            }
        }

        for (int i = 0; i < n; i++)
        {
            A[i] = output[i];
        }
    }
}