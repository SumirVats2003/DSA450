// Move all negative numbers to beginning and positive to end with constant extra space

#include <bits/stdc++.h>
using namespace std;

void sortWithSign(vector<int> &arr)
{
	int start = 0, end = arr.size() - 1;

	while (start <= end)
	{
		if (arr[start] < 0 && arr[end] < 0)
			start++;
		else if (arr[start] > 0 && arr[end] < 0)
		{
			swap(arr[start], arr[end]);
			end--;
			start++;
		}
		else if (arr[start] > 0 && arr[end] > 0)
		{
			end--;
		}
		else
		{
			start++;
			end--;
		}
	}
}
