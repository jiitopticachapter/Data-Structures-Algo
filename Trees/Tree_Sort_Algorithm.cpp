/* Tree sort is one of the sorting algorithm that is based on Binary Search 
Tree data structure. First of all it creates a binary search tree from the 
elements of the input array and then performs an in-order traversal on the
created binary search tree to get the elements in sorted order   */

/* Average TC : O(nlogn)        Space: O(n)      */

#include<bits/stdc++.h>   // This header file has all standard libraries
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};


struct Node *newNode(int val)   //Function to create a new BST Node
{
	struct Node *temp = new Node;
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}


void storeSorted(Node *root, int a[], int &j) // Stores inorder traversal of the BST in a[]
{
	if (root != NULL)
	{
		storeSorted(root->left, a, j);
		a[j++] = root->data;
		storeSorted(root->right, a, j);
	}
}


Node* insert(Node* node, int data)
{
	                           
	if (node == NULL)          //If the tree is empty then return a new Node
	return newNode(data);

	                                
	if (data < node->data)     // else recur down the tree 
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);


	return node;
}

                              
void treeSort(int a[], int n)  // This function sorts array 'a' using Tree Sort
{
	struct Node *root = NULL;

	root = insert(root, a[0]);   // Constructing the BST
	for (int i=1; i<n; i++)
		root = insert(root, a[i]);

	int i = 0;                    	// Storing inorder traversal of the BST
	                                // in a[]
	storeSorted(root, a, i);
}

// Execution of code starts from here
int main()
{
	                                   
	int brr[] = {10, 7, 3, 9, 20};         // Input array
	int n = sizeof(brr)/sizeof(brr[0]);  // size of array

	treeSort(brr, n);

	for (int i=0; i<n; i++)
	cout << brr[i] << " ";

	return 0;
}

