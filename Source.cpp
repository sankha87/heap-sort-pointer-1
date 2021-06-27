#include <stdio.h>
#include <conio.h>

void swap(int *m, int *n)
{
	int temp = *m;
	*m = *n;
	*n = temp;
}

void heapify(int *ptr, int n, int i)		// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
{
	int largest = i;						// Initialize largest as root
	int l = 2 * i + 1;						// left = 2*i + 1
	int r = 2 * i + 2;						 // right = 2*i + 2

	if (l < n && *(ptr+l) > *(ptr+largest))		// If left child is larger than root
		largest = l;

	if (r < n && *(ptr+r) > *(ptr+largest))		// If right child is larger than largest so far
		largest = r;

	if (largest != i)						// If largest is not root
	{
		swap((ptr+i), (ptr+largest));

		heapify(ptr, n, largest);			// Recursively heapify the affected sub-tree
	}
}

void heapSort(int *ptr, int n)				// main function to do heap sort
{
	for (int i = n / 2 - 1; i >= 0; i--)	// Build heap (rearrange array)
		heapify(ptr, n, i);

	for (int i = n - 1; i > 0; i--)			// Build heap (rearrange array)
	{
		swap((ptr+0), (ptr+i));				// Move current root to end

		heapify(ptr, i, 0);					// call max heapify on the reduced heap
	}
}

void printArray(int *p, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", *(p+i));
	printf("\n");
}

int main()
{
	int arr[] = { 8, 6, 21, 19, 17, 55, 5, 66, 77, 22, 11 };
//	int arr[] = {4, 5, 3, 10, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	int *p = arr;
	heapSort(p, n);
	printf("Sorted array: \n");
	printArray(p, n);

	_getch();
}
