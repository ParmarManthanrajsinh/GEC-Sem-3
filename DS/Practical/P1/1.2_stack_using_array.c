/*
 * Practical 1.2: Stack Operations using Array
 * Operations: PUSH, POP, PEEP, CHANGE, DISPLAY
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int val)
{
	if (top == MAX - 1)
	{
		printf("Stack Overflow!\n");
		return;
	}
	top++;
	stack[top] = val;
	printf("Pushed %d onto stack.\n", val);
}

void pop()
{
	if (top == -1)
	{
		printf("Stack Underflow!\n");
		return;
	}
	printf("Popped %d from stack.\n", stack[top]);
	top--;
}

void peep()
{
	if (top == -1)
	{
		printf("Stack is empty!\n");
		return;
	}
	printf("Top element: %d\n", stack[top]);
}

void change(int pos, int val)
{
	if (top - pos + 1 < 0 || pos <= 0)
	{
		printf("Invalid position!\n");
		return;
	}
	stack[top - pos + 1] = val;
	printf("Changed position %d to %d.\n", pos, val);
}

void display()
{
	printf("Stack elements: ");
	for (int i = top; i >= 0; i--)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int main()
{
	int choice, val, pos;

	while (1)
	{
		printf("\n--- Stack Menu ---\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. PEEP\n");
		printf("4. CHANGE\n");
		printf("5. DISPLAY\n");
		printf("6. EXIT\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter value: ");
				scanf("%d", &val);
				push(val);
				break;
			case 2:
				pop();
				break;
			case 3:
				peep();
				break;
			case 4:
				printf("Enter position: ");
				scanf("%d", &pos);
				printf("Enter new value: ");
				scanf("%d", &val);
				change(pos, val);
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
			default:
				printf("Invalid choice!\n");
		}
	}
	return 0;
}

/*
 * Output:
 * --- Stack Menu ---
 * 1. PUSH
 * 2. POP
 * 3. PEEP
 * 4. CHANGE
 * 5. DISPLAY
 * 6. EXIT
 * Enter choice: 1
 * Enter value: 10
 * Pushed 10 onto stack.
 * Enter choice: 1
 * Enter value: 20
 * Pushed 20 onto stack.
 * Enter choice: 1
 * Enter value: 30
 * Pushed 30 onto stack.
 * Enter choice: 5
 * Stack elements: 30 20 10
 * Enter choice: 3
 * Top element: 30
 * Enter choice: 4
 * Enter position: 2
 * Enter new value: 25
 * Changed position 2 to 25.
 * Enter choice: 5
 * Stack elements: 30 25 10
 * Enter choice: 2
 * Popped 30 from stack.
 * Enter choice: 2
 * Popped 25 from stack.
 * Enter choice: 5
 * Stack elements: 10
 * Enter choice: 6
 */
