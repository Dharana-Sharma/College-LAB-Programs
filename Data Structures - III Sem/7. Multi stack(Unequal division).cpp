#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
typedef struct stack
{
    int a[MAX];
    int top1;
    int top2;
}s;
int is_full (s st)
{
    if(st.top1==st.top2-1)
    {
        return 1;
    }
    return 0;
}
int is_empty1 (s st)
{
    if(st.top1==-1)
    {
        return 1;
    }
    return 0;
}
int is_empty2 (s st)
{
    if(st.top2==MAX)
    {
        return 1;
    }
    return 0;
}
void push1 (s *st)
{
    int value;
    if(is_full(*st))
    {
        printf("\nSTACK OVERFLOW");
        return;
    }
    printf("\nENTER THE VALUE TO BE PUSHED:");
    scanf("%d",&value);
    st->a[++(st->top1)]=value;
    printf("\n%d PUSHED",value);
}
void push2 (s *st)
{
    int value;
    if(is_full(*st))
    {
        printf("\nSTACK OVERFLOW");
        return;
    }
    printf("\nENTER THE VALUE TO BE PUSHED:");
    scanf("%d",&value);
    st->a[--(st->top2)]=value;
    printf("\n%d PUSHED",value);

}
int pop1 (s *st)
{
    if(is_empty1(*st))
    {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    return st->a[(st->top1)--];
}
int pop2 (s *st)
{
    if(is_empty2(*st))
    {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    return st->a[(st->top2)++];
}
int peek1(s*st)
{
    if(is_empty1(*st))
    {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    return st->a[st->top1];
}
int peek2(s*st)
{
    if(is_empty2(*st))
    {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    return st->a[(st->top2)];
}

void display1(s st)
{
    int i;
    if(is_empty1(st))
    {
        printf("\nSTACK UNDERFLOW");
        return;
    }
    for(i=st.top1; i>=0; i--)
    {
        printf("%d",st.a[i]);
    }
}
void display2(s st)
{
    int i;
    if(is_empty2(st))
    {
        printf("\nSTACK UNDERFLOW");
        return;
    }
    for(i=st.top2; i<MAX; i++)
    {
        printf("%d",st.a[i]);
    }
}
int main()
{
    s st;
    st.top1=-1; 
    st.top2=MAX;
    int pop_item1,peek_item1,pop_item2,peek_item2,ch;
    char ch2;
    do
    {
        printf("\nMENU CHOICES:");
        printf("\n1.PUSH ELEMENTS IN STACK");
        printf("\n2.POP ELEMENTS FROM STACK");
        printf("\n3.PEEK ELEMENT OF STACK");
        printf("\n4.DISPLAY STACK");
        printf("\n5.Exit");
        printf("\nENTER YOUR CHOICE (1-5):");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nENTER THE STACK YOU WANT TO PERFORM OPERATIONS ON:");
                    printf("\nA.STACK 1:");
                    printf("\nB.STACK 2:");
                    printf("\nENTER YOUR CHOICE (A-B):");
                    fflush(stdin);
                    scanf("%s" , &ch2);
                    switch(ch2)
                    {
                        case 'A': push1(&st);
                                  break;

                        case 'B': push2(&st);
                                  break;

                        default: printf("\nWRONG CHOICE");
                    }
                    break;
            case 2: printf("\nENTER THE STACK YOU WANT TO PERFORM OPERATIONS ON:");
                    printf("\nA.STACK 1:");
                    printf("\nB.STACK 2:");
                    printf("\nENTER YOUR CHOICE (A-B):");
                    fflush(stdin);
                    scanf("%s" , &ch2);
                    switch(ch2)
                    {
                        case 'A': pop_item1=pop1(&st);
                                  printf("\n%d POPPED",pop_item1);
                                  break;

                        case 'B': pop_item2=pop2(&st);
                                  printf("\n%d POPPED",pop_item2);
                                  break;

                        default: printf("\nWRONG CHOICE");
                    }  
                    break;
            case 3: printf("\nENTER THE STACK YOU WANT TO PERFORM OPERATIONS ON:");
                    printf("\nA.STACK 1:");
                    printf("\nB.STACK 2:");
                    printf("\nENTER YOUR CHOICE (A-B):");
                    fflush(stdin);
                    scanf("%s" , &ch2);
                    switch(ch2)
                    {
                        case 'A': peek_item1=peek1(&st);
                                  printf("\n%d PEEK VALUE",peek_item1);
                                  break;

                        case 'B': peek_item2=peek2(&st);
                                  printf("\n%d PEEK VALUE",peek_item2);
                                  break;

                        default: printf("\nWRONG CHOICE");
                    }
                    break;
            case 4: printf("\nENTER THE STACK YOU WANT TO PERFORM OPERATIONS ON:");
                    printf("\nA.STACK 1:");
                    printf("\nB.STACK 2:");
                    printf("\nENTER YOUR CHOICE (A-B):");
                    fflush(stdin);
                    scanf("%s" , &ch2);
                    switch(ch2)
                    {
                        case 'A': display1(st);
                                  break;

                        case 'B': display2(st);
                                  break;

                        default: printf("\nWRONG CHOICE");
                    }
                    break;
            case 5: printf("\nEXIT");
                    exit(0);
            default: printf("\nWRONG CHOICE");
        }
    }
    while(1);
    return 0;
}

