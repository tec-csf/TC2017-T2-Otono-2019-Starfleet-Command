// C++ program to implement Tree Sort
#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;

struct Node
{
	int key;
	struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Stores inoder traversal of the BST
// in arr[]
void storeSorted(Node *root, int arr[], int &i)
{
	if (root != NULL)
	{
		storeSorted(root->left, arr, i);
		arr[i++] = root->key;
		storeSorted(root->right, arr, i);
	}
}

/* A utility function to insert a new
Node with given key in BST */
Node* insert(Node* node, int key)
{
	/* If the tree is empty, return a new Node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) Node pointer */
	return node;
}

// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arreglo[], int tamanio)
{
	struct Node *root = NULL;

	// Construct the BST
	root = insert(root, arreglo[0]);
	for (int i=1; i<tamanio; i++)
		insert(root, arreglo[i]);

	// Store inoder traversal of the BST
	// in arr[]
	int i = 0;
	storeSorted(root, arreglo, i);
}

// Driver Program to test above functions
int main()
{

  int sizeA;

	cout << "Inserte el tamaño del arreglo" << endl;

	cin >> sizeA;

	cout << "\n";

  int arreglo[sizeA];

  srand((unsigned) time(0));

  cout << "El tamaño por default del arreglo es de "<< sizeA << "\n";

  for (int cont = 0; cont < sizeA; cont++) {

    arreglo[cont] = (rand()%sizeA)+1;

  }

  //int x = (rand() % 100) + 1;

  int tamanio = sizeof(arreglo)/sizeof(arreglo[0]);

    //int arr[] = {5, 4, 7, 2, 11};
	//int n = sizeof(arr)/sizeof(arr[0]);

	//treeSort(arr, n);

	auto start = high_resolution_clock::now();

	treeSort(arreglo, tamanio);

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(stop - start);

	cout << "\n\nLos valores del arreglo ordenados son los siguientes:" << endl;

	for (int i = 0; i < tamanio; i++)
	{
		cout << arreglo[i] << " ";
	}

	cout << "\n\n";

	cout << "Le tomo " << duration.count() << " milisegundos\n";

	return 0;
}
