#include <iostream>
using namespace std;


void selectionSort(int arr[], int n)
{
	int min;
	for(int k = 0; k < n-1; k++)
	{
		min = k;
		for(int j = k+1; j < n; j++)
		{
			if(arr[j] < arr[min])
				min = j;
		}
		swap(arr[min], arr[k]);
	}
}

