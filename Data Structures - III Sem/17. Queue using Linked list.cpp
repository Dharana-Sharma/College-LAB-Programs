#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NodeQueue
{
    int data;
    struct NodeQueue *next;
    int front,rear;
}node;

int isEmpty(node *front,node *rear)
{
    if(front==NULL && rear==NULL)
        return 1;
    return 0;
}

node *createNode(int v)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = v;
    newnode->next = NULL;

    return newnode;
}


node *enq(node *front, node*rear, int val)
{
    node *newnode;
    newnode = createNode(val);

    if(isEmpty(front,rear))
    {
        rear = newnode;
        rear->next = NULL;
        return rear;
    }
    rear->next = newnode;
    rear = newnode;
    rear->next = NULL;

    return rear;
}

node *deq(node *front)
{
    node *p;
    p = front;
    front = front->next;
    printf("%d is dequeued from the queue\n", p->data);
    free(p);
    return front;
}

void display(node *front, node *rear)
{
    if(isEmpty(front,rear))
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        while(front!=rear)
        {
            printf("\t%d", front->data);
            front = front->next;
        }
        printf("\t%d", front->data);
    }
}
int main()
{
    node *front=NULL, *rear=NULL;
    int choice, val;
    do
    {
         printf("\n **MAIN MENU**");
         printf("\n 1. enqueue (INSERT)");
         printf("\n 2. dequeue (DELETE)");
         printf("\n 3. DISPLAY");
         printf("\n 4. EXIT");
         printf("\n Enter your choice: ");
         scanf("%d", &choice);
        switch(choice)
         {
             case 1:printf("\nEnter the value: ");
                    scanf("%d", &val);
                    rear = enq(front,rear,val);
                    if(front==NULL)
                        front = rear;
                    printf("%d: enqueued", val);
                    break;

             case 2: if(isEmpty(front,rear))
                        printf("\nQUEUE UNDERFLOW");
                    else
                    {
                        front = deq(front);
                        if(front==NULL)
                            rear=front;
                    }
                    break;

             case 3: if(isEmpty(front, rear))
                        printf("\nQueue is empty!!!");
                     else
                        display(front,rear);
                    break;
             case 4:printf("\nEnd of program!!!");
                    break;

            default: printf("\nINVALID SELECTION");
         }
    }
    while(choice!=4);
    return 0;
}

