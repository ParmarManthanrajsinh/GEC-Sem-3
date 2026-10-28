/*
 * Practical 10.1: Hash Table using Linear Probing
 * Inserts keys into a hash table and resolves collisions using linear probing.
 */

#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hash_table[TABLE_SIZE];

int hash_function(int key)
{
	return key % TABLE_SIZE;
}

void insert_key(int key)
{
	int index = hash_function(key);
	int start = index;

	while (hash_table[index] != EMPTY && hash_table[index] != key)
	{
		index = (index + 1) % TABLE_SIZE;
		if (index == start)
		{
			printf("Hash table is full. Cannot insert %d.\n", key);
			return;
		}
	}

	if (hash_table[index] == key)
	{
		printf("Key %d already exists at index %d.\n", key, index);
		return;
	}

	hash_table[index] = key;
	printf("Key %d inserted at index %d.\n", key, index);
}

void search_key(int key)
{
	int index = hash_function(key);
	int start = index;

	while (hash_table[index] != EMPTY)
	{
		if (hash_table[index] == key)
		{
			printf("Key %d found at index %d.\n", key, index);
			return;
		}
		index = (index + 1) % TABLE_SIZE;
		if (index == start)
			break;
	}

	printf("Key %d not found.\n", key);
}

void display_table()
{
	printf("\nIndex\tKey\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hash_table[i] == EMPTY)
			printf("%d\t--\n", i);
		else
			printf("%d\t%d\n", i, hash_table[i]);
	}
}

int main()
{
	int choice, key;

	for (int i = 0; i < TABLE_SIZE; i++)
		hash_table[i] = EMPTY;

	do
	{
		printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter key to insert: ");
			scanf("%d", &key);
			insert_key(key);
			break;
		case 2:
			printf("Enter key to search: ");
			scanf("%d", &key);
			search_key(key);
			break;
		case 3:
			display_table();
			break;
		case 4:
			printf("Exiting.\n");
			break;
		default:
			printf("Invalid choice.\n");
		}
	} while (choice != 4);

	return 0;
}

/*
 * Output:
 * 1. Insert
 * 2. Search
 * 3. Display
 * 4. Exit
 * Enter your choice: 1
 * Enter key to insert: 15
 * Key 15 inserted at index 5.
 *
 * Enter your choice: 1
 * Enter key to insert: 25
 * Key 25 inserted at index 6.
 *
 * Enter your choice: 3
 *
 * Index   Key
 * 0       --
 * 1       --
 * 2       --
 * 3       --
 * 4       --
 * 5       15
 * 6       25
 * 7       --
 * 8       --
 * 9       --
 *
 * Enter your choice: 2
 * Enter key to search: 25
 * Key 25 found at index 6.
 *
 * Enter your choice: 4
 * Exiting.
 */
