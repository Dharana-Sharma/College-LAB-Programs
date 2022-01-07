#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node *createnode(int val)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}

node *enq(node *tail)
{
	node *newnode;
	int x;
	printf("Enter the value ");
	scanf("%d",&x);
	newnode = createnode(x);
	if(newnode==NULL)
	{
		printf("Queue Overflow\n");
		return tail;
	}
	if(tail!=NULL)
	{
		newnode->next = tail->next;
		tail->next = newnode;
		tail = tail->next;
	}
	else
	{
		tail = newnode;
		tail->next=tail;
	}
	printf("%d inserted into queue",x);
	return tail;
}
node *deq(node *tail)
{
	node *p;
	int x;
	if(tail==NULL)
	{
		printf("\nQueue Underflow\n");
		return tail;
	}
	x = tail->next->data;
	p = tail->next;
	if(tail!=tail->next)
		tail->next = tail->next->next;
	else
		tail = NULL;
	free(p);
	printf("%d deleted from queue",x);
	return tail;
}
void display(node *tail)
{
	node  *p = tail;
	node *q = tail->next;
	if(tail==NULL)
	{
		printf("Queue Underflow");
	}
	else
	{
		while(q!=p)
		{
			printf("%d ",q->data);
			q = q->next;
		}
		printf("%d ",q->data);
	}
}

int main()
{
	node *tail = NULL;
	int choice;
	do
	{
		printf("\n\nMenu\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your choice(1-4): ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : tail = enq(tail);
					 break;

			case 2 : tail = deq(tail);
					 break;

			case 3 : display(tail);
					 break;

			case 4 : printf("Exiting!!!");
					 break;

			default: printf("Wrong Choice");
		}
	}while(choice!=4);
}
