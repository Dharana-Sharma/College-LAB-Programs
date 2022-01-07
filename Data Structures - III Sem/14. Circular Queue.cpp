#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct CircularQueue
{
    int que[MAX];
    int front,rear;
}queue;

int isFull(queue q)
{
    if(q.front==0&&q.rear==MAX-1)
        return 1;
    return 0;
}

int isEmpty(queue q)
{
    if(q.front==-1&&q.rear==-1)
        return 1;
    return 0;
}

void enqueue(queue *q)
{
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);
    if(isFull(*q))
    {
        printf("\nOVERFLOW");
        return;
    }

    else if(q->front==-1 && q->rear==-1)
    {
        q->front=q->rear=0;
        q->que[q->rear]=num;
    }
    else if(q->rear==MAX-1 && q->front!=0)
    {
        q->rear=0;
        q->que[q->rear]=num;
    }
    else
    {
         q->rear++;
         q->que[q->rear]=num;
    }
    printf("\n %d is enqueued", num);
}

int dequeue(queue *q)
{
    int val;
    if(isEmpty(*q))
     {
         printf("\n UNDERFLOW");
         return -1;
     }
     val=q->que[q->front];

    if(q->front==q->rear)
        q->front=q->rear=-1;
    else
    {
        if(q->front==MAX-1)
            q->front=0;
        else
            q->front++;
    }
    return val;
}
void display(queue q)
{
    int i;
    printf("\n");
    if (isEmpty(q))
        printf ("\nQUEUE IS EMPTY");
    else
    {
        if(q.front<q.rear)
        {
            for(i=q.front;i<=q.rear;i++)
                printf("\t%d", q.que[i]);
        }

        else
        {
            for(i=q.front;i<MAX;i++)
                printf("\t%d", q.que[i]);
            for(i=0;i<=q.rear;i++)
                printf("\t%d", q.que[i]);
        }
    }
}

int main()
{
    queue q;
    q.front=-1;
    q.rear=-1;
    int option, val;

        do
        {
         printf("\n ** MAIN MENU **");
         printf("\n 1. enqueue (Insert an element)");
         printf("\n 2. Dequeue (delete an element)");
         printf("\n 3. Display the queue");
         printf("\n 4. EXIT");
         printf("\n Enter your option : ");
         scanf("%d", &option);
         switch(option)
         {
            case 1: enqueue(&q);
                    break;
            case 2: val = dequeue(&q);
                    if(val!=-1)
                        printf("\n The number deleted is: %d",val);
                    break;
            case 3: display(q);
                    break;
            case 4: printf("\nEnd of the program!!!");
                    break;
            default: printf("\nInvalid choice!");
         }

    }
    while(option!=4);

return 0;
}
