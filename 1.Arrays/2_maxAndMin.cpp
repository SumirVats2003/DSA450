// Maximum and minimum of an array using minimum number of comparisons

#include <iostream>
using namespace std;

// Linear Search method
int minInArray(int arr[], int n)
{
	int arrMin = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arrMin)
			arrMin = arr[i];
	}
	return arrMin;
}

int maxInArray(int arr[], int n)
{
	int arrMax = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arrMax)
			arrMax = arr[i];
	}
	return arrMax;
}

// Tournament Method
// Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.

struct Pair
{
	int min;
	int max;
};

Pair minAndMax(int arr[], int low, int high)
{
	Pair ans, maxMinLeft, maxMinRight;
	maxMinLeft.min = arr[low];
	maxMinLeft.max = arr[low];
	maxMinRight.min = arr[low];
	maxMinRight.max = arr[low];
	int mid;

	if (low == high)
	{
		ans.max = arr[low];
		ans.min = arr[low];
		return ans;
	}

	else if (low + 1 == high)
	{
		if (arr[low] < arr[high])
		{
			ans.min = arr[low];
			ans.max = arr[high];
		}
		else
		{
			ans.min = arr[high];
			ans.max = arr[low];
		}
		return ans;
	}

	else
	{
		mid = (low + high) / 2;
		maxMinLeft = minAndMax(arr, low, mid);
		maxMinLeft = minAndMax(arr, mid + 1, high);

		if (maxMinLeft.min < maxMinRight.min)
			ans.min = maxMinLeft.min;
		else
			ans.min = maxMinRight.min;

		if (maxMinLeft.max > maxMinRight.max)
			ans.max = maxMinLeft.max;
		else
			ans.max = maxMinRight.max;
	}

	return ans;
}
