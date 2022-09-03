#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;

/* Genera numeri */

void generaNumeri(int v[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        v[i] = rand();
    }
}

/* Stampa */

void stampa(int v[], int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl << endl;
}

/* Swap */

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

/* BubbleSort */

void bubbleSort(int arr[], int n)
{
	bool swapped;

	for(int i = 0; i < n-1; i++)
    {
		swapped = false;
		for(int j = 0; j < n-i-1; j++)
        {
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}

		if(swapped == false)
			break;
	}
}

/* SelectionSort */

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

/* InsertionSort */

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

/* MergeSort */

void Merge(int a[], int from, int to, int mid)
{
	int i = from;
	int j = mid + 1;
	int k = 0;

	int temp[to-from+1];

	while(i <= mid && j <= to)
    {
		if(a[i] < a[j]){
			temp[k] = a[i];
			k++;
			i++;
		}
        else
        {
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while(i <= mid)
    {
		temp[k] = a[i];
		k++;
		i++;
	}

	while(j <= to)
    {
		temp[k] = a[i];
		k++;
		j++;
	}

	for(i = from; i <= to; i++)
    {
		a[i] = temp[i-from];
	}
}

void MergeSort(int a[], int from, int to)
{
	int mid;

	if(from < to)
	{
		mid = (from + to)/2;

		MergeSort(a, from, mid);
		MergeSort(a, mid + 1, to);

		Merge(a, from, to, mid);
	}
}

/* QuickSort */

void QuickSort(int arr[], int left, int right)
{
	int l = left;
	int r = right - 1;
	int size = right - left;

	if(size > 1){
		int pivot = arr[rand() % size + l];
		while(l < r){
			while(arr[r] > pivot && r > l)
            {
				r--;
			}

			while(arr[l] < pivot && l <= r)
            {
				l++;
			}

			if(l < r)
			{
				swap(arr[l], arr[r]);
				l++;
			}

		}

		QuickSort(arr, left, l);
		QuickSort(arr, r, right);
	}
}

/* Rispristino Vettore */

void copiaVettore(int v1[], int v2[], int n)
{
    for (int i = 0; i < n; i++)
        v2[i] = v1[i];
}

int main ()
{
	clock_t start, end;
    int n;
    cout << "Insersci la deimensione del vettore: ";
    cin >> n;

    int vett[n], v2[n];
    generaNumeri(vett, n);
    //stampa(vett, n);

    copiaVettore(vett, v2, n);
    start = clock();
    bubbleSort(v2, n);
    end = clock();
    cout << "Bubble sort: " << (end - start)/CLOCKS_PER_SEC << "s"<< endl;
    //stampa(v2, n);

    copiaVettore(vett, v2, n);
	start = clock();
    selectionSort(v2, n);
	end = clock();
    cout << "Selection sort: " << (end - start)/CLOCKS_PER_SEC << "s"<< endl;
    //stampa(v2, n);

    copiaVettore(vett, v2, n);
	start = clock();
    insertionSort(v2, n);
  	end = clock();
    cout << "Insert sort: " << (end - start)/CLOCKS_PER_SEC << "s"<< endl;
    //stampa(v2, n);

    copiaVettore(vett, v2, n);
	start = clock();
    MergeSort(v2, 0, n - 1);
    end = clock();
    cout << "Merge sort: " << end - start << "ms"<< endl;
    //stampa(v2, n);

    copiaVettore(vett, v2, n);
	start = clock();
    QuickSort(v2, 0, n);
    end = clock();
    cout << "Quick sort: " << end - start<< "ms"<< endl;
    //stampa(v2, n);

    stampa(v2, n);
}