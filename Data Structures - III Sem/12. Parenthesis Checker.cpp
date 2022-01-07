#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30

typedef struct stack
{
	int top;
	char opdst[MAX];
}stack;

void push(stack*,char);
char pop(stack*);
char peek(stack);
int isFull(stack);
int isEmpty(stack);
int matching(char op,char cp);
int check(char[]);

int main()
{
	char infix[MAX], postfix[MAX];
    printf("\nINPUT THE EXPRESSION : ");
    scanf("%s", infix);
    if(strlen(infix)+1>MAX)
    {
    	printf("................EXPRESSION TOO LONG........");
    	exit(0);
    }
    if(check(infix))
       printf("INVALID");
    else
       printf("VALID");
       return 0;
}

int isFull(stack s)
{
   if(s.top==MAX-1)
      return 1;
   return 0;
}

 int isEmpty(stack s)
{
   if(s.top==-1)
      return 1;
   return 0;
}

void push(stack *s,char item)
{
	s->opdst[++(s->top)]=item;
}

char pop(stack *s)
{
	if(!isEmpty(*s))
	   return s->opdst[(s->top)--];
}

char peek(stack s)
{
	return s.opdst[s.top];
}

int matching(char op,char cp)
{
    if(op==')' && cp=='(')
		return 1;
	if(op=='}' && cp=='{')
        return 1;			
	if(op==']' && cp=='[')
		return 1;
	 return 0;
}
int check(char exp[] )
{
        int i;
        stack s;
        s.top=-1;
        for(i=0;exp[i]!='\0';i++)
        {
            if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                push(&s,exp[i]);
            else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            {
				if(!matching(exp[i],peek(s)))
                    return 0;
                pop(&s);
            }
        }
        if(isEmpty(s))
            return 0;
        return 1;
}