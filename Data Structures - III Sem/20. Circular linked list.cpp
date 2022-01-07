#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
int count()
{
	struct node *cur;
	int c=0;
	if(head!=NULL)
	{
		cur=head;
		while(cur->next!=head)
		{
			cur=cur->next;
			c++;
		}
		c=c+1;
	}
	return(c);
}
void display()
{
	struct node *cur;
	cur=head;
	if(cur==NULL)
	{
		printf("\nSORRY NO ELEMENT IN THE LIST !!");
		return;
	}
	printf("\nTHE LIST IS : ");
	while(cur->next!=head)
	{
		printf("%d -> ",cur->data);
		cur=cur->next;
	}
	printf("%d ",cur->data);
	printf("\n");
}

void addloc(int num,int loc)
{
	int i;
	struct node *newnode, *prv, *cur;
	cur=head;
	if(loc>count()+1 || loc<=0)
	{
		printf("\nINSERTION IS NOT POSSIBLE !!");
		return;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	if(loc==1)//insertion at beginning
	{
		if(head==NULL)
		{
			head=newnode;//head and newnode are same
			head->next=head;//head is pointing itself
			return;
		}
		else //insertion before first location
		{
			newnode->next=head;
			while(cur->next!=head)//reach upto the last node
				cur=cur->next;
			cur->next=newnode;
			head=newnode;
			printf("\nNODE CREATED AT FIRST INDEX");
			return;
		}
	}
	else
	{
		for(i=1;i<loc;i++)
		{
			prv=cur;
			cur=cur->next;
		}
		prv->next=newnode;
		newnode->next=cur;
		return;
	}
}
void addbef()
{
	int n,num;
	struct node *newnode, *cur, *prev;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n ENTER THE ELEMENT TO BE INSERTED : ");
	scanf("%d",&num);
	newnode->data=num;
	cur=head;
	//if list is empty, add at beginning
	if(head==NULL)
	{
		head=newnode;
		head->next=head;
		return;
	}
	else //adding before first node
	{
		printf("\nENTER THE ELEMENT BEFORE WHICH YOU WANT TO INSERT : ");
		scanf("%d",&n);
		if(cur->data==n)
		{
			newnode->next=head;
			while(cur->next!=head) //reach unto the last node
				cur=cur->next;
			cur->next=newnode;
			head=newnode;
			return;
		}
		while(cur->next!=head)
		{
			prev=cur;
			cur=cur->next;
			if(cur->data==n)
			{
				prev->next=newnode;
				newnode->next=cur;
				return;
			}
		}
	}
	printf("\nNODE NOT FOUND !!");
}
void addafter()
{
	struct node *cur, *prv, *newnode;
	int x=0,n,num;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n ENTER THE ELEMENT TO BE INSERTED : ");
	scanf("%d",&num);
	newnode->data=num;
	cur=head;
	if(head==NULL)
	{
		head=newnode;
		head->next=head;
		return;
	}
	else
	{
		printf("\nENTER THE ELEMENT AFTER WHICH YOU WANT TO INSERT : ");
		scanf("%d",&n);
		while(cur->next!=head)
		{
			//check for all nodes excetp last node
			if(cur->data==n)
			{
				newnode->next=cur->next;
				cur->next=newnode;
				x=1;
			}
			cur=cur->next;
		}
		if(x==0 && cur->next==head && cur->data==n)
		{
			//check for last node
			newnode->next=cur->next; //head copied in newnode->next
			cur->next=newnode;
			x=1;
		}
	}
	if(x==0 && cur->next==head)
		printf("\nNODE NOT FOUND !!");
}
void delnode()
{
	struct node *cur, *prv, *del;
	int num;
	cur=head;
	printf("\nPLEASE ENTER THE ELEMENT TO BE DELETED FROM THE LIST : ");
	scanf("%d",&num);
	if(cur->data==num)//deleting first node of list
	{
		if(cur->next==head) //check if only node is left in the list
		{
			free(cur);
			head=NULL;
			return;
		} //else the list has more than one node
		while(cur->next!=head)
			cur=cur->next;
		del=head;
		cur->next=head->next;
		head=head->next;
		free(del);
		return;
	}
	//delete node other than first node
	while(cur->next!=head)
	{
		prv=cur;
		cur=cur->next;
		if(cur->data==num)
		{
			prv->next=cur->next;
			free(cur);
			return;
		}
	}
	printf("\nELEMENT %d NOT FOUND !!",&num);
}
void search()
{
	int num,i=0;
	struct node *cur;
	cur=head;
	printf("\nENTER ELEMENT TO BE SEARCHED : ");
	scanf("%d",&num);
	while(cur->next!=head)
	{
		i++;
		if(cur->data==num)
		{
			printf("\nELEMENT %d FOUND AT LOCATION %d !\n",cur->data,i);
			return;
		}
		cur=cur->next;
	}
	if(cur->next==head && cur->data==num)
	{
		i++;
		printf("\n %d FOUND AT LOCATION %d !! \n",cur->data,i);
		return;
	}
	printf("\n ELEMENT NOT FOUND !!\n");
}
void reverse()
{
	struct node *cur,*temp,*prev;
	temp=head;
	prev=head;
	cur=head;
	cur=cur->next;
	temp=temp->next->next;
	while(cur!=head)
	{
		cur->next=prev;
		prev=cur;
		cur=temp;
		temp=temp->next;
	}
	head=prev;
	cur->next=head;
}
int main()
{
	int ch;
	head=NULL;
	while(1)
	{
		printf(" \nDEMONSTRATION OF CIRCULAR LINKED LIST");
		printf("\n 1. INSERTION AT BEGINNING / BEFORE AN ELEMENT");
		printf("\n 2. INSERTION AFTER AN ELEMENT");
		printf("\n 3. INSERTION AT GIVEN LOCATION");
		printf("\n 4. DELETE A NODE");
		printf("\n 5. SEARCH A NODE");
		printf("\n 6. COUNT NUMBER OF NODES IN LIST");
		printf("\n 7. REVERSE THE CIRCULAR LINKED LIST");
		printf("\n 8. DISPLAY LIST");
		printf("\n 9. EXIT LIST");
		printf("\n ENTER YOUR CHOICE : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				int num;
				//addbeg();
				addbef();
				display();
				break;
			}
			case 2:
			{

				addafter();
				//addend();
				display();
				break;
			}
			case 3:
			{
				int num,loc,k;
				printf("\nENTER THE ELEMENT TO BE INSERTED : ");
				scanf("%d",&num);
				printf("\nPLEASE ENTER THE LOCATION : ");
				scanf("%d",&loc);
				addloc(num,loc);
				display();
				break;
			}
			case 8:
			{
				//printf("\nTHE ELEMENTS IN THE LIST ARE : ");
				display();
				break;
			}
			case 5:
			{
				search();
				break;
			}
			case 6:
			{
				struct node *n;
				display();
				printf("\nTHE TOTAL NUMBER OF ELEMENTS IN THE LIST ARE : %d\n",count());
				break;
			}
			case 7:
			{
				reverse();
				display();
				break;
			}
			case 4:
			{
				delnode();
				display();
				break;
			}
			default:
				exit(1);
				break;
		}
	}
}
