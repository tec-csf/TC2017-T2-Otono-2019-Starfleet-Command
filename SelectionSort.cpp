/* obtenido de https://www.tutorialspoint.com/cplusplus-program-to-implement-selection-sort */

#include <bits/stdc++.h>
#include <chrono>
#include<stdio.h>

using namespace std;
using namespace::chrono;
void swapping(int &a, int &b) {         //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void selectionSort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;   //get index of minimum data
      for(j = i+1; j<size; j++)
      {
         if(array[j] < array[imin])
            imin = j;
         //placing in correct position
      	 	 swap(array[i], array[imin]); // @suppress("Invalid arguments")
      }
   }
}
int main() {
	int n=100000;
	int array[n];
	int nrand =n*10;

		srand((unsigned)time(0));

				 for(int i=0; i<n; i++){
				        array[i] = (rand()%nrand)+1;
				    	}

				    auto start = high_resolution_clock::now();
				       selectionSort(array,n);
				       auto stop = high_resolution_clock::now();
				       auto duration = duration_cast<milliseconds>(stop - start);
				       cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;


}
