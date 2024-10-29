#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1,rear = -1;
int Max = 0;


void initializeQueue(int size)
{
    queue = (int *)malloc(size * sizeof(int));

    if (queue == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    Max = size;
}

void enqueue(int value)
{
    if(rear == Max -1)
    {
        printf("Queue overflow.\n",value);
    }
    else
    {
        if(front == -1) front = 0;
        queue[++rear] = value;
        printf("%d enqueue into the queue.\n",value);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("%d dequeued from the queue\n", queue[front++]);
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choose = 0,value,Size;


    printf("Enter the size of queue: ");
    scanf("%d", &Size);
    initializeQueue(Size);

    while(1)
    {
        printf("\nChoose the Operation\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choose);

        if(choose == 1)
        {
            printf("Enter the value of Enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if(choose == 2)
        {
            dequeue();
        }
        else if(choose == 3)
        {
            display();
        }
        else if(choose == 4)
        {
            printf("Exiting Program.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
