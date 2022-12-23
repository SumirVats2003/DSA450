// Write a program to reverse an array or string

#include <bits/stdc++.h>
using namespace std;

int *reverse(int arr[], int n)
{
	for (int i = 0; i < n / 2; i++)
		swap(arr[i], arr[n - 1 - i]);
	return arr;
}
