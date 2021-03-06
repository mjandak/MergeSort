// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MergeSort.h"
#include "Tests.h"

class MyClass
{
public:
	MyClass()
	{
	}

	~MyClass()
	{
	}

private:

};

int main()
{
	Tests tests;
	tests.Test1();
	tests.Test2();
	tests.Test3();
	tests.Test4();
	tests.Test5();

    return 0;
}

MergeSort::MergeSort()
{
}

MergeSort::~MergeSort()
{
}

int * MergeSort::Sort(int arr[], int size)
{
	if (size == 1) return new int[1]{ arr[0] };
	int sizeMod = size % 2;
	int aSize = (size - sizeMod) / 2;
	int bSize = aSize + sizeMod;
	int * a = new int[aSize];
	int * b = new int[bSize];

	for (int i = 0; i < aSize; i++)
	{
		a[i] = arr[i];
		b[i] = arr[i + aSize];
	}
	b[bSize - 1] = arr[size - 1];

	int * aSorted = Sort(a, aSize);
	int * bSorted = Sort(b, bSize);

	int * ret = MergeSorted(aSorted, aSize, bSorted, bSize);

	delete[] a;
	delete[] b;
	delete[] aSorted;
	delete[] bSorted;

	return ret;
}

int * MergeSort::MergeSorted(int aSorted[], int aSize, int bSorted[], int bSize)
{
	int retSize = aSize + bSize;
	int * ret = new int[retSize];
	int retIdx = 0;

	int aIdx = 0;
	int bIdx = 0;
	bool stop = false;
	int aItem;
	int bItem;

	while (true)
	{
		if (retIdx >= retSize) break;
		if (aIdx >= aSize || bIdx >= bSize) break;
		aItem = aSorted[aIdx];
		bItem = bSorted[bIdx];
		if (aItem == bItem)
		{
			ret[retIdx] = aItem;
			retIdx++;
			ret[retIdx] = bItem;
			retIdx++;
			aIdx++;
			bIdx++;
		}
		else if (aItem < bItem)
		{
			ret[retIdx] = aItem;
			retIdx++;
			aIdx++;
		}
		else
		{
			ret[retIdx] = bItem;
			retIdx++;
			bIdx++;
		}
	}

	if (aIdx < aSize)
	{
		for (int i = aIdx; i < aSize; i++)
		{
			ret[retIdx] = aSorted[i];
			retIdx++;
		}
	}

	if (bIdx < bSize)
	{
		for (int i = bIdx; i < bSize; i++)
		{
			ret[retIdx] = bSorted[i];
			retIdx++;
		}
	}

	return ret;
}
