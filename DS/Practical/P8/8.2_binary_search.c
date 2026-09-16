/*
 * Practical 8.2: Binary Search
 * Searches for a key element in a sorted array by repeatedly dividing the search interval in half.
 */

#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int n, int key)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int main()
{
	int n, key;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));
	printf("Enter the sorted elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Enter the element to search: ");
	scanf("%d", &key);

	int result = binary_search(arr, n, key);
	if (result != -1)
		printf("Element %d found at index %d.\n", key, result);
	else
		printf("Element %d not found in the array.\n", key);

	free(arr);
	return 0;
}

/*
 * Output:
 * Enter the number of elements: 7
 * Enter the sorted elements: 5 12 18 25 33 40 56
 * Enter the element to search: 25
 * Element 25 found at index 3.
 *
 * Enter the number of elements: 7
 * Enter the sorted elements: 5 12 18 25 33 40 56
 * Enter the element to search: 15
 * Element 15 not found in the array.
 */
