#include <stdio.h>
#include <stdlib.h>
#define max 20
int isempty(int fr,int re)
{
    if((fr==-1||fr>re))
        return 1;
    else 
        return 0;
}
int isfull(int re)
{
    if(re==max)
        return 1;
    else 
        return 0;
}
void enqueue(int q[max],int*f,int*r,int*x)
{
    if(isfull(*r))
        printf("overflow\n");
    else
    {
        (*r)++;
        if(*f==-1)
            (*f)=0;
        q[*r]=*x;
        printf("element entered =%d\n",q[*r]);
    }
}
void dequeue(int q[max],int*f,int*r)
{
    if(isempty(*f,*r)==1)
        printf("underflow\n");
    else
    {
        printf("deleted element=%d\n",q[*f]);
        (*f)++;
        if(*f>*r)
        {
            *f=*r=-1;
            printf("underflow\n");
        }
    }
}
int main()
{
    int i,el,ch,qu[max],front=-1,rear=-1;
    while(1)
    {
        printf("\n*****menu*****\n");
        printf("1. insert element\n ");
        printf("2. delete element\n");
        printf("3. display queue\n");
        printf("4. exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter element:");
                   scanf("%d",&el);
                   enqueue(qu,&front,&rear,&el);
                   break;
            case 2:dequeue(qu,&front,&rear);
                   break;
            case 3:if(isempty(front,rear))
                   {
                        printf("queue is empty\n");
                    }
                    else
                    {
                        printf("elements of queue are:" );
                        for(i=front;i<=rear;i++)
                        {
                            printf("%d",qu[front++]);
                        }
                    }
                    break;
            case 4: printf("exit");
                    exit(0);
            default:printf("wrong choice");
        }
    }
}