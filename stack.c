#include <stdio.h>
struct stack
{
    int top;
    int elements;
    struct stack *next;
    struct stack *previous;
};

typedef struct stack Stack;

Stack myStack;

int pop(void);
void push(int);
void display(void);

int main(int argc, char *argv[])
{

    myStack.top = -1;

    int choice, value;

    while (1)
    {
        printf ("------------------------------------------\n");
        printf ("      1    -->    PUSH               \n");
        printf ("      2    -->    POP               \n");
        printf ("      3    -->    DISPLAY               \n");
        printf ("      4    -->    EXIT           \n");
        printf ("------------------------------------------\n");

        printf ("Enter your choice\n");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the integer you want to push: ");
            scanf("%d", &value);
            printf("\nPushing to stack... \n\n");
            push(value);
            break;
        case 2:
            printf("\nPoping from stack... \n\n");
            value = pop();
            printf("\n Poped value is %d\n", value);
            break;
        case 3:
            printf("\nDisplaying stack... \n\n");
            display();
            break;
        case 4:
            printf("\nExiting... \n\n\n");
            return 0;
        default:
            break;
        }
    }

    return 0;
}

int pop()
{
    if (myStack.top >= 0)
    {

        int value =myStack.elements[myStack.top];
        myStack.top--;

        return value;
    }
    return -1;
}

void push(int value)
{
    if(myStack.top < MAXSIZE - 1)
    {
        myStack.top++;
        myStack.elements[myStack.top] = value;
    }
}

void display()
{
    while(myStack.top>=MAXSIZE)
    {
        int value=myStack.elements[myStack.top];
        myStack.top--;
        printf("%d , ",value);
    }
}
