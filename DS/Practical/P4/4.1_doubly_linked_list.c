/*
 * Practical 4.1: Doubly Linked List Operations
 * Menu driven program to insert a node at the front/end and delete the last
 * node or the node before a specified position in a doubly linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

void print_list(struct node *head)
{
	if (head == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	printf("List: ");
	while (head != NULL)
	{
		printf("%d <-> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

struct node *insert_at_front(struct node *head, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = head;

	if (head != NULL)
		head->prev = new_node;

	return new_node;
}

struct node *insert_at_end(struct node *head, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *n = head;

	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL)
	{
		new_node->prev = NULL;
		return new_node;
	}

	while (n->next != NULL)
	{
		n = n->next;
	}

	n->next = new_node;
	new_node->prev = n;

	return head;
}

struct node *delete_last(struct node *head)
{
	struct node *n = head;

	if (head == NULL)
	{
		printf("List is empty.\n");
		return NULL;
	}

	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}

	while (n->next != NULL)
	{
		n = n->next;
	}

	n->prev->next = NULL;
	free(n);

	return head;
}

struct node *delete_before_position(struct node *head, int pos)
{
	struct node *n;
	struct node *target;
	int i = 1;

	if (head == NULL)
	{
		printf("List is empty.\n");
		return NULL;
	}

	if (pos <= 1)
	{
		printf("No node before position %d.\n", pos);
		return head;
	}

	if (pos == 2)
	{
		n = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		free(n);
		return head;
	}

	n = head;
	while (n != NULL && i < pos)
	{
		n = n->next;
		i++;
	}

	if (n == NULL)
	{
		printf("Position %d does not exist.\n", pos);
		return head;
	}

	target = n->prev;
	target->prev->next = n;
	n->prev = target->prev;
	free(target);

	return head;
}

int main()
{
	struct node *head = NULL;
	int choice, value, pos;

	while (1)
	{
		printf("\n--- Doubly Linked List Menu ---\n");
		printf("1. Insert at front\n");
		printf("2. Insert at end\n");
		printf("3. Delete last node\n");
		printf("4. Delete node before position\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				head = insert_at_front(head, value);
				printf("%d inserted at front.\n", value);
				break;
			case 2:
				printf("Enter value: ");
				scanf("%d", &value);
				head = insert_at_end(head, value);
				printf("%d inserted at end.\n", value);
				break;
			case 3:
				head = delete_last(head);
				break;
			case 4:
				printf("Enter position: ");
				scanf("%d", &pos);
				head = delete_before_position(head, pos);
				break;
			case 5:
				print_list(head);
				break;
			case 6:
				exit(0);
			default:
				printf("Invalid choice.\n");
		}
	}
	return 0;
}

/*
 * Output:
 * --- Doubly Linked List Menu ---
 * 1. Insert at front
 * 2. Insert at end
 * 3. Delete last node
 * 4. Delete node before position
 * 5. Display
 * 6. Exit
 * Enter choice: 2
 * Enter value: 10
 * 10 inserted at end.
 * Enter choice: 2
 * Enter value: 20
 * 20 inserted at end.
 * Enter choice: 2
 * Enter value: 30
 * 30 inserted at end.
 * Enter choice: 1
 * Enter value: 5
 * 5 inserted at front.
 * Enter choice: 5
 * List: 5 <-> 10 <-> 20 <-> 30 <-> NULL
 * Enter choice: 3
 * Enter choice: 5
 * List: 5 <-> 10 <-> 20 <-> NULL
 * Enter choice: 4
 * Enter position: 3
 * Enter choice: 5
 * List: 5 <-> 20 <-> NULL
 * Enter choice: 4
 * Enter position: 1
 * No node before position 1.
 * Enter choice: 6
 */