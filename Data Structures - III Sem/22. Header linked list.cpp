#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;

typedef struct Head
{
	int count, min, max;
	node *next;
}head;

node* create_node(int);
head* createhead(void);
head* createlist(head*);
void printlist(head*);

int main()
{
	head *h=NULL;
	h = createhead();
	int val, ch;
	

	printf("         \n    MENU\n");
	printf("---------------------------------------\n");
	printf("01. Create a list\n");
	printf("02. Count number of nodes\n");
	printf("03. Display Maximum value\n");
	printf("04. Display Minimum value\n");
	printf("05. Print list\n");
	printf("06. EXIT\n");
	
	do
	{
		printf("\nEnter choice of operation: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: h=createlist(h);
			        printf("\n....LIST CREATED.........\n");
			        break;
			case 2: printf("Number of nodes = %d\n", h->count);
			        break;
			case 3: if(h->next)
			           printf("Maximum value = %d\n", h->max);
			        else
			           printf("NO NODES PRESENT !\n");
			        break;
			case 4: if(h->next)
			           printf("Minimum value = %d\n", h->min);
			        else
			           printf("NO NODES PRESENT !\n");
			        break;
			case 5: printlist(h);
		            break;
			case 6: break;
			default: printf("\n...........INVALID CHOICE...........\n");
		          printf("ENTER A NUMBER FROM 1 TO 6\n");
	    }
	}while(ch!=6);
	printf("\n.....EXIT......\n");
}
node* create_node(int n)
{
	node *n_node;
	n_node=(node *)malloc(sizeof(node));
	if(n_node)
	{
		n_node->data=n;
		n_node->next=NULL;
	}
	return n_node;
}
head* createhead(void)
{
	head *n;
	n =(head *)malloc(sizeof(head));
	if(n)
	{
		n->count = 0;
		n->max = 0;
		n->min = 0;
		n->next = NULL;
	}
	return n;
}
head* createlist(head *h)
{
	node *n_node , *p=NULL;
	int val;
	
	printf("Enter values :\n");
	printf("Enter -1 to exit\n");
	do
	{
		printf("\nEnter value for the node: ");
		scanf("%d",&val);
		n_node=create_node(val);
		if(n_node==NULL)
		{
			printf("\nMAX LIMIT REACHED\n CANNOT ADD MORE\n");
			return h;
		}
		if(val == -1)
		   break;
		if(!h->next)
		{
			h->min = val;
			h->max = val;
			h->next = n_node;
			p = h->next;
		}
		else
		{
			if(val < h->min)
			   h->min = val;
			if(val > h->max)
			   h->max = val;
			p->next = n_node;
			p=p->next;
		}
		
		(h->count)++;
		
	}while(val != -1);
	return h;
}

void printlist(head *h)
{
	node *p=h->next;
	if(p==NULL)
	{
		printf("LIST EMPTY\n");
		return;
	}
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
