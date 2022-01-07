#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
}node;

node *create_node(int);
node* createlist(node*);
node* insertatbeg(node*);
node* insertatend(node*);
void display(node *head);
node *insertatpos(node *head);
node *delfrombeg(node *head);
node *delfromend(node *head);
node *delfrompos(node *head);
node *reverse(node *head);

int main()
{
	int ch;
	node *head=NULL;
	do
	{
		printf("\n\n **MENU*\n");
		printf("01.Create a list\n");
	    printf("02.To insert at beginning\n");
	    printf("03.To insert at end\n");
	    printf("04.To insert at any given position\n");
	    printf("05.To reverse a list\n");
	    printf("06.To delete the first node\n");
	    printf("07.To delete last node\n");
	    printf("08.To delete from any given position\n");
	    printf("09.To end the program\n");
	   
	    printf("\n Enter your choice ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1: head=createlist(head);
	    	        printf("\n.......LIST CREATED...\n");
	    	        break;
	    	case 2: printf("\n insert a node at beginning");
	    	        head=insertatbeg(head);
	    	        break;
	    	case 3: printf("\n insert a node at end");
	    	        head=insertatend(head);
	    	        break;
	    	case 4: printf("\n insert a node at given position");
	    	        head=insertatpos(head);
	    	        break;
	    	case 5: printf("\n reversed list: \n");
	    	        head=reverse(head);
	    	        break;
	    	case 6: printf("\n list after deletion of first node is:\n");
	    	        head=delfrombeg(head);
	    	        break;
	    	case 7: printf("\n list after deletion of last node is:\n");
	    	        head=delfromend(head);
	    	        break;
	    	case 8: printf("\n list after deletion of given node is:\n");
	    	        head=delfrompos(head);
	    	        break;
	    	case 9: exit(0);
	    	default: printf("\n INVALID CHOICE");
	    }
	}while(ch);
}

node *create_node(int n)
{
	node *n_node;
	n_node=(node *)malloc(sizeof(int));
	n_node->data=n;
	n_node->prev=NULL;
	n_node->next=NULL;
	return n_node;
}
node *createlist(node *head)
{
	node *tail,*n_node;
	head=NULL;
	int choice=1,n;
	while(choice)
	{
		printf("Enter data ");
		scanf("%d",&n);
		n_node=create_node(n);
		if(head==0)
		{
			head=tail=n_node;
		}
		else
		{
			n_node->prev=tail;
			tail->next=n_node;
			tail=n_node;
		}
		printf("\n Do you still want to continue(1/0)");
		scanf("%d",&choice);
	}
	return head;
}
void display(node *head)
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
node *insertatbeg(node *head)
{
	int n;
	printf("\n Enter data ");
	scanf("%d",&n);
	node *n_node;
	n_node=create_node(n);
	n_node->next=head;
	head->prev=n_node;
	head=n_node;
	display(head);
	return head;
}
node *insertatend(node *head)
{
	node *temp,*n_node;
	int n;
	printf("\n Enter data");
	scanf("%d",&n);
	n_node=create_node(n);
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	n_node->prev=temp;
	temp->next=n_node;
	display(head);
	return head;
}
node *insertatpos(node *head)
{
	int pos,i=1,n,c=0;
	node *n_node,*temp;
	printf("n Enter position where you want to insert node");
	scanf("%d",&pos);

	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	if(c<pos)
	{
		printf("\n INVALID CHOICE\n");
	}
	else
	{
		printf("\n Enter data");
		scanf("%d",&n);
		n_node=create_node(n);
		temp=head;
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		n_node->prev=temp->prev;
		temp->prev=n_node;
		n_node->next=temp;
		n_node->prev->next=n_node;
	}
	display(head);
	return head;
}
node *delfrombeg(node *head)
{
	node *temp;
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
	display(head);
	return head;
}
node *delfromend(node *head)
{
	node *temp;
	temp=head;
	while(temp->next!=NULL)
	   temp=temp->next;
	temp->prev->next=NULL;
	free(temp);
	display(head);
	return head;
}
node *delfrompos(node *head)
{
	int pos,i=1,n,c=0;
	node *n_node,*temp;
	printf("n Enter position where you want to delete node");
	scanf("%d",&pos);

	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	if(c<pos)
	{
		printf("\n INVALID CHOICE\n");
	}
	else if(pos==1)
	{
		head=delfrombeg(head);
	}
	else
	{
		temp=head;
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
	display(head);
	return head;
}
node *reverse(node *head)
{
	node *temp,*current,*next;
	temp=NULL;
	current=head;
	next=0;
	while(current!=NULL)
	{
		next=current->next;
		current->next=temp;
		temp=current;
		current=next;
	}
	head=temp;
	display(head);
	return head;
}