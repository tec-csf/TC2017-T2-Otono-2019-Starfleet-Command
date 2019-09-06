/*obtenido de https://www.tutorialspoint.com/cplusplus-program-to-implement-shell-sort*/

#include <bits/stdc++.h>
#include <chrono>
#include<stdio.h>
using namespace std;
using namespace std::chrono;
void swapping(int &a, int &b) {        //swap the content of a and b
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
void shellSort(int *arr, int n) {
   int gap, j, k;
   for(gap = n/2; gap > 0; gap = gap / 2) {        //initially gap = n/2, decreases by n/2
      for(j = gap; j<n; j++) {
         for(k = j-gap; k>=0; k -= gap) {
            if(arr[k+gap] >= arr[k])
               break;
            else
               swapping(arr[k+gap], arr[k]);
         }
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
   shellSort(array, n);
   auto stop = high_resolution_clock::now();
   		auto duration = duration_cast<milliseconds>(stop - start);
   		cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;

}


