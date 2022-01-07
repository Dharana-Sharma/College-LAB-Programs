#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}node;
node* create_node(int);
node* create_list(node*);
node* node_before(node*);
node* node_after(node*);
node* del_node(node*);
void search_node(node*);
node* del_list(node*);
node* rev_list(node*);
void print_list(node*);
int main()
{
	node *head=NULL;
	int val, ch;
	printf("****************\n");
	printf("                  MENU\n");
	printf("--------------------------------------------\n");	
	printf("01. Create a list\n");
	printf("02. Add a node before a node the list\n");
	printf("03. Add a node after a node in the list\n");
	printf("04. Delete a node from list\n");
	printf("05. Search a node\n");
	printf("06. Delete list\n");
	printf("07. Reverse list\n");
	printf("08. Print list\n");
	printf("09. EXIT\n");
	printf("****************\n");
	do
	{
			//Enter users choice
		printf("\nEnter choice of operation: ");
		scanf("%d",&ch);
			//Call functions
		switch(ch)
		{
			case 1:head=create_list(head);
				printf("\n.....LIST CREATED.....\n");
				break;
			case 2:head=node_before(head);
				break;
			case 3:head=node_after(head);
				break;
			case 4:head=del_node(head);
				break;
			case 5:search_node(head);
				break;
			case 6:head=del_list(head);
				break;
			case 7:head=rev_list(head);
				break;
			case 8:print_list(head);
				break;
			case 9:break;
			default:printf("\n.......INVALID CHOICE.......\n");
				printf("ENTER A NUMBER FROM 1 TO 8\n");
		}
	}while(ch!=9);
	printf("\n......EXIT......\n");
}
node* create_node(int n)
{
	node *n_node;
	n_node=(node *)malloc(sizeof(int));
	if(n_node)
	{
		n_node->data=n;
		n_node->next=NULL;
	}
	return n_node;
}
node* create_list(node *head)
{
	node *n_node, *p=head;
	int val;
	char c;
	if(head)
		while(p->next)
			p=p->next;
	do
	{
		printf("\nEnter value for the node: ");
		scanf("%d",&val);
		n_node=create_node(val);
		if(n_node==NULL)
		{
			printf("\nMAX LIMIT REACHED\NCANNOT ADD MORE\n");
			return head;
		}
		if(p==NULL)
			p=head=n_node;
		else
		{
			p->next=n_node;
			p=p->next;
		}
		printf("\n.....NODE ADDED.....\n");
		printf("Do you want to add more? (y/Y): ");
		fflush(stdin);
		scanf("%c",&c);
	}while(c=='y' || c=='Y');
	return head;
}
node* node_before(node *head)
{
	node *p=head, *newnode;
	int  val, target;
	printf("Enter a value to add : ");
	scanf("%d",&val);
	printf("Enter a value before which you want to add : ");
	scanf("%d",&target);
	newnode=create_node(val);
	if(newnode==NULL)
	{
		printf("\nMAX LIMIT REACHED\NCANNOT ADD MORE\n");
		return head;
	}
	if(head==NULL)
	{
		printf("...LIST EMPTY...\n");
		printf("CREATE LIST FIRST\n");
		return head;
	}
	if(head->data==target)
	{
		head=newnode;
		newnode->next=p;
		return head;
	}
	while(p->next && p->next->data!=target)
		p=p->next;
	if(p->next==NULL)
	{
		printf("!!!Target not found!!!");
		return head;
	}
	newnode->next=p->next;
	p->next=newnode;
	printf("\n.....NODE ADDED.....\n");
	return head;
}
node* node_after(node *head)
{
	node *p=head, *newnode;
	int  val, target;
	printf("Enter a value to add : ");
	scanf("%d",&val);
	printf("Enter a value after which you want to add : ");
	scanf("%d",&target);
	newnode=create_node(val);
	if(newnode==NULL)
	{
		printf("\nMAX LIMIT REACHED\NCANNOT ADD MORE\n");
		return head;
	}
	if(head==NULL)
	{
		printf("...LIST EMPTY...\n");
		printf("CREATE LIST FIRST\n");
		return head;
	}
	while(p && p->data!=target)
		p=p->next;
	if(p==NULL)
	{
		printf("!!!Target not found!!!");
		return head;
	}
	newnode->next=p->next;
	p->next=newnode;
	printf("\n.....NODE ADDED.....\n");
	return head;
}
node* del_node(node *head)
{
	node *p=head, *to_del;
	int val;
	printf("Enter value to delete: ");
	scanf("%d",&val);
	if(head==NULL)
	{
		printf("...LIST EMPTY...\n");
		printf("CREATE LIST FIRST\n");
		return head;
	}
	if(head->data==val)
	{
		to_del=head;
		head=head->next;
		free(to_del);
		printf("\n.....NODE DELETED.....\n");
		return head;
	}
	while(p->next && p->next->data!=val)
		p=p->next;
	if(p->next==NULL)
	{
		printf("!!!Target not found!!!");
		return head;
	}
	to_del=p->next;
	p->next=to_del->next;
	free(to_del);
	printf("\n.....NODE DELETED.....\n");
	return head;
}
void search_node(node *head)
{
	int val;
	node *p=head;
	printf("Enter value to search: ");
	scanf("%d",&val);
	while(p)
	{
		if(p->data==val)
		{
			printf("Value is present\n");
			return;
		}
		p=p->next;
	}
	printf("Value absent\n");
}
node* del_list(node *head)
{
	node *p=head,*nxt;
	if(head==NULL)
	{
		printf("...LIST EMPTY...\n");
		printf("CREATE LIST FIRST\n");
		return head;
	}
	while(p)
	{
		nxt=p->next;
		free(p);
		p=nxt;
	}
	printf("...LIST DELETED...\n");
	return NULL;
}
node* rev_list(node *head)
{
	node *prev=NULL;
	node *current=head;
	node *nxt=head->next;
	if(head==NULL)
	{
		printf("...LIST EMPTY...\n");
		printf("CREATE LIST FIRST\n");
		return head;
	}
	while(current)
	{
		current->next=prev;
		prev=current;
		current=nxt;
		if(nxt)
			nxt=nxt->next;
	}
	printf("...LIST REVERSED...\n");
	return prev;
}
void print_list(node *head)
{
	node *p=head;
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