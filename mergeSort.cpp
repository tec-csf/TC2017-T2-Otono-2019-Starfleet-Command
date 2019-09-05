/* Obtenido de */


#ifndef MERGESORT_CPP_
#define MERGESORT_CPP_
#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
int Merge(int A[],int p, int q,int r)
{

    int n1,n2,i,j,k;

    n1=q-p+1;
    n2=r-q;
    int L[n1],R[n2];

    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];
    }

    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }
    i=0,j=0;

    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
        }
    }

    while(i<n1)
    {
        A[k++]=L[i++];
    }

    while(j<n2)
    {
        A[k++]=R[j++];
    }
}

int MergeSort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}



int main()
{
	int n=1000000;
	int* array= new int[n];
	int nrand =n*10;

	srand((unsigned)time(0));

		    for(int i=0; i<n; i++){
		        array[i] = (rand()%nrand)+1;
		    	}

	auto start = high_resolution_clock::now();
	MergeSort(array,0,n-1);
	auto stop = high_resolution_clock::now();
	    auto duration = duration_cast<milliseconds>(stop - start);
	    cout << "La duracion es: "<< duration.count() << " ms, con tamaño: " << n << endl;
	    delete[] array;
	    return 0;
}




#endif /* MERGESORT_CPP_ */
