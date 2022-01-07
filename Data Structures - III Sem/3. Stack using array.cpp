#include <stdio.h>
#include <stdlib.h>
#define max 20
int isempty(int top)
{
    if(top<0)
        return 1;
    else 
        return 0;
}
int isfull(int top)
{
    if(top==max-1)
        return 1;
    else 
        return 0;
}
void push(int s[max],int*t,int*x)
{
    if(isfull(*t))
        printf("overflow\n");
    else
    {
        s[++(*t)]=*x;
        printf("pushed element=%d\n",s[*t]);
    }
}
void pop (int s[max],int*t)
{
    if(isempty(*t))
        printf("underflow\n");
    else
    {
        printf("popped element=%d\n",s[(*t)--]);
    }
}
int peek (int s[max],int*t)
{	
    if(isempty(*t))
	{
        printf("stack is empty\n");
        return -1;
	}
    return s[*t];
}

int main()
{	
    int i,el,ch,st[max],top=-1;
    while(1)
    {
        printf("\n*****menu*****\n");
        printf("1. push element\n ");
        printf("2. pop element\n");
        printf("3. peek \n");
        printf("4. display stack\n");
        printf("5. exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter element:");
                   scanf("%d",&el);
                   push(st,&top,&el);
                   break;
                   
            case 2:pop(st,&top);
                   break;
            
			case 3: {int x=peek(st,&top);
            		printf("top element=%d\n",x);
                   break;}
           
		    case 4:if(isempty(top))
                   {
                        printf("stack is empty\n");
                    }
                    else
                    {
                        printf("elements of stack are:" );
                        for(i=top;i>=0;i--)
                        {
                            printf("%d",st[top--]);
                        }
                    }
                    break;
            case 5: printf("exit");
                    exit(0);
            default:printf("wrong choice");
        }
    }
}