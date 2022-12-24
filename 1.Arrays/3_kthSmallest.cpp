/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	// arr : given array
	// l : starting index of the array i.e 0
	// r : ending index of the array i.e size-1
	// k : find kth smallest element and return using this function
	int kthSmallest(int arr[], int l, int r, int k)
	{
		int min = arr[l];
		int n = r + 1;
		if (k == 1)
		{
			for (int i = l; i < r; i++)
			{
				if (arr[i] < min)
					min = arr[i];
			}
			return min;
		}

		int a[k];
		int low = 0, high = n / k;
		a[0] = kthSmallest(arr, low, high, 1);
		for (int i = 1; i < k; i++)
		{
			a[i] = kthSmallest(arr, low, high, 1);
			low = i * (n / k) + 1;
			high = (i + 1) * (n / k);
		}

		int max = a[0];
		for (int i = 0; i < k; i++)
		{
			if (a[i] > max)
				max = arr[i];
		}
		return max;
	}
};

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// finding the pivot element and partition the array along that
int randomPartition(int arr[], int l, int r)
{
	int n = r - l + 1;
	int pivot = rand() % n;
	swap(&arr[l + pivot], &arr[r]);
	return partition(arr, l, r);
}

int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of elements in array
	if (k > 0 && k <= r - l + 1)
	{
		// find a position for random partition
		int pos = randomPartition(arr, l, r);

		// if this pos gives the kth smallest element, then return
		if (pos - l == k - 1)
			return arr[pos];

		// else recurse for the left and right half accordingly
		if (pos - l > k - 1)
			return kthSmallest(arr, l, pos - 1, k);
		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}

	return INT_MAX;
}

// partitioning the array along the pivot
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}
