/*obtenido de https://www.sanfoundry.com/cpp-program-implement-radix-sort/ */

#include<iostream>
#include<list>
#include<cmath>
#include <bits/stdc++.h>
#include <chrono>
#include<stdio.h>

using namespace std;
using namespace std::chrono;

// Get maximum value from array.
int getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

// Count sort of arr[].
void countSort(int arr[], int n, int exp)
{
	// Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place.
	int output[n], i, count[10] = {0};

	// Count the number of times each digit occurred at (exp)th place in every input.
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Calculating their cumulative count.
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];

	// Inserting values according to the digit '(arr[i] / exp) % 10' fetched into count[(arr[i] / exp) % 10].
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Assigning the result to the arr pointer of main().
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// Sort arr[] of size n using Radix Sort.
void radixsort(int arr[], int n)
{
	int exp, m;
	m = getMax(arr, n);

	// Calling countSort() for digit at (exp)th place in every input.
	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);

}

int main() {
	int n=1000000;
	int array[n];
	int nrand =n*10;

			srand((unsigned)time(0));

					 for(int i=0; i<n; i++){
					        array[i] = (rand()%nrand)+1;
					    	}

					    auto start = high_resolution_clock::now();
					       radixsort(array,n);
					       auto stop = high_resolution_clock::now();
					       auto duration = duration_cast<milliseconds>(stop - start);
					       cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;
}
