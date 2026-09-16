/*
 * Practical 8.1: Linear Search
 * Searches for a key element in an array by checking each element sequentially.
 */

#include <stdio.h>
#include <stdlib.h>

int linear_search(int arr[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int main()
{
	int n, key;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));
	printf("Enter the elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Enter the element to search: ");
	scanf("%d", &key);

	int result = linear_search(arr, n, key);
	if (result != -1)
		printf("Element %d found at index %d.\n", key, result);
	else
		printf("Element %d not found in the array.\n", key);

	free(arr);
	return 0;
}

/*
 * Output:
 * Enter the number of elements: 5
 * Enter the elements: 10 25 30 45 50
 * Enter the element to search: 30
 * Element 30 found at index 2.
 *
 * Enter the number of elements: 5
 * Enter the elements: 10 25 30 45 50
 * Enter the element to search: 15
 * Element 15 not found in the array.
 */
