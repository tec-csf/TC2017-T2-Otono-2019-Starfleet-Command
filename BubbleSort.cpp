/* */
#include <bits/stdc++.h>
#include <chrono>
#include<stdio.h>

using namespace std;
using namespace::chrono;

void swap(int *x, int *y)
{
    int temporal = *x;
    *x = *y;
    *y = temporal;
}//Close swap


void BubbleSort(int arr[], int size){
    for (int i = 0; i < size-1; i++){
     for (int j = 0; j < size-i-1; j++){
        if (arr[j] > arr[j+1]){
            swap(&arr[j], &arr[j+1]);
        }//if1
     }//for2
    }//for1
}


int main()
{
int n=1000000;
	int array[n];
	int nrand =n*10;

	srand((unsigned)time(0));

	for(int i=0; i<n; i++){
	     array[i] = (rand()%nrand)+1;
		}

	auto start = high_resolution_clock::now();
	BubbleSort(array,n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;

}

