/* Obtenido de https://rosettacode.org/wiki/Sorting_algorithms/Cocktail_sort*/
#include <bits/stdc++.h>
#include <chrono>
#include<stdio.h>

using namespace std;
using namespace::chrono;

//To swap elements in the array
void swap(int *x, int *y)
{
    int temporal = *x;
    *x = *y;
    *y = temporal;
}//Close swap

void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int begin = 0;
    int end = n-1;

    while (swapped)
    {
        swapped = false;

        for (int i = begin; i < end; ++i)
        {
            if (a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }

        swapped = false;

        --end;

        for (int i = end-1; i >= begin; --i)
        {
            if (a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }

        ++begin;
    }
}//Close CocktailSort

int main()
{
int n=100;
	int array[n];
	int nrand =n*10;

	srand((unsigned)time(0));

	for(int i=0; i<n; i++){
	     array[i] = (rand()%nrand)+1;
		}

	auto start = high_resolution_clock::now();
	CocktailSort(array,n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;

}

