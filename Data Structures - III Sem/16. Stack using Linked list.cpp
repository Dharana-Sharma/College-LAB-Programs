#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
    int info;
    struct node *link;
}NODE;

NODE *push(NODE *top, int pushed_item)
{
	NODE *NewNode;
	NewNode= (NODE*)malloc(sizeof(NODE));
	NewNode->info=pushed_item;
	NewNode->link=top;
	top=NewNode;
	return(top);
}

NODE *pop(NODE *top)
{
	NODE *tmp;
	if(top==NULL)
	printf("\nUnderflow\n");
	else
	{
		tmp=top;
		printf("\nPopped item is %d\n",tmp->info);
		top=top->link;
		tmp->link=NULL;
		free(tmp);
	}
	return(top);
}

void display(NODE *top)
{
	if(top==NULL)
	printf("\nUnderflow\n");
	else
	{
		printf("\nStack elements: \n");
		while(top!=NULL)
		{
			printf("%d\n", top->info);
			top=top->link;
		}
	}
}

int main()
{
	char opt;
	int choice, pushed_item;
	NODE *Top=NULL;
	while(1)
	{
		printf("\n1. Push\n");
		printf("2. Pop\n");
		printf("3.Display\n");
		printf("4. Exit\n");
		printf("Enter ur choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Input the new value to be pushed on the stack:");
				scanf("%d", &pushed_item);
				Top=push(Top,pushed_item);
				break;
		case 2:
			    Top=pop(Top);
			    break;
		case 3:
			    display(Top);
			    break;
		case 4:
			    exit(0);
		default: 
		        printf("\nWrong choice\n");
		        
		}
		getch();
	}
}