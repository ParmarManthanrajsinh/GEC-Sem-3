/*
 * Practical 2.1: Queue using Array
 * Implement a queue using array with INSERT, DELETE, and DISPLAY operations.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int value)
{
	if (rear == MAX - 1)
	{
		printf("Queue Overflow\n");
		return;
	}
	if (front == -1)
		front = 0;
	rear++;
	queue[rear] = value;
	printf("%d inserted into queue\n", value);
}

void delete ()
{
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		return;
	}
	printf("%d deleted from queue\n", queue[front]);
	front++;
	if (front > rear)
	{
		front = -1;
		rear = -1;
	}
}

void display()
{
	if (front == -1 || front > rear)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements: ");
	for (int i = front; i <= rear; i++)
		printf("%d ", queue[i]);
	printf("\n");
}

int main()
{
	int choice, value;

	while (1)
	{
		printf("\n--- Queue Operations ---\n");
		printf("1. INSERT\n");
		printf("2. DELETE\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				insert(value);
				break;
			case 2:
				delete ();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}

/*
 * Output:
 * --- Queue Operations ---
 * 1. INSERT
 * 2. DELETE
 * 3. DISPLAY
 * 4. EXIT
 * Enter choice: 1
 * Enter value: 10
 * 10 inserted into queue
 * Enter choice: 1
 * Enter value: 20
 * 20 inserted into queue
 * Enter choice: 3
 * Queue elements: 10 20
 * Enter choice: 2
 * 10 deleted from queue
 * Enter choice: 3
 * Queue elements: 20
 * Enter choice: 4
 */
