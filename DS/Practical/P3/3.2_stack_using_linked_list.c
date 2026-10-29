/*
 * Practical 3.2: Stack using Linked List
 * Implement PUSH, POP, PEEP and DISPLAY operations on a stack using a
 * singly linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *top = NULL;

void push(int value)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->info = value;
	new_node->next = top;
	top = new_node;
	printf("%d pushed onto stack.\n", value);
}

void pop()
{
	if (top == NULL)
	{
		printf("Stack Underflow!\n");
		return;
	}
	struct node *temp = top;
	printf("%d popped from stack.\n", temp->info);
	top = top->next;
	free(temp);
}

void peep()
{
	if (top == NULL)
	{
		printf("Stack is empty!\n");
		return;
	}
	printf("Top element: %d\n", top->info);
}

void display()
{
	if (top == NULL)
	{
		printf("Stack is empty!\n");
		return;
	}
	printf("Stack elements: ");
	struct node *temp = top;
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
		printf("\n--- Stack using Linked List ---\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. PEEP\n");
		printf("4. DISPLAY\n");
		printf("5. EXIT\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				peep();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid choice.\n");
		}
	}
	return 0;
}

/*
 * Output:
 * --- Stack using Linked List ---
 * 1. PUSH
 * 2. POP
 * 3. PEEP
 * 4. DISPLAY
 * 5. EXIT
 * Enter choice: 1
 * Enter value: 10
 * 10 pushed onto stack.
 * Enter choice: 1
 * Enter value: 20
 * 20 pushed onto stack.
 * Enter choice: 1
 * Enter value: 30
 * 30 pushed onto stack.
 * Enter choice: 4
 * Stack elements: 30 20 10
 * Enter choice: 3
 * Top element: 30
 * Enter choice: 2
 * 30 popped from stack.
 * Enter choice: 4
 * Stack elements: 20 10
 * Enter choice: 5
 */