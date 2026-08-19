/*
 * Practical 2.2: Circular Queue using Array
 * Implement a circular queue using array with INSERT, DELETE, and DISPLAY operations.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int cqueue[MAX];
int front = -1;
int rear = -1;

void insert(int value)
{
	if ((rear + 1) % MAX == front)
	{
		printf("Queue Overflow\n");
		return;
	}
	if (front == -1)
		front = 0;
	rear = (rear + 1) % MAX;
	cqueue[rear] = value;
	printf("%d inserted into circular queue\n", value);
}

void delete ()
{
	if (front == -1)
	{
		printf("Queue Underflow\n");
		return;
	}
	printf("%d deleted from circular queue\n", cqueue[front]);
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1) % MAX;
	}
}

void display()
{
	if (front == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Circular Queue elements: ");
	int i = front;
	while (i != rear)
	{
		printf("%d ", cqueue[i]);
		i = (i + 1) % MAX;
	}
	printf("\n");
}

int main()
{
	int choice, value;

	while (1)
	{
		printf("\n--- Circular Queue Operations ---\n");
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
 * --- Circular Queue Operations ---
 * 1. INSERT
 * 2. DELETE
 * 3. DISPLAY
 * 4. EXIT
 * Enter choice: 1
 * Enter value: 10
 * 10 inserted into circular queue
 * Enter choice: 1
 * Enter value: 20
 * 20 inserted into circular queue
 * Enter choice: 1
 * Enter value: 30
 * 30 inserted into circular queue
 * Enter choice: 3
 * Circular Queue elements: 10 20 30
 * Enter choice: 2
 * 10 deleted from circular queue
 * Enter choice: 1
 * Enter value: 40
 * 40 inserted into circular queue
 * Enter choice: 3
 * Circular Queue elements: 20 30 40
 * Enter choice: 4
 */
