/*
 * Practical 1.3: Infix to Postfix Conversion using Stack
 */

#include <stdio.h>

#define MAX 50

char stack[MAX];
int	 top = -1;

void push(char c)
{
	stack[++top] = c;
}

char pop()
{
	return stack[top--];
}

char peek()
{
	return stack[top];
}

int precedence(char c)
{
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	if (c == '^')
		return 3;
	return 0;
}

int is_operator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infix_to_postfix(char infix[], char postfix[])
{
	int	 i = 0, j = 0;
	char ch;

	for (i = 0; infix[i] != '\0'; i++)
	{
		ch = infix[i];

		if (ch == '(')
		{
			push(ch);
		}
		else if (ch == ')')
		{
			while (top != -1 && peek() != '(')
			{
				postfix[j++] = pop();
			}
			pop(); // remove '('
		}
		else if (is_operator(ch))
		{
			while (top != -1 && precedence(peek()) >= precedence(ch))
			{
				postfix[j++] = pop();
			}
			push(ch);
		}
		else
		{
			postfix[j++] = ch;
		}
	}

	while (top != -1)
	{
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
}

int main()
{
	char infix[MAX], postfix[MAX];

	printf("Enter infix expression: ");
	scanf("%s", infix);

	infix_to_postfix(infix, postfix);

	printf("Postfix expression: %s\n", postfix);

	return 0;
}

/*
 * Output:
 * Enter infix expression: A+B*C
 * Postfix expression: ABC*+
 *
 * Enter infix expression: (A+B)*(C-D)
 * Postfix expression: AB+CD-*
 *
 * Enter infix expression: A^B^C
 * Postfix expression: ABC^^
 */
