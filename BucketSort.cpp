/*Obtenido de https://www.programmingalgorithms.com/algorithm/bucket-sort?lang=C%2B%2B*/

#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include<stdio.h>

using namespace std;
using namespace std::chrono;

static void BucketSort(int* data, int count) {
	int minValue = data[0];
	int maxValue = data[0];

	for (int i = 1; i < count; i++)
	{
		if (data[i] > maxValue)
			maxValue = data[i];
		if (data[i] < minValue)
			minValue = data[i];
	}

	int bucketLength = maxValue - minValue + 1;
	vector<int>* bucket = new vector<int>[bucketLength];

	for (int i = 0; i < bucketLength; i++)
	{
		bucket[i] = vector<int>();
	}

	for (int i = 0; i < count; i++)
	{
		bucket[data[i] - minValue].push_back(data[i]);
	}

	int k = 0;
	for (int i = 0; i < bucketLength; i++)
	{
		int bucketSize = bucket[i].size();

		if (bucketSize > 0)
		{
			for (int j = 0; j < bucketSize; j++)
			{
				data[k] = bucket[i][j];
				k++;
			}
		}
	}
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
   BucketSort(array, n);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<milliseconds>(stop - start);
   cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;

}

