#include "ArraySorter.h"
#include <random>

using namespace std;

ArraySorter::ArraySorter(void)
{
}

void ArraySorter::InsertionSort(int* arr, int n)
{
	InsertionSort(arr, n, 0, 1);
}

void ArraySorter::InsertionSort(int* arr, int n, int startIndex, int gap)
{
	int num, i, j;
	for (i = startIndex + gap; i < n; i++)
	{
		num = arr[i];
		for (j = i; j >= gap && arr[j - gap] > num; j = j - gap)
		{
			arr[j] = arr[j - gap];
		}
		arr[j] = num;
	}
}

// Checks to see if the array is in sorted order
bool ArraySorter::IsSorted(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		// If an item is less than the one before it, then we're not sorted
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}

	return true;
}

void ArraySorter::MergeSort(int* arr, int n)
{
	msort(arr, 0, n);
}

void ArraySorter::msort(int* arr, int begin, int end)
{
	if (end - begin <= 1)
	{
		return;
	}

	int mid = (begin + end) / 2;

	msort(arr, begin, mid);
	msort(arr, mid + 1, end);

	merge(arr, begin, mid + 1, end);
}

int ArraySorter::Size(int *arr)
{
	int size = 0;
	while (arr[size])
		size++;
	return size;
}

void ArraySorter::merge(int* arr, int leftBegin, int rightBegin, int rightEnd)
{
	int *sorted = arr, i, num = rightEnd - leftBegin + 1, temp = leftBegin, leftEnd = rightBegin - 1;

	while ((leftBegin <= leftEnd) && (rightBegin <= rightEnd))
	{
		if (arr[leftBegin] <= arr[rightBegin])
		{
			sorted[temp++] = arr[leftBegin++];
		}
		else
		{
			sorted[temp++] = arr[rightBegin++];
		}
	}

	while (leftBegin <= leftEnd)
	{
		sorted[temp++] = arr[leftBegin++];
	}

	while (rightBegin <= rightEnd)
	{
		sorted[temp++] = arr[rightBegin++];
	}

	for (i = 1; i <= num; i++, rightEnd--)
	{
		arr[rightEnd] = sorted[rightEnd];
	}
	arr = sorted;
}

void ArraySorter::QuickSort(int* arr, int n)
{
	qsort(arr, 0, n);
}

void ArraySorter::qsort(int* arr, int begin, int end)
{
	if (begin < end) // Invalid inputs
	{
		/////////////Partition///////////////
		int part = Partition(arr, begin, end);
		////////////////////////////////////
		qsort(arr, begin, part - 1);
		qsort(arr, part + 1, end);
	}
}

int ArraySorter::Partition(int *arr, int left, int right)
{
	int p_index = choosePivot(left, right), pivot = arr[p_index], ret_index = left;

	Swap(arr[p_index], arr[right]);
	for (int i = left; i <= right - 1; i++)
	{
		if (arr[i] <= pivot)
		{
			Swap(arr[i], arr[ret_index]);
			ret_index++;
		}
	}
	Swap(arr[ret_index], arr[right]);
	return ret_index;
}

int ArraySorter::choosePivot(int left, int right)
{
	if (left < right){
		return (right + left)/2;
	}
	return right;
}

// This is implemented for you, but you need to implement the InsertionSort 
// function that it calls.
void ArraySorter::ShellSort(int* arr, int n, int* gapVals, int gapValsCount)
{
	// Do an insertion sort pass for each of the gap values
	int i;
	for (i = 0; i < gapValsCount; i++)
	{
		for (int j = 0; j < gapVals[i]; j++)
		{
			InsertionSort(arr, n, j, gapVals[i]);
		}
	}

	// We always need to finish with a pass using gap=1
	if (1 != gapVals[i - 1])
	{
		InsertionSort(arr, n);
	}
}
