#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct stack
{
	int top;
	char st[MAX];
}stack;

void convert(char[],char[]);
void push(stack*,char);
char pop(stack*);
char peek(stack);
int isEmpty(stack);
int isFull(stack);
int prec(char);

int main()
{
	char infix[MAX],postfix[MAX];
	printf("Enter the infix expression:");
	scanf("%s",infix);
	if(strlen(infix)+1>MAX)
	{
		printf("............EXPRESSION TOO LONG...........");
		exit(0);
	}
	convert(infix,postfix);
	printf("The required postfix expression  is %s",postfix);
}

void convert(char from[],char to[])
{
	stack s;
	int i,j=0,pre;
	char val;
	s.top=-1;
	
	push(&s,'(');
	for(i=0;from[i]!='\0';i++);
	from[i++]=')';
	from[i]='\0';
	for(i=0;from[i]!='\0';i++)
	{
		if(isdigit(from[i]) || isalpha(from[i]))
		    to[j++]=from[i];
		else if(from[i]==')')
		{
			while(peek(s)!='(')
			    to[j++]=pop(&s);
			val=pop(&s);
		}
		else if(from[i]=='(')
		     push(&s,from[i]);
		else
		{
			pre=prec(from[i]);
			if(pre==-1)
			{
				printf("............INVALID EXPRESSION............");
				exit(0);
			}
			while(prec(peek(s))>=pre)
			      to[j++]=pop(&s);
			push(&s,from[i]);
		}
	}
	to[j]='\0';
	if(!isEmpty(s))
	{
		printf("............INVALID EXPRESSION.............");
		exit(0);
	}
}

void push(stack*s,char opr)
{
	s->st[++(s->top)]=opr;
}

char pop(stack *s)
{
	char ele;
	ele=s->st[(s->top)--];
	return ele;
}

char peek(stack s)
{
	return s.st[s.top];
}

int isEmpty(stack s)
{
	if(s.top==-1)
	   return -1;
	return 0;
}

int prec(char a)
{
	if(a=='(')
	    return 1;
	else if(a=='+' || a=='-')
	    return 2;
	else if(a=='*' || a=='/' || a=='%')
	    return 3;
	else
	    return -1;
}