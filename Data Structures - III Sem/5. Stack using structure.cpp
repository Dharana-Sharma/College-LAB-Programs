#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 10

typedef struct Stack
{
    int data[max];
    int top;
}stack;

int isEmpty(stack*s)
{
    if(s->top=-1)
        return 1;
    else
    	return 0;
}

int isFull(stack*s)
{
    if(s->top==max-1)
        return 1;
    else
    	return 0;
}

void push(stack*s)
{
	int y;
	if(isFull(s))
	    printf("Overflow.\n");
	else    
   	{	
   		printf("Enter element:");
            scanf("%d",&y);
    	s->top = s->top+1;
    	s->data[s->top]=y;
    	printf("Pushed element=%d\n",s->data[s->top]);
    }
        
}

int pop(stack *s)
{
	int x;
	if(isEmpty(s)){
        printf("Underflow.\n");
        return -1;
		}
	else
    {
    	x=s->data[s->top];
    	printf("Popped element is= %d\n",s->data[s->top]);
    	s->top = s->top-1;
    }
    return(x);
}

int peek(stack*s)
{
	if(isEmpty(s)){
	    printf("Stack is empty.\n");
	    return -1;
	}
	else
    {
    	int x;
    	x=s->data[s->top];
    	printf("Top element is= %d\n",s->data[s->top]);
    	return(x);
    }   
}

void print(stack*s)
{
    int i;
    for(i=s->top;i>=0;i--)
    {
        printf("%d  ",s->data[s->top--]);
        
    }
}

int main()
{
    stack s;
    int ch,el,p,q;
    s.top=-1;

    while(1)
    {
        printf("\nMenu:\n");    
        printf("1.push\n");
        printf("2.pop:\n");
        printf("3.peek:\n");
        printf("4.Print stack:\n");
        printf("5.EXIT\n");
        printf("\nEnter choice:");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1: push(&s);
                    break;

            case 2: p=pop(&s);
                    break;
                    
            case 3: q=peek(&s);
                    
                    break;
                    
                    
            
            case 4: if(!isEmpty(&s))
            		{
            			printf("Elements of stack are: ");
            			print(&s);
					}
                        
                    else
                        printf("Stack is empty.\n");    
                    break;
                     
            case 5: printf("Exiting.\n");
                    exit(0);
                    
            default: printf("Invalid Choice.\n");         
        }
    }
	return 0;
}