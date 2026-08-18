#include <stdio.h>
#include <stdlib.h>

int size = 0;
int top = -1;
int *arr = NULL;

void Stack(int n)
{
    arr = (int *)malloc(n * sizeof(int));
    size = n;
}

void Push(int value)
{
    if (top < size - 1)
    {
        top++;
        arr[top] = value;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

void Pop()
{
    if (top > -1)
    {
        top--;
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

void Peep()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d\n", arr[top]);
}

void Display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void Change(int index, int value)
{
    if (index >= 0 && index <= top)
    {
        arr[index] = value;
    }
    else
    {
        printf("Index not found\n");
    }
}

int main()
{
    int c = 0;
    int n = 0;

    printf("Enter size of Stack: ");
    scanf("%d", &n);

    Stack(n);

    while (c != -1)
    {
        printf("\n1 for push element\n");
        printf("2 for pop element\n");
        printf("3 for display element\n");
        printf("4 for peep element\n");
        printf("5 for change element\n");
        printf("6 for exit\n\n");

        scanf("%d", &c);

        int v = 0;
        int i = 0;

        switch (c)
        {
            case 1:
                printf("Enter a value to push: ");
                scanf("%d", &v);
                Push(v);
                break;

            case 2:
                Pop();
                printf("Popped the element\n");
                break;

            case 3:
                Display();
                break;

            case 4:
                printf("The peep element is ");
                Peep();
                break;

            case 5:
                printf("Enter the index: ");
                scanf("%d", &i);

                printf("Enter the value: ");
                scanf("%d", &v);

                Change(i, v);
                break;

            case 6:
                c = -1;
                break;

            default:
                printf("Invalid option\n");
        }

        if (c != -1)
            c = 0;
    }

    free(arr);

    return 0;
}
