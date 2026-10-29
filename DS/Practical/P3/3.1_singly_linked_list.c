/*
 * Practical 3.1: Singly Linked List Operations
 * Menu driven program to insert at front/end, insert in ascending order,
 * delete first node, delete node before/after a specified position.
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
	if (head == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	printf("List: ");
	while (head != NULL)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

struct node *insert_at_first(struct node *head, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = head;
	return new_node;
}

struct node *insert_at_end(struct node *head, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *n = head;

	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL)
		return new_node;

	while (n->next != NULL)
	{
		n = n->next;
	}

	n->next = new_node;

	return head;
}

struct node *insert_sorted(struct node *head, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *n = head;

	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL || head->data >= data)
	{
		new_node->next = head;
		return new_node;
	}

	while (n->next != NULL && n->next->data < data)
	{
		n = n->next;
	}

	new_node->next = n->next;
	n->next = new_node;

	return head;
}

struct node *delete_at_first(struct node *head)
{
	struct node *n = head;

	if (head == NULL)
	{
		printf("List is empty.\n");
		return NULL;
	}

	head = head->next;
	free(n);

	return head;
}

struct node *delete_before_position(struct node *head, int pos)
{
	struct node *prev;
	struct node *n;
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
		return delete_at_first(head);

	prev = head;
	n = head->next;

	while (n != NULL && i < pos - 2)
	{
		prev = prev->next;
		n = n->next;
		i++;
	}

	if (n == NULL || n->next == NULL)
	{
		printf("Position %d does not exist.\n", pos);
		return head;
	}

	prev->next = n->next;
	free(n);

	return head;
}

struct node *delete_after_position(struct node *head, int pos)
{
	struct node *n = head;
	struct node *temp;
	int i = 1;

	if (head == NULL)
	{
		printf("List is empty.\n");
		return NULL;
	}

	while (n != NULL && i < pos)
	{
		n = n->next;
		i++;
	}

	if (n == NULL || n->next == NULL)
	{
		printf("No node after position %d.\n", pos);
		return head;
	}

	temp = n->next;
	n->next = temp->next;
	free(temp);

	return head;
}

int main()
{
	struct node *head = NULL;
	int choice, value, pos;

	while (1)
	{
		printf("\n--- Singly Linked List Menu ---\n");
		printf("1. Insert at front\n");
		printf("2. Insert at end\n");
		printf("3. Insert in ascending order\n");
		printf("4. Delete first node\n");
		printf("5. Delete node before position\n");
		printf("6. Delete node after position\n");
		printf("7. Display\n");
		printf("8. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				head = insert_at_first(head, value);
				printf("%d inserted at front.\n", value);
				break;
			case 2:
				printf("Enter value: ");
				scanf("%d", &value);
				head = insert_at_end(head, value);
				printf("%d inserted at end.\n", value);
				break;
			case 3:
				printf("Enter value: ");
				scanf("%d", &value);
				head = insert_sorted(head, value);
				printf("%d inserted in ascending order.\n", value);
				break;
			case 4:
				head = delete_at_first(head);
				break;
			case 5:
				printf("Enter position: ");
				scanf("%d", &pos);
				head = delete_before_position(head, pos);
				break;
			case 6:
				printf("Enter position: ");
				scanf("%d", &pos);
				head = delete_after_position(head, pos);
				break;
			case 7:
				print_list(head);
				break;
			case 8:
				exit(0);
			default:
				printf("Invalid choice.\n");
		}
	}
	return 0;
}

/*
 * Output:
 * --- Singly Linked List Menu ---
 * 1. Insert at front
 * 2. Insert at end
 * 3. Insert in ascending order
 * 4. Delete first node
 * 5. Delete node before position
 * 6. Delete node after position
 * 7. Display
 * 8. Exit
 * Enter choice: 2
 * Enter value: 30
 * 30 inserted at end.
 * Enter choice: 3
 * Enter value: 10
 * 10 inserted in ascending order.
 * Enter choice: 3
 * Enter value: 20
 * 20 inserted in ascending order.
 * Enter choice: 1
 * Enter value: 5
 * 5 inserted at front.
 * Enter choice: 7
 * List: 5 -> 10 -> 20 -> 30 -> NULL
 * Enter choice: 6
 * Enter position: 2
 * Enter choice: 5
 * Enter position: 3
 * Enter choice: 4
 * Enter choice: 7
 * List: 30 -> NULL
 * Enter choice: 8
 */