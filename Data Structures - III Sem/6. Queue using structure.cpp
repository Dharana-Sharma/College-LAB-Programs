#include<stdio.h>
#define MAX 10
struct Queue
{
	int que[15],front,rear;
};
void enqueue(struct Queue*);
int dequeue(struct Queue*);
void display(struct Queue);
int isFull(int);
int isEmpty(int);

int main()
{
	int ch,e;
	struct Queue q;
	q.rear=q.front=-1;
	printf("              MENU\n");
	printf("--------------------------------------------------------\n");
	printf("1. Enqueue(Insert an element)\n");
	printf("2. Dequeue(Remove an element)\n");
	printf("3. Display Queue\n");
	printf("4. EXIT\n");
	
	do
	{
		printf("\nChoose the operation: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue(&q);
			        break;
			case 2: e = dequeue(&q);
			        if(e!=-999)
			           printf(".....dequeued %d....",e);
			        break;
			case 3: display(q);
			        break;
			case 4: break;
			default: printf(".....INVALID INPUT....\n");
			    printf("ENTER A VALUE FROM 1 TO 4\n");
		
		}
		printf("\n.......................................");
	}while(ch!=4);
	printf("\n....................EXIT.............\n");
}

void enqueue(struct Queue *q)
{
	int ele;
	if(isFull(q->rear))
	{
		printf(".....QUEUE OVERFLOW.....");
		return;
	}
	if((q->front)==-1)
	   (q->front)++;
	printf("Enter element to enqueue: ");
    scanf("%d",&ele);
	q->que[++(q->rear)]=ele;
	printf(".......Enqueued %d.......",ele);
}

int dequeue(struct Queue *q)
{
	int ele;
	if(isEmpty(q->front))
	{
		printf("......QUEUE UNDERFLOW..........");
		return -999;
	}
	ele=q->que[q->front];
	(q->front)++;
	if((q->front)>(q->rear))
	   (q->front)=(q->rear)=-1;
	return ele;
}

void display(struct Queue q)
{
	int i;
	if(isEmpty(q.front))
	{
		printf("......QUEUE EMPTY..........");
		return;
	}
	for(i=q.front;i<=q.rear;i++)
	    printf("%d ",q.que[i]);
}

int isFull(int rear)
{
	if(rear==MAX-1)
	    return 1;
	return 0;
}

int isEmpty(int front)
{
	if(front==-1)
	    return 1;
	return 0;
}
