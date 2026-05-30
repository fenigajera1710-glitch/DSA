#include <stdio.h>
#define MAX 5

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

int isFull()
{
    if (top1 == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (top1 == -1 && top2 == -1)
        return 1;
    else
        return 0;
}

void push1(int value)
{
    if (top1 == MAX - 1)
        printf("Overflow\n");
    else
    {
        top1++;
        stack1[top1] = value;
    }
}

void push2(int value)
{
    top2++;
    stack2[top2] = value;
}

int pop1()
{
    int value = stack1[top1];
    top1--;
    return value;
}

int pop2()
{
    int value = stack2[top2];
    top2--;
    return value;
}

void enqueue(int value)
{
    if (isFull())
        printf("Queue Overflow\n");
    else
        push1(value);
}

void dequeue()
{
    int x;

    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }

    if (top2 == -1)
    {
        while (top1 != -1)
        {
            x = pop1();
            push2(x);
        }
    }

    printf("Deleted: %d\n", pop2());
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    for (i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);

    for (i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}
