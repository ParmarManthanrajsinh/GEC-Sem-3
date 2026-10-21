/*
 * Practical 5.1: Circular Linked List Operations
 * Menu driven program to insert a node at the end, insert a node before a
 * specified position, delete the first node and delete the node after a
 * specified position in a circular linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void print_list(struct node *head)
{
	struct node *n;

	if (head == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	printf("List: ");
	n = head;
	do
	{
		printf("%d -> ", n->data);
		n = n->next;
	} while (n != head);
	printf("(back to %d)\n", head->data);
}

struct node *insert_at_end(struct node *head, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *n = head;

	new_node->data = data;

	if (head == NULL)
	{
		new_node->next = new_node;
		return new_node;
	}

	while (n->next != head)
	{
		n = n->next;
	}

	n->next = new_node;
	new_node->next = head;

	return head;
}

struct node *insert_before_position(struct node *head, int pos, int data)
{
	struct node *new_node;
	struct node *prev;
	int i = 1;

	if (head == NULL)
	{
		printf("List is empty.\n");
		return head;
	}

	if (pos == 1)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = data;
		prev = head;
		while (prev->next != head)
		{
			prev = prev->next;
		}
		new_node->next = head;
		prev->next = new_node;
		return new_node;
	}

	prev = head;
	while (i < pos - 1 && prev->next != head)
	{
		prev = prev->next;
		i++;
	}

	if (i != pos - 1 || prev->next == head)
	{
		printf("Position %d does not exist.\n", pos);
		return head;
	}

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = prev->next;
	prev->next = new_node;

	return head;
}

struct node *delete_first(struct node *head)
{
	struct node *last;
	struct node *temp;

	if (head == NULL)
	{
		printf("List is empty.\n");
		return NULL;
	}

	if (head->next == head)
	{
		free(head);
		return NULL;
	}

	last = head;
	while (last->next != head)
	{
		last = last->next;
	}

	temp = head;
	last->next = head->next;
	head = head->next;
	free(temp);

	return head;
}

struct node *delete_after_position(struct node *head, int pos)
{
	struct node *n = head;
	struct node *target;
	int i = 1;

	if (head == NULL)
	{
		printf("List is empty.\n");
		return NULL;
	}

	while (i < pos && n->next != head)
	{
		n = n->next;
		i++;
	}

	if (i != pos)
	{
		printf("Position %d does not exist.\n", pos);
		return head;
	}

	target = n->next;

	if (target == head)
	{
		printf("No node after position %d.\n", pos);
		return head;
	}

	n->next = target->next;
	free(target);

	return head;
}

int main()
{
	struct node *head = NULL;
	int choice, value, pos;

	while (1)
	{
		printf("\n--- Circular Linked List Menu ---\n");
		printf("1. Insert at end\n");
		printf("2. Insert before position\n");
		printf("3. Delete first node\n");
		printf("4. Delete node after position\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				head = insert_at_end(head, value);
				printf("%d inserted at end.\n", value);
				break;
			case 2:
				printf("Enter position: ");
				scanf("%d", &pos);
				printf("Enter value: ");
				scanf("%d", &value);
				head = insert_before_position(head, pos, value);
				break;
			case 3:
				head = delete_first(head);
				break;
			case 4:
				printf("Enter position: ");
				scanf("%d", &pos);
				head = delete_after_position(head, pos);
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
 * --- Circular Linked List Menu ---
 * 1. Insert at end
 * 2. Insert before position
 * 3. Delete first node
 * 4. Delete node after position
 * 5. Display
 * 6. Exit
 * Enter choice: 1
 * Enter value: 10
 * 10 inserted at end.
 * Enter choice: 1
 * Enter value: 20
 * 20 inserted at end.
 * Enter choice: 1
 * Enter value: 30
 * 30 inserted at end.
 * Enter choice: 5
 * List: 10 -> 20 -> 30 -> (back to 10)
 * Enter choice: 2
 * Enter position: 1
 * Enter value: 5
 * Enter choice: 2
 * Enter position: 3
 * Enter value: 25
 * Enter choice: 5
 * List: 5 -> 10 -> 25 -> 20 -> 30 -> (back to 5)
 * Enter choice: 3
 * Enter choice: 5
 * List: 10 -> 25 -> 20 -> 30 -> (back to 10)
 * Enter choice: 4
 * Enter position: 2
 * Enter choice: 5
 * List: 10 -> 25 -> 30 -> (back to 10)
 * Enter choice: 4
 * Enter position: 3
 * No node after position 3.
 * Enter choice: 6
 */