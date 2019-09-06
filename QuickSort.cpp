/* obtenido de https://www.geeksforgeeks.org/cpp-program-for-quicksort/ */

#include <bits/stdc++.h>
#include <chrono>
#include<stdio.h>

using namespace std;
using namespace std::chrono;
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

// Driver program to test above functions
int main()
{
	int n=100000;
	int array[n];
	int nrand =n*10;

		srand((unsigned)time(0));

			    for(int i=0; i<n; i++){
			        array[i] = (rand()%nrand)+1;
			    	}

    int q = sizeof(array)/sizeof(array[0]);
    auto start = high_resolution_clock::now();
    quickSort(array, 0, q-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;

    return 0;
}




