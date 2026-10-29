/*
 * Practical 3.3: Queue using Linked List
 * Implement INSERT, DELETE and DISPLAY operations on a queue using a
 * singly linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert(int value)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->info = value;
	new_node->next = NULL;

	if (rear == NULL)
	{
		front = new_node;
		rear = new_node;
	}
	else
	{
		rear->next = new_node;
		rear = new_node;
	}
	printf("%d inserted into queue.\n", value);
}

void delete ()
{
	if (front == NULL)
	{
		printf("Queue Underflow!\n");
		return;
	}
	struct node *temp = front;
	printf("%d deleted from queue.\n", temp->info);
	front = front->next;
	if (front == NULL)
		rear = NULL;
	free(temp);
}

void display()
{
	if (front == NULL)
	{
		printf("Queue is empty.\n");
		return;
	}
	printf("Queue elements: ");
	struct node *temp = front;
	while (temp != NULL)
	{
		printf("%d ", temp->info);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int choice, value;

	while (1)
	{
		printf("\n--- Queue using Linked List ---\n");
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
				printf("Invalid choice.\n");
		}
	}
	return 0;
}

/*
 * Output:
 * --- Queue using Linked List ---
 * 1. INSERT
 * 2. DELETE
 * 3. DISPLAY
 * 4. EXIT
 * Enter choice: 1
 * Enter value: 10
 * 10 inserted into queue.
 * Enter choice: 1
 * Enter value: 20
 * 20 inserted into queue.
 * Enter choice: 1
 * Enter value: 30
 * 30 inserted into queue.
 * Enter choice: 3
 * Queue elements: 10 20 30
 * Enter choice: 2
 * 10 deleted from queue.
 * Enter choice: 3
 * Queue elements: 20 30
 * Enter choice: 4
 */