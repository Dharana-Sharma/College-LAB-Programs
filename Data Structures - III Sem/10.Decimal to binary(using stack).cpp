#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct stack
{
	int data[MAX];
	int top;;
}stack;

int isempty(stack s)
{
	if(s.top==-1)
		return(1);
	return 0;	
}

int isfull(stack s)
{
	if(s.top==MAX-1)
		return 1;
	return 0;	
}

// to push the remainder into the stack
void push(stack *s,int x)
{
	s->top=s->top+1;
	s->data[s->top]=x;
}

//to pop the remainder out from the stack
int pop(stack *s)
{
	int x;
	x=s->data[s->top];
	s->top=s->top-1;
	return x;
}

int main()
{
	stack s;
	int num;
	s.top=-1;
	printf("enter a decimal number:");
	scanf("%d",&num);
	while((num!=0))
	{
		if(!isfull(s))
		{
			push(&s,num%2);
			num=num/2;
		}
		else
		{
			printf("stack overflow");
			exit(0);
		}
	}
	while(!isempty(s))
	{
		num=pop(&s);
		printf("%d",num);
	}
}
