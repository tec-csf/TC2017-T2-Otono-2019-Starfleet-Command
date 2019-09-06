/*obtenido de https://www.sanfoundry.com/cpp-program-implement-heap-sort/*/

#include <bits/stdc++.h>
#include <chrono>
#include<stdio.h>
using namespace std;
using namespace std::chrono;

// A function to heapify the array.
void MaxHeapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;

 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
		// Break if parent value is already greater than child value.
		if (temp > a[j])
			break;
		// Switching value with the parent node if temp < a[j].
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		// Storing maximum value at the end.
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		// Building max heap of remaining element.
		MaxHeapify(a, 1, i - 1);
	}
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
}
int main()
{
	int n=1000;
		int array[n+1];
		int nrand =n*10;

		srand((unsigned)time(0));

		for(int i=0; i<n; i++){
		array[i] = (rand()%nrand)+1;
		}

	// Building max heap.
	Build_MaxHeap(array, n-1);
	auto start = high_resolution_clock::now();
	HeapSort(array, n-1);
	auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;



	return 0;
}




