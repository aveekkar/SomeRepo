// SomeRepo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int getPartition(int *a, int start, int end);
int binarySearch(int *a, int key, int start, int end);

int main(int argc, char** argv)
{
	int key = 4;
	int a[] = {11,12,13,1,2,3,4,5,6,7,8,9};
	int end = 10;
	int index = -1;
	int pivot = getPartition(a, 0, end);
	cout<<"partition at: "<<pivot<<endl;
	if(pivot == -1)
	{
		pivot = end;
	}

	if(key >= a[0] && key <= a[pivot])
	{
		index = binarySearch(a, key, 0, pivot);
	}
	else
	{
		index = binarySearch(a, key, pivot, end);
	}

	cout<<"found key "<<key<<" at index "<<index<<endl;

	getchar();
	return 0;
}

int getPartition(int *a, int start, int end)
{
	if(end <= start)
	{
		return -1;
	}
	
	int mid = (end + start) / 2;
	
	if(a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
	{
		return mid;
	}

	else
	{
		if(a[mid] < a[start])
		{
			getPartition(a, start, mid);
		}
		else
		{
			getPartition(a, mid, end);
		}
	}
 }

int binarySearch(int *a, int key, int start, int end)
{
	if(end <= start)
	{
		return -1;
	}

	int mid = (start + end) / 2;

	if(a[mid] == key)
	{
		return mid;
	}

	else
	{
		if(key > a[mid])
		{
			return binarySearch(a, key, mid +1, end);
		}
		else
		{
			return binarySearch(a, key, start, mid - 1);
		}
	}
}

