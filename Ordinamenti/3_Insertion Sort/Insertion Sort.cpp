#include <iostream>
using namespace std;


void insertionSort(int arr[], int n)
{
	int i, j;
	for(i = 1; i < n; i++)
	{
		j = i;
		while(j > 0 && arr[j - 1] > arr[j])
		{
			swap(arr[j], arr[j -1 ]);
			j--;
		}
	}
}
